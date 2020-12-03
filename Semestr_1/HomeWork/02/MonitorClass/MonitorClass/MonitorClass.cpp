#include <string>
#include <iostream>
using namespace std;

class Monitor
{
public:

    Monitor()
    {
    }
    Monitor(double screenSize, string name, double price)
    {
        this->screenSize = screenSize;
        this->name = name;
        this->price = price;
    }

    void Print()
    {
        cout << "Monitor: " << name << endl
            << "Resolution: " << resolution[0] << "x" << resolution[1] << endl
            << "Size: " << screenSize << endl
            << "Color Rendering: " << colorRendering << endl
            << "Contrast: " << contrast << endl
            << "Frequency: " << frequency << endl
            << "Price: " << price << endl;
    }

    double GetScreenSize()
    {
        return this->screenSize;
    }
    void SetScreenSize(double screenSize)
    {
        this->screenSize = screenSize;
    }  
    
    double GetPrice()
    {
        return this->price;
    }
    void SetPrice(double price)
    {
        this->price = price;
    }

    int* GetResolution()
    {
        return this->resolution;
    } 
    void SetResolution(int* resolution)
    {
        this->resolution[0] = resolution[0]; 
        this->resolution[1] = resolution[1];
    }

    int GetColorRendering()
    {
        return this->colorRendering;
    }
    void SetColorRendering(int colorRendering)
    {
        this->colorRendering = colorRendering;
    }

    string GetContrast()
    {
        return this->contrast;
    }
    void SetContrast(string contrast)
    {
        this->contrast = contrast; 
    }

    int GetFrequency()
    {
        return this->frequency;
    } 
    void SetFrequency(int frequency)
    {
        this->frequency = frequency;
    }

    string GetName()
    {
        return this->name;
    }   
    void SetName(string name)
    {
       this->name = name;
    }
 
    ~Monitor()
    {
    }


private:

    double screenSize = 14;  
    double price = 1000;
    int resolution[2] = { 800, 600 };
    int colorRendering = 32;
    string contrast = "1000:1";
    int frequency = 60;
    string name = "Monitor";
};

Monitor* CreateNewMonitor();
void MenuMonitor(Monitor&);
void ChangeParameters(Monitor& );

int main()
{
    Monitor monitor;
    MenuMonitor(monitor);
}

void MenuMonitor(Monitor& monitor)
{
    short s;
    while (true)
    {
        cout << "1. Show Data Monitor\n"
            << "2. Create Monitor\n"
            << "3. Change Parameters\n"
            << "0. Exit\n";
        cin >> s;

        switch (s)
        {
        case 1:
            system("cls");
            monitor.Print();
            break;
        case 2:
            system("cls");
          monitor = *CreateNewMonitor();
            break;
        case 3:
            system("cls");
            ChangeParameters(monitor);
            break;
        case 0:
            exit(0);
        }
    }
}

Monitor* CreateNewMonitor()
{
    cout << "Enter Name Monitor -> ";
    string name = "";
    cin >> name;
    cout << "Enter Size Monitor -> ";
    double size = 0;
    cin >> size;   
    cout << "Enter Price Monitor -> ";
    double price = 0;
    cin >> price;

    Monitor monitor(size, name, price);
    MenuMonitor(monitor);
    return &monitor;
}

void ChangeParameters(Monitor& monitor)
{
    short s;
    while (true)
    {
        cout << "1. Change Name\n"
            << "2. Change Screen Size \n"
            << "3. Change Resolutions\n" 
            << "4. Change Color Rendering\n"
            << "5. Change Contrast\n"
            << "6. Change Frequency\n"
            << "7. Change Price\n"
            << "0. Back\n";
        cin >> s;

        switch (s)
        {
        case 1:
        { 
              cout << "Enter New Name -> ";
              string name;
              cin >> name;
              monitor.SetName(name);
              system("cls");
              break;
        }
        case 2:
        {
            cout << "Enter New Screen Size -> ";
            int size;
            cin >> size;
            monitor.SetScreenSize(size);
            system("cls");
            break;
        }
        case 3:
        {
            cout << "Enter New Screen Width -> ";
            int width;
            cin >> width;
            cout << "Enter New Screen Height -> ";
            int height;
            cin >> height;
            int resolutions[2] = { width, height };
            monitor.SetResolution(resolutions);
            system("cls");
            break;
        }
        case 4:
        {
            cout << "Enter New Color Rendering -> ";
            int rColor;
            cin >> rColor;
            monitor.SetColorRendering(rColor);
            system("cls");
            break;
        }
        case 5:
        {
            cout << "Enter New Contrast -> ";
            string contrast;
            cin >> contrast;
            monitor.SetContrast(contrast);
            system("cls");
            break;
        }
        case 6:
        {
            cout << "Enter New Frequency-> ";
            int Frequency;
            cin >> Frequency;
            monitor.SetFrequency(Frequency);
            system("cls");
            break;

        }  
        case 7:
        {
            cout << "Enter New Price-> ";
            double price;
            cin >> price;
            monitor.SetPrice(price);
            system("cls");
            break;

        }
        case 0:
            system("cls");
            return;
        }
    }
}