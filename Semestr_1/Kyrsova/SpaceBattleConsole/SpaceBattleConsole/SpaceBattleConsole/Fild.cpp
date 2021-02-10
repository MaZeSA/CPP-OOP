#include "Fild.h"
#include <thread>

Fild::Fild(int x_, int y_, int retreat_)
{
	this->X = x_;
	this->Y = y_;
	this->retreat = retreat_;

	for (int i = 0; i < y_; i++)
	{
		this->listLine.push_back(new GameLine(retreat_ + i, x_));
	}

	ship_L.PrintLife(x_);	
	ship_R.PrintLife(x_);
	ship_L.SetEnemy(&ship_R);	
	ship_R.SetEnemy(&ship_L);
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

time_t t = std::time(0);

void Fild::Play()
{
	int y_l = this->retreat + 10, y_r = this->retreat + 10;
	ship_L.SetPosition(y_l, X);
	ship_R.SetPosition(y_r, X);
	
	t = std::time(0);

	while (true)
	{
		this_thread::sleep_for(std::chrono::milliseconds(40));

		if (time(0) - t > 30)//30sec
		{
			t = time(0);
		}

		UpdateFild();
		

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

