#include <iostream>
#include <string>
#include <cassert>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "dataStructure/bits/fileBitReader.h"
#include "dataStructure/bits/fileBitWriter.h"

class HuffmanEncoderDecoderBase
{
protected:
    int bitLength = 0;
public:
    int getBitLength();
};

class HuffmanFileEncoder : public HuffmanEncoderDecoderBase
{
private:
    std::string *huffmanCode;
    FileBitWriter *fileBitWriter;

public:
    HuffmanFileEncoder(std::string huffmanCode[256], const std::string& filename);
    ~HuffmanFileEncoder();
    void putChar(char char2put);
    void flush();
    bool is_open();
    void close();
};

class HuffmanFileDecoder : public HuffmanEncoderDecoderBase
{
private:
    BasicBinaryTreeNode<char, int> *huffmanTree;
    FileBitReader *fileBitReader;
    int bitBuffer;
    bool getCharHelper(BasicBinaryTreeNode<char, int> *currentNode, char &charBuffer);

public:
    HuffmanFileDecoder(BasicBinaryTreeNode<char, int> * huffmanTree, const std::string& filename, int contentBitLength);
    ~HuffmanFileDecoder();
    bool getChar(char &charBuffer);
    bool is_open();
    void close();
};
