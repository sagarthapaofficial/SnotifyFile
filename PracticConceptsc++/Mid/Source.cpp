#include <iostream>
#include <string.h>

using namespace std;

class Marks
{
private:
	int rno;
	float perc;

public:
	//constructor

	Marks()
	{
		
		rno = 0; perc = 0.0f;
	}

	
	//input roll numbers and percentage

	void readMarks(void)
	{
	
		cout << "Enter roll number: ";
		cin >> rno;
		cout << "Enter percentage: ";
		cin >> perc;
	}

	//print roll number and percentage
	void printMarks(void)
	{
		cout << "Roll No.: " << rno << endl;
		cout << "Percentage: " << perc << "%" << endl;
	}
};

class Student
{
private:
	//object to Marks class
	char name[30];

public:
	Marks objM;
	//input student details
	

	void play()
	{
		cout << "I love to play" << endl;
	}
	void readStudent(void)
	{
		objM.printMarks();
		//Input name
		cout << "Enter name: ";
		cin.getline(name, 30);
		//input Marks;
	
	}
	//print student details
	void printStudent(void)
	{
		//print name
		cout << "Name: " << name << endl;
		//print marks
		objM.printMarks();
	}
};

//main code
int main()
{
	//create object to student class
	Student std;
	std.readStudent();
	std.printStudent();
	std.play();

	return 0;
}
