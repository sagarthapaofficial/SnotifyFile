#include "Book.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
typedef shared_ptr<Book> BookPtr;

void Print(string heading,vector<BookPtr>BookPtrVec)
{
	cout << heading << endl;
	bool a = false;

	if (a == false)
	{
		for (int i = 0; i < BookPtrVec.size(); i++)
		{
			cout << *BookPtrVec[i] << endl;
		}
		cout << endl;
	}
}
// Sort by author
bool byAuthor(BookPtr const & lhs, BookPtr const & rhs)
{
	return lhs->getAuthor()< rhs->getAuthor();
}

// Sort by Title
bool operator > (BookPtr const & lhs, BookPtr const& rhs)
{
	return lhs->getTitle() > rhs->getTitle();
}


int main()
{

	BookPtr pBook1= make_shared <Book>("Sagar", "3545fw", "THe Main land", 231);
	BookPtr pBook2 = make_shared <Book>("Chandra", "1323fw", "Lady in the garden", 431);
	BookPtr pBook3 = make_shared <Book>("Krishna", "643fw", "Final Destination", 131);
	BookPtr pBook4 = make_shared <Book>("Krita", "643fw", "Fidal Destination", 131);
	BookPtr pBook5 = make_shared <Book>();


	vector<BookPtr>BookPtrVec;
	BookPtrVec.push_back(pBook1);
	BookPtrVec.push_back(pBook2);
	BookPtrVec.push_back(pBook3);
	BookPtrVec.push_back(pBook4);
	BookPtrVec.push_back(pBook5);

	cout << "Without Sorting" << endl;
	Print("Without Sorting", BookPtrVec);
	// Sort by Author
	sort(BookPtrVec.begin(), BookPtrVec.end(), byAuthor);
	Print("Sort By Author", BookPtrVec);
	
	// Sort by Title
	
	sort(BookPtrVec.begin(), BookPtrVec.end(), greater<BookPtr>());
	Print("Sort by Greater Title", BookPtrVec);


return 0;
}