#pragma once
#include <string>
#include <iostream>
#include "Offer.h"
#include <assert.h>
using namespace std;

template <class T>
class DynamicArray
{
public:
	DynamicArray(int capacity = 100); 
	~DynamicArray();

	DynamicArray(const DynamicArray& other);

	DynamicArray& operator=(const DynamicArray& other);
	inline unsigned int getLength() const { return length; }

	inline unsigned int getCapacity() const { return capacity; }
	
	T& operator[](int index)
	{
		assert(index >= 0 && index < length);
		return data[index];
	}
	void Erase();
	friend ostream& operator<<(ostream& s, const DynamicArray& arr);
	T& get(unsigned int index);
	
private:
	
	static int count;
	unsigned int length;
	unsigned int capacity;
	T* data;

	void resize(unsigned int newCapacity);
};

