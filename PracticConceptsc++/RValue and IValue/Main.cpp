#include <iostream>

#include <string>
#include <iomanip>
using namespace std;





int main()
{
    int a = 10;

    // Declaring lvalue reference 
    // (i.e variable a) 
    int& lref = a;

    // Declaring rvalue reference 
    int&& rref = 20;

    // Print the values 
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;

    // Value of both a 
    // and lref is changed 
    lref = 30;

    // Value of rref is changed 
    rref = 40;
    cout << "lref = " << lref << endl;
    cout << "rref = " << rref << endl;

    // This line will generate an error 
    // as l-value cannot be assigned 
    // to the r-vaue referances 
    // int &&ref = a; 

	return EXIT_SUCCESS;
}