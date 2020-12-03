#include "get_huffman_code.hpp"

using namespace std;

void getHuffmanCode(BasicBinaryTreeNode<char, int> *huffmanTree, string *codeStorage[256], char code[100], int depth)
{
    if (huffmanTree)
    {
        if (huffmanTree->getKey())
        {
            codeStorage[huffmanTree->getKey()] = new string(code, depth);
            // cout << huffmanTree->getKey() << ": " << code << endl;
        }
        code[depth] = '0';
        getHuffmanCode(huffmanTree->getLeftChild(), codeStorage, code, depth + 1);
        code[depth] = '1';
        getHuffmanCode(huffmanTree->getRightChild(), codeStorage, code, depth + 1);
    }
}

BasicBinaryTreeNode<char, int> *countFile(ifstream &inputFileStream, int charCount[256], string *huffmanCode[256], int &differentCharCount)
{
    BasicBinaryTreeNode<char, int> *binNodes[256];
    countChar(inputFileStream, charCount);
    for (size_t i = 0; i < 256; i++)
    {
        if (charCount[i] > 0)
        {
            binNodes[differentCharCount] = new BasicBinaryTreeNode<char, int>(i, charCount[i]);
            differentCharCount++;
        }
    }
    BasicBinaryTreeNode<char, int> *huffmanTree = buildHuffmanTree(binNodes, differentCharCount, 256);
    char huffcode[64] = {0};
    getHuffmanCode(huffmanTree, huffmanCode, huffcode);
    return huffmanTree;
}
