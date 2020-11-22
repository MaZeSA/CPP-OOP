#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct User
{
    int id=0;
    string login;
    string password;
    string phone;
    string adress;
};

void Login(); 
void Registration();
string GetPassword(User);//встановлення, перевірка, зміна паролю
void UserEnterMenu(User);
void PersonalAccount(User);
void ChangePassword(User);
void ExitAccount();
void BackWait(User);//меню повернутись назад
void LoadBase();//загрузка бази
void SaveBase();//збереження бази

User BaseUsers[10];//база юзерів на 10 користувачів
int Count = 0;//кількість користувачів

int main()
{
    LoadBase();

    cout << "1. Login Enter\n"
        << "2. Registration\n"
        << "0. Exit\n";
    while (true)
    {
        int ans;
        cin >> ans;
        if (ans == 1)
            if (Count < 1)
                cout << "No Users!!!\n";
            else
            {
                Login();
                break;
            }
        else if (ans == 2)
        {
            Registration();
            break;
        }
        else if (ans == 0)
            exit(0);
    }
}

void Registration()
{
    system("cls");

    cout << "Registration\n";
    cout << "Enter login _> ";
    cin >> BaseUsers[Count].login;

    BaseUsers[Count].password = GetPassword(BaseUsers[Count]);
    cout << "Enter phone _> ";
    cin >> BaseUsers[Count].phone;
    cout << "Enter adress _> ";
    cin >> BaseUsers[Count].adress;
    BaseUsers[Count].id = Count;

    Count++;
    SaveBase();//збереження бази
    UserEnterMenu(BaseUsers[Count-1]);//авто вхід після реєстрації
}

void Login()
{
    system("cls");

    string login, password, phone;

    bool found = false;
    while (!found)
    {
        cout << "Enter login -> ";
        cin >> login;
        cout << "Enter password -> ";
        cin >> password;

        for (User us : BaseUsers)//пошук юзера в базі
            if (login == us.login && password == us.password)
            {
                UserEnterMenu(us);
                found = true;
                break;
            }
        if (!found)
            cout << "Data entered incorrectly!\n";
    }
}

string GetPassword(User user)
{
    string result;
    while (true)
    {    string pass, pass2;
    cout << "Enter password _> ";
    cin >> pass;
    cout << "Repeat password _> ";
    cin >> pass2;
        if (pass == pass2)
        {
            result = pass;
            break;
        }
        else
            cout << "Passwords do not match!\n";
    }
    return result;
}

void UserEnterMenu(User user)
{
    system("cls");

    cout << "Successful login! User ID=" << user.id << endl
        << "1. View personal account\n"
        << "2. Change password\n"
        << "0. Exit account\n";
    int i;
    cin >> i;
    if (i == 1)
        PersonalAccount(user);
    else if (i == 2)
        ChangePassword(user);
    else if (i == 0)
        ExitAccount();
}

void PersonalAccount(User user)
{
    system("cls");

    cout << user.id << " - Personal Account\n"
        << "Login: " << user.login << endl;
   
    cout << "Password: ";
    for (char c : user.password)//зірочки замість паролю
        cout << "*";

     cout<< "\nPhone: " << user.login << endl
        << "Adress: " << user.login << endl;
 
     cout << "0. Back\n";
    
     BackWait(user);
}

void ChangePassword(User user)
{
    system("cls");

    cout << "Change password\n";
    user.password = GetPassword(user);
    cout << "New password successfully set!\n"
        << "0. Back\n";
    BackWait(user);
}

void ExitAccount()
{
    system("cls");
    main();
}

void BackWait(User user)
{
    while (true)
    {
        int i;
        cin >> i;
        if (i == 0)
        {
            UserEnterMenu(user);
            break;
        }
    }
}

void LoadBase()
{
    ifstream fin("users.txt");
    if (fin.is_open())
    {
        while (fin >> BaseUsers[Count].login)
        {
            fin >> BaseUsers[Count].password >> BaseUsers[Count].phone >> BaseUsers[Count].adress;
            BaseUsers[Count].id = Count;
            Count++;
        }
    }
}

void SaveBase()
{
    ofstream file("users.txt");
    for (int i = 0; i < Count; i++)
    {
        file << BaseUsers[i].login << " " << BaseUsers[i].password << " " << BaseUsers[i].phone << " " << BaseUsers[i].adress << endl;
    }

    if (file.fail())
        cout << "Save Error!\n";
   
    file.close();
}