#include "List.h"

List::List()
{
	pHead = pTail = NULL;
	count = 0;
}

List::~List()
{
	Clear();
}

void List::Print() const
{
	Node* temp = pHead;

	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->pNext;
	}
	cout << endl;
}

void List::addToHead(int value)
{
	Node* forAdd = new Node;
	forAdd->value = value; 
	forAdd->pNext = NULL;

	if (pHead != NULL)
	{
		forAdd->pNext = pHead;
		pHead = forAdd;
	}
	else pHead = pTail = forAdd;

	count++;
}
void List::AddTail(int value)
{
	Node* forAdd = new Node;
	forAdd->value = value; 
	forAdd->pNext = NULL; 

	if (pHead != NULL)
	{
		pTail->pNext = forAdd;
		pTail = forAdd; 
	}
	else pHead = pTail = forAdd;

	count++;
}

void List::DeleteHead()
{
	Node* temp = pHead;
	if (pHead != NULL)
	{
		pHead = pHead->pNext;
	}

	count--;

	delete temp;
}
void List::delFromTail()
{
	if (pHead == NULL) return;

	Node* temp = pTail;
	
	if (count > 2)
	{
		Node* newTail = &(*this)[count - 1];
		newTail->pNext = NULL;
		pTail = newTail;
	}
	else
	{
		pHead->pNext = NULL;
		pTail = pHead;
	}

	count--;

	delete temp;
}
void List::delByIndex(const int index)
{
	if (pHead == NULL) return;

	Node* temp = &(*this)[index];

	if (pTail == temp)
		delFromTail();
	else if (pHead == temp)
		DeleteHead();
	else
	{
		Node* before = &(*this)[index-1];
		before->pNext = temp->pNext;
	}

	count--;
}

void List::insByInde(const int value, const int index)
{
	if (index == 0)
		addToHead(value);
	else if (index == count - 1)
		AddTail(value);
	else if (index >= 0 && index <= count - 1)
	{
		Node* newNode = new Node;
		newNode->value = value;

		newNode->pNext = &(*this)[index];
		(*this)[index-1].pNext = newNode;
	}
}

int List::searchByValue(int value)
{
	Node* temp = pHead;
	int ReturnIndex = -1;
	
	while (temp->pNext)
	{
		ReturnIndex++;
		if (value == temp->value)
			return ReturnIndex;
	
		temp = temp->pNext;
	}
	return -1;
}

int List::GetCount() const
{
	return count;
}

void List::Clear()
{
	while (pHead)
	{
		DeleteHead();
	}

	count = 0;
}

Node& List::operator[](const int index)
{
	Node* temp = pHead;
	int ReturnIndex = 0;
	while (temp)
	{
		if (ReturnIndex == index)
			return *temp;
		
		ReturnIndex++;
		temp = temp->pNext;
	}

	throw ("Array index out of bounds");
}
