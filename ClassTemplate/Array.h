#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
	T* arr;
	int size;
public:
	Array();
	Array(int size);
	Array(T a[], int s);
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	~Array();

	int GetSize();
	int GetUpperBound();

	void Input();
	void Print();
};

template<class T>
inline Array<T>::Array()
{
	arr = nullptr;
	size = 0;
}

template<class T>
inline Array<T>::Array(int size)
{
	this->size = size;
	arr = new T[size] {};
}

template<class T>
inline Array<T>::Array(T a[], int s)
{
	size = s;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
}

template<class T>
inline Array<T>::Array(const Array& copy)
{
	size = copy.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = copy.arr[i];
	}
}
template<class T>
inline Array<T>& Array<T>:: operator=(const Array& copy)
{
	if (this == &copy)
	{
		return *this;
	}
	if (arr != nullptr)
	{
		delete[] arr;
	}
	size = copy.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = copy.arr[i];
	}
	return *this;
}

template<class T>
inline Array<T>::~Array()
{
	delete[] arr;
	size = 0;
}

template<class T>
inline int Array<T>::GetSize()
{
	return size;
}

template<class T>
inline int Array<T>::GetUpperBound()
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			index++;
		}
	}
	return index-1;
}

template<class T>
inline void Array<T>::Input()
{
	cout << "Enter size: ";
	cin >> size;
	while (size <= 0)
	{
		cout << "Invalid number! Enter a positive size" << endl;
		cout << "Size: ";
		cin >> size;
	}
	arr = new T[size];
	bool answer = true;
	int elements = 0;
	cout << "Enter array's members" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Element #" i + 1 << ": ";
		cin >> arr[i];
		elements++;
		if (i < size - 1)
		{
			cout << "Wound you like to enter one more element? (1 - yes, 0 - no)" << endl;
			cout << "Answer: ";
			cin >> answer;
		}
		if (answer == 0)
		{
			cout << "Input completed!" << endl;
			break;
		}
	}
}

template<class T>
inline void Array<T>::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
