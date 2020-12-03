#include "get_huffman_code.hpp"

using namespace std;

void getHuffmanCode(BasicBinaryTreeNode<char, int> *huffmanTree, string codeStorage[256], char code[100], int depth)
{
    if (huffmanTree)
    {
        if (huffmanTree->getKey())
        {
            codeStorage[huffmanTree->getKey()].append(code, depth);
            // cout << huffmanTree->getKey() << ": " << code << endl;
        }
        code[depth] = '0';
        getHuffmanCode(huffmanTree->getLeftChild(), codeStorage, code, depth + 1);
        code[depth] = '1';
        getHuffmanCode(huffmanTree->getRightChild(), codeStorage, code, depth + 1);
    }
}
