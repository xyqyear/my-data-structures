#include "count_char.hpp"

using namespace std;

void countChar(std::ifstream &fileStream, int charCount[256])
{
    streampos savedPos = fileStream.tellg();
    fileStream.seekg(0);
    char tempChar;
    while (fileStream.get(tempChar))
    {
        charCount[tempChar]++;
    }
    fileStream.clear();
    fileStream.seekg(savedPos);
}
