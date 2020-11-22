//2. Користувач вводить з клавіатури 2 числа.
//Рекурсивно знайти найбільший спільний дільник
//(алгоритм Евкліда(фото нижче) - зверніть увагу)
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
int Euclid(int, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m = 0, n = 0;

    cout << "Введіть значення (m): \n" <<"->_";
    cin >> m;
    cout << "ведіть значення (n): \n" << "->_";
    cin >> n;

    cout << "Спільний дільник: " << Euclid(m, n);
}

int Euclid(int m, int n)
{
    if (m == n)
        return n;

    if (m > n)
        return Euclid(m - n, n);
    else
        return Euclid(m, n - m);
}