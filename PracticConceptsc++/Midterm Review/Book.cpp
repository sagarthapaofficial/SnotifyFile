#include "Book.h"
#include <iostream>

Book::Book(Book const& book)
{
	this->author_ = book.author_;
	this->author_ = book.author_;
	this->price_ = book.price_;
}


Book::Book(Book&& book)
{
	this->author_ = std::move(book.author_);
	this->price_ = book.price_;
	this->title_ = std::move(book.title_);

}

// Getters
std::string  Book::getAuthor() const
{
	return this->author_;
}

std::string Book:: getTitle()const
{
	return this->title_;

}
double Book:: price()const
{
	return this->price_;
}


// setters implementation

void Book:: setAuthor(std::string author)
{
	this->author_ = author;
}
void  Book::setTitle(std::string title)
{
	this->title_ = title;
}
void Book:: setPrice(double price)
{
	this->price_ = price;
}

// Operator
std::ostream& operator << (std::ostream& output, Book const& b)
{
	return output << "\""<< b.getTitle() << "\""<<" "<<  b.getAuthor()<< " " << b.price();

}
