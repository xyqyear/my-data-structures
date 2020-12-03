#pragma once
#include <iostream>
#include <fstream>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/huffman_tree/huffmanTree.hpp"
#include "get_huffman_code.hpp"
#include "count_char.hpp"
#include "huffman_encoder_decoder.hpp"

/*
using huffman code to decompress a file.
the file's format is presented in the "file-format.md" file.

srcFileName: the file you want to decompress.
destFileName: where you want to save the decompressed file to.
return: whether the process succeeded or not (not impletemented).

使用哈夫曼编码解压一个文件。
压缩文件格式在 "file-format.md" 中有说明。

srcFileName: 压缩文件路径
destFileName: 解压后的文件保存路径
return: 是否成功 (未实现)
*/
bool decompress(const std::string &srcFileName, const std::string &destFileName);
