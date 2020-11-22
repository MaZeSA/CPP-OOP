// Example program
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include<windows.h>
//Попробуємо порахувати кількість елементів в масиві
int getCountElement(int* mas);

int main()
{
	SetConsoleCP(1251);  //для того, що працювали українські букви
	SetConsoleOutputCP(1251); //для того, що працювали українські букви
	//int * mymas = new int[5];
	int mymas[5];// = new int[5];
	int a = 12;
	cout << "sizeof int " << sizeof a<<"\n";
	mymas[0] = 1;
	mymas[1] = 15;
	mymas[2] = 23;
	mymas[3] = 3;
	mymas[4] = 12;

	//int i = 1;
	cout << "sizeof() = "<<sizeof mymas<<"\n";
	for (int i = 0; i < 5; i++)
	{
		cout << mymas[i] << "\n"; //отримуємо значення
		cout << *(mymas + i) << "\n"; //отримуємо значення
		cout << &mymas[i] << "\n"; //отримуємо адресу
		cout << mymas + i << "\n"; //отримуємо адресу
								  //cout << "Hello\n";
	}
	cout<<"count = " << getCountElement(mymas)<< "\n";

	return 0;
}

int getCountElement(int* mas) 
{
	return sizeof(mas);
}