#include "Ship.h"
#include <iostream>

Ship::Ship(Side s_, bool* liv_)
{
	this->side = s_;
	this->liv = liv_;
}

void Ship::Print()
{
	std::string* temp;
	setTextColour(this->ShipColor);
	if (side == Side::LEFT)
	{
		if (this->up_ship)
			temp = this->ship_L_UP;
		else 
			temp = this->ship_L;

		setCursorPosition(1, position_Y - 1);
		std::cout << temp[0];
		setCursorPosition(2, position_Y);
		std::cout << temp[1];
		setCursorPosition(1, position_Y + 1);
		std::cout << temp[2];
	}
	else
	{
		if (this->up_ship)
			temp = this->ship_R_UP;
		else
			temp = this->ship_R;

		setCursorPosition(GetLenght() -3, position_Y - 1);
		std::cout << temp[0];
		setCursorPosition(GetLenght() -4, position_Y);
		std::cout << temp[1];
		setCursorPosition(GetLenght() -3, position_Y + 1);
		std::cout << temp[2];
	}
}

void Ship::SetPosition(int y_, int l_)
{
	Clear();
	this->position_Y = y_;
	this->fildLenght = l_;
	Print();
}

int Ship::GetPosition()
{
	return this->position_Y;
}

int Ship::GetLenght()
{
	return this->fildLenght;
}

void Ship::Clear()
{
	if (side == Side::LEFT)
	{
		setCursorPosition(1, position_Y - 1);
		std::cout << "  ";
		setCursorPosition(2, position_Y);
		std::cout << "  ";
		setCursorPosition(1, position_Y + 1);
		std::cout << "  ";
	}
	else
	{
		setCursorPosition(GetLenght() - 3, position_Y - 1);
		std::cout << "  ";
		setCursorPosition(GetLenght() - 4, position_Y);
		std::cout << " ";
		setCursorPosition(GetLenght() - 3, position_Y + 1);
		std::cout << "  ";
	}
}

//void Ship::Fire(GameLine* gl_)
//{
//	if (this->side == Side::LEFT)
//		gl_->SetActivity(3, Activity::TypeActyvity::bullet, 3); 
//	else if (this->side == Side::RIGHT)
//		gl_->SetActivity(-(gl_->GetLenght()- 4), Activity::TypeActyvity::bullet, gl_->GetLenght() - 4);
//}

void Ship::Damage()
{
	if (this->GetShield())
		this->SetShield(false);
	else
	{
		this->lives--;
		this->SetUp(false);
	}
	if (this->lives == 0)
		*(this->liv) = false;
}

void Ship::SetHP(int hp_)
{
	if (this != nullptr)
		if (this->lives < 4)
		{
			this->lives += hp_;
			PrintLife();
		}
}

void Ship::PrintLife()
{
	int x = 2;

	if (this->side == Side::RIGHT)
		x = GetLenght() - (x + 24);

	SetColor(FG_COLORS::FG_LIGHTGRAY, FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(x, 1);
	std::cout << "123456789012345678901234";
	
	setCursorPosition(x , 1);

	SetColor(FG_COLORS::FG_GREEN, FG_COLORS::FG_GREEN);
	for (int i = 0; i < this->lives; i++)
		std::cout << "123456";
}

bool Ship::HitCheck(int y_)
{
	if (y_ == this->position_Y || y_ == this->position_Y + 1 || y_ == this->position_Y - 1)
	{
		this->Damage();
		this->PrintLife();
		return true;
	}
	return false;
}

Ship::Side Ship::GetSide()
{
	return this->side;
}

void Ship::SetEnemy(Ship* enemy_)
{
	this->enemyShip = enemy_;
}

Ship* Ship::GetEnemy()
{
	return this->enemyShip;
}

void Ship::SetShield(bool sh_)
{
	this->shield = sh_;
	PrintShield();
}

bool Ship::GetShield()
{
	return this->shield;
}

void Ship::PrintShield()
{
	int x = 27;
	if (this->side == Side::RIGHT)
		x = GetLenght() - (x + 8);

	//setTextColour(FG_COLORS::FG_GRAY);
	SetColor(FG_COLORS::FG_GRAY, FG_COLORS::FG_GRAY);

	setCursorPosition(x, 1);
	std::cout << "[shield]";

	if (this->GetShield())
	{
		setCursorPosition(x, 1);
		//setTextColour(FG_COLORS::FG_YELLOW);
		SetColor(FG_COLORS::FG_CYAN, FG_COLORS::FG_CYAN );

		std::cout << "[shield]";
	}
}


void Ship::PrintAmunition()
{
	int t = 2, x = 0;

	setTextColour(FG_COLORS::FG_LIGHTGRAY);
	(this->side == Side::LEFT) ? setCursorPosition(t, 2) : setCursorPosition(this->GetLenght() - t - this->countAmunition, 2);
	std::cout << "                                 ";
	(this->side == Side::LEFT) ? setCursorPosition(t, 2) : setCursorPosition(this->GetLenght() - t - this->countAmunition, 2);

	for (int i = 0; i < this->countAmunition; i++)
		std::cout << "*";

	setTextColour(FG_COLORS::FG_BROWN);
   	
		if (this->usingAmunition != this->countAmunition)
		{
			for (int i = 0; i < this->countAmunition - this->usingAmunition; i++)
			{
				if (this->side == Side::RIGHT)
					x = (GetLenght() - t-1) - (i);
				else
					x = t + i;

				setCursorPosition(x, 2);
				(this->side == Side::LEFT) ? std::cout << "*" : std::cout << "*";
			}
		}
		else
		{
		/*	(this->side == Side::LEFT) ? setCursorPosition(t, 2) : setCursorPosition(this->GetLenght() - t+1, 2);
			std::cout << " ";*/
		}
}

void Ship::AddAmunition()
{
	if (this->countAmunition <= this->maxUsingAmunition)
		this->countAmunition++;
}

bool Ship::TakeAmunition()
{
 	if (this->countAmunition == this->usingAmunition)
		return false;
	
	this->usingAmunition++;
	this->PrintAmunition();
	return true;
}

void Ship::ReturnAmunition()
{
	this->usingAmunition--;
	this->PrintAmunition();
}

void Ship::SetShipColor(FG_COLORS color_)
{
	this->ShipColor = color_;
}

FG_COLORS Ship::GetShipColor()
{
	return this->ShipColor;
}

void Ship::SetUp(bool up_)
{
	this->up_ship = up_;

	if (up_)
	{
		if (this->maxAmunition > this->maxUsingAmunition)
			this->maxUsingAmunition += 10;
	}
	else
	{
		this->maxUsingAmunition = 10;
		if (this->countAmunition > 10)
			this->countAmunition = 10;
		this->PrintAmunition();
	}
	this->Print();
}

bool Ship::GetUp()
{
	return this->up_ship;
}

int Ship::GetLives()
{
	return this->lives;
}

