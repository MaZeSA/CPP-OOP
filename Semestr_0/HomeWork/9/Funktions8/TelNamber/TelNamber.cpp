//4. Не обов'язкова задача: написати функцію, 
//яка перевіряє коректність вводу номера телефона.Телефон має вводитися
//як у приват24. + 380 22 333 44 це правильний номер

#include <iostream>
#include <conio.h> //для чистки консолі
#include <vector>
#include <Windows.h>
using namespace std;

const int max = 13;
string contryName = "";//країна номер якої введенно
char number[max] = { 0 }; //введений номер
int coun = 0;//кількість введених символів

//Клас для бази країн
class Country
{
public:
	char n[max] = { 0 };
	string name = "?";

	void Create(string nc, string name1)
	{
		for (int i = 0; i < 4; i++)
			n[i] = nc[i];

		name = name1;
	}
};

vector<Country> ListContry; //список країн і кодів

//показ номера і відступи 
void Show(string message)
{
	system("cls");//чистка консолі для емуляції інтерактивності
	cout << "Введіть 12 значний номер телефону (підтримуються коди країн +375, +95, +61, +48, +370)" << contryName << message << endl;;

	for (int f = 0; f < max; f++)
	{
		if (number[f] != '\0')
		{
			cout << number[f];
			if (f == 3 || f == 5 || f == 8 || f == 10) //відступи
				cout << " ";
		}
	}
}
//пошук введеного номера в базі 
bool OperatorChack(const char* ch, int c)
{
	bool found = false;
	for (Country tr : ListContry)
	{
		bool searh = true;
		for (int y = 0; y < 4; y++)
			if (tr.n[y] != ch[y])
			{
				searh = false;
				break;
			}

		if (searh)
		{
			found = true;
			contryName = "\n" + tr.name;
			break;
		}
	}
	return found;
}
//основна функція
void Start()
{
	bool found = false;
	for (; coun < max;)
	{
		number[coun] = _getch(); //зчитуємо символ

		if (number[coun] == '\b')//підтримка видалення клавішою Backspace
		{
			if (coun != 0)
			{
				number[coun] = { 0 };//поточний ввід відміняється
				number[coun - 1] = { 0 };//видалення попередньго символа
				coun--;
				if (coun < 4)
				{
					found = false;
					contryName = "\nНе відомий код країни";
				}
				Show("");
			}
		}
		else
		{
			bool j = isdigit(number[coun]); //перевірка на числа, заборона вводу символів, крім + якцо це 0 елемент
			if (j == false && coun > 0) { continue; }

			switch (coun)
			{
			case 0:
				if (number[coun] != '+')
				{
					number[coun] = { 0 };
					Show("\nНомер повинен починатися з +");
				}
				else
				{
					Show("");
					coun++;
				}
				break;
			case 2:case 3:
			{
				if (found == false)
				{
					if (OperatorChack(number, coun)) //пошук номера в базі
					{
						found = true;
					}
					else
					{
						contryName = "\nНе відомий код країни";
					}
				}

				Show("");
				coun++;
				break;
			}
			default:
			{
				Show("");
				coun++;
			}
			}
		}
	}
	if (contryName == "\nНе відомий код країни")
		cout << "\nНе відомий номер\n";
	else
		cout << "\nНомер введенно вірно!\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string contrys[6][2] = { 
		{"+380", "Україна"},
		{"+375", "Білорусія"},
		{"+95", "Грузія"},
		{"+61", "Австралія"},
		{"+48", "Польща"},
		{"+370", "Литва"}
	};

	Country *c;
	for (string* s : contrys)
	{
		 c = new Country();
		 c->Create(s[0], s[1]);
		 ListContry.push_back(*c);
	}

	cout << "Введіть 12 значний номер телефону (підтримуються коди країн +375, +95, +61, +48, +370)" << endl;
	Start();
}