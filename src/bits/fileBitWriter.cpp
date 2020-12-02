#include "dataStructure/bits/fileBitWriter.h"

using namespace std;

FileBitWriter::FileBitWriter(const string &filename)
{
    fileStream.open(filename, ios::out | ios::binary | ios::app);
}

bool FileBitWriter::is_open()
{
    return fileStream.is_open(); 
}

void FileBitWriter::writeBit(int bit)
{
    buffer <<= 1;
    buffer |= bit;
    bufferPointer++;
    if (bufferPointer == 8)
    {
        fileStream.put(buffer);
        bufferPointer = 0;
    }
}

void FileBitWriter::flush()
{
    if (bufferPointer > 0)
    {
        buffer <<= (8 - bufferPointer);
        fileStream.put(buffer);
    }
}

void FileBitWriter::close()
{
    flush();
    fileStream.close();
}
