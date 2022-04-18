#include "DynamicArray.h"
#include <iostream>
using namespace std;

template <class T>

DynamicArray<T>::DynamicArray(int capacity) {
	length = 0;
	this->capacity = capacity;
	data = new T[capacity]();

	if (data == nullptr) {
		cerr << "DynamicArray(): failed to allocate memory" << endl;
		exit(-1);
	}
}
template <class T>

DynamicArray<T>::~DynamicArray() {
	//free the allocated memory
	delete[] data;
}
template <class T>

DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {

	if (this != &other) { // self assignment check
		// deep copy of other
		length = other.length;
		capacity = other.capacity;

		delete[] this->data;
		// !! data 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		data = new T[other.capacity]();

		if (data == nullptr) {
			cerr << "operator=(): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			data[i] = other.data[i];
	}
	return *this; // the type of this is DynamicArray* -> dereferencing
}
template <class T>

DynamicArray<T>::DynamicArray(const DynamicArray& other) {
	// deep copy of other
	length = other.length;
	capacity = other.capacity;
	data = new T[other.capacity]();

	if (data == nullptr) {
		cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < length; i++)
		data[i] = other.data[i];
}
template <class T>

void DynamicArray<T>::Erase()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

template <class T>

ostream& operator<<(ostream& s, const DynamicArray<T>& arr) {
	// [1 2 3 4 5 ]
	s << "[";
	for (unsigned int i = 0; i < arr.length; i++) {
		s << arr.data[i].to_string() << " ";
	}
	s << "]";
	return s;
}



template <class T>

T& DynamicArray<T>::get(unsigned int index) {

	// pre index >=0 and index < length
	if (index >= 0 && index < length) {
		return data[index];
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: get()" << endl;
		exit(-1);
	}
}
template <class T>

void DynamicArray<T>::resize(unsigned int newCapacity) {

	this->capacity = newCapacity;
	// no realloc  in c++

	T* newData = new T[newCapacity]();
	if (newData == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}
	
	for (unsigned int i = 0; i < length; i++) {
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
}

