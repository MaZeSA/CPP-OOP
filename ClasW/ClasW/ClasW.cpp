
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:

    void SetX()
    {
        int temp;
        cout << "Enter X: ";
        cin >> temp;
        
        this->x = temp;
    }
    int GetX()
    {
        return x;
    } 
    
    void SetY()
    {
        int temp;
        cout << "Enter Y: ";
        cin >> temp;
        this->y = temp;
    } 
    int GetY()
    {
        return y;
    }
};


int main()
{
    Point newPoint;

    newPoint.SetX();
    newPoint.SetY();

    cout << "Point X=" << newPoint.GetX() << " | " << "Y=" << newPoint.GetY() << endl;;

    int temp;
    while (true)
    {
        cout << "Replase X - enter 0" << " | Y - enter 1" << endl;
        cin >> temp;
        if (temp == 0)
            newPoint.SetX();
        else if (temp == 1)
            newPoint.SetY();
        else
            exit(0);
        cout << "Point X=" << newPoint.GetX() << " | " << "Y=" << newPoint.GetY() << endl;;
    }
}
