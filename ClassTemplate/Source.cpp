#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	srand(time(0));
	int mas[]{ 1,2,3,4,5 };
	Array<int>obj1(mas, 5);
	cout << "Array: ";
	obj1.Print();
	cout << endl;

	Array<int>obj2;
	obj2.Input();
	cout << "Array: ";
	obj2.Print();
	cout << endl;
	
	cout << "Get upper bound: " << obj2.GetUpperBound() << endl;
	cout << "Is empty? (1 - not empty, 0 - empty): " << obj2.IsEmpty() << endl;
	cout << "FreeExtra: ";
	obj2.FreeExtra();
	obj2.Print();
	cout << "Size before: " << obj2.GetTrueSize();
	cout << "Size after:" << obj2.GetSize();
}