// Написати додаток, який буде виводити вміст файлу в консоль. 
//Ім'я файлу користувач вводить з клавіатури.
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

bool Message(bool);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string FileName = "";
    ifstream openFile;

    cout<< "Вивести вміст файла в консоль\n"
        << "Введіть повний шлях до файла, або лише імя, якщо файл в папці з програмою \n ->_";

    do
    {
        cin >> FileName;
        openFile.open(FileName);
    } 
    while (!Message(openFile.is_open())); //Вивід повідомлення якщо файла не існує, завершення циклу якщо файл існує

    cout << "Вміст файлу:\n";

    string file;
    while (!openFile.eof())
    {
        getline(openFile, file);
        cout << file << endl;;
    }
}

bool Message(bool is_open)
{
    if (!is_open)
        cout << "Файл не знайдено!\n"
        <<"Введіть повний шлях до файла ->_"
        <<endl;

    return is_open;
}
