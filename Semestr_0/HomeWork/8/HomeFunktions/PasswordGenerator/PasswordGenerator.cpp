//3. Написати для генерації рандомного пароля. (довжина пароля від 6 до 9 символів)
//Пароль має включати мін 2 цифри та 2 символи.
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

void GeneratePassword();
int GetChar();
int GetInt();
char* AuditPass(char*, int, int, int);

int main()
{
    srand((int)time(0));

    for (int t = 0; t < 25; t++) //генеруємо 25 паролів
    {
        GeneratePassword();
    }
}

void GeneratePassword()
{
    int size = 6 + rand() % 4; //випадковий розмір паролю від 6 до 9 символів

    char* pass = new char[size + 1]{ 0 };

    int intC = 0, charC = 0; //підрахунок цифр і символів щоб реревірити умову - мінімум 2 цифри і 2 букви

    for (int i = 0; i < size; i++)
    {
        int r = rand() % 2 + 1; //випадково аибираємо генерацію цифри чи символа
        if (r % 2 == 0) //генеруємо цифру
        {
            pass[i] = GetInt();
            intC++;
        }
        else //генеруємо символ
        {
            pass[i] = GetChar();
            charC++;
        }
    }
   
    cout << AuditPass(pass, size, intC, charC) << endl; //перевіряємо на вірність умові, корегуємо якщо потрібно і виводимо
}

int GetChar()//генеруємо символ
{
    if ((rand() % 2 + 1) % 2 == 0) // випадково вибераємо реєстр символів
        return(65 + rand() % 26); //великі
    else
        return(97 + rand() % 26);//маленькі
}

int GetInt()//генеруємо цифру 
{
    return(48 + rand() % 10); 
}

char* AuditPass(char* pass, int size, int intC, int charC)//перевірка і корегування 
{
    while (intC < 2)//якщо цифр <2
        for (int i = 0; i < size; i++)
        {
            if (pass[i] >= 65)
            {
                pass[i] = GetInt();
                intC++;
                break;
            }
        }

    while (charC < 2)//якщо символів <2
        for (int i = 0; i < size; i++)
        {
            if (pass[i] <= 65)
            {
                pass[i] = GetChar();
                charC++;
                break;
            }
        }
    return pass;
}
