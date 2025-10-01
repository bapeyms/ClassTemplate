#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array
{
	T* arr;
	int size;
	int trueSize;
public:
	Array();
	Array(int size);
	Array(T a[], int s, int ts);
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	~Array();

	int GetSize() const;
	int GetTrueSize() const;

	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra();
	void DeleteAll();
	T& operator=(int index);
	T& operator=(int index) const;
	T GetAt(int index);
	void SetAt(int index);
	void Add();
	Array operator+(const T& obj);

	void Input();
	void Print() const;
};

template<class T>
inline Array<T>::Array() :arr(nullptr), size(0), trueSize(0) {}

template<class T>
inline Array<T>::Array(int size)
{
	this->size = size;
	this->trueSize = 0;
	arr = new T[size] {};
}

template<class T>
inline Array<T>::Array(T a[], int s, int ts)
{
	size = s;
	trueSize = ts;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
		trueSize++;
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
	trueSize = 0;
}

template<class T>
inline int Array<T>::GetSize() const
{
	return size;
}

template<class T>
inline int Array<T>::GetTrueSize() const
{
	return trueSize;
}

template<class T>
inline int Array<T>::GetUpperBound()
{
	return trueSize-1;
}

template<class T>
inline bool Array<T>::IsEmpty()
{
	if (trueSize == 0)
	{
		return false;
	}
	return true;
}

template<class T>
inline void Array<T>::FreeExtra()
{
	if (trueSize < size)
	{
		T* tempArr = new T[trueSize];
		for (int i = 0; i < trueSize; i++)
		{
			tempArr[i] = arr[i];
		}
		delete[] arr;
		arr = tempArr;
	}
}

template<class T>
inline void Array<T>::DeleteAll()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = nullptr;
	size = 0;
	trueSize = 0;
}

template<class T>
inline T& Array<T>::operator=(int index)
{
	if (index < 0 && index >= trueSize)
	{
		throw out_of_range("Index out of range");
	}
	return arr[index];
}
template<class T>
inline T& Array<T>::operator=(int index) const
{
	if (index < 0 && index >= trueSize)
	{
		throw out_of_range("Index out of range");
	}
	return arr[index];
}

template<class T>
inline T Array<T>::GetAt(int index)
{
	return arr[index];
}

template<class T>
inline void Array<T>::SetAt(int index)
{
	T element;
	cout << "Enter a new value for the element " << GetAt(index) << ": ";
	cin >> element;
	arr[index] = element;
}

template<class T>
inline void Array<T>::Add()
{
	int newSize = trueSize + 1;
	T* newArr = new T[newSize];
	T newElement;
	cout << "Enter a new element: ";
	cin >> newElement;
	for (int i = 0; i < trueSize; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[newSize - 1] = newElement;
	delete[] arr;
	arr = newArr;
	trueSize = newSize;
}

template<class T>
inline Array<T> Array<T>::operator+(const T& obj)
{
	int newSize;
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
	int answer = 1;
	cout << "Enter array's members" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Element #" << i + 1 << ": ";
		cin >> arr[i];
		trueSize++;
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
inline void Array<T>::Print() const
{
	for (int i = 0; i < trueSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
