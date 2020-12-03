#pragma once
#include <iostream>
#include <string>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"

void getHuffmanCode(BasicBinaryTreeNode<char, int> *huffmanTree, std::string codeStorage[256], char code[100], int depth = 0);
