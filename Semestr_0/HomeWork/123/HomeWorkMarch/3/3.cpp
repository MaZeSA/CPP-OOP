//3. Даны два массива : А[n] и B[m].Необходимо создать
//третий массив, в котором нужно собрать : общие элементы двух массивов;
#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

/// <summary>
/// Створення мамива
/// </summary>
int* GetMas(int);
/// <summary>
/// Обєднання спільних елементів масивів
/// </summary>
void Union(int*, int, int*, int);
/// <summary>
/// Вивести масив
/// </summary>
void ShowMas(int*, int);
/// <summary>
/// Кількість співпадінь в масиві
/// </summary>
int GetCount(int*, int , int*, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((int)time(0));

	cout << "Обєднання спільних елементів масивів:" << endl;

	int n = 9, m = 10;
	int* A = GetMas(n);
	cout << "Масив №1_>: ";
	ShowMas(A, n);
	int* B = GetMas(m);
	cout << "Масив №2_>: ";
	ShowMas(B, m);

	Union(A, n, B, m);
}



void Union(int* A, int Ac, int* B, int Bc)
{
	int count = GetCount(A, Ac, B, Bc); //отримуємо розмір майбутньго иасива
	cout << "Кількість співпадінь_>: "<< count<<endl;
	int* mas = new int[count] {0};

	int* masSel = mas;
	for (int* i = A; i != A + Ac; i++)//Звіряємо масиви А і В, якщо елементи одинакові добавляємо в новий масив значення з масиву А
		for (int* j = B; j != B + Bc; j++)
			if (*i == *j)
			{
				*masSel++ = *i;
				break;
			}
	for (int* j = B; j != B + Bc; j++)//Звіряємо масиви В і новостворенний третій масив, якщо елементи одинакові добавляємо в новий масив значення з масиву В
		for (int* i = mas; i != mas + Bc + Ac; i++)
			if (*i == *j)
			{
				*masSel++ = *j;
				break;
			}

	cout << "Масив №3_>: ";
	for (int i = 0; i < count; i++)
		cout << mas[i];

	cout << endl;
}

int *GetMas(int c)
{
	int* mas = new int[c];

	for (int* i = mas; i != mas + c; i++)
		*i = rand() % 10;

	return mas;
}
void ShowMas(int* mas, int count)
{
	for (int* i = mas; i != mas + count; i++)
		cout << *i;
	cout << endl;
}
int GetCount(int* A, int Ac, int* B, int Bc)
{
	int count = 0;
	for (int* i = A; i != A + Ac; i++)
		for (int* j = B; j != B + Bc; j++)
			if (*i == *j)
			{
				count++;
				break;
			}
	for (int* j = B; j != B + Bc; j++)
		for (int* i = A; i != A + Bc + Ac; i++)
			if (*i == *j)
			{
				count++;
				break;
			}
	return count;
}