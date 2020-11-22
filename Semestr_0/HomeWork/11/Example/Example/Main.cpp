// Example program
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include<windows.h>
int m = 0;
string* split(string str, char ch = ' ');


int main()
{
	SetConsoleCP(1251);  //для того, що працювали українські букви
	SetConsoleOutputCP(1251); //для того, що працювали українські букви
	string str;//= "Привіт! Сьогодні хороша погода.";
	cout << "Вкажіть свою фразу: ";
	getline(cin, str);
	cout << str<<"\n";
	char ch = ' ';
	string* works = split(str);//, ch);
	for (int i = 0; i < m; i++)
	{
		cout << works[i] << "\n";
	}
	return 0;
}

string* split(string str, char ch) 
{
	int n = str.length(); //довжина вхідного рядка
	int count_ch = 0; //підраховує кількість входжень символа ch
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ch)
		{
			count_ch++;
		}
	}
	cout << "Кількість пробілів: " << count_ch << "\n";
	m = count_ch + 1; //кількість рядків, які у нас має получитися
	string* works = new string[m];
	//works[0] += 'П'; works[0] += 'р';
	//works[0] = "Привіт!";
	//works[1] = "Сьогодні";
	//works[2] = "хороша";
	//works[3] = "погода.";
	int j = 0; //лічильник переміщення по фразам
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ch)
		{
			j++;
			continue; //пропускаємо пробіли
		}
		works[j] += str[i];
	}
	return works;
	
}