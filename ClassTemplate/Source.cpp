#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	srand(time(0));
	int mas[]{ 1,2,3,4,5 };
	Array<int>obj1(mas, 5);
	obj1.Print();
	cout << endl;

	Array<int>obj2;
	obj2.Input();
	obj2.Print();


	//cout << "Get upper bound: " << obj1.GetUpperBound();
}