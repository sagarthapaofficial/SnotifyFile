//Book_Application.cpp
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Book.h"

using namespace std;

typedef shared_ptr<Book>BookPtr;
// Predicate to sort by author

 bool byAuthor (BookPtr const& lhs, BookPtr const& rhs)
{
	return lhs->getAuthor() < rhs->getAuthor();
}

//// Operator to sort by title
bool operator < (BookPtr const& lhs, BookPtr const& rhs)
{
	return lhs->getTitle() < rhs->getTitle();
}

void print_books(string heading, vector < BookPtr> v)
{
	cout << heading << endl;
	for (auto b: v)
	{
		cout << *b << endl;
	}
	cout << endl;
}

int main()
{

	
	// create four book objects, 
	BookPtr pbook1(new Book("Zaka, Margaret", 29.99,"The Blind Assasin"));
	BookPtr pbook2(new Book("Sagar, Thapa", 49.99, "The Foreover Kingdom"));
	BookPtr pbook3(new Book("Harry, Potter", 19.99, "House of Death"));
	BookPtr pBook4(new Book);


	// Create a vectpr amd load with Books
	
	vector<BookPtr>v;

	v.push_back(pbook1);
	v.push_back(pbook2);
	v.push_back(pbook3);


	vector<BookPtr>ver = v;
	//Prints the books, unsorted
	print_books("Unsorted ", v);


	// Print the books , sorted by author
	sort(v.begin(), v.end(), byAuthor);
	print_books("Sorted by Author", v);

	//// Print the books, sorted by title
	sort(v.begin(), v.end(), less<BookPtr>());
	print_books("Sorted by Title", v);


}