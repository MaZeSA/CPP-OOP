#include "Shooter.h"

void Shooter::Shot()
{
	if (*countAmunition != 0)
	{
		*countAmunition = *(this->countAmunition) - 1;
		std::cout << "Remaining " << *(this->countAmunition) << " units of ammunition\n\n";
	}
	else
		std::cout << "There is not enough ammunition for the shot\n\n";
}

void Shooter::AddAmunition(std::string name_, int* count_)
{
	this->amynition = name_;
	countAmunition = count_;
	std::cout << "Amunition -> " << name_ << " --> " << *(this->countAmunition) << std::endl;
}

std::string Shooter::GetAmynition()
{
	return this->amynition;
}

void Archer::Shot()
{	
	std::cout << "A Archer of " << GetAmynition() << " was used!\n";
	((Shooter*)(this))->Shot();
}

void Ranger::Shot()
{
	std::cout << "A Ranger of " << this->GetAmynition() << " was used!\n";
	((Shooter*)(this))->Shot();
}

void Catapult::Shot()
{
	std::cout << "A Catapult of " << this->GetAmynition() << " was used!\n";
	((Shooter*)(this))->Shot();
}

