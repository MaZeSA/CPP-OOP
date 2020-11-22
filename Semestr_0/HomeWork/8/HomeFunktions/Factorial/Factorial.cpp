// 4. Написати функцію для обчислення факторіала числа.

#include <Windows.h>
#include <iostream>
using namespace std;

int GetFactorial(int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
 
    cout << "Обчислення факторіалу \n" << "Введіть число _> ";
   
    int num;
    cin >> num;

    cout << num <<"! = "<< GetFactorial(num);

}

int GetFactorial(int num)
{
    int result = 1;
    for (int i = 2; i < num + 1; i++)
    {
        result *= i;
    }

    if (num > 0 && result <= 0)
    {
        cout << "Введено надто велике число, результат не можна вмістити в тип int\n";
    }
    return result;
}