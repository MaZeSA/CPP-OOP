#pragma once
#include <iostream>
#include <string>

class Shooter
{
public:
	Shooter(int* cA_, std::string typeAmunition_) { AddAmunition(typeAmunition_, cA_); }
	void Shot();
	void AddAmunition(std::string name_, int* count_);
	std::string GetAmynition();

private:
	std::string amynition = "";
	int* countAmunition= nullptr;
};	
	
class Archer : public Shooter
{
public:
	Archer(int* cA_) : Shooter(cA_, "arrow") {};
	void Shot();
private:
}; 

class Ranger : public Shooter
{
public:
	Ranger(int* cA_) : Shooter(cA_, "arrow") {};
	void Shot();
}; 

class Catapult : public Shooter
{
public:
	Catapult(int* cA_) :Shooter(cA_, "stone") {}
	void Shot();
};

class ArcherTower : public Archer, public Ranger
{
public:
	ArcherTower(int* cA_) :Archer(cA_), Ranger(cA_) {};
};

class Fortress : public ArcherTower , public Catapult
{
public:
	Fortress(int* countArrow_, int* contStone_) :ArcherTower(countArrow_), Catapult(contStone_) {};
};