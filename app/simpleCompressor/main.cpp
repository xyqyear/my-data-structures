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
    cout << "��ӭʹ��huffman������:D" << endl;
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
            cout << "��������ȷ��ѡ�" << endl;
            break;
        }
    }
    compress("testI.txt", "test.huf");
    decompress("test.huf", "testO.txt");
    return 0;
}

void printMenu()
{
    cout << "��ѡ����Ҫʹ�õĹ��ܣ�" << endl;
    cout << "1: ͳ�������ļ��ַ�Ƶ�Ȳ�������й���������" << endl;
    cout << "2: �������ļ����б��벢��������Ľ��" << endl;
    cout << "3: �����ļ�" << endl;
    cout << "> ";
}

void countFileMenu()
{
    cout << "������ԭ�ļ���·��: " << endl;
    cout << "> ";
    string filePath;
    getline(cin, filePath);

    ifstream srcFileStream(filePath, ios::binary);
    int charCount[256] = {0};
    string *codeStorage[256] = {nullptr};
    int differentCharCount = 0;
    BasicBinaryTreeNode<char, int> *huffmanTree = countFile(srcFileStream, charCount, codeStorage, differentCharCount);

    cout << "ÿ���ַ��ı��뼰��Ƶ�����£�" << endl;
    cout << "�ַ�\t\t\tƵ��\t\t\t����������" << endl;
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
    cout << "������ԭ�ļ�·��" << endl;
    cout << "> ";
    getline(cin, srcFileName);
    cout << "������Ҫ������ļ���·��" << endl;
    cout << "> ";
    getline(cin, destFileName);

    if (compress(srcFileName, destFileName))
    {
        cout << "ѹ���ɹ���" << endl;
        cout << "ѹ����Ϊ";
        ifstream srcFileStream(srcFileName, ios::ate | ios::binary);
        ifstream destFileStream(destFileName, ios::ate | ios::binary);

        int srcFileSize = srcFileStream.tellg(), destFileSize = destFileStream.tellg();

        cout << (double) destFileSize / srcFileSize * 100 << "% (���ԭ�ļ���С���ܵ��³���100%��ѹ����)" << endl;

        srcFileStream.close();
        destFileStream.close();
    }
    else
        cout << "ѹ��ʧ�ܣ�" << endl;
}

void decompressMenu()
{
    string srcFileName;
    string destFileName;
    cout << "������Ҫ��ѹ���ļ���·��" << endl;
    cout << "> ";
    getline(cin, srcFileName);
    cout << "������Ҫ������ļ���·��" << endl;
    cout << "> ";
    getline(cin, destFileName);

    if (decompress(srcFileName, destFileName))
        cout << "��ѹ�ɹ���" << endl;
    else
        cout << "��ѹʧ��." << endl;
}
