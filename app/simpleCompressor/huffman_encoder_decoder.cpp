#include "huffman_encoder_decoder.hpp"

using namespace std;

int HuffmanEncoderDecoderBase::getBitLength()
{
    return bitLength;
}

HuffmanFileEncoder::HuffmanFileEncoder(string *huffmanCode[256], const string& filename)
{
    this->huffmanCode = huffmanCode;
    fileBitWriter = new FileBitWriter(filename);
}

HuffmanFileEncoder::~HuffmanFileEncoder()
{
    if (fileBitWriter->is_open())
        fileBitWriter->close();
    delete fileBitWriter;
}

void HuffmanFileEncoder::putChar(char char2put)
{
    for (char codeChar : *huffmanCode[char2put])
    {
        fileBitWriter->writeBit(codeChar == '1' ? 1 : 0);
        bitLength++;
    }
}

void HuffmanFileEncoder::flush()
{
    fileBitWriter->flush();
}

void HuffmanFileEncoder::close()
{
    fileBitWriter->close();
}

bool HuffmanFileEncoder::is_open()
{
    return fileBitWriter->is_open();
}

int HuffmanFileEncoder::tell()
{
    return fileBitWriter->tell();
}

void HuffmanFileEncoder::seek(int pos)
{
    fileBitWriter->seek(pos);
}

void HuffmanFileEncoder::clearError()
{
    fileBitWriter->clearError();
}

HuffmanFileDecoder::HuffmanFileDecoder(BasicBinaryTreeNode<char, int> * huffmanTree, const string& filename, int contentBitLength)
{
    this->huffmanTree = huffmanTree;
    bitLength = contentBitLength;
    fileBitReader = new FileBitReader(filename);
}

HuffmanFileDecoder::~HuffmanFileDecoder()
{
    if (fileBitReader->is_open())
        fileBitReader->close();
    delete fileBitReader;
}

bool HuffmanFileDecoder::getCharHelper(BasicBinaryTreeNode<char, int> *currentNode, char &charBuffer)
{
    if (currentNode->isLeaf())
    {
        charBuffer = currentNode->getKey();
        return true;
    }
    else
    {
        bitLength--;
        if(!fileBitReader->readBit(bitBuffer))
            return false;
        if (bitBuffer == 0)
        {
            return getCharHelper(currentNode->getLeftChild(), charBuffer);
        } else 
        {
            return getCharHelper(currentNode->getRightChild(), charBuffer);
        }
    }
}

bool HuffmanFileDecoder::getChar(char &charBuffer)
{
    if (bitLength > 0)
    {
        // if the tree has only one node
        if (huffmanTree->isLeaf())
        {
            bitLength--;
            charBuffer = huffmanTree->getKey();
            return true;
        }
        else
            return getCharHelper(huffmanTree, charBuffer);
    }
    else
        return false;
}

bool HuffmanFileDecoder::is_open()
{
    return fileBitReader->is_open();
}

void HuffmanFileDecoder::close()
{
    fileBitReader->close();
}

int HuffmanFileDecoder::tell()
{
    return fileBitReader->tell();
}

void HuffmanFileDecoder::seek(int pos)
{
    fileBitReader->seek(pos);
}

void HuffmanFileDecoder::clearError()
{
    fileBitReader->clearError();
}
