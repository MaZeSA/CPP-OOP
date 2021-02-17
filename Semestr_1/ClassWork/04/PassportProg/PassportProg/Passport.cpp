#include "Passport.h"
#include <iostream>

ForeignPassport::Visa::Visa(string country_, string expirationDate_)
{
    this->country = country_;
    this->expirationDate = expirationDate_;
}

void ForeignPassport::Visa::Print()
{
    cout << "Visa-> " << this->GetCountry() << " ExpirationDate: " << this->GetExpirationDate() << endl;
}

string ForeignPassport::Visa::GetCountry()
{
    return this->country;
}

string ForeignPassport::Visa::GetExpirationDate()
{
    return this->expirationDate;
}

void ForeignPassport::Print()
{
    cout << " ForeignPassport-> " << this->GetName() << " " << this->GetSN() << "Count Visa: " << this->Visas.size() << endl;
}

void ForeignPassport::PrintAllVisas()
{
    for (int i = 0; i < this->Visas.size(); i++)
    {
        cout << "("<< i << ") ";
        this->Visas[i].Print();
    }
}

void ForeignPassport::AddVisa(Visa* newVisa_)
{
    this->Visas.push_back(*newVisa_);
}

void ForeignPassport::RemoveVisa(int i_)
{
    this->Visas.erase(this->Visas.begin() + i_);
}


Passport::Passport(string name_, string Sn_)
{
    this->Name = name_;
    this->SN = Sn_;
}

string Passport::GetName()
{
    return this->Name;
}

string Passport::GetSN()
{
    return this->SN;
}

void Passport::Print()
{
    cout << "Passport-> " << this->GetName() << " " << this->GetSN() << endl;
}

