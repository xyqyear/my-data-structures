#include <cassert>
#include <cstdio>

#include "dataStructure/bits/fileBitReader.h"
#include "dataStructure/bits/fileBitWriter.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "start testing fileBitReader and fileBitWriter" << endl;

    int testBitArray[] = {0, 1, 1, 1, 0, 1, 0, 1, 1, 0};
    int testBitLength = 10;

    FileBitWriter bitWriter("test.txt");
    if (bitWriter.is_open())
    {
        for (size_t i = 0; i < testBitLength; i++)
        {
            bitWriter.writeBit(testBitArray[i]);
        }
    }
    else
        assert(false);
    bitWriter.close();

    FileBitReader bitReader("test.txt");
    int bit;
    if (bitReader.is_open())
    {
        for (size_t i = 0; i < testBitLength; i++)
        {
            bitReader.readBit(bit);
            assert(bit == testBitArray[i]);
        }
    }
    else
        assert(false);
    bitReader.close();
    remove("test.txt");
    cout << "test passed." << endl;
    return 0;
}
