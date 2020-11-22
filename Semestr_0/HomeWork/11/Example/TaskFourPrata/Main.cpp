// Example program
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include<windows.h>
//Попробуємо порахувати кількість елементів в масиві
void setValue(int *mas, int *masEnd, int value);

int main()
{
	SetConsoleCP(1251);  //для того, що працювали українські букви
	SetConsoleOutputCP(1251); //для того, що працювали українські букви
	//int * mymas = new int[5];
	int mymas[5];// = new int[5];
	
	mymas[0] = 1;
	mymas[1] = 15;
	mymas[2] = 23;
	mymas[3] = 3;
	mymas[4] = 12;

	for (int i = 0; i < 5; i++)
	{
		cout << mymas[i] << "\t";
	}
	cout << "\n";

	setValue(mymas+1, mymas + 3, 6);
	
	for (int i = 0; i < 5; i++)
	{
		cout << mymas[i] << "\t";
	}
	cout << "\n";
	return 0;
}

void setValue(int* mas, int* masEnd, int value)
{
	do {
		*mas = value; //Змінюємо значенян масив в даній комірці памяті
		mas = mas + 1; //переміщення на наступний елемент в памяті
	} while (mas != masEnd);
}