#include "Ship.h"
#include <iostream>

Ship::Ship(Side s_)
{
	this->side = s_;
}

void Ship::Print( int l_)
{
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
		setCursorPosition(l_-3, position_Y - 1);
		std::cout << this->ship_R[0];
		setCursorPosition(l_-4, position_Y);
		std::cout << this->ship_R[1];
		setCursorPosition(l_-3, position_Y + 1);
		std::cout << this->ship_R[2];
	}
}

void Ship::SetPosition(int y_, int l_)
{
	Clear(l_);
	this->position_Y = y_;
	Print(l_);
}

int Ship::GetPosition()
{
	return this->position_Y;
}

void Ship::Clear(int l_)
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
		setCursorPosition(l_ - 3, position_Y - 1);
		std::cout << "  ";
		setCursorPosition(l_ - 4, position_Y);
		std::cout << " ";
		setCursorPosition(l_ - 3, position_Y + 1);
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
	this->lives--;
}

void Ship::PrintLife(int l_)
{
	int x = 7;
	if (this->side == Side::RIGHT)
		x = l_ - (x+2);

	setCursorPosition(x, 1);
	std::cout << "      ";
	setCursorPosition(x, 1);
	for (int i = 0; i < this->lives; i++)
		std::cout << "*";
}

bool Ship::HitCheck(int y_, int l_)
{
	if (y_ == this->position_Y || y_ == this->position_Y + 1 || y_ == this->position_Y - 1)
	{
		this->Damage();
		this->PrintLife(l_);
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
