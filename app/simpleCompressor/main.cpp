#include <iostream>
#include "compress.hpp"
#include "decompress.hpp"

using namespace std;

void printMenu();
void countFileMenu();
void compressMenu();
void decompressMenu();

int main(int argc, char const *argv[])
{
    cout << "欢迎使用huffman编码器:D" << endl;
    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore(1);
        switch (choice)
        {
        case 1:
            countFileMenu();
            break;
        case 2:
            compressMenu();
            break;
        case 3:
            decompressMenu();
            break;
        default:
            cout << "请输入正确的选项！" << endl;
            break;
        }
    }
    compress("testI.txt", "test.huf");
    decompress("test.huf", "testO.txt");
    return 0;
}

void printMenu()
{
    cout << "请选择你要使用的功能：" << endl;
    cout << "1: 统计输入文件字符频度并对其进行哈夫曼编码" << endl;
    cout << "2: 对整个文件进行编码并保存编码后的结果" << endl;
    cout << "3: 解码文件" << endl;
    cout << "> ";
}

void countFileMenu()
{
    cout << "请输入原文件的路径: " << endl;
    cout << "> ";
    string filePath;
    getline(cin, filePath);

    ifstream srcFileStream(filePath, ios::binary);
    int charCount[256] = {0};
    string *codeStorage[256] = {nullptr};
    int differentCharCount = 0;
    BasicBinaryTreeNode<char, int> *huffmanTree = countFile(srcFileStream, charCount, codeStorage, differentCharCount);

    cout << "每个字符的编码及其频度如下：" << endl;
    cout << "字符\t\t\t频度\t\t\t哈夫曼编码" << endl;
    for (size_t i = 0; i < 256; i++)
    {
        if (charCount[i])
        {
            // the first column
            if (i < 33)
            {
                if (i == '\n')
                    cout << "\\n";
                else if (i == '\r')
                    cout << "\\r";
                else if (i == '\t')
                    cout << "\\t";
                else if (i == ' ')
                    cout << "[SPACE]";
                else
                    cout << "\\x" << hex << i << dec;
            }
            else
                cout << (char)i;
            cout << "\t\t\t";

            // the second column
            cout << charCount[i];
            cout << "\t\t\t";

            // the third column
            cout << *codeStorage[i] << endl;

            // clean up
            delete codeStorage[i];
        }
    }
    delete huffmanTree;
}

void compressMenu()
{
    string srcFileName;
    string destFileName;
    cout << "请输入原文件路径" << endl;
    cout << "> ";
    getline(cin, srcFileName);
    cout << "请输入要保存的文件的路径" << endl;
    cout << "> ";
    getline(cin, destFileName);

    if (compress(srcFileName, destFileName))
    {
        cout << "压缩成功！" << endl;
        cout << "压缩率为";
        ifstream srcFileStream(srcFileName, ios::ate | ios::binary);
        ifstream destFileStream(destFileName, ios::ate | ios::binary);

        int srcFileSize = srcFileStream.tellg(), destFileSize = destFileStream.tellg();

        cout << (double) destFileSize / srcFileSize * 100 << "% (如果原文件过小可能导致超过100%的压缩率)" << endl;

        srcFileStream.close();
        destFileStream.close();
    }
    else
        cout << "压缩失败！" << endl;
}

void decompressMenu()
{
    string srcFileName;
    string destFileName;
    cout << "请输入要解压的文件的路径" << endl;
    cout << "> ";
    getline(cin, srcFileName);
    cout << "请输入要保存的文件的路径" << endl;
    cout << "> ";
    getline(cin, destFileName);

    if (decompress(srcFileName, destFileName))
        cout << "解压成功！" << endl;
    else
        cout << "解压失败." << endl;
}
