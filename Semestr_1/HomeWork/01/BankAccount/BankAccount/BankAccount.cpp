#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <Windows.h>

using namespace std;

void CreateDefoultTestAccount();
void MainMenu();
void SetBackgroundColor(int, int);
void ShowAccounts();
void SelectAccount();
void CreateAccount();
int GenNumber();

class Account
{
private:
    unsigned int number = 0;
    double balance = 0;
    string valuta = "";
    string pin = "0000";
    bool lock = false; //статус рахунка (не заблоковано)
    short pinCout = 0;//кількість введенних спроб

public:

    Account(string valuta, string pin)
    {
        this->valuta = valuta;
    }
    bool EnterPin(string pin)
    {
        if (pin == this->pin)
        {
            pinCout = 0; //скидаємо щочик
            return true;
        }
        else
            pinCout++;

        if (pinCout == 3)
            lock = true;
        return false;
    }
    short GetPinCout()
    {
        return pinCout;
    }
    int GetNumber()
    {
        return number;
    }
    void SetNumber(int Number)
    {
        this->number = Number;
    }
    
    /// <summary>
    /// функція для правильного відображення юзеру номера рахунка
    /// </summary>
    string GetFullNumber()
    {
        string s_numb = to_string(number);
        if (s_numb.size() < 8)
        {
            short nul = 9 - (short)s_numb.size();
            while (--nul)
            {
                s_numb = "0" + s_numb;
            }
        }
        return s_numb;
    }
    void SetBalance(double sum)
    {
        balance += sum;
    }
    double GetBalance()
    {
        return balance;
    }
    string GetValuta()
    {
        return valuta;
    }
    bool GetStatus()
    {
        return lock;
    }
  
    /// <summary>
    /// Функція для демонстрації
    /// </summary>
    void SetStatus(bool stat)
    {
        lock = stat;
    }
};

vector<Account> ListAccounts;

int main()
{
    srand((int)time(0));
    CreateDefoultTestAccount();//тестові рахунки для демонстрації
    MainMenu();
}
void MainMenu()
{
    short s = 0;
    while (true)
    {
       cout << "1. Show Accounts\n"
            << "2. Create Account\n"
            << "3. Select Account\n"
            << "0. Exit\n";
       cin >> s;

       switch (s)
       {
           case 1:
               system("cls");
               ShowAccounts();
               break; 
           case 2:
               system("cls");
               CreateAccount();
               break; 
           case 3:
               SelectAccount();
               break;
           case 0:
               exit(0);
       }
    }
}

void SelectAccount()
{
    int num = 0; //00000001==1 можна вводити без нулів на початку
    cout << "Enter Number Account-> ";
    cin >> num;

    int selectAcc = -1;
    for (size_t i = 0; i < ListAccounts.size(); i++)
    {
        if (num == ListAccounts[i].GetNumber())
            selectAcc = i;
        break;
    }
    if (selectAcc == -1)//введенний акаунт не знайдено
    {
        cout << "Number Account Not Correctly\n";
        SelectAccount();
    }
    else if (ListAccounts[selectAcc].GetStatus())//ак заблокований
        cout << "This account is lock!\n";
    else
    {
        while (ListAccounts[selectAcc].GetStatus() == false)
        {
            cout << "Enter Pin-> ";
            string pin;
            cin >> pin;
            if (ListAccounts[selectAcc].EnterPin(pin))
                break;
            else if (ListAccounts[selectAcc].GetStatus())
            {
                cout << "This Account LOCKED\n";
                return;
            }
            else
                cout << "Pin Not Correctl! Attempts left " << 3 - ListAccounts[selectAcc].GetPinCout() << endl;
        }

        short s;
        while (true)
        {
            cout << "1. Withdraw money\n"
                << "2. Top up the balance\n"
                << "3. Show balance\n"
                << "0. Back\n";
            cin >> s;

            switch (s)
            {
            case 1:
            { 
                double sum = 0.0;
                cout << "Enter the amount you want to withdraw -> ";
                cin >> sum;
                ListAccounts[selectAcc].SetBalance(sum);
                break;
            }
            case 2:
            {  
                double sumRep = 0.0;
                cout << "Replenish the balance of -> ";
                cin >> sumRep;
                ListAccounts[selectAcc].SetBalance((sumRep * -1));
                break; 
            }
            case 3:
                cout << "Your balance: " << ListAccounts[selectAcc].GetBalance() << endl;
                break;
            case 0:
                system("cls");
                MainMenu();
            }
        }
    }
}

void CreateAccount()
{
    cout << "   CREATE ACCOUNT \n";

    string valuta = "";
    string pin = "0000";
    double balance = 0;
    cout << "Enter Valuta -> ";
    cin >> valuta;

    while (true)
    {
        string f_pin; 
        string s_pin;
        cout << "Enter Pin -> ";
        cin >> f_pin;
        cout << "Confirm Pin -> ";
        cin >> s_pin;
        if (f_pin == s_pin) {
            pin = s_pin;
            break;
        }
        else
            cout << "Passwords do not match!\n";
    }

    cout << "Enter Account Balance -> ";
    cin >> balance;

    Account newAccaunt(valuta, pin);
    newAccaunt.SetBalance(balance);
    newAccaunt.SetNumber(GenNumber());
    ListAccounts.push_back(newAccaunt);
    cout << "Accaunt Added!\n";
}

void ShowAccounts()
{
    cout << "List Accaunt: " << endl;
    for (Account ac : ListAccounts)
    {
        if (ac.GetStatus()) {
            SetBackgroundColor(0,12);
            cout << "LOCKED ";
        }
        else
            cout << "       ";

        cout << "# " << ac.GetFullNumber() << " Balance: " << ac.GetBalance()<< " " << ac.GetValuta() << endl;
        SetBackgroundColor(15,0);
    }
}

/// <summary>
/// генерація унікаьного номера рахунка
/// </summary>
int GenNumber()
{
    unsigned int number = rand() % 100000000;
        for (Account account : ListAccounts)
        {
            if (account.GetNumber() == number)
            { 
                return GenNumber();
            }
        }
        return number;
}

void SetBackgroundColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void CreateDefoultTestAccount()
{
    Account newAccaunt1("PLZ", "0000");
    newAccaunt1.SetBalance(2500);
    newAccaunt1.SetNumber(1);
    ListAccounts.push_back(newAccaunt1);

    Account newAccaunt("BTC", "0000");
    newAccaunt.SetBalance(1000);
    newAccaunt.SetNumber(99999999);
    newAccaunt.SetStatus(true);
    ListAccounts.push_back(newAccaunt); 
}