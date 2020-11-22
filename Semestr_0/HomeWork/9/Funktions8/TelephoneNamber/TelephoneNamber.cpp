#include <iostream>
#include <conio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int coun = 0;
char nam[] = { 0 };

class Country
{
public:
	char n[12] = { 0 };
	string name = "?";

	void Create(string nc, string name1)
	{
		for (int i = 0; i < 4; i++)
			n[i] = nc[i];

		name = name1;
	}
};

vector<Country> ListContry;

void Repl(string message)
{
	system("cls");

	cout << "Enter namber" << message << endl;
	//	cout << nam;
	for (int f = 0; f < 12; f++)
	{
		cout << nam[f];
		if (nam[f] != '\0')
		{
			if (f == 3 || f == 5 || f == 8)
				cout << " ";
		}
	}
}

bool OperatorChack(const char* ch, int c)
{
	bool fou = false;
	string contr = "No operator";
	//		cout << nam[coun];
	for (Country tr : ListContry)
	{
		//		if (tr.n == ch)
		//			{
		for (int i = 0; i < 3; i++)
		{
			bool found = true;
			for (int y = 0; y < 4; y++)
				if (tr.n[y] != ch[y])
				{
					found = false;
					break;
				}

			if (found)
			{
				contr = tr.name;
				break;
			}
		}

		//		break;
		//		}
	}
	coun++;

	Repl("\n" + contr);

	return true;
}

void Start()
{
	Repl("");
	bool fou = false;
	for (; coun < 13;)
	{
		nam[coun] = _getch();

		switch (coun)
		{
		case 0:
			if (nam[coun] != '+')
			{
				nam[coun] = { 0 };
				Repl("");
				cout << "Namber start with +" << endl;
			}
			else
			{
				coun++;
				Start();
				return;
			}
			break;
		case 2:
		case 3:
			if (OperatorChack(nam, coun))
			{
				fou = true;
			}
			break;
		default:
		{
			cout << nam[coun];
			if (coun == 3 || coun == 5 || coun == 8)
				cout << " ";
			coun++;
		}
		}
	}
	//	system("cls");
	cout << "\ntest2";
}

int main()
{
	Country c1, c2, c3, c4;
	c1.Create("+380", "Ukraine");
	c2.Create("+375", "Bilorusia");
	c3.Create("+95", "Gruzia");
	c4.Create("+371", "Latvia");

	ListContry.push_back(c1);
	ListContry.push_back(c2);
	ListContry.push_back(c3);
	ListContry.push_back(c4);


	Start();
	return 0;
}