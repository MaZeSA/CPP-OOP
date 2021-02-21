#include "Fild.h"
#include <thread>
#include <iostream>

Fild::Fild(int x_, int y_, int retreat_)
{
	this->X = x_;
	this->Y = y_;
	this->retreat = retreat_;

	for (int i = 0; i < y_; i++)
	{
		this->listLine.push_back(new GameLine(retreat_ + i, x_));
	}
		
	PreparationFild();
}

void Fild::PreparationFild()
{
	setCursorPosition(X / 2 - 3, 0);
	std::cout << "DevMode";	
	setCursorPosition(X / 2 - 3, 1);
	std::cout << "<Lives>"; 
	setCursorPosition(X / 2 - 6, 2);
	std::cout << "<Amunitions>";

	ship_L.SetShipColor(FG_COLORS::FG_LIGHTRED);
	ship_R.SetShipColor(FG_COLORS::FG_LIGHTBLUE);
	ship_L.SetEnemy(&ship_R);	
	ship_R.SetEnemy(&ship_L);	
	ship_L.SetPosition(this->retreat + 10, X);
	ship_R.SetPosition(this->retreat + 10, X);
	ship_L.PrintLife();	
	ship_R.PrintLife();
	ship_L.PrintAmunition(); 
	ship_R.PrintAmunition();
}

void Fild::StartTest()
{	
	int r = 0;

	for (int i = 0; i < 6; i++)
	{
		r = rand() % 20;
		listLine[r]->StartTest(i);
		listLine[r]->SetChange(true);
	}
}

vector<GameLine*> Fild::GetList()
{
	return this->listLine;
}

void Fild::UpdateFild()
{
	for ( GameLine *gl : this->listLine)
	{
		if (gl->GetChange())
		{
			gl->UpdateLine();
		}
	}
}

void Fild::Play()
{
	int y_l = this->retreat + 10, y_r = this->retreat + 10;
	
	while (true)
	{
		this_thread::sleep_for(std::chrono::milliseconds(40));

		UpdateFild();
		
GenerateActivity(); //test

		if (GetAsyncKeyState(VK_UP) == -32767)
		{
			if (y_l > 1 + this->retreat)
			{
				y_l--;
				ship_L.SetPosition(y_l, X);
			}
		}
		if (GetAsyncKeyState(VK_DOWN) == -32767)
		{
			if (y_l < this->Y - 1 + this->retreat)
			{
				y_l++;
				ship_L.SetPosition(y_l, X);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD8) == -32767)
		{
			if (y_r > 1 + this->retreat)
			{
				y_r--;
				ship_R.SetPosition(y_r, X);
			}
		}
		if (GetAsyncKeyState(VK_NUMPAD2) == -32767)
		{
			if (y_r < this->Y - 1 + this->retreat)
			{
				y_r++;
				ship_R.SetPosition(y_r, X);
			}
		}
		if (GetAsyncKeyState(VK_SPACE) == -32767)
		{
			ShipFire(&ship_L);
		}
		if (GetAsyncKeyState(VK_NUMPAD0) == -32767)
		{
			ShipFire(&ship_R);
		}
	}
}

void Fild::ShipFire(Ship* ship_)
{
	if (ship_->GetSide() == Ship::Side::LEFT)
	  this->listLine[ship_->GetPosition() - this->retreat]->SetActivity(4, Activity::TypeActyvity::bullet, 4, ship_); 
	else if (ship_->GetSide() == Ship::Side::RIGHT)
		this->listLine[ship_->GetPosition() - this->retreat]->SetActivity(-(this->X- 5), Activity::TypeActyvity::bullet, this->X - 5, ship_);
}

time_t t = time(0);
void Fild::GenerateActivity()
{
	
	if ((time(0) - t ) > 2)//30sec
	{
		Activity::TypeActyvity typ = Activity::TypeActyvity::none;
		int i = rand() % 3;

		switch (i)
		{
			case 0:
			{
				typ = Activity::TypeActyvity::hp;
				break;
			}
			case 1:
			{
				typ = Activity::TypeActyvity::ammunition;
				break;
			}
			case 2:
			{
				typ = Activity::TypeActyvity::amor;
				break;
			}
		}
		t = time(0);
		
		int y = 2 + rand() % (this->Y - this->retreat -2);
		this->listLine[y]->SetActivity(0, typ, GetMinGen() + rand() % ((GetMaxGen() - GetMinGen()) + 1), nullptr);

		t = time(0);
	}
	
}

int Fild::GetMinGen()
{
	return this->X / 3;
}
int Fild::GetMaxGen()
{
	return this->X / 3 * 2;
}

