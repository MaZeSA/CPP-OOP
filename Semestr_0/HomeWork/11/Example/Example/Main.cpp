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
	SetConsoleCP(1251);  //��� ����, �� ��������� �������� �����
	SetConsoleOutputCP(1251); //��� ����, �� ��������� �������� �����
	string str;//= "�����! ������� ������ ������.";
	cout << "������ ���� �����: ";
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
	int n = str.length(); //������� �������� �����
	int count_ch = 0; //�������� ������� �������� ������� ch
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ch)
		{
			count_ch++;
		}
	}
	cout << "ʳ������ ������: " << count_ch << "\n";
	m = count_ch + 1; //������� �����, �� � ��� �� ����������
	string* works = new string[m];
	//works[0] += '�'; works[0] += '�';
	//works[0] = "�����!";
	//works[1] = "�������";
	//works[2] = "������";
	//works[3] = "������.";
	int j = 0; //�������� ���������� �� ������
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ch)
		{
			j++;
			continue; //���������� ������
		}
		works[j] += str[i];
	}
	return works;
	
}