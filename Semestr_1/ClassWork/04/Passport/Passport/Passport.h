#pragma once
#include <string>
#include <vector>

using namespace std;

class Passport
{
public:

	Passport(string, string, unsigned int);

private:
	string Name="";

	string SN = "";
	unsigned int namber = 0;
};

class ForeignPassport : public Passport
{
public:

	ForeignPassport(string name_, string Sn_, unsigned int num_) : Passport(name_, Sn_, num_) {};
	class  Visa
	{
	public:
		Visa(string, string);

	private:
		string country = "";
		string expirationDate = "";
	};
	void AddVasa(Visa*);
private:

	vector<Visa> Visas;
};

