#pragma once
#include "../bin_tree/basicBinaryTree.hpp"
#include "../heap/heap.hpp"

BasicBinaryTreeNode<char, int>* buildHuffmanTree(BasicBinaryTreeNode<char, int>** nodeArray, int arrayLength, int arrayMaxLength)
{
    MinPointerHeap<BasicBinaryTreeNode<char, int>*> heap(nodeArray, arrayLength, arrayMaxLength);
    heap.buildHeap();
    while (heap.getSize() > 1)
    {
        BasicBinaryTreeNode<char, int>* smallestNode = heap.removeFirst();
        BasicBinaryTreeNode<char, int>* secondSmallestNode = heap.removeFirst();
        BasicBinaryTreeNode<char, int>* rootNode = new BasicBinaryTreeNode<char, int>(0, smallestNode->getValue() + secondSmallestNode->getValue(), smallestNode, secondSmallestNode);
        heap.insert(rootNode);
    }
    return heap.removeFirst();
}
