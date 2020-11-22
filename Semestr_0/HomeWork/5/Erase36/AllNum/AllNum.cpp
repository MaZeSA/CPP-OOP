//2
//Пользователь вводит число.Определить количество цифр в этом числе, посчитать их
//сумму и среднее арифметическое.Определить количество нулей в этом числе.

#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть число: \n";
    int num = 0;
    cin >> num;

    double suma = 0, zeroCount = 0, count = 0;

    while (num)
    {
        int i = num % 10;

        suma += i;
        count++; 
        
        if (i == 0)
            zeroCount++;

        num /= 10;
    }

   cout << "\nКількість цифр: " << count 
        << "\nСума чисел: " << suma 
        << "\nСереднє арифметичне: " << suma / count 
        << "\nКількість нулів в числі: " <<zeroCount
        << endl;
}
