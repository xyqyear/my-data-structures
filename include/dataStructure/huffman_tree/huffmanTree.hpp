#pragma once
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/heap/heap.hpp"

BasicBinaryTreeNode<char, int> *buildHuffmanTree(BasicBinaryTreeNode<char, int> **nodeArray, int arrayLength, int arrayMaxLength);
