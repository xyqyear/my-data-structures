#pragma once
#include <iostream>
#include <cstring>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"

void printCode(BasicBinaryTreeNode<char, int> *huffmanTree, char codeStorage[256][256], char *code, int depth = 0);
