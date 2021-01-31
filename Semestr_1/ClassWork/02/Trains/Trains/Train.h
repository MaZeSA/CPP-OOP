#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Train
{

public:
	void CreateTrain(int, string, string);
	void PrintTrain();
	int GetNumber();
	string GetStation(); 
	string GetTime();
	void RandomCreateVagon();
	int GetVagonCount();
	int GetAllPlaceCount();
	void ShowVagon();

	class Vagon
	{	
	public:

		enum class  VagonType
		{
			passenger = 40,
			sleeping = 20,
			luggage = 0,
			reserved =10,
			restaurant = 15
		};

		Vagon(VagonType);
		int GetPlace();
		string GetType();

	private:
		VagonType VagonType_;
	};

private:
	int number = 0;
	string station = "";
	string time = "";
	vector<Vagon> VagonList;

};

