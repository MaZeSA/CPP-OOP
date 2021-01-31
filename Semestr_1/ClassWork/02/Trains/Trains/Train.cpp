#include "Train.h"

void Train::CreateTrain(int num, string stat, string time)
{
	this->number = num;
	this->station = stat;
	this->time = time;

	RandomCreateVagon();
}

void Train::PrintTrain()
{
	cout << " Train   #" << this->number << endl
		<< " Station - " << this->station << endl
		<< " Time    - " << this->time
		<< "\n Vagon Count - " << this->GetVagonCount() << "  All Place Count - " << this->GetAllPlaceCount() << endl;
}

int Train::GetNumber()
{
	return this->number;
}

string Train::GetStation()
{
	return this->station;
}

string Train::GetTime()
{
	return this->time;
}

void Train::RandomCreateVagon()
{
	int count = 4 + rand() % 15;
	int r = 0;
	for (int i = 0; i < count; i++)
	{
		r = rand() % 5;
		if (r == 0)
			VagonList.push_back(*new Vagon(Train::Vagon::VagonType::passenger));
		if (r == 1)
			VagonList.push_back(*new Vagon(Train::Vagon::VagonType::luggage));	
		if (r == 2)
			VagonList.push_back(*new Vagon(Train::Vagon::VagonType::reserved));	
		if (r == 3)
			VagonList.push_back(*new Vagon(Train::Vagon::VagonType::restaurant));	
		if (r == 4)
			VagonList.push_back(*new Vagon(Train::Vagon::VagonType::sleeping));

	}
}

int Train::GetVagonCount()
{
	return this->VagonList.size();
}

int Train::GetAllPlaceCount()
{
	int result = 0;
	for (Vagon v : this->VagonList)
	{
		result += v.GetPlace();
	}
	return result;
}

void Train::ShowVagon()
{
	cout << "All place - " << GetAllPlaceCount()<< endl;
	for (Vagon v : this->VagonList)
		cout << "Vagon type = " << v.GetType() << " Place count = " << v.GetPlace() << endl;
}

Train::Vagon::Vagon(VagonType v)
{
	this->VagonType_ = v;
}

int Train::Vagon::GetPlace()
{
	return (int)VagonType_;
}

string Train::Vagon::GetType()
{
	if (VagonType_ == Train::Vagon::VagonType::passenger)
		return "passenger";
	else if (VagonType_ == Train::Vagon::VagonType::luggage)
		return "luggage"; 
	else if (VagonType_ == Train::Vagon::VagonType::reserved)
		return "reserved";	
	else if (VagonType_ == Train::Vagon::VagonType::restaurant)
		return "restauran"; 
	else if (VagonType_ == Train::Vagon::VagonType::sleeping)
		return "sleeping";
}
