#include "decompress.hpp"

using namespace std;

bool decompress(const std::string &srcFileName, const std::string &destFileName)
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

    char differentCharCount;
    srcFileStream.get(differentCharCount);

    BasicBinaryTreeNode<char, int> *binNodes[256];
    char tempChar;
    int tempValue;
    for (size_t i = 0; i < differentCharCount; i++)
    {
        srcFileStream.get(tempChar);
        srcFileStream.read((char *)&tempValue, 4);
        binNodes[i] = new BasicBinaryTreeNode<char, int>(tempChar, tempValue);
    }

    int compressedDataBitLength;
    srcFileStream.read((char *)&compressedDataBitLength, 4);

    int dataPos = srcFileStream.tellg();
    srcFileStream.close();
    BasicBinaryTreeNode<char, int> * huffmanTree = buildHuffmanTree(binNodes, differentCharCount, 256);

    HuffmanFileDecoder huffmanFileDecoder(huffmanTree, srcFileName, compressedDataBitLength);
    if (!huffmanFileDecoder.is_open())
    {
        cout << "error while opening the compressed file." << endl;
        exit(0);
    }
    huffmanFileDecoder.seek(dataPos);

    while (huffmanFileDecoder.getChar(tempChar))
    {
        destFileStream.put(tempChar);
    }

    huffmanFileDecoder.close();
    destFileStream.close();
    delete huffmanTree;

    return true;
}
