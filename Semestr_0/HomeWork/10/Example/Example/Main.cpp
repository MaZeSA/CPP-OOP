// Example program
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include<windows.h>
#include"MyFunction.h";
#include"TestPragme.h";

void simpleString();
void cinString();
string getYourName();
/// <summary>
/// ��������� �� ���������
/// </summary>
/// <param name="name">���� �����, �� ���� ����</param>
/// <returns>���������� �����</returns>
string reverse(string name="����");

/// <summary>
/// ������� ������� ���� �� ����� ����� ��������� �������� ch
/// </summary>
/// <param name="str">������� �����</param>
/// <param name="ch">������ �� ����� �����, ���� �� ������� �� ���� ' '</param>
/// <returns>����� ����� string</returns>
string* split(string str, char ch = ' ');
int length = 0;

int main()
{
	SetConsoleCP(1251);  //��� ����, �� ��������� �������� �����
	SetConsoleOutputCP(1251); //��� ����, �� ��������� �������� �����

	srand((unsigned)time(NULL));

	//simpleString();
	//cinString();
	//getYourName();

	/*cout << "������ ����:\n";
	string temp;
	getline(cin, temp);

	string result = reverse(temp);
	cout << result << "\n";*/

	string* result = split("������ ������ �����a",'a');
	
	/*int n = result->length();
	result++;
	int m = result->length();
	string f = *(result);
	result++;
	string v = *(result);
	int t = result->length();
	*/
	for (int i = 0; i < length; i++)
	{
		cout<<result[i]<<"\n";
	}

	//print();
	/*print("��������");*/
	/*image_compress();
	bool result = image_compress(200, 150);
	
	myTest();*/

	return 0;
}
void simpleString() 
{
	string str = "������ ���� ��'�: ";
	cout << str << "\n";

	string name;
	cin >> name;
	name[0] = '�';
	string newName = name;
	newName[0] = 'T';

	cout << "��� �����: " << name << "\n";
	cout << "New name: " << newName << "\n";
	cout << "����� � ������: " << name.length() << "\n";
}

void cinString() 
{
	string fullName;
	cout << "������� ��� ϲ�: ";
	getline(cin, fullName);
	cout << "�����: " << fullName << "\n";
	//fullName.substr();

}

string getYourName() 
{
	string name = getYourName();
	string containsName = name + "hello";
	cout << "Name: " << name << "\n";
	cout << "Contains Name: " << containsName << "\n";
	string listNames[2] = { "������", "������" };
	for (int i = 0; i < 2; i++)
	{
		cout << listNames[i] << "\n";
	}
	return "Ok";
}

string reverse(const string name) {

	string result = "";
	int n = name.length()-1; //n=5  n-1 - ������ �������
	//name[n-1];
	for (int i = n; i>=0; i--) //������� � ���� � ��� �� �������
		result += name[i]; //������� � ����� ����� name[4], name[3]

	return result;
}

string* split(string str, char ch) {
	//string mas[2] = { "sdfsd", "sdfsdf" };
	string* array = new string[2];
	array[0] = "������";
	array[1]="����";
	length = 2;
	return array;
}