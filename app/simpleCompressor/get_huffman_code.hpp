#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/huffman_tree/huffmanTree.hpp"
#include "count_char.hpp"

void getHuffmanCode(BasicBinaryTreeNode<char, int> *huffmanTree, std::string *codeStorage[256], char code[100], int depth = 0);

BasicBinaryTreeNode<char, int> *countFile(std::ifstream &inputFileStream, int charCount[256], std::string *huffmanCode[256], int &differentCharCount);
