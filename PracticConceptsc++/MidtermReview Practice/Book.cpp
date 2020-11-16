#include"Book.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


Book::Book(Book const& orig)
{
	author_ = orig.author_;
	isbn_ = orig.isbn_;
	price_ = orig.price_;
	title_ = orig.title_;
}

Book::Book(Book&& orig)
{
	author_ = move(orig.author_);
	isbn_ = move(orig.isbn_);
	price_ = orig.price_;
	title_ = move(orig.title_);

}
// getters
std::string Book:: getAuthor()const
{
	return this->author_;
}

std::string  Book::getisbn() const
{
	return this->isbn_;
}

std::string Book::getTitle()const
{

	return this->title_;
}

double Book::getPrice()const
{
	return this->price_;

}


// setters
void Book::setAuthor(std::string author)
{
	this->author_ = author;
}

void  Book:: setTitle(std::string title)
{
	this->title_ = title;
}

void  Book:: setIsbn(std::string isbn)
{
	this->isbn_ = isbn;
}


void Book::setPrice(double price)
{
	this->price_ = price;
}

// Operator
std::ostream& operator << (std::ostream& output, Book const & b)
{
	return output << "\"" << b.getTitle() << "\"" << " " << b.getAuthor() << " " << b.getPrice();

}








