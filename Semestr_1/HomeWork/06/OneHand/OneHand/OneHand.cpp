#include "Baraban.h"
#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std;

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

class MyGame
{
private:
	Baraban barabans[3];
	int points = 100;
	int rate = 0;

public:
	
	MyGame(int rate_)
	{
		this->rate = rate_;
	}

	void Play()
	{
		barabans[0].Mix();
		barabans[1].Mix();
		barabans[2].Mix();

		int twistCout1 = 5 + rand() % 50;
		int twistCout2 = 5 + rand() % 50;
		int twistCout3 = 5 + rand() % 50;

		int max = twistCout1;
		if (twistCout2 > max) max = twistCout2;
		if (twistCout3 > max) max = twistCout3;

		int efect = 30;
		for (int i = 0; i < max; i++)
		{
			if (i < twistCout1)
				barabans[0].Twist();
			if (i < twistCout2)
				barabans[1].Twist();
			if (i < twistCout3)
				barabans[2].Twist();
			
			setCursorPosition(1, 3);

			cout << barabans[0].GetChar() << " - " << barabans[1].GetChar() << " - " << barabans[2].GetChar();
		
			this_thread::sleep_for(std::chrono::milliseconds(efect));
			efect += 300 / max;
		}
	
		ResultGame();
	}

	void ResultGame()
	{
		int res0 = barabans[0].CalcResult(barabans[1].GetChar(), barabans[2].GetChar());
		int res1 = barabans[1].CalcResult(barabans[0].GetChar(), barabans[2].GetChar());
		if (res0 < res1)res0 = res1;

		int res2 = barabans[2].CalcResult(barabans[1].GetChar(), barabans[0].GetChar());
		if (res0 < res2)res0 = res2;
	
		EndGame(res0);
	}

	void EndGame(int res)
	{
		if (res == 1)
			this->points -= rate;
		else if(res == 2)
			this->points += rate/2;
		else if (res == 3)
			this->points += rate*2;

		if (this->GetPoints() < 0)
			this->points = 0;
	}

	int GetPoints()
	{
		return this->points;
	}
};


int main()
{
	system("cls");
	int action = 0;
	cout << "The one-armed bandit!\n"
		<< "Enter enter your rate ->";
	cin >> action;

	MyGame game(action);

	system("cls");
	cout << "The one-armed bandit!\n"
		<< "Rate-> " << action;

	while (game.GetPoints())
	{
		setCursorPosition(1, 2);
		cout << "Your Points-> " << game.GetPoints() <<"      ";

		cin.get();
		game.Play();
	}
	system("cls");
	cout << "   \nYour Lost!";
	setCursorPosition(1, 3);
	system("pause");
	main();
}
