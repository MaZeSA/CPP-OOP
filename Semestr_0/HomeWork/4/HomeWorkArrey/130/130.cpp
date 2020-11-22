//130. Написать программу, которая генерирует последователь -
//ность из 10 случайных чисел(в диапазоне от 1 до 10), выводит
//эти числа на экран и вычисляет их среднее арифметическое.

#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((int)time(0));

	cout <<"Випадкові числа:\n" ;

	int suma = 0;
	int i = 0;
	while (i < 10)
	{
		int r = rand() % 10 + 1;
		suma += r;
		cout << r << endl;
		i++;
    }

	cout <<"Середне арифметичне: "<< suma / 10.0<< "\n";

	return 0;
}
