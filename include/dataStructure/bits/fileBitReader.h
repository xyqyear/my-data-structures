#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileBitReader
{
private:
    std::ifstream fileStream;
    char buffer = 0;
    // -1 means buffer underrun
    int bufferPointer = -1;

public:
    FileBitReader(const std::string &filename);
    bool readBit(int& bit);
    bool is_open();
    void close();
};
