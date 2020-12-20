
#include <iostream>
using namespace std;

enum class  TypeRoom
{
    kitchen = 1,
    livingRoom = 2,
    bedroom = 3,

    room = 0
};

class House
{
public:
    class Room
    {
    private:
        double width = 0.0;
        double lenght = 0.0;
        int storey = 0;
        TypeRoom type = TypeRoom::room;
    public:
        Room()
        {}
        Room(TypeRoom _type)
        {
            SetWidth(10);
            SetLenght(8);
            SetStorey(1);
        }
        void SetWidth(double _width)
        {
            this->width = _width;
        }
        double GetWidth()
        {
            return this->width;
        } 
        void SetLenght(double _lenght)
        {
            this->lenght = _lenght;
        }
        double GetLenght()
        {
            return this->lenght;
        }
        void SetStorey(int _storey)
        {
           this->storey = _storey;
        }
        int GetStorey()
        {
            return this->storey;
        }

        double GetPRum()
        {
            return width * lenght;
        }
        void Print()
        {
            cout << "Room\n"
                << "Storey - " << this->storey << endl
                << "Size: " << this->lenght << "x" << this->width << " P=" << this->GetPRum() << endl;
        }
        void CreateRoom()
        {
            cout << "  Make room\n"
                << "Select type room: \n"
                << "1. Kitchen\n"
                << "2. Living Room\n"
                << "3. Bedroom \n"
                << "0. Room\n";
            short c=0;
            if (c >= 0 && c <= 3)
                this->type = (TypeRoom)c;

            SetSize();
            int temp = 0;
            cout << "  Enter Storey -> ";
            cin >> temp;
            this->SetStorey(temp);
        }
        void SetSize()
        {
            double temp = 0.0;
            cout << "  Enter Width -> ";
            cin >> temp;
            this->SetWidth(temp);

            cout << "  Enter Lenght -> ";
            cin >> temp;
            this->SetLenght(temp);
        }
        void SetType(TypeRoom _type)
        {
            this->type = _type;
        }  
        TypeRoom GetType()
        {
            return this->type;
        }
    };
    House(int _roomCount, int _storey)
    {
        this->countRoom = _roomCount;
        this->countStorey = _storey;
        rooms = new Room[_roomCount];
        kitchen = new Room(TypeRoom::kitchen);
        rooms[0] = *kitchen;

        for (int i = 1; i < _roomCount; i++) //Випадково вибераємо поверх, тип кімнати, розмір 
        {
            rooms[i].SetStorey(1 + rand() % _storey);
            rooms[i].SetLenght(2 + rand() % 10);  
            rooms[i].SetWidth(2 + rand() % 10);
            rooms[i].SetType((TypeRoom)(rand() % 4));
        }
    }
    ~House()
    {
        delete[]  kitchen;  
        delete[]  rooms;
    }
    void ShowInfo()
    {
        cout << " House:\n"
            << "Count Storey -> " << this->countStorey << endl
            << "Count Room -> " << this->countRoom-1 << endl
            << "Kitchen -> 1\n";
    }
    int totalRoomsSquare()
    {
        int result = 0;
        for (int i = 0; i < countRoom; i++)
            result += (int)rooms[i].GetPRum();
        return result;
    }
    int levelRoomsSquare(int _level)
    {
        int result = 0;
        for (int i = 0; i < countRoom; i++)
          if(rooms[i].GetStorey() == _level)
              result += (int)rooms[i].GetPRum();

        return result;
    }
    void ChangeSize(int _room)
    {
        rooms[_room].SetSize();
    }
    void ShowRoomInStorey(int _level)
    {
        int bedroomCount = 0;
        int count = 0;
        for (int i = 0; i < countRoom; i++)
        {
            if (rooms[i].GetStorey() == _level)
                count++;
            if (rooms[i].GetType() == TypeRoom::bedroom)
                bedroomCount++;
        }
        cout << "Room in Storey -> " << count << endl
            << "Bedroom in Storey ->" << bedroomCount << endl;
    }
private:
     Room* rooms;
     Room* kitchen=NULL;
    int countRoom = 0;
    int countStorey = 0;
};


int main()
{
    int storey = 0;
    int rooms = 0;
    cout << "Create House\n"
        << "Enter Storey -> ";
    cin >> storey;  
    
    cout << "Enter Rooms -> ";
    cin >> rooms;

    House house(rooms, storey);
    system("cls");

    short c = 0;
    while (true)
    {
        cout << "1. Room info\n"
            << "2. Room in Storey\n"
            << "3. Total Rooms Square\n"
            << "4. Level Rooms Square\n"
            << "5. Change room\n"
            << "6. Change kitchen\n"
            << "0. Exit\n";

        cin >> c;

        switch (c)
        {
        case 1:
            house.ShowInfo();
            break; 
        case 2:
            cout << "Select Storey -> ";
            cin >> c;
            house.ShowRoomInStorey(c);
            break; 
        case 3:
            cout << "    value -> "<<  house.totalRoomsSquare() << endl;
            break; 
        case 4:    
            cout << "Select Storey -> ";
            cin >> c;
            cout << "    value -> " << house.levelRoomsSquare(c) << endl;
            break; 
        case 5:
            cout << "Select Room for change -> ";
            cin >> c;
            house.ChangeSize(c);
            break; 
        case 6:
            house.ChangeSize(0);
            break;  
        case 0:
            exit(0);
        }
    }
}

//вивід інформації про кімнати на заданому поверсі
////Перевірити роботу класу.
//виведення інформації про кімнати будинку 
//обчислення сумарної площі кімнати int totalRoomsSquare()
//обчислення площі кімнат на певному поверсі int levelRoomsSquare(int level)
//зміна розмірів певної кімнати(за номером у масиві кімнат)
//зміна розмірів кухні
//вивід інформації про кімнати на заданому поверсі
