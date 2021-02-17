#pragma once
#include <string>
#include <vector>

	using namespace std;

class Passport
	{
	public:

		Passport(string, string);
		string GetName();
		string GetSN();
		void Print();

	private:
		string Name = "";
		string SN = "";
	};

class ForeignPassport : public Passport
{
public:

	ForeignPassport(string name_, string Sn_) : Passport(name_, Sn_) {}; 
	ForeignPassport(Passport pass_) : Passport(pass_.GetName(), pass_.GetSN()) {};
	void Print();
	void PrintAllVisas();

	class  Visa
	{
	public:
		Visa(string, string);
		void Print();
		string GetCountry();
		string GetExpirationDate();

	private:
		string country = "";
		string expirationDate = "";
	};
	void AddVisa(Visa*);
	void RemoveVisa(int);

private:

	vector<Visa> Visas;
};


