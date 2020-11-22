//1
//Пользователь вводит любое целое число.Необходимо из этого целого числа удалить
//все цифры 3 и 6 и вывести обратно на экран.

#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //число не повинно перевищувати розмір змінної int
    cout << "Введіть число (4 байти) з якого потрібно видалити числа '3' і '6': " << endl << endl;

    int i = 0;

    cin >> i;

    vector<int> temp; //в данному випадку використовувати вектор зручніше ніж масив
    while (i)
    {
        int n = i % 10;

        if (n != 3 && n != 6)
            temp.insert(temp.begin(), n); //вставляємо нове число на початок списку
        
        i /= 10;
    }

    int numResult = 0;
    for (int x : temp) //отримуєм ціле число
    {
        numResult += x;
        numResult *= 10;
    }

    cout << numResult / 10 << "- Кінцеве число" << endl;
}

