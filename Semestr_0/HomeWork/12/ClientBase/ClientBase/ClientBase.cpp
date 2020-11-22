
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

const int Max_client = 5; //Максимальна кількість клієнтів
int BaseID[Max_client][1] = { 0 };//База ID, для того щоб кожен клієнт мав унікальній идентифікатор, не залежно від індексу в списку
int CountClient = -1; //Кількість клієнтів

struct Client
{
    int Id = -1;
    string LastName = "";
    string Name = "";
    int Age = -1;
    string Phone = "";

    void GetID()//Функція видає перший вільний ідентифікатор
    {
        for(int i=0; i< Max_client;i++)
            if (BaseID[i][0] == 0)
            {
                Id = i;
                BaseID[i][0] = 1;//резервуємо ид
                break;
            }
        CountClient++;
    }
};

Client ListClient[Max_client];
/// <summary>
/// Додати клієнта
/// </summary>
void AddClient();
/// <summary>
/// Створення клієнтів то дефолту
/// </summary>
void CreteDefoultClients();
/// <summary>
/// Показати дані клієнта
/// </summary>
void ShowClient(Client);
/// <summary>
/// Пошук клієнта, по одному чи кількох введених данних
/// </summary>
void SearchClient();
/// <summary>
/// Редагувати клієнта
/// </summary>
void EditClient(int); 
/// <summary>
/// Видалити клієнта
/// </summary>
void DeleteClient();


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CreteDefoultClients();

    int action = -1;
    do
    {
        cout << "В базі: " << CountClient+1 << " клієнтів\n\n"
            << "0. Віхід\n"
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
            break;
        }
        case 2: {
            cout << "Пошук клієнта:\n";
            SearchClient();
            break;
        }  
        case 3: { 
            DeleteClient();
            break;
        }
        case 4: {
            cout << "Зміна даних клієнта:\n" << "Введіть Id клієнта " << "->_";
            int id = -1;
            cin >> id;
            EditClient(id);
            break;
        }
        case 5: {
            for (Client* i = ListClient; i != ListClient + CountClient + 1; i++)//через вказівник, для практики
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
    cout << "------Дані клієнта----------\n";
    cout << "id = " << Client.Id << endl;
    cout << Client.LastName << " " << Client.Name << "\n";
    cout << Client.Phone << "\n";
    cout << Client.Age << " років\n\n";
}
void AddClient()
{ 
    if (CountClient == Max_client - 1)
    {
        cout << "Досягнута максимальна кількість клієнтів!\n\n";
        return;
    }
    Client client;
    cin.ignore();
    cout << "Вкажіть прізвище: "; getline(cin, client.LastName);
    cout << "Вкажіть ім'я: "; getline(cin, client.Name);
    cout << "Вкажіть телефон: "; getline(cin, client.Phone);
    cout << "Вкажіть вік: "; cin >> client.Age;
    client.GetID();//отримуємо унікальний ид
    ListClient[CountClient] = client;

    cout << "Клієнта успішно додано!\n\n";
}
void EditClient(int Id)
{
    if (CountClient < 1) {
        cout << "В базі немає клієнтів\n";
        return;
    }

    for(Client &client: ListClient)
        if (client.Id == Id)
        {
            cin.ignore();
            string temp;
            cout << "\nВкажіть прізвище: "; getline(cin, temp);
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
                client.Age = stoi(temp);//Конвертація стрінга і число
            else
                cout << "Збережено попередне значення: " << client.Age << endl << endl;

            break;
        }
}
void DeleteClient()
{ 
    if(CountClient <1){
        cout << "В базі немає клієнтів\n";
        return;
    }

    cout << "Видалення клієнта:\n" << "Введіть Id клієнта " << "->_";
    int Id = -1;
    cin >> Id;

    for (Client &client: ListClient)
        if (client.Id == Id)
        {
            client = ListClient[CountClient];//Видаляємого клієнта заміняємо останім клієнтом, був варіант для виводу клієнтів, по порядку ид, здвинути усі, та при тисячах клієнтів цей варіант буде працювати найшвидше
            BaseID[Id][0] = 0;//звільняємо id
            CountClient--;
            break;
        }
    cout <<"Клієнта ID="<< Id<< " Успішно видалено\n\n";
}
void SearchClient()
{
    cin.ignore();
    string lastName = "";
    cout << "\nВкажіть прізвище: "; getline(cin, lastName);
    string name = "";
    cout << "\nВкажіть ім'я: "; getline(cin, name);
    string phone = "";
    cout << "\nВкажіть телефон: "; getline(cin, phone);

    int suma = 0;//вхідна сума пошуку, в залежності від введених даних для пошуку (імя, фамілія, номер) значення суми завжди буде унікальне, в подальшому це дозволить не писати купу if else
    if (!lastName.empty())
        suma = +1;//введено фамілію для пошуку
    if (!name.empty())
        suma = +2;//введено імя для пошуку
    if (!phone.empty())
        suma = +4;//введено телефон для пошуку

    int foundCount = 0;//кількість знайдених
    if (suma > 0)
        for (int i = 0; i < CountClient; i++)
        {
            int resultSuma = 0;//вихідна сума пошуку
            if (!lastName.empty())
                if (ListClient[i].LastName == lastName)
                    resultSuma = +1;//введенна фамілія співпала
            if (!name.empty())
                if (ListClient[i].Name == name)
                    resultSuma = +2;//введенне імя співпало
            if (!phone.empty())
                if (ListClient[i].Phone == phone)
                    resultSuma = +4;//введений номер співпав

            if (resultSuma == suma) //всі введені дані співпали з данними клієнта
            {
                ShowClient(ListClient[i]);
                foundCount++;
            }
        }
    cout << "Знайдено: " << foundCount << endl << endl;
}

void CreteDefoultClients()
{
    Client client; 
    client.LastName = "Пупкін";
    client.Name = "Валєра";
    client.Phone = "+380974523789";
    client.Age = 22;
    client.GetID();
    ListClient[CountClient] = client;

    Client client1;
    client1.LastName = "Копиця";
    client1.Name = "Жора";
    client1.Phone = "+380674590709";
    client1.Age = 33;
    client1.GetID();
    ListClient[CountClient] = client1;
   
}

