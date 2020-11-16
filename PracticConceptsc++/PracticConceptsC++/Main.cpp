#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class cPerson
{



};

class Rectangle {
private:
	std::string colour = "black";
	int width = 0, length = 0;
	int* p = &width;
public:

	Rectangle() :Rectangle("red", 123, 123) {}
	Rectangle(string const& c):Rectangle("red",123,43) {}


	Rectangle(std::string c, int w, int l):colour("yellow"),width(8), length(6) {


		std::cout << "area of the " << colour << " rectangle is " << width * length << std::endl;
	}


	Rectangle(int w, int l): width(w), length(l)
	{

	}

	
	Rectangle(int width): width(width)
	{
		std::cout << "Invoking Noraml constructor" << endl;
		
	}


	Rectangle(const Rectangle& r)
	{
		cout << "Invokes copy construuctor" << endl;
		int abc;
		abc = r.width;
	}
	
	/*	 copy assignment Operator  copys the objects
		 copy only thhe address of the pointer and the the value which it is pointing to*/
	Rectangle & operator =(const Rectangle& r)
	{
		cout << "Copy Assignment Operator" << endl;
			width = r.width;
			length = r.length;
			int *p = r.p;
			cout << *p << endl;
		return *this;
	}
	friend ostream& operator <<(ostream& output, Rectangle& r);

};

ostream& operator <<(ostream& output, Rectangle& r)
{
	return	output << r.colour<<" " << r.length <<" "<< r.width << " " <<r.p<< endl;
}

 //Copy Asiignment 
 //Pointers will only have theri address copied thereby performing a shallow copy

int main()
{	

	Rectangle rec(10);
	// This is copy coonstructor
	Rectangle re= rec;

	cout << "REctangle re:\n" << re << endl;
	Rectangle r1;
	cout << "Rectangle 1:\n" << r1 << endl;
	cout << endl;
	
	// This is copy assignement operator
	Rectangle r5;
		r5=r1;
	cout << "Rectangle 5:\n" << r5 << endl;

	Rectangle r2("yellow", 5, 5);
	cout << "Rectangle 2:\n" << r2 << endl;

	Rectangle r3(12, 15);
	cout << "Rectangle 3:\n" << r3 << endl;

	Rectangle r4("green");
	cout << "Rectangle 4:\n" << r4 << endl;

	return EXIT_SUCCESS;
}