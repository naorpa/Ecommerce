#ifndef Array_H
#define Array_H
#pragma warning(disable : 4996)
#include <ostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
	int physicalSize, logicalSize;
	char delimiter;
	T** arr;

public:
	Array(int size = 1, char delimiter = ' ');
	Array(const Array& other);
	~Array();

	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);

	const int& getLogSize();
	const int& getPhysicalSize();
	T getArrByIndex(const int& index);
	T** getArray();

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0;, i < arr.logicalSize; i++)
			os << *(arr.arr[i]) << arr.delimiter;
	}
	void  Array<T>::CheckSizeOfArrayAndReAllocateIfNeeded();
};

template<class T>
T Array<T>::getArrByIndex(const int& index)
{
	return *(arr[index]);
}

template<class T>
T** Array<T>::getArray()
{
	return arr;
}

template <class T>
Array<T>::Array(int size, char delimiter) :physicalSize(size), logicalSize(0), delimiter(delimiter)
{
	arr = new T*[physicalSize];//allocation for physicalSize of the class T array
}

template <class T>
Array<T>::Array(const Array& other)
{
	*this = other;
}

template <class T>
Array<T>::~Array()
{
	for (int i = 0; i < logicalSize; i++)
		delete arr[i];
	delete[]arr;
}

template <class T>
const Array<T>& Array<T>:: operator=(const Array<T>& other)
{
	if (this != &other)
	{
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T*[physicalSize];//new allocate 
		for (int i = 0; i < logicalSize; i++)
			arr[i] = new T(*(other.arr[i]));
	}
	return *this;
}

template <class T>
const Array<T>& Array<T>:: operator+=(const T& newVal)
{
	CheckSizeOfArrayAndReAllocateIfNeeded();
	//	if (logicalSize < physicalSize)
		//{
	arr[logicalSize] = new T(newVal);
	logicalSize++;
	//}
	return *this;
}

template<class T>
void  Array<T>::CheckSizeOfArrayAndReAllocateIfNeeded()
{
	T** TempArray = NULL;
	if (logicalSize >= physicalSize)
	{
		physicalSize *= 2;
		TempArray = new T*[physicalSize];
		for (int i = 0; i < logicalSize; i++)
		{
			TempArray[i] = new T(*arr[i]);
			//	TempArray[i] = arr[i];
		}
		for (int i = 0; i < logicalSize; i++)
			delete arr[i];
		delete[]arr;
		arr = TempArray;
	}
}

template<class T>
const int& Array<T>::getLogSize()
{
	return logicalSize;
}

template<class T>
const int& Array<T>::getPhysicalSize()
{
	return physicalSize;
}

#endif