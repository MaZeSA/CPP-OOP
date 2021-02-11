#pragma once
#include <string>
#include <deque> 
#include <iostream>
using namespace std;

class Library
{
public:
	class  Book
	{
	public:
		//Сортування по автору і назві
		bool operator<(const Book& b) const {
			return this->Autor + this->Name < this->Autor + b.Name;
		}

		string GetSetName(string); 
		string GetSetAutor(string);
		int GetSetNumber(int);
		bool GetIssuse();
		void SetIssuse(bool);
		void Print();
		void SetYer(int);
		int GetYer();
	
	private:
		string Name = "";
		string Autor = "";
		int Number = -1;
		bool Issue = false;
		int yer = 0;
	};
	void Add(Book*);
	void Addbook(Book*, string name_, string autor_, int yer_);
	Book* Search();
	void SearchAvtor();
	void BookToIssue(Book*);
	void BookToBack(Book*);
	void Sort();
	void RemoveBook();
	void EditBook(); 
	void ShowAll();
	Book* GetBookNum();
	~Library();
private:
	
	deque<Book> listBook;
};
