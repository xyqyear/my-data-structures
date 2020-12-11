#include "compress.hpp"

using namespace std;

bool compress(const std::string &srcFileName, const std::string &destFileName)
{
    ifstream srcFileStream(srcFileName, ios::binary);
    ofstream destFileStream(destFileName, ios::binary);

    if (!srcFileStream.is_open())
    {
        srcFileStream.close();
        destFileStream.close();
        return false;
    }

    if (!destFileStream.is_open())
    {
        srcFileStream.close();
        destFileStream.close();
        return false;
    }

    // build huffman tree and get huffman code
    int charCount[256] = {0};
    string *codeStorage[256] = {nullptr};
    int differentCharCount = 0;
    BasicBinaryTreeNode<char, int> *huffmanTree = countFile(srcFileStream, charCount, codeStorage, differentCharCount);

    // 1st field - different char count
    destFileStream.put(differentCharCount);

    // 2nd field - char & frequency array
    for (size_t i = 0; i < 256; i++)
    {
        if (charCount[i])
        {
            destFileStream.put(i);
            destFileStream.write((char *)&charCount[i], 4);
        }
    }

    // 3rd field - the length of the compressed data
    int lengthOfCompressedData = 0;
    for (size_t i = 0; i < 256; i++)
    {
        if (codeStorage[i])
        {
            lengthOfCompressedData += charCount[i] * codeStorage[i]->length();
        }
    }
    destFileStream.write((char *)&lengthOfCompressedData, 4);
    destFileStream.close();

    // 4nd field - compressed data
    HuffmanFileEncoder huffmanFileEncoder(codeStorage, destFileName);
    if (!huffmanFileEncoder.is_open())
    {
        delete huffmanTree;
        for (size_t i = 0; i < 256; i++)
        {
            if (codeStorage[i])
            {
                delete codeStorage[i];
            }
        }
        huffmanFileEncoder.close();
        srcFileStream.close();
        return false;
    }

    char originalFileCharBuffer;
    while (srcFileStream.get(originalFileCharBuffer))
    {
        huffmanFileEncoder.putChar(originalFileCharBuffer);
    }
    huffmanFileEncoder.close();

    // clean up
    srcFileStream.close();
    for (size_t i = 0; i < 256; i++)
    {
        if (codeStorage[i])
        {
            delete codeStorage[i];
        }
    }
    delete huffmanTree;

    return true;
}
