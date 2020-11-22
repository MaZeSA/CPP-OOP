
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
void AddClient();
void CreteDefoultClients();
void ShowClient(Client Client);
void SearchClient(string Data);
void EditClient(int Id); 
void DeleteClient(int Id);


struct Client
{
    int Id = -1;
    string LastName = "";
    string Name = "";
    int Age = -1;
    string Phone = "";

    void DeleteMe()
    {
        int Id = -1;
        string LastName = "";
        string Name = "";
        int Age = -1;
        string Phone = "";
    };

    void GetID()
    {
        for(int i=0; i< Max_client;i++)
            if (BaseID[i][0] == 0)
            {
                Id = i;
                BaseID[i][0] = 1;
            }
    }

};


const int Max_client = 3;
int CurrentIndex = -1; 
Client ListClient[Max_client];

int BaseID[Max_client][1] = { 0 };




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CreteDefoultClients();

    int action = -1;
    do
    {
        cout << "0. Віхід\n"
            << "1. Додати клієнта\n"
            << "2. Знайти клієнта\n"
            << "3. Видалити клієнта\n"
            << "4. Змінити дані клієнта\n"
            << "5. Показати усіх клієнтів\n"
            << "->_";

        cin >> action;

        switch (action)
        {
        case 0: {
            break;
        }
        case 1: {
            AddClient();
        }
        case 2: {
            string data = "";
            getline(cin, data);
            SearchClient(data);
            break;
        }  
        case 3: { 
            cout << "Введіть Id клієнта\n" << "->_";
            int id = -1;
            cin >> id;
            DeleteClient(id);
            break;
        }
        case 4: {
            cout << "Введіть Id клієнта\n" << "->_";
            int id = -1;
            cin >> id;
            EditClient(id);
            break;
        }
        case 5: {
            for (Client* i = ListClient; i != ListClient + CurrentIndex + 1; i++)
                ShowClient(*i);
            break;
        }
        default:
            break;
        }

    } while (action != 0);
}
void ShowClient(Client Client)
{
    cout << "------Client info----------\n";
    cout << "id = " << Client.Id << endl;
    cout << Client.LastName << " " << Client.Name << "\n";
    cout << Client.Phone << "\n";
    cout << Client.Age << " років\n\n";
}

void AddClient()
{
    Client client = ListClient[CurrentIndex++];
    cin.ignore();
    cout << "Вкажіть прізвище: "; getline(cin, client.LastName);
    cout << "Вкажіть ім'я: "; getline(cin, client.Name);
    cout << "Вкажіть телефон: "; getline(cin, client.Phone);
    cout << "Вкажіть вік: "; cin >> client.Age;
    client.Id = CurrentIndex;
}
void EditClient(int Id)
{
    cout << "Зміна данних клієнта ID=" << Id << endl;

    for(Client &client: ListClient)
        if (client.Id == Id)
        {
            cin.ignore();
            string temp;

            cout << "Вкажіть прізвище: "; getline(cin, temp);
            if (!temp.empty())
                client.LastName = temp;
            else
                cout << "Збережено попередне значення: " << client.LastName << endl;

            cout << "Вкажіть ім'я: "; getline(cin, temp);
            if (!temp.empty())
                client.Name = temp;
            else
                cout << "Збережено попередне значення: " << client.Name << endl;

            cout << "Вкажіть телефон: "; getline(cin, temp);
            if (!temp.empty())
                client.Phone = temp;
            else
                cout << "Збережено попередне значення: " << client.Phone << endl;

            cout << "Вкажіть вік: "; getline(cin, temp);
            if (!temp.empty())
                client.Age = stoi(temp);
            else
                cout << "Збережено попередне значення: " << client.Age << endl;

            break;
        }
}

void DeleteClient(int Id)
{
    for (Client client: ListClient)
        if (client.Id == Id)
        {
            for (int j = client.Id; j <= CurrentIndex; j++)
            {
                if (ListClient[j + 1].Id == 0)
                    ListClient[j].DeleteMe();
                else
                {
                    ListClient[j] = ListClient[j + 1];
                    ListClient[j].Id--;
                }
            }
            CurrentIndex--;
            break;
        }
}

void SearchClient(string Data)
{ 
    //string strSplit = Data;

    //string* result = new string[countSplit];
    //for (int i = 0; i < countSplit; i++)
    //{
    //    int t = strSplit.find(ch); //пошук о символа
    //    result[i] = strSplit.substr(0, t); //копія строки до символа
    //    strSplit.erase(0, t + 1);//видалення строки разом з символом
    //}

    //for (Client client : ListClient)
    //    if (client.Name == Data ||client.LastName == Data|| client.Phone== Data)
    //    {
    //        cout << "Результати пошуку: " << endl;
    //        ShowClient(client);
    //    }
}
//
//string* Split(const string str, char ch)
//{
// /*   countSplit = GetCountSplit(str, ch);
//  
//    return result;*/
//}

void CreteDefoultClients()
{
    Client client; 
    client.LastName = "Пупкін";
    client.Name = "Валєра";
    client.Phone = "+380974523789";
    client.Age = 22;
    client.Id = ++CurrentIndex; 
    ListClient[CurrentIndex] = client;

    Client client1;
    client1.LastName = "Копиця";
    client1.Name = "Жора";
    client1.Phone = "+380674590709";
    client1.Age = 33;
    client1.Id = ++CurrentIndex;
    ListClient[CurrentIndex] = client1;
    
    Client client12;
    client12.LastName = "К222опиця";
    client12.Name = "Жо22222222ра";
    client12.Phone = "+3222222280674590709";
    client12.Age = 323;
    client12.Id = ++CurrentIndex;
    ListClient[CurrentIndex] = client12;
}

