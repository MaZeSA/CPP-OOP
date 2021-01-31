#include "Baraban.h"
#include <stdlib.h>

void Baraban::Twist()
{
	int temp = masChar[0];
	for (int i = 1; i < queueLength; i++)
	{
		masChar[i - 1] = masChar[i];
	}
	masChar[queueLength - 1] = temp;
}

char Baraban::GetChar()
{
	return masChar[0];
}

void Baraban::Mix()
{
	int tempIx = 0, temp2Ix = 0, temp=0;

	for (int i = 0; i < 50; i++)
	{
		tempIx = rand() % 5;
		temp2Ix = rand() % 5;

		temp = masChar[tempIx];
		masChar[tempIx] = masChar[temp2Ix];
		masChar[temp2Ix] = temp;
	}
}

int Baraban::CalcResult(char c, char c2)
{
	int res = 1;
	if (c == GetChar()) res++;
	if (c2 == GetChar()) res++;
	return res;
}