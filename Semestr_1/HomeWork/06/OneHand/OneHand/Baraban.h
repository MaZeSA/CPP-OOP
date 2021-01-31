#pragma once
class Baraban
{
private:

	static const int queueLength = 5;
	char masChar[queueLength] = {'@','#','$','%','*'};

public:

	void Twist();
	char GetChar();
	void Mix();
	int CalcResult(char, char);
};
