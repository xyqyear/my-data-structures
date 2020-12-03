#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include "dataStructure/huffman_tree/huffmanTree.hpp"
#include "dataStructure/bin_tree/basicBinaryTree.hpp"
#include "../app/simpleCompressor/get_huffman_code.hpp"
#include "../app/simpleCompressor/huffman_encoder_decoder.hpp"
#include "../app/simpleCompressor/count_char.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "start testing huffman decoder and encoder" << endl;
    string testString("geriosutybw48tu9q3874tyvq347hb389q7tyq389047yhqv8  347btv 4783t 8734y8t3\n\neraete");
    ofstream fileStream("testOrigin.txt");
    fileStream << testString;
    fileStream.close();

    int charCount[256] = {0};
    BasicBinaryTreeNode<char, int> *binNodes[256];
    ifstream originalFileInputStream("testOrigin.txt");
    countChar(originalFileInputStream, charCount);

    int appearedCharCount = 0;
    for (size_t i = 0; i < 256; i++)
    {
        if (charCount[i] > 0)
        {
            binNodes[appearedCharCount] = new BasicBinaryTreeNode<char, int>(i, charCount[i]);
            appearedCharCount++;
        }
    }

    BasicBinaryTreeNode<char, int> *huffmanTree = buildHuffmanTree(binNodes, appearedCharCount, 256);

    string codeStorage[256];
    char huffcode[64] = {0};

    getHuffmanCode(huffmanTree, codeStorage, huffcode);

    HuffmanFileEncoder huffmanFileEncoder(codeStorage, "test.huf");
    char originalFileCharBuffer;
    while (huffmanFileEncoder.is_open() && originalFileInputStream.get(originalFileCharBuffer))
    {
        huffmanFileEncoder.putChar(originalFileCharBuffer);
    }
    int contentBitLength = huffmanFileEncoder.getBitLength();
    huffmanFileEncoder.close();
    originalFileInputStream.close();

    HuffmanFileDecoder huffmanFileDecoder(huffmanTree, "test.huf", contentBitLength);
    char charBuffer;
    int i = 0;
    while (huffmanFileDecoder.is_open() && huffmanFileDecoder.getChar(charBuffer))
    {
        assert(charBuffer == testString[i]);
        i++;
    }
    huffmanFileDecoder.close();

    remove("test.huf");
    remove("testOrigin.txt");
    
    cout << "test passed" << endl;
    return 0;
}
