#ifndef _Book_HG_
#define _Book_HG_
#include <string>
#include <sstream>

class Book
{
private:
	std::string author_;
	std::string isbn_;
	double price_;
	std::string title_;

public:

	// A constructor that supplies the default argumemnt for all tits parameter
	// also defines the default constructor
	Book(std::string author="Unknown", std::string isbn="24234asdf", std::string title="Unknown", double price=0) : author_(author), isbn_(isbn), title_(title), price_(price) {}
	// Destructor

	// getters
	std::string getAuthor()const;
	std::string getisbn()const;

	std::string getTitle()const;
	 double getPrice()const;
	
	// setters

	void setAuthor(std::string author);
	void setTitle(std::string title);
	void setIsbn(std::string isbn);
	void setPrice(double price);

	// copy constructor
	Book(Book const& orig);
	// move constructor
	Book(Book&& orig);
};

std::ostream& operator << (std::ostream& output, Book const& b);







#endif