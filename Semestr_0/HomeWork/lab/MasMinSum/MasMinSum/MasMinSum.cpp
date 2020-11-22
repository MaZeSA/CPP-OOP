//Попередні завдання були зроблені в аудиторії

//4. (по бажанню, не обов'язково) Напишите рекурсивную функцию, 
//	которая принимает одномерный массив из 100 целых чисел,
//	заполненных случайным образом, и находит позицию,
//	с которой начинается последовательность из  10 чисел, сумма которых минимальна.

#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

int Sum(int*, int);

int countMas = 100;//кількість елементів
int minIdex = 0;//індекс мінімального елемента

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((int)time(0));
	
	int* mas = new int[countMas];

	for (int i = 0; i <countMas; i++) 
	{
		mas[i] = rand() % 10;
		cout << mas[i] << " ";
	}
	cout << endl <<"Підрахунок суми елементів:" << endl;

	Sum(mas, 0);
	cout<< "Мінімальний елемент: " <<minIdex ;

	delete[] mas;
}

int Sum(int* Mas, int select)
{
	int sum = 0;
	for (int i = select; i < select + 10; i++)
	{
		sum += Mas[i];
	}

	cout << select << " ->_" << sum << endl;

	if (countMas - select == 10) //Досягнули кінця
	{
		minIdex = select;
		return sum;
	}

	int getNext = Sum(Mas, select + 1);
	if (getNext >= sum)
	{
		minIdex = select;
		return sum;
	}
	return getNext;
}
