#include "Library.h"
#include <algorithm>  
string Library::Book::GetSetName(string name_)
{
	if (name_ != "")
		this->Name = name_;

		return this->Name;
}
string Library::Book::GetSetAutor(string autor_)
{
	if (autor_ != "")
		this->Autor = autor_;

	return this->Autor;
}
int Library::Book::GetSetNumber(int num_)
{
	if (num_ != -1)
		this->Number = num_;

	return this->Number;
}
bool Library::Book::GetIssuse()
{
	return this->Issue;
}
void Library::Book::SetIssuse(bool i_)
{
	this->Issue = i_;
}

void Library::Book::Print()
{
	string Issued = "";
	(GetIssuse() == true) ? Issued = " Issued " : Issued = " In place ";

	cout << this->Autor << " | " << this->Name <<" | "<<  this->yer << " | " << Issued  << " | #" << this->Number << endl;
}

void Library::Book::SetYer(int y_)
{
	this->yer = y_;
}
int Library::Book::GetYer()
{
	return this->yer;
}

void Library::Add(Book* book)//додавання або редагування книжки
{
	cin.ignore();
	string name, autor;
	cout << "Enter Name Book ->";
	getline(cin, name);

	cout << "Enter Autor Book ->";
	getline(cin, autor);

	int yer = 0;
	cout << "Enter Yer Book ->";
	cin >> yer;

	Addbook(book, name, autor, yer);

	Sort();
}
void Library::Addbook(Book* book, string name_, string autor_, int yer_)
{
	if (book == nullptr)
		book = new Book();
	
	book->GetSetName(name_);
	book->GetSetAutor(autor_);
	book->SetYer(yer_);
	
	if (book->GetSetNumber(-1) == -1)
	{
		book->GetSetNumber(listBook.size());
		listBook.push_back(*book);
	}
}

Library::Book* Library::Search()
{
	cin.ignore();
	string name_, autor_;
	cout << "Enter Name Book ->";
	getline(cin, name_);
	cout << "Enter Autor Book ->";
	getline(cin, autor_);

	for (Book& b : listBook)
	{
		if (b.GetSetName("") == name_ && b.GetSetAutor("") == autor_)
			return &b;
	}
	return nullptr;
}
void Library::SearchAvtor()
{
	string autor_;
	cout << "Enter Autor Book ->";

	cin.ignore();
	getline(cin, autor_);

	for (Book& b : listBook)
	{
		if (b.GetSetAutor("") == autor_)
			b.Print();
	}
}

void Library::BookToIssue(Book* b_)
{
	b_->SetIssuse(true);
	cout << "Book Issuse\n";
}
void Library::BookToBack(Book* b_)
{
	b_->SetIssuse(false);
	cout << "Book Return\n";
}

void Library::Sort()
{
	sort(listBook.begin(), listBook.end());
}

void Library::RemoveBook()
{
	cout << "Remove book\n"
		<< "Enter Autor-> ";
	cin.ignore();
	string au;
	getline(cin, au);	
	cout << "Remove name book->";
	string nam;
	getline(cin, nam);
	cout << "Remove yer book->";
	int yer;
	cin >> yer;

	bool r = false;
	for(int i =0; i<this->listBook.size(); i++)
		if (this->listBook[i].GetSetAutor("") == au && this->listBook[i].GetSetName("") == nam && this->listBook[i].GetYer())
		{
			this->listBook.erase(this->listBook.begin() + i);
			r = true;
			break;
		}

	(r != true) ? cout << "Book not found!" : cout << "Book Removed!";
}

void Library::EditBook()
{
	cout << "Edit Book\n"
		<< "1. Enter number or\n"
		<< "2. Enter name end autor\n";
	int i = 0;
	cin >> i;

	Book* book = nullptr;
	if (i == 1)
	{
		book = GetBookNum();
	}
	else if (i == 2)
	{
		book = Search();
	}

	if (book == nullptr)
		cout << "Book not Found!\n";
	else
	{
		Add(book);
	}
}

void Library::ShowAll()
{
	cout << " Autor\t |\t Name\t |\t Yer\t |\t Issued\t |\t Number\n";

	for (int i = 0; i < listBook.size(); i++)
		listBook[i].Print();
}

Library::Book* Library::GetBookNum()
{
	int i = 0;
	cout << "Enter book number(#) ->\n";
		cin >> i;

	for (Book& b : listBook)
	{
		if (b.GetSetNumber(-1) == i)
			return &b;
	}
	return nullptr;
}


Library::~Library()
{
	for (int i = 0; i < listBook.size(); i++)
		delete &listBook[i];
}
