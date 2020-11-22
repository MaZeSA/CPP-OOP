//3. Написати програму, що вираховує середнє арифметине усіх чисел в файлі
//(файл створюєте собі самі)
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <ostream>
using namespace std;

void CreateFile();
void ReadFile();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));
   
    cout << "Створення файлу в папці з програмою\n";
    CreateFile(); 
    cout << "Знаходження середньго арифметичного\n";
    ReadFile();
}

void CreateFile()
{
    fstream file;
    file.open("TextFile.txt", ios::out);
    for (int str = 0; str < 10; str++)
    {
        for (int c = 0; c < 10; c++)
        {
            int r = rand() % 10;
            string tab = r < 10 ? "    " : "   ";
            file << r << tab;
        }
        file << endl;
    }
    file.close();

    if (file.fail())
        cout << "Помилка збереження!\n";
    else
        cout << "Успішно збережено !\n";
}

void ReadFile()
{
    ifstream file("TextFile.txt");
    int suma = 0, count = 0, temp = 0;
    while (!file.eof())
    {
        file >> temp;
        suma += temp;
        count++;
    }

    cout << "Середне арифметичне: " << suma/count;
}