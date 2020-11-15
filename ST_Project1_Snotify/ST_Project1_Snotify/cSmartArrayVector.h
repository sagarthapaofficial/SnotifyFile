#ifndef  _cSmartArrayVector_HG_
#define _cSmartArrayVector_HG_

#include "cPerson.h"
#include <iomanip>
#include <iostream>
template <class T>
class cSmartArrayVector
{

public:
	// declaring constructor
	cSmartArrayVector()
	{
		this->nextIndex = 0;

	};
	//declaring e
	~cSmartArrayVector()
	{

	}

	// pushes value at the end of the data
	void PushAtBack(T person)
	{
		if (this->nextIndex == this->presentArraySize)
		{
			this->getResize();
		}

		this->Person[nextIndex] = person;
		this->nextIndex++;
	}


	// pops value from the back
	void PopAtBack()
	{
		// moving one index back

		if (nextIndex > 0)
		{
			this->nextIndex--;
			~cSmartArrayVector();
		}
		else
		{
			// showing error and exiting the program
			std::cerr << "Error !!! array is empty.. NOthing to Pop" << std::endl;
			std::exit(-1);
		}

	}

	unsigned int getSize()
	{
		return this->nextIndex;
	}

	void clearAll()
	{
		// setting the index to 0 making it empty
		nextIndex = 0;
	}


	void remove(int index)
	{
		T* array = new T[this->presentArraySize];
		int i = 0;;
		for (i = 0; i < nextIndex; i++)
		{
			array[i] = this->Person[i];
			if (i == index)
			{
				break;
			}
			
		}
		nextIndex--;
		for (int j = i; j < nextIndex; j++)
		{
			array[j] = this->Person[j+1];
		}
		T* pOPointer = this->Person;
		this->Person = array;
		delete []pOPointer;

	}
	void getResize()
	{
		// doubling the array when it reaches it capacity limit
		this->presentArraySize *= 2;

		T* array = new T[this->presentArraySize];
		for (int i = 0; i < nextIndex; i++)
		{
			array[i] = this->Person[i];
		}

		T* pOPointer = this->Person;

		// pointing the pointer to the newly created array
		this->Person = array;

		delete[] pOPointer;

	}

	int Arraycapacity()
	{
		return presentArraySize;
	}



	bool isEmpty()
	{
		std::cout << std::boolalpha << std::endl;
		if (nextIndex == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	T ValueAtIndex(unsigned int index)
	{
		return this->Person[index];

	}

	T& operator [] (int i)
	{
		if (i > nextIndex)
		{
			std::cout << "Index out of bounds" << std::endl;
			return Person[0];
		}

		return Person[i];

	}



private:
	// this will automatically resize the array 

	// location of the next item to be addes
	unsigned int nextIndex;
	static const unsigned INITIAL_ARRAYSIZE = 10;
	unsigned int presentArraySize = INITIAL_ARRAYSIZE;
	//Actual pointer

	T* Person = new T[INITIAL_ARRAYSIZE];

};



#endif 

