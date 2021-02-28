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
	
}

void Fild::PreparationFild()
{
	setTextColour(FG_COLORS::FG_CYAN);
	setCursorPosition(X / 2 - 6, 0);
	std::cout << "Spase Battle";	

	ship_L.SetShipColor(FG_COLORS::FG_LIGHTRED);
	ship_R.SetShipColor(FG_COLORS::FG_LIGHTBLUE);
	ship_L.SetEnemy(&ship_R);	
	ship_R.SetEnemy(&ship_L);	
	ship_L.SetPosition(this->retreat + 10, X);
	ship_R.SetPosition(this->retreat + 10, X);
	ship_L.PrintLife();	
	ship_R.PrintLife();
	ship_L.PrintShield(); 
	ship_R.PrintShield();
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
	this->liv = true;

	cin.ignore();
	cin.clear();
	while (this->liv)
	{
		this_thread::sleep_for(std::chrono::milliseconds(40));

		UpdateFild();
		
		GenerateActivity(); //test

		if (GetAsyncKeyState(Settings::setting->Get_Up_key(1)) == -32767)
		{
			if (y_l > 1 + this->retreat)
			{
				y_l--;
				ship_L.SetPosition(y_l, X);
			}
		}
		if (GetAsyncKeyState(Settings::setting->Get_Down_key(1)) == -32767)
		{
			if (y_l < this->Y - 2 + this->retreat)
			{
				y_l++;
				ship_L.SetPosition(y_l, X);
			}
		}
		if (GetAsyncKeyState(Settings::setting->Get_Shot_key(1)) == -32767)
		{
			ShipFire(&ship_L);
		}
		
		if (GetAsyncKeyState((Settings::setting->Get_Up_key(2))) == -32767)
		{
			if (y_r > 1 + this->retreat)
			{
				y_r--;
				ship_R.SetPosition(y_r, X);
			}
		}
		if (GetAsyncKeyState(Settings::setting->Get_Down_key(2)) == -32767)
		{
			if (y_r < this->Y - 2 + this->retreat)
			{
				y_r++;
				ship_R.SetPosition(y_r, X);
			}
		}
		
		if (GetAsyncKeyState(Settings::setting->Get_Shot_key(2)) == -32767)
		{
			ShipFire(&ship_R);
		}
		if (GetAsyncKeyState(VK_ESCAPE) == -32767)
		{
			this->liv= false;
		}	
	}
}

void Fild::ShipFire(Ship* ship_)
{
	if (ship_->GetSide() == Ship::Side::LEFT)
		if (ship_->GetUp())
		{
			Fire(ship_, 4, 4, (ship_->GetPosition() - this->retreat) - 1);
			Fire(ship_, 4, 4, (ship_->GetPosition() - this->retreat) + 1);
		}
		else
			Fire(ship_, 4, 4, ship_->GetPosition() - this->retreat);
	else if (ship_->GetSide() == Ship::Side::RIGHT)
		if (ship_->GetUp())
		{
			Fire(ship_, -(this->X - 5), this->X - 5, (ship_->GetPosition() - this->retreat) - 1);
			Fire(ship_, -(this->X - 5), this->X - 5, (ship_->GetPosition() - this->retreat) + 1);
		}
		else
			Fire(ship_, -(this->X - 5), this->X - 5, ship_->GetPosition() - this->retreat);
}

void Fild::Fire(Ship* ship_, int move_, int position_, int index_)
{
	this->listLine[index_]->SetActivity(move_, Activity::TypeActyvity::bullet, position_, ship_);
}

time_t t = time(0);
void Fild::GenerateActivity()
{
	
	if ((time(0) - t ) > 5)//30sec
	{
		Activity::TypeActyvity typ = Activity::TypeActyvity::none;
		int i = rand() % 100;

		if (i < 17)
			typ = Activity::TypeActyvity::hp;
		else if (i <60)
			typ = Activity::TypeActyvity::ammunition;
		else if (i < 85)
			typ = Activity::TypeActyvity::amor;
		else if (i < 100)
			typ = Activity::TypeActyvity::up;

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

void Fild::CleanFild(int y_start_, int y_end_, int x_start_, int x_end_)
{
	for (int y = y_start_; y < y_end_; y++)
	{
		setCursorPosition(x_start_, y);
		for (int x = x_start_; x < x_end_; x++)
			cout << " ";
	}
}

int Fild::GetResultGame()
{
	if (!this->liv)
		if (ship_L.GetLives() <= 0)
			return 1;
		else if (ship_R.GetLives() <= 0)
			return 2;
	return 0;
}



