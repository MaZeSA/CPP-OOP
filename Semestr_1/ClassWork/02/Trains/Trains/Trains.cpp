
#include "Train.h"
#include <vector>
#include <time.h>


void AddOrEditTrain(Train* train)
{
	int number = 0;
	string station = "";
	string time = "";

	cout << "Enter new train number -> ";
	cin >> number;
	if (number == 0) number = train->GetNumber();

	cout << "Enter new End Station-> ";
	cin >> station;
	if (station == "0") station = train->GetStation();

	cout << "Enter new Time-> ";
	cin >> time;
	if (time == "0") time = train->GetTime();

	train->CreateTrain(number, station, time);
}
Train& Searh(vector<Train> &trainList)
{
	int data = 0;
	cout << "Enter Number Train-> ";
	cin >> data;

	Train* train = NULL;

	for (int i = 0; i < trainList.size(); i++)
	{
		if (trainList[i].GetNumber() == data)
		{
			return trainList[i];
			break;
		}
	}
	return *train;
}
void ShowAllTrain(vector<Train> &trainList)
{
	if (trainList.empty())
		cout << "List is Empty";
	else
		for (int i = 0; i < trainList.size(); i++)
		{
			trainList[i].PrintTrain();
			cout << endl;
		}
}
void EditTrain(vector<Train> &trainList)
{
	cout << "Edit Train\n";

	Train* train = &Searh(trainList);
	if (train == NULL)
		cout << "Train Number Not Found!\n";
	else
	{
		cout << "Enter '0' for skip!\n";
		AddOrEditTrain(train);
	}
}

void ShowVagon(vector<Train>& trainList)
{
	cout << "Vagon:\n";

	Train* train = &Searh(trainList);
	if (train == NULL)
		cout << "Train Number Not Found!\n";
	else
	{
		train->ShowVagon();
	}
}

void CreateDefoultTrain(vector<Train>& trainList)
{
	string Station[3] = { "Lviv", "Kyiv", "Rivne" };
	string time[3] = { "11.20", "18.40", "5.00" };

	for (int i = 0; i < 3; i++)
	{
		Train train;
		train.CreateTrain(i, Station[i], time[i]);
		trainList.push_back(train);
	}
}


int main()
{
	srand((unsigned int)time(0));

	vector<Train> ListTrain;

	CreateDefoultTrain(ListTrain);

	int action = 1;
	
	while (action)
	{
		cout << "\n1. Add Train\n"
			<< "2. Show All Train\n"
			<< "3. Searh Train\n" 
			<< "4. Edit Train\n" 
			<< "5. Show Vagon in Train\n"
			<< "0. Exit\n";

		cin >> action;

		switch (action)
		{
		
			case 1:
			{
				Train train;
				AddOrEditTrain(&train);
				ListTrain.push_back(train);
				break;
			}
			case 2:
			{
				ShowAllTrain(ListTrain);
				break;
			}
			case 3:
			{
				if (!ListTrain.empty())
				{
					Train* train = &Searh(ListTrain);
					if (train != NULL)
						train->PrintTrain();
					else
						cout << "Not Found Train!\n";
				}
				break;
			}
			case 4:
			{
				EditTrain(ListTrain);
				break;
			}	
			case 5:
			{
				ShowVagon(ListTrain);
				break;
			}
		}
	}
}


