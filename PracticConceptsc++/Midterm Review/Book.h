#ifndef _Book_HG_
#define _Book_HG_

#include <string>

class Book
{
private:
	double price_;
	std::string title_;
	std::string author_;
public:
	// Default constructor
	/*
		if we give default value than it is default value
	*/
	Book(std::string author="unknown", double price=0, std::string title="unknown") :author_(author), price_(price), title_(title)
	{
	}
	// Prototype
	Book(Book const& book);
	Book(Book&& book);
	~Book() {}

	// Getters
	std::string getAuthor() const;
	std::string getTitle()const;
	double price()const;

	// Setters
	void setAuthor(std::string author);
	void setTitle(std::string title);
	void setPrice(double price);

};


// Non- Member Operator
std::ostream& operator << (std::ostream& output, Book const& b);





#endif
