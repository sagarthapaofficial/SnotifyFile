#include <iostream>
#include <string>
#include <vector>
void getArray(int* array, int& size);
using namespace std;
int main()

{
	 int size = 10;
	int array[10];
	
	getArray(array, size);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << endl;
	}
	return 0;
}

void getArray(int * array, int &size)
{

	for (int i = 0; i <size; i++)
	{
		array[i] = i;
	}


}