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
    //конструктор по умолчанию, позвол€ющий создать строку длиной 80 символов
    MyString() {
        length = 80;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';

        objCount++;
    }

    //конструктор, позвол€ющий создать строку произвольного размера
    MyString(int size) {
        length = size;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';
        objCount++;
    }

    //конструктор, который создаЄт строку и инициализирует еЄ строкой, полученной от пользовател€
    MyString(const char* inputStr) {
        length = strlen(inputStr);
        str = new char[length + 1];
        strcpy(str, inputStr);
        objCount++;
    }

    //  онструктор копировани€
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        objCount++;
    }

    //деструктор
    ~MyString() {
        delete[] str;
        objCount--;
    }

    void Input() {
        cout << "¬ведите строку: ";
        cin.getline(str, length);
    }

    void Output() const {
        cout << str << endl;
    }

    void MyStrcpy(MyString& obj) //копирование строк 
    {
        if (this == &obj)
            return;
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        strcpy(str, obj.str);
    }

    bool MyStrStr(const char* substr) //поиск подстроки в строке
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

    int MyChr(char c) //поиск символа в строке 
    {
        for (int i = 0; i < length; ++i) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen() const //возвращает длину строки
    {
        return length;
    }

    void MyStrCat(MyString& b) //объединение строк
    {
        char* newStr = new char[length + b.length + 2]; // +1 дл€ пробела и +1 дл€ '\0'
        for (int i = 0; i < length; ++i) {
            newStr[i] = str[i];
        }
        newStr[length] = ' ';  // ƒобавл€ем пробел
        for (int i = 0; i < b.length; ++i) {
            newStr[length + 1 + i] = b.str[i];
        }
        newStr[length + b.length + 1] = '\0';  // «авершаем строку
        delete[] str;
        str = newStr;
        length += (b.length + 1); // +1 дл€ пробела
    }

    void MyDelChr(char c) //удал€ет указанный символ 
    {
        int newLength = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) str[newLength++] = str[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    int MyStrCmp(MyString& b) //сравнение строк
    {
        int cmp = strcmp(str, b.str);
        if (cmp < 0) return -1;
        if (cmp > 0) return 1;
        return 0;
    }

    int main() {}