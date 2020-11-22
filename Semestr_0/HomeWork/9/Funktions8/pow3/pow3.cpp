//2. Написати функцію для піднесення числа до куба.
#include <Windows.h>
#include <iostream>
using namespace std;
double newPow(double, double);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Піднесення до кубу\n"
        << "Введіть число \n"
        << "_>";

    double num = 0;
    cin >> num;

    cout << num <<" В кубі = " << newPow(num, 3.0) << endl;
}

double newPow(const double num, double n) //функція пвднесення до будьякої степені (аналог pow(double, double))
{
    double result = num;
    for (int c = 0; c < n - 1; c++)
    {
        result *= num;
    }
    return result; 
}
