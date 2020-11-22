#include <Windows.h>
#include <iostream>
#include <ctime>
using namespace std;

string* first1()
{
    string* first = new string[5];
    first[0] = "77";
    first[1] = "";
    first[3] = "733";
    first[4] = "555";
    return first;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    string* first = first1();

    int u = first->length();

}

