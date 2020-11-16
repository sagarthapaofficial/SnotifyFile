#include <iostream>
#include <vector>
using namespace std;


/*

RValue reference -> temporary value reference eg. 10, 12, "sagar" without variable name



*/

/*
Move semantice:
to move objects



*/




class String
{

public:
    String() = default;



};





// Move Class
class Move {
private:
    // Declaring the raw pointer as
    // the data member of the class
    int* data;

public:
    // Constructor
    Move(int d)
    {
        // Declare object in the heap
        data = new int;
        *data = d;

        cout << "Constructor is called for "
            << d << endl;
    };

    // Copy Constructor to delegated
    // Copy constructor
    Move(const Move& source)
        : Move{ *source.data }
    {

        // Copying constructor copying
        // the data by making deep copy
        cout << "Copy Constructor is called - "
            << "Deep copy for "
            << *source.data
            << endl;
    }


    //Move constructor
    Move(Move&& source)
        : data{ source.data }
    {
        cout << "Move constructor for "
            << *source.data << endl;
        source.data = nullptr;

    }


    // Destructor
    ~Move()
    {
        if (data != nullptr)

            // If the pointer is not
            // pointing to nullptr
            cout << "Destructor is called for "
            << *data << endl;
        else

            // If the pointer is
            // pointing to nullptr
            cout << "Desturctor is called"
            << " for nullptr"
            << endl;

        // Free the memory assigned to
        // data member of the object
        delete data;
    }
};

// Driver Code
int main()
{
    // Create vector of Move Class
    vector<Move> vec;

    // Inserting object of Move class
    vec.push_back(Move{ 10 });
    vec.push_back(Move{ 20 });
    return 0;
}