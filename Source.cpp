#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;

class MyString {
    char* str;
    int length;
    static int objCount;

public:
    //����������� �� ���������, ����������� ������� ������ ������ 80 ��������
    MyString() {
        length = 80;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';

        objCount++;
    }

    //�����������, ����������� ������� ������ ������������� �������
    MyString(int size) {
        length = size;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';
        objCount++;
    }

    //�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������
    MyString(const char* inputStr) {
        length = strlen(inputStr);
        str = new char[length + 1];
        strcpy(str, inputStr);
        objCount++;
    }

    // ����������� �����������
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        objCount++;
    }

    //����������
    ~MyString() {
        delete[] str;
        objCount--;
    }

    void Input() {
        cout << "������� ������: ";
        cin.getline(str, length);
    }

    void Output() const {
        cout << str << endl;
    }

    void MyStrcpy(MyString& obj) //����������� ����� 
    {
        if (this == &obj)
            return;
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

    bool MyStrStr(const char* substr) //����� ��������� � ������
    {
        int substrLen = strlen(substr);
        if (substrLen == 0 || substrLen > length) {
            return false;
        }

        for (int i = 0; i <= length - substrLen; ++i) {
            int j = 0;
            while (j < substrLen && str[i + j] == substr[j]) {
                j++;
            }
            if (j == substrLen) {
                return true;
            }
        }

        return false;
    }

    int MyChr(char c) //����� ������� � ������ 
    {
        for (int i = 0; i < length; ++i) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() const //���������� ����� ������
    {
        return length;
    }

    void MyStrCat(MyString& b) //����������� �����
    {
        char* newStr = new char[length + b.length + 2]; // +1 ��� ������� � +1 ��� '\0'
        for (int i = 0; i < length; ++i) {
            newStr[i] = str[i];
        }
        newStr[length] = ' ';  // ��������� ������
        for (int i = 0; i < b.length; ++i) {
            newStr[length + 1 + i] = b.str[i];
        }
        newStr[length + b.length + 1] = '\0';  // ��������� ������
        delete[] str;
        str = newStr;
        length += (b.length + 1); // +1 ��� �������
    }

    void MyDelChr(char c) //������� ��������� ������ 
    {
        int newLength = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) str[newLength++] = str[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    int MyStrCmp(MyString& b) //��������� �����
    {
        int cmp = strcmp(str, b.str);
        if (cmp < 0) return -1;
        if (cmp > 0) return 1;
        return 0;
    }

    int main() {}