#include <iostream>
#include "compress.hpp"
#include "decompress.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    compress("testI.txt", "test.huf");
    decompress("test.huf", "testO.txt");
    return 0;
}
