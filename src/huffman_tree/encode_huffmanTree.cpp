#include "dataStructure/huffman_tree/encode_huffmanTree.hpp"

using namespace std;

void printCode(BasicBinaryTreeNode<char, int> *huffmanTree, char *code, int depth)
{
    if (huffmanTree)
    {
        if (huffmanTree->getKey())
        {
            code[depth] = 0;
            cout << huffmanTree->getKey() << ": " << code << endl;
        }
        code[depth] = '0';
        printCode(huffmanTree->getLeftChild(), code, depth + 1);
        code[depth] = '1';
        printCode(huffmanTree->getRightChild(), code, depth + 1);
    }
}
