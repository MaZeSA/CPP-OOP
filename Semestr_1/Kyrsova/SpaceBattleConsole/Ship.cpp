#include "Ship.h"
#include <iostream>

Ship::Ship(Side s_)
{
	this->side = s_;
}

void Ship::Print()
{
	setTextColour(this->ShipColor);
	if (side == Side::LEFT)
	{
		setCursorPosition(1, position_Y - 1);
		std::cout << this->ship_L[0];
		setCursorPosition(2, position_Y);
		std::cout << this->ship_L[1];
		setCursorPosition(1, position_Y + 1);
		std::cout << this->ship_L[2];
	}
	else
	{
		setCursorPosition(GetLenght() -3, position_Y - 1);
		std::cout << this->ship_R[0];
		setCursorPosition(GetLenght() -4, position_Y);
		std::cout << this->ship_R[1];
		setCursorPosition(GetLenght() -3, position_Y + 1);
		std::cout << this->ship_R[2];
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
		this->lives--;
}

void Ship::SetHP(int hp_)
{
	if (this != nullptr)
		if (this->lives < 3)
		{
			this->lives += hp_;
			PrintLife();
		}
}

void Ship::PrintLife()
{

	int x = 9;
	if (this->side == Side::RIGHT)
		x = GetLenght() - (x + 2);

	setCursorPosition(x, 1);
	std::cout << "        ";

	setTextColour(FG_COLORS::FG_LIGHTGRAY);
	setCursorPosition(x, 1);
	if (this->GetShield())
		std::cout << "# ";

	setTextColour(FG_COLORS::FG_GREEN);
	for (int i = 0; i < this->lives; i++)
		std::cout << "+";
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
	PrintLife();
}

bool Ship::GetShield()
{
	return this->shield;
}


void Ship::PrintAmunition()
{
	setTextColour(FG_COLORS::FG_BROWN);
   		int t = 2, x = 0;

		if (this->usingAmunition != this->countAmunition)
		{
			for (int i = 0; i < this->countAmunition - this->usingAmunition; i++)
			{
				if (this->side == Side::RIGHT)
					x = (GetLenght() - t) - (i);
				else
					x = t + i;

				setCursorPosition(x, 2);
				(this->side == Side::LEFT) ? std::cout << "* " : std::cout << " *";
			}
		}
		else
		{
			(this->side == Side::LEFT) ? setCursorPosition(t, 2) : setCursorPosition(this->GetLenght() - t+1, 2);
			std::cout << " ";
		}
}

void Ship::AddAmunition()
{
	if (this->countAmunition <= 10)
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

