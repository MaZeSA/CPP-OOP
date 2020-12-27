#include <iostream>

using namespace std;

class Book
{
private:
    string name="";
    string publishing="";
    string autor="";
    double price=0.0;
    bool bookNew=false;
public:

    Book() { }
    Book(string _name, string _publishing, string _autor, double _price)
    {
        this->name = _name;
        this->publishing = _publishing;
        this->autor = _autor;
        this->price = _price;
    }

    void Print()
    {
        cout << name << "   " << publishing << "   " << autor << "   " << price << endl;
    }
    double GetPrice()
    {
        return this->price;
    }
    void SetOld(bool _old)
    {
        this->bookNew = _old;
    }
    bool GetOld()
    {
        return this->bookNew;
    }
    Book* CreateNew()
    {
        cout << "Enter Name-> ";
        cin >> this->name;
        cout << "Enter Publishing-> ";
        cin >> this->publishing; 
        cout << "Enter Autor-> ";
        cin >> this->autor;
        cout << "Enter Price-> ";
        cin >> this->price;

        return this;
    }
};
class Megazine
{
private:
    string name="";
    double price=0.0;
    bool bookNew=false;
public:

    Megazine() {}
    Megazine(string _name, double _price)
    {
        this->name = _name;
        this->price = _price;
    }

    void Print()
    {
        cout << name << "   "  << price<< endl;
    }
    double GetPrice()
    {
        return this->price;
    } 
    void SetOld(bool _old)
    {
        this->bookNew = _old;
    }   
    bool GetOld()
    {
        return this->bookNew;
    }   
    Megazine* CreateNew()
    {
        cout << "Enter Name-> ";
        cin >> this->name;
        cout << "Enter Price-> ";
        cin >> this->price;

        return this;
    }
};
class Audio
{
private:
    string name="";
    string performer="";
    int trackCount = 0;
    double price=0.0;
    bool bookNew=false;
public:
   
    Audio() {  }
    Audio(string _name, string _performer, int _trackCount, double _price)
    {
        this->name = _name;
        this->performer = _performer;
        this->trackCount = _trackCount;
        this->price = _price;
    }

    void Print()
    {
        cout << name << "   " << performer << "   " << price<<endl;
    }
    double GetPrice()
    {
        return this->price;
    }
    void SetOld(bool _old)
    {
        this->bookNew = _old;
    }
    bool GetOld()
    {
        return this->bookNew;
    }
    Audio *CreateNew()
    {
        cout << "Enter Name-> ";
        cin >> this->name;
        cout << "Enter Performer-> ";
        cin >> this->performer;
        cout << "Enter Track Count-> ";
        cin >> this->trackCount;
        cout << "Enter Price-> ";
        cin >> this->price;
        return this;
    }
};

template<typename T>
class CShop
{
private:
    T* value;
    int count = 0;
public:
    CShop(int count)
    {
        this->count = count;
        this->value = new T[count];
    };
    //інформація про всіх
    void ShowAllInfo()
    {
        for (int i = 0; i < this->count; i++)
        {
            value[i].Print();
        }
    }
    //найбільша ціна
    void GetBigPrice()
    {
        T item = value[0];
        for (int i = 1; i < this->count; i++)
        {
            if (value[i].GetPrice() > item.GetPrice())
                item = value[i];
        }
        cout << "Big Price:\n";
        item.Print();
    }
    //найменьша ціна
    void GetLittlePrice()
    {
        T item = value[0];
        for (int i = 1; i < this->count; i++)
        {
            if (value[i].GetPrice() < item.GetPrice())
                item = value[i];
        }
        cout << "Little Price:\n";
        item.Print();
    }
    //середня ціна
    void GetArithmeticMeanPrice()
    {
        double priceall = 0;
        for (int i = 0; i < this->count; i++)
        {
            priceall += value[i].GetPrice();
        }
        cout << "Arithmetic mean price:\n"
            << priceall / this->count;
    }
    //Показати нові елементи
    void ShowNewItem()
    {
        cout << "List new elements:\n";
        for (int i = 0; i < this->count; i++)
        {
            if (value[i].GetOld())
                value[i].Print();
        }
    }
    //сортування
    void SortToPrice()
    {
        for (int i = 1; i < count; i++)
            for (int j = i; j > 0 && value[j - 1].GetPrice() > value[j].GetPrice(); j--)
                swap(value[j - 1], value[j]);
    }
    //добавити новий
    void AddNew(T &_item)
    {
        T* newMas = new T[this->count + 1];
        for (int i = 0; i < this->count; i++)
            newMas[i] = value[i];

        _item.SetOld(true);
        newMas[this->count] = _item;

        delete[] value;
        value = newMas;
        this->count++;
    }
    T* GetMas()
    {
        return value;
    }

