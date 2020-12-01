#pragma once
#include "basicBinaryTree.hpp"
#include "heap.hpp"

BasicBinaryTreeNode<char, int> *buildHuffmanTree(BasicBinaryTreeNode<char, int> **nodeArray, int arrayLength, int arrayMaxLength);
