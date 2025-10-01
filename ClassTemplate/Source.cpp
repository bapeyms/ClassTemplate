#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	srand(time(0));
	int mas1[]{ 1,2,3,4,5 };
	Array<int>obj1(mas1, 5, 0);
	cout << "- Array: ";
	obj1.Print();
	int mas2[]{ 6,7,8,9,10 };
	Array<int>obj2(mas2, 5, 0);
	cout << "- Array: ";
	obj2.Print();

	Array<int>obj3;
	obj3.Input();
	cout << "- Array: ";
	obj3.Print();
	cout << endl;

	cout << "1) Get upper bound: " << obj3.GetUpperBound() << endl;

	cout << "2) Is empty? (1 - not empty, 0 - empty): " << obj3.IsEmpty() << endl;

	cout << "3) Free extra: ";
	obj3.FreeExtra();
	obj3.Print();
	cout << "Size before: " << obj3.GetSize() << endl;
	cout << "Size after: " << obj3.GetTrueSize() << endl;

	cout << "4) Delete all: " << endl;
	cout << "Array before: ";
	obj1.Print();
	obj1.DeleteAll();
	cout << "Array after (1 - not empty, 0 - empty): " << obj1.IsEmpty() << endl;

	cout << "5) Get at: " << endl;
	int index1;
	cout << "Enter a desired index: ";
	cin >> index1;
	while (index1 < 0 || index1 >= obj3.GetTrueSize())
	{
		cout << "Invalid index! Enter a positive index" << endl;
		cout << "Index: ";
		cin >> index1;
	}
	cout << "Element: " << obj3.GetAt(index1) << endl;

	cout << "6) Set at: " << endl;
	int index2;
	cout << "Enter a desired index: ";
	cin >> index2;
	while (index2 < 0 || index2 >= obj3.GetTrueSize())
	{
		cout << "Invalid index! Enter a positive index" << endl;
		cout << "Index: ";
		cin >> index2;
	}
	cout << "Index " << index2 << " - element " << obj3.GetAt(index2) << endl;
	cout << "Array before: ";
	obj3.Print();
	obj3.SetAt(index2);
	cout << "Array after : ";
	obj3.Print();

	cout << "7) Add: " << endl;
	cout << "Array before: ";
	obj3.Print();
	obj3.Add();
	cout << "Array after: ";
	obj3.Print();

	cout << "8) Append: obj2 + obj3 = ";
}