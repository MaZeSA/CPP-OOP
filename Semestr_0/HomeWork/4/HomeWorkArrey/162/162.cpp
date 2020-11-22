//162. Написать программу, которая вычисляет среднее арифметическое 
//элементов массива без учета минимального и максимального 
//элементов массива.

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 10;

	cout << "Введіть елементи масиву (" << n << " цілих чисел в одну строку) \n";

	int mas[n];
	for (int &i : mas)
		cin >> i;

	int min = 0, max = 0; //індекси чисел в масиві
	for (int i = 1; i < n; i++) //шукаємо мінімальне і максимальне число
	{
		if (mas[min] > mas[i])
			min = i;
		else if (mas[max] < mas[i])
			max = i;
	}

	cout << "Мінімальний елемент: " << mas[min] << endl
		<< "Максимальний елемент: " << mas[max] << endl;

	double suma = 0; //сума чисел
	double elements = 0; //кількість чисел які підлягають обчисленню
	for (int i = 0; i < n; i++)
		if (mas[i] != mas[min] && mas[i] != mas[max]) //число не дорівнює ні максимальному ні мінімальному
		{
			suma += mas[i];
			elements++;
		}

	if (elements == 0)
		cout << "Всі значення відповідають мінімальному чи максимальному числу \n";
	else
		cout << "Середнє арифметичне без урахування '" << mas[min] << "' i '" << mas[max] << "' значень: " 
			<< suma / elements << endl;

	return 0;
}

