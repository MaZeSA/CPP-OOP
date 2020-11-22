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
/// Параметри по умолчанию
/// </summary>
/// <param name="name">Якщо пусто, то буде Іван</param>
/// <returns>розвернуте слово</returns>
string reverse(string name="Іван");

/// <summary>
/// Зробиває вхідйни рідок на слова згідно вказаного парметра ch
/// </summary>
/// <param name="str">Вхідний рядок</param>
/// <param name="ch">символ по якому ділимо, якщо не вказали то буде ' '</param>
/// <returns>Вертає масив string</returns>
string* split(string str, char ch = ' ');
int length = 0;

int main()
{
	SetConsoleCP(1251);  //для того, що працювали українські букви
	SetConsoleOutputCP(1251); //для того, що працювали українські букви

	srand((unsigned)time(NULL));

	//simpleString();
	//cinString();
	//getYourName();

	/*cout << "Введіть фраз:\n";
	string temp;
	getline(cin, temp);

	string result = reverse(temp);
	cout << result << "\n";*/

	string* result = split("Капітан крутий чувакa",'a');
	
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
	/*print("Земеляни");*/
	/*image_compress();
	bool result = image_compress(200, 150);
	
	myTest();*/

	return 0;
}
void simpleString() 
{
	string str = "Введіть ваше ім'я: ";
	cout << str << "\n";

	string name;
	cin >> name;
	name[0] = 'В';
	string newName = name;
	newName[0] = 'T';

	cout << "Вас звати: " << name << "\n";
	cout << "New name: " << newName << "\n";
	cout << "Розмір в байтах: " << name.length() << "\n";
}

void cinString() 
{
	string fullName;
	cout << "Введеть ваш ПІБ: ";
	getline(cin, fullName);
	cout << "Привіт: " << fullName << "\n";
	//fullName.substr();

}

string getYourName() 
{
	string name = getYourName();
	string containsName = name + "hello";
	cout << "Name: " << name << "\n";
	cout << "Contains Name: " << containsName << "\n";
	string listNames[2] = { "Оксана", "Іванка" };
	for (int i = 0; i < 2; i++)
	{
		cout << listNames[i] << "\n";
	}
	return "Ok";
}

string reverse(const string name) {

	string result = "";
	int n = name.length()-1; //n=5  n-1 - останій елемент
	//name[n-1];
	for (int i = n; i>=0; i--) //починаю з кінця і іду на початок
		result += name[i]; //зберігаю в новий масив name[4], name[3]

	return result;
}

string* split(string str, char ch) {
	//string mas[2] = { "sdfsd", "sdfsdf" };
	string* array = new string[2];
	array[0] = "Оксана";
	array[1]="Іван";
	length = 2;
	return array;
}