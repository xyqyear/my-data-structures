#pragma once
#include <iostream>
#include <fstream>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/huffman_tree/huffmanTree.hpp"
#include "get_huffman_code.hpp"
#include "count_char.hpp"
#include "huffman_encoder_decoder.hpp"

bool decompress(const std::string &srcFileName, const std::string &destFileName);
