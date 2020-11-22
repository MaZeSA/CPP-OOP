//1.Визначити кількість входжень заданого символу "С"
//в рядку "S".Функція отримує 3 параметри:
//-символ с, який потрібно порівняти з кожним символом рядка s;
//-рядок s;
//-додаткова змінна i, яка є лічильником рекурсивного
//циклу.
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
int GetCount(char, string, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char C = ' ';
    string S = "";
    int i = 0;

    cout << "Визначення кількості входжень заданого символу(С)\n Введіть строку (S)\n" << "->_";
    cin.sync(); //для правильного зчитування буфера, не ігноруючи перший символ
    getline(cin, S);
    cout << "Введіть символ для пошуку(C)\n" <<"->_";
    cin >> C;


  cout<< "Кількість входжень '" << C<< "'= "<<  GetCount(C, S, i);
}

int GetCount(char C, string S, int i)
{
    if (S.length() == 0)//кінець строки
        return i;

    if (S[0] == C)
        i++;

    return  GetCount(C, S.erase(0, 1), i); //рекурсія, видалення першого символа з строки

}