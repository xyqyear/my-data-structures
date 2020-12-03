#include "compress.hpp"

using namespace std;

bool compress(const std::string &srcFileName, const std::string &destFileName)
{
    ifstream srcFileStream(srcFileName, ios::binary);
    ofstream destFileStream(destFileName, ios::binary);

    if (!srcFileStream.is_open())
    {
        cout << "error while opening the compressed file." << endl;
        exit(0);
    }

    if (!destFileStream.is_open())
    {
        cout << "error while opeing the destination file." << endl;
        exit(0);
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
        cout << "error while opening the destination file." << endl;
        exit(0);
    }
    char originalFileCharBuffer;
    while (srcFileStream.get(originalFileCharBuffer))
    {
        huffmanFileEncoder.putChar(originalFileCharBuffer);
    }
    int contentBitLength = huffmanFileEncoder.getBitLength();
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
