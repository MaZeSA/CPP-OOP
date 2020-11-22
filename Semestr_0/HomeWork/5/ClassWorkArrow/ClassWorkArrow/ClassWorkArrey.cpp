#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int u = 0; 
    cin >> u;

    int x = u, 
        n = 0; //кількість цифр в числі
    while ((x /= 10) > 0) n++;

    char ch[20] = {'\0'};

   

    int y = 0;
    for (int i = n; i >= 0; i--)
    {
        y = u % 10;
        ch[i] = y + '0';
        u /= 10;
    }

    for (int i = 0; i < sizeof(ch); i++)
        cout << ch[i] << "\t";

    return 0;
    
}
