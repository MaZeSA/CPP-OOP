//3. Написати функцію, яка перевіряю чи пароль відповідає 
//вимогами(2 числа та 2 символи).Функція верта true або false.
#include <Windows.h>
#include <iostream>
using namespace std;
bool ValidPass(const string, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть пароль латинськими літерами і числами\n"
        << "_>";

    string pas = "";
    cin >> pas;

    bool y = ValidPass(pas, pas.size());
    if (y)
        cout << "Пароль відповідає усім вимогам\n";
    else
        cout << "Пароль не відповідає вимогам (2 числа та 2 символи)\n";
}

//якщо під "символом" розуміти будь який символ, то можна обійтися лише перевіркою на цифри якщо довжина >= 4
bool ValidPass(const string str, int count)
{
    int b = 0, n = 0;
    for (int i = 0; i < count; i++)
    {
        if (isalpha(str[i]))
            b++;
        else if (isdigit(str[i]))
            n++;
    }

    cout << endl<< b << "-cимволів, " << n << "-цифр \n";

    if (b >= 2 && n >= 2)
        return true;
    else
        return false;
}

