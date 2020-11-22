//Написати функцію, яка строку string розбиває по вказаному символу.
//Протопит функції.
//string* split(string str, char ch = ' ');

#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;
/// <summary>
/// Видаленння пустих елементів. 
/// Анолог функції в C#
/// </summary>
enum class StringSplitOptions
{
    none,
    RemoveEmptyEntries
};
/// <summary>
/// Розбивання строки по символу
/// </summary>
/// <param name="">Строка</param>
/// <param name="ch">Роздільник</param>
/// <returns>string[]</returns>
string* Split(string, char ch = ' '); 
/// <summary>
/// Розбивання строки по символу без пустих елементів
/// </summary>
/// <param name="">Строка</param>
/// <param name="ch">Роздільник</param>
/// <returns>string[]</returns>
string* Split(string, char, StringSplitOptions); 
/// <summary>
/// </summary>
/// <returns>Повертає кількість елементів масиву</returns>
int GetCountSplit(const string, char);
/// <summary>
/// Функція автоматизації, та зручності перевірки ДЗ
/// </summary>
void AutoUseSplit(string, char);

int countSplit = 0;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    // Демонстрація роботи програми
    string str = "Тестова++строка+для+розділення++по плюсу";
    AutoUseSplit(str, '+');

    // Ввід даних для розділення користувачем
    cout << endl << "Введіть строку для розділення " 
        << endl
        <<"_> ";

    getline(cin, str);

    char c = ' ';
    cout << "Введіть розділювач "
        << endl
        << "_> ";
    cin >> c;

    AutoUseSplit(str, c);
}
void AutoUseSplit (string str, char ch)
{
    cout << "*** Розділення строки: " << str << endl << endl;

    string* none = Split(str, ch);
    for (int i = 0; i < countSplit; i++)
        cout << none[i] << endl;

    // Демонстрація роботи з увімкненим параметром StringSplitOptions
    cout << endl << "*** З увімкненим параметром StringSplitOptions::RemoveEmptyEntries:" << endl << endl;

    string* removeEntries = Split(str, ch, StringSplitOptions::RemoveEmptyEntries);
    for (int i = 0; i < countSplit; i++)
        cout << removeEntries[i] << endl;

    delete[] none;
    delete[] removeEntries;
}

string* Split(const string str, char ch)
{
    countSplit = GetCountSplit(str, ch);
    string strSplit = str;

    string* result = new string[countSplit];
    for (int i = 0; i < countSplit; i++)
    {
        int t = strSplit.find(ch); //пошук о символа
        result[i]= strSplit.substr(0, t); //копія строки до символа
        strSplit.erase(0, t + 1);//видалення строки разом з символом
    }
   
    return result;
}
string* Split(const string str, char ch, StringSplitOptions option)
{
    if (option == StringSplitOptions::RemoveEmptyEntries)//перевірка на пусті елементи
    { 
        string res = "";

        string strSplit = str;
        while (strSplit.length())
        {
            int t = strSplit.find(ch);
            if (t == -1)
                t = strSplit.length();

            string sub = strSplit.substr(0, t);
            strSplit.erase(0, t + 1);

            for (char c : sub)
            {
                if (c != 32)//якщо не пустий
                {
                    res += sub + ch;
                    break;
                }
            }
        }
     
        return Split(res, ch);
    }
    else
        return Split(str, ch);
}

int GetCountSplit(const string str, char ch)
{
    string strSplit = str;
    int result = 0;

    while (strSplit.length())
    {
        int t = strSplit.find(ch);

        if (t != -1)
        {
            strSplit.erase(0, t + 1);
            result++;
        }
        else {    
            result++;
            break;
        }
    }
    return result;
}


