//140. Написать программу, которая выводит на экран изображе -
//ние шахматной доски.Черные клетки отображать "звездочкой",

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int strok = 40; //Кількість строк
	int radok = 40; //Кількість символів в строці

	for (int i = 0; i < strok; i++)
	{
		for (int str = i % 2; str < radok; str++)
		{
			if (str % 2 == 0)
				cout << "*";
			else
				cout << " ";
		}

		cout << endl;
	}

	return 0;
}

