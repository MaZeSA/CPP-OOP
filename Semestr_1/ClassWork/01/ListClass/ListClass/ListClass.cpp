#include "List.h"
#include <ctime>

int main()
{
    srand((unsigned int)time(0));

    List list;

    cout << "Create list ...\n";
    for (int i = 0; i < 8; i++)
        list.addToHead(rand() & 20);

    list.Print();

    cout << "\nAdd New Element To Head:*\n";
    list.addToHead(rand() & 20);
    list.Print();
    
    cout << "\nAdd New Element To Tail:\n";
    list.AddTail(rand() & 20);
    list.Print();  
    
    cout << "\nInsent New Element To Random Index:* ";
    int val = rand() & 20, index = 1 + rand() % 8;
    cout << " index= " << index << " value= " << val<< endl;
    list.insByInde(val, index);
    list.Print();

    cout << "\nDelete Element From Head:\n";
    list.DeleteHead();
    list.Print();   
    
    cout << "\nDelete Element From Tail*:\n";
    list.delFromTail();
    list.Print();

    cout << "\nDelete Element From Random Index*: ";
    index = 1 + rand() % 8;
    cout << " index= " << index << endl;
    list.delByIndex(index);
    list.Print();

    cout << "\nSearh Elements*: \n";
    for (int i = 0; i < 5; i++)
    {
         val = val = rand() & 20;
         cout << "  -Searh ("<< val <<")" << " result index= " << list.searchByValue(val) <<endl;
    }

    system("pause");
    list.Clear();
}
