#include <iostream>
using namespace std;

class String
{
public:
	String() = default;

	// String constructor
	String(const char* string)
	{

		printf("Created!\n");
		m_size = strlen(string);
		m_Data = new char[m_size];
		
		memcpy(m_Data, string, m_size);
	}

	// Copy constructor
	String(const String& other)
	{
		printf("Copied!\n");
		m_size = other.m_size;
		m_Data = new char[m_size];
		memcpy(m_Data, other.m_Data, m_size);
	}


	// Move constructor
	String(String&& other)noexcept
	{
		// copies the value from the older object
		printf("Moved!\n");
		m_size = other.m_size;
		m_Data = other.m_Data;

		// setting the old pointer to null pointer
		other.m_size = 0;
		other.m_Data = nullptr;

	}


	// Move assignment operator
	String& operator=(String&& other)noexcept
	{
		printf("Moved!\n");
		// if the objec is not equal to the older object we delete it
		
		if (this != &other)
		{
			// deleting the older array;
			delete[] m_Data;
		
			// Copies the value from older object to the current object
			m_size = other.m_size;
			m_Data = other.m_Data;

			// setting the old pointer to null pointer
			other.m_size = 0;
			other.m_Data = nullptr;

		}
		return *this;
	
	}

	~String()
	{

		cout << "Destroyed" << endl;
		delete [] m_Data;


	}

	void Print()
	{

		for (uint32_t i = 0; i < m_size; i++)
		{
			printf("%c", m_Data[i]);
		}

		printf("\n");
	}




private:
	char* m_Data;
	uint32_t m_size;
};




class Entity
{

public :
	Entity(const String& name)
		: m_Name(name)
	{}

	Entity(String&& name)
		: m_Name(move(name))
	{}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};


int main()
{

	/*Entity entity("Sagar");
	entity.PrintName();

	*/
	String apple = "Apple";
	String dest;

	
	// This copies the apple object to the dest
	// Done when the object is create initially
	// This is move constuctor
	//String dest = apple;
	// Move takes an rValue reference

	//dest = move(apple);
	// This will call the constructor
	//String dest = move(apple);

//	Moves the value of one object to another object

	cout << "Apple: ";
	apple.Print();
	cout << "Dest :";
	dest.Print();

	// Moves the value from the string to the dest
	dest = move(apple);

	// Another of doing move
	//dest = ((String&&)apple);

	cout << "Apple: ";
	apple.Print();
	cout << "Dest: ";
	dest.Print();

	std::cin.get();

}