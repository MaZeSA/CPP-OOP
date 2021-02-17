#include <iostream>
#include "Passport.h"

int main()
{
	int act = 1;

	Passport newPass("Alexander Pushkin", "IT 11001001");
	ForeignPassport newFgPass(newPass);

    ForeignPassport::Visa testVisa("USA", "27.05.2022");
	newFgPass.AddVisa(&testVisa);


	while (act)
	{
		cout << "\n1. Show Passport\n"
			<< "2. Show ForeignPassport\n"
			<< "3. Add Visa\n"
			<< "4. Show all Visa\n"
			<< "5. Remove Visa\n";

		cin >> act;

		switch (act)
		{
		case 1:
		{
			newPass.Print();
			break;
		}	
		case 2:
		{
			newFgPass.Print();
			break;
		}
		case 3:
		{
			string country;
			cout << "Enter Country->";
			cin >> country;
			
			string data;
			cout << "Enter Data-> ";
			cin >> data;

			ForeignPassport::Visa newVisa(country, data);
			newFgPass.AddVisa(&newVisa);
			break;
		}
		case 4:
		{
			newFgPass.PrintAllVisas();
			break;
		}	
		case 5:
		{
			int c;
			cout << "Enter number->";
			cin >> c;
			newFgPass.RemoveVisa(c);
			break;
		}
		}
	}
}
