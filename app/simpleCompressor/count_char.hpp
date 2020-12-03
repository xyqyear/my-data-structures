#pragma once
#include <iostream>
#include <fstream>

/*
open a file and count how many times each character has appeared

fileStream: source file's ifstream
    the position of the stream should be saved and resume before returning.
    any errir happened in this function should be cleared before returning.
charCount: character count
    e.g. the number of occurrences of 'e'(ascii: 101) is 5, then charCount['e'] should be 5 (charCount[101] should be 5)

打开文件统计每个字符出现的次数

fileStream: 原文件的ifstream
    函数应该保存这个stream的指针位置并在返回之前恢复指针的位置。
    这个stream在函数内部发生的任何错误应该在返回之前被清除。
charCount: 字符出现的次数统计
    例如：'e'(ascii码为101)的出现次数为5， 那么 charCount['e'] 应为 5 (charCount[101] 应为5)
*/
void countChar(std::ifstream &fileStream, int charCount[256]);
