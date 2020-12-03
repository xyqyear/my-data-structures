#include "dataStructure/huffman_tree/huffmanTree.hpp"

BasicBinaryTreeNode<char, int> *buildHuffmanTree(BasicBinaryTreeNode<char, int> **nodeArray, int arrayLength, int arrayMaxLength)
{
    MinPointerHeap<BasicBinaryTreeNode<char, int> *> heap(nodeArray, arrayLength, arrayMaxLength);
    heap.buildHeap();
    while (heap.getSize() > 1)
    {
        auto *smallestNode = heap.removeFirst();
        auto *secondSmallestNode = heap.removeFirst();
        auto *rootNode = new BasicBinaryTreeNode<char, int>(0, smallestNode->getValue() + secondSmallestNode->getValue(), smallestNode, secondSmallestNode);
        heap.insert(rootNode);
    }
    // the node returned should be deleted after use
    // you only need to delete the root node and the elements in the original node array is going to be deleted automatically
    return heap.removeFirst();
}
