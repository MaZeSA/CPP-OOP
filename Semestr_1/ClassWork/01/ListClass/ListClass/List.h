#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* pNext;
};

class List
{
	Node* pHead; 
	Node* pTail; 
	int count;

public:
	List();
	~List();

	void addToHead(int);
	void AddTail(int value);

	void DeleteHead();
	void delFromTail();
	void delByIndex(const int);

	void insByInde(const int value ,const int);

	int searchByValue(int value);

	int GetCount() const;
	void Clear();	
	void Print() const;

	Node& operator[](const int);
};