    ~CShop()
    {
        delete[] value;
    }
};

//Бібліотека для прикладу
void CreateDefoultLibs(CShop<Book> &book, CShop<Megazine> &megazine, CShop<Audio> &audio)
{
    book.GetMas()[0] = *(new Book("Dune", "Sandora", "Frenk Garbert", 132.0));
    book.AddNew(*(new Book("Harry Potter", "Sandora", "Joanne Rowling", 99.99))); 
    
    megazine.GetMas()[0] = *(new Megazine("Fishing",  2.10));
    megazine.AddNew(*(new Megazine("PlayBoy ", 5.99)));

    audio.GetMas()[0] = *(new Audio("Splin", "New Human", 11, 72.0));
    audio.AddNew(*(new Audio("NANSI & SIDOROV", "Kaver", 15, 59.90)));
}

int Menu()
{
    cout<< "1. Book\n"
        << "2. Megazine\n"
        << "3. Audio\n";
    int c = 0;
    cin >> c;
    return c;
}

int main()
{
    CShop <Book> book(1);
    CShop <Megazine>megazine(1);
    CShop <Audio>audio(1);
    CreateDefoultLibs(book, megazine, audio);
 
    int c = 1; 
    short m = 0;
    while (c)
    {
        cout << "\n1. Show\n"
            << "2. Show Most Price\n"
            << "3. Show Least Price\n"
            << "4. Show Arithmetic Mean Price\n"
            << "5. Add new Items\n"
            << "6. Show New Items\n"
            << "7. Sort\n"
            << "0. Exit\n";

        cin >> c;

        switch (c)
        {

        case 1:
        {
            m = Menu();
            if (m == 1)
                book.ShowAllInfo();
            else if (m == 2)
                megazine.ShowAllInfo();
            else
                audio.ShowAllInfo();
            break;
        }  
        case 2:
        {
            m = Menu();
            if (m == 1)
                book.GetBigPrice();
            else if (m == 2)
                megazine.GetBigPrice();
            else
                audio.GetBigPrice();
            break;
        }   
        case 3:
        {
            m = Menu();
            if (m == 1)
                book.GetLittlePrice();
            else if (m == 2)
                megazine.GetLittlePrice();
            else
                audio.GetLittlePrice();
            break;
        }    
        case 4:
        {
            m = Menu();
            if (m == 1)
                book.GetArithmeticMeanPrice();
            else if (m == 2)
                megazine.GetArithmeticMeanPrice();
            else
                audio.GetArithmeticMeanPrice();
            break;
        }   
        case 5:
        {
            m = Menu();
            if (m == 1)
                book.AddNew(*(new Book())->CreateNew());
            else if (m == 2)
                megazine.AddNew(*(new Megazine())->CreateNew());
            else
                audio.AddNew(*(new Audio())->CreateNew());
          
            cout << "OK!\n";
            break;
        }
        case 6:
        {
            m = Menu();
            if (m == 1)
                book.ShowNewItem();
            else if (m == 2)
                megazine.ShowNewItem();
            else
                audio.ShowNewItem();
            break;
        }    
        case 7:
        {
            m = Menu();
            if (m == 1)
                book.SortToPrice();
            else if (m == 2)
                megazine.SortToPrice();
            else
                audio.SortToPrice();

            cout << "OK!\n";
            break;
        }
        }
    }
}
//метод для сортування елементів масиву по зростанню або спаданню(наприклад, по ціні; на 12 балів);
//метод для пошуку середнього арифметичного всіх елементів масиву;
//перенавантажити оператор індексування.
