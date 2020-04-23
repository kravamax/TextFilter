#include <iostream>
#include<stdio.h>
#include<Windows.h>

using namespace std;

void filter(char*, char*, unsigned, bool&);

char copy(char* str, char* str_copy);

void StatusAction(bool status);

int main() {

    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 20;
    char* str = new char[size];
    cout << "Enter string: ";
    cin.getline(str, size);

    unsigned len = strlen(str);
    char* str_copy = new char[size];
    copy(str, str_copy);
    
    bool status1 = false;
    bool status2 = false;
    bool status3 = false;
    bool status4 = false;
    unsigned action;

    do {
        cout << str_copy;
        cout << "\n1 latin\t\t"; StatusAction(status1);
        cout << "2 cyrillic\t"; StatusAction(status2);
        cout << "3 punctuation\t"; StatusAction(status3);
        cout << "4 digits \t"; StatusAction(status4);
        cout << "5 exit \n";
        
        cout << "\ntype number ";
        cin >> action;

        switch (action) {
        case 1: filter(str, str_copy, 1, status1); break;
        case 2: filter(str, str_copy, 2, status2); break;
        case 3: filter(str, str_copy, 3, status3); break;
        case 4: filter(str, str_copy, 4, status4); break;
        }

        system("cls");

    } while (action != 5);
   
    delete[] str;
    delete[] str_copy;

    system("pause");
    return 0;

}

void filter(char* str, char* buff, unsigned t, bool& Flag) {
    unsigned len = strlen(str);

    for (unsigned i = 0; i < len; i++)
        if (((t == 1) && (str[i] > 64 && str[i] < 123))
            ||
            ((t == 2) && (str[i] >= 'À' && str[i] <= 'ÿ'))
            ||
            ((t == 3) && (str[i] > 32 && str[i] < 48) || (str[i] > 57 && str[i] < 65))
            ||
            ((t == 4) && (str[i] > 47 && str[i] < 58)))
            buff[i] = (!Flag) ? '*' : str[i];

    Flag = !Flag;
    cout << endl << buff << endl;
}

char copy(char* str, char* str_copy) {

    unsigned len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        str_copy[i] = str[i];
    }
    str_copy[len] = '\0';
    return *str_copy;
}

void StatusAction(bool status) {
    if (status == true)
    {
        cout << "ON" << endl;
    }
    else if (status == false)
    {
        cout << "OFF" << endl;
    }
}