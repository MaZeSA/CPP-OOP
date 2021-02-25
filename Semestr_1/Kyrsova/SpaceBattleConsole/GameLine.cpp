#include "GameLine.h"

GameLine::GameLine(int y_, int l_)
{
	this->Y = y_;
	this->lenght = l_;

	Activity* temp = nullptr;
	Activity* newActivity = nullptr;

	for (int i = 0; i < l_; i++)
	{
		newActivity = new Activity(i, y_, l_);

		if (i == 0)
		{
			temp = newActivity;
		}
		/*	else if (i == l_)
			{
				newActivity->SetBackActivity(temp);
			}*/
		else
		{
			newActivity->SetBackActivity(temp);
			listActyvity[i - 1]->SetNextActivity(newActivity);	//temp->SetNextActivity(newActivity);
		}
		listActyvity.push_back(newActivity);
		temp = newActivity;
	}

}

vector<Activity*>GameLine::GetList()
{
	return this->listActyvity;
}

void GameLine::UpdateLine()
{
	int count = 0;
	for (int i = 0; i < this->lenght; i++)
	{
		if (listActyvity[i]->GetSymbol() == 42)
		{
			listActyvity[i]->Move();
			i++;
			count++;
		}
	}
	if (count == 0)
		this->change = false;

}

void GameLine::SetChange(bool c_)
{
	this->change = c_;
}

bool GameLine::GetChange()
{
	return this->change;
}

void GameLine::SetActivity(int indexMove_, Activity::TypeActyvity a_, int x_, Ship* ship_)
{
	if (a_ == Activity::TypeActyvity::bullet)
		if (ship_ != nullptr)
			if (!ship_->TakeAmunition())
				return;

	this->listActyvity[x_]->SetState(indexMove_, a_, ship_);
	SetChange(true);
}

void GameLine::StartTest(int temp_)
{
	if (temp_ % 2 == 0)
		this->listActyvity[3]->SetState(3, Activity::TypeActyvity::bullet, nullptr);
	else
		this->listActyvity[96]->SetState(-96, Activity::TypeActyvity::bullet, nullptr);
}

int GameLine::GetLenght()
{
	return this->lenght;
}

