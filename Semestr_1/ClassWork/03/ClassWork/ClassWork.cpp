

#include "Library.h"
using namespace std;

void AddDefoultBook(Library* lib_)
{
	lib_->Addbook(nullptr, "Dune Messiah", "Franklin Herbert", 1969);
	lib_->Addbook(nullptr, "Dune", "Franklin Herbert", 1965);
	lib_->Addbook(nullptr, "Children of Dune", "Franklin Herbert", 1976);

	lib_->Addbook(nullptr, "Harry Potter and the Philosopher's Stone", "Joanne Rowling", 1997);
	lib_->Addbook(nullptr, "Harry Potter and the Chamber of Secrets", "Joanne Rowling", 1998);
	lib_->Addbook(nullptr, "Harry Potter and the Prisoner of Azkaban", "Joanne Rowling", 1999);
	
	lib_->Sort();
}

int main()
{
	Library lib;

	AddDefoultBook(&lib);

    cout << "\tLIBRARY\n";

    int act = 1;
	Library::Book* book = nullptr;

	while (act)
	{
		cout << "1. Add Book\n"
			<< "2. Search book by Autor end Name\n"
			<< "3. Searh all book by Autor\n"
			<< "4. Hand over book\n"
			<< "5. Return book to library\n"
			<< "6. Remove book\n" 
			<< "7. Edit book\n"
			<< "8. Show all book\n";

		cin >> act;
		
		switch (act)
		{

			case 1:
			{
				lib.Add(nullptr);
				break;
			}	
			case 2:
			{
				book = lib.Search();
				if (book == nullptr)
					cout << "Book not found!\n";
				else {
					book->Print();
					int i = 0;

					cout << "1. Hand over book\n"
						<< "2. Return book to library\n"
						<< "0. Back\n";

					cin >> i;
					switch (i) {
					case 1: {
						book->SetIssuse(true);
						break;
					}
					case 2: {
						book->SetIssuse(false);
						break; }
					}
				}
				break;
			}
			case 3:
			{
				lib.SearchAvtor();
				break;
			}	
			case 4:
			{
				lib.ShowAll();
				book = lib.GetBookNum();
				if (book != nullptr)
					book->SetIssuse(true);
				break;
			}	
			case 5:
			{
				lib.ShowAll();
				book = lib.GetBookNum();
				if (book != nullptr)
					book->SetIssuse(false);
				break;
			}
			case 6:
			{
				lib.RemoveBook();
				break;
			}
			case 7:
			{
				lib.EditBook();
				break;
			}
			case 8:
			{
				lib.ShowAll();
				break;
			}
		}

	}
}
