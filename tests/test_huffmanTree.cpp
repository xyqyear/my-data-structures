#include <iostream>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/huffman_tree/huffmanTree.hpp"
#include "dataStructure/huffman_tree/encode_huffmanTree.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int frequency[256] = {0};
    frequency['e'] = 50;
    frequency['a'] = 30;
    frequency['o'] = 20;
    frequency['p'] = 10;
    frequency['x'] = 2;

    BasicBinaryTreeNode<char, int> *nodes[10];
    nodes[0] = new BasicBinaryTreeNode<char, int>('e', frequency['e']);
    nodes[1] = new BasicBinaryTreeNode<char, int>('a', frequency['a']);
    nodes[2] = new BasicBinaryTreeNode<char, int>('o', frequency['o']);
    nodes[3] = new BasicBinaryTreeNode<char, int>('p', frequency['p']);
    nodes[4] = new BasicBinaryTreeNode<char, int>('x', frequency['x']);

    BasicBinaryTreeNode<char, int> *huffmanTree = buildHuffmanTree(nodes, 5, 10);
    cout << huffmanTree->getValue() << endl;

    char huffcode[64] = {0};

    printCode(huffmanTree, huffcode);

    delete huffmanTree;
    return 0;
}
