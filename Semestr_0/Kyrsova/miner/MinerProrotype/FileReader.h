#pragma once

#include <vector>
#include <string>
struct Winners
{
	std::string Level_ = "";
	std::string Name_ = "";
	int time_ = 0;
	std::string data_ = "";
};

void ReadWinners();
int GetRecord(int i);
std::vector<Winners> GetListWinnes();
std::string ShowGetYouName();
void WriteWinner(int lvl, int time_, std::string Level);
void SaveFileWinners();