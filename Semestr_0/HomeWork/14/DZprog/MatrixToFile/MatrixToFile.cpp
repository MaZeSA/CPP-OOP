//2. Написати додаток, що записує двовимірний масив у файл у коректному вигляді(матриця)
#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;

constexpr auto Colum = 7;
constexpr auto Rows = 10;

void CreateMatrix(int[][Rows]);
void WriteToFile(int[][Rows], string);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((int)time(0));

    cout << "Збереження матриці\n";
    int matrix[Colum][Rows];
      
    CreateMatrix(matrix);
   
    string path = "";
    cout  << "Введіть повний шлях для збереження файла, або лише імя для збереження в папці з програмою \n ->_";
    cin >> path;

    WriteToFile(matrix, path);

}

void CreateMatrix(int mas[][Rows])
{
    for (int str = 0; str < Colum; str++)
    {
        for (int c = 0; c < Rows; c++)
        {
            int r = rand() % 50;
            mas[str][c] = r;
            string tab = r < 10 ? "    " : "   ";
            cout << mas[str][c] << tab;
        } 
        cout << endl;
    }
}

void WriteToFile(int mas[][Rows], string path)
{
    fstream file;
    file.open(path, ios::out);
    for (int str = 0; str < Colum; str++)
    {
        for (int c = 0; c < Rows; c++)
        {
            string tab = mas[str][c] < 10 ? "    " : "   ";
            file << mas[str][c] << tab;
        }
        file << endl;
    }
    file.close();

    if (file.fail())
        cout << "Помилка збереження!";
    else
        cout << "Успішно збережено!";
}
