#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileBitWriter
{
private:
    std::ofstream fileStream;
    char buffer = 0;
    int bufferPointer = 0;

public:
    FileBitWriter(const std::string &filename);
    void writeBit(int bit);
    bool is_open();
    void flush();
    void close();
    int tell();
    void seek(int pos);
    void clearError();
};
