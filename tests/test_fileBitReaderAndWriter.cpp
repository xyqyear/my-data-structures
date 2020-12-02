#include <cassert>

#include "dataStructure/bits/fileBitReader.h"
#include "dataStructure/bits/fileBitWriter.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "start testing fileBitReader and fileBitWriter" << endl;

    FileBitWriter bitWriter("D:/test.txt");
    if (bitWriter.is_open())
    {
        bitWriter.writeBit(0);
        bitWriter.writeBit(1);
        bitWriter.writeBit(1);
        bitWriter.writeBit(1);
        bitWriter.writeBit(0);
        bitWriter.writeBit(1);
        bitWriter.writeBit(0);
        bitWriter.writeBit(1);
        bitWriter.writeBit(1);
    }
    bitWriter.close();

    FileBitReader bitReader("D:/test.txt");
    int bit;
    if (bitReader.is_open())
    {
        for (size_t i = 0; i < 9; i++)
        {
            bitReader.readBit(bit);
            cout << bit;
        }
        
    }
    bitReader.close();
    cout << endl;
    return 0;
}

