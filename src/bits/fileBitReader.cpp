#include "dataStructure/bits/fileBitReader.h"

using namespace std;

FileBitReader::FileBitReader(const std::string &filename)
{
    fileStream.open(filename, ios::in | ios::app | ios::binary);
}

bool FileBitReader::readBit(int &bit)
{
    if (bufferPointer == -1)
    {
        if (!fileStream.get(buffer))
            return false;
        bufferPointer = 7;
    }

    bit = (buffer >> bufferPointer) & 1;
    bufferPointer--;
    return true;
}

bool FileBitReader::is_open()
{
    return fileStream.is_open();
}

void FileBitReader::close()
{
    fileStream.close();
}
