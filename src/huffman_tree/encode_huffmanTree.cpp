#include "dataStructure/huffman_tree/encode_huffmanTree.hpp"

using namespace std;

void printCode(BasicBinaryTreeNode<char, int> *huffmanTree, char codeStorage[256][256], char *code, int depth)
{
    if (huffmanTree)
    {
        if (huffmanTree->getKey())
        {
            code[depth] = 0;
            strcpy_s(codeStorage[huffmanTree->getKey()], code);
            // cout << huffmanTree->getKey() << ": " << code << endl;
        }
        code[depth] = '0';
        printCode(huffmanTree->getLeftChild(), codeStorage, code, depth + 1);
        code[depth] = '1';
        printCode(huffmanTree->getRightChild(), codeStorage, code, depth + 1);
    }
}
