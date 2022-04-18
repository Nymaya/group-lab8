#include "FilteringCriteria.h"
#include "Offer.h"
#include <string.h>
#include <iostream>
using namespace std;

DynamicArray<Offer> FilteringCriteria::filter(DynamicArray<Offer>& other)
{
    return other;
}

DynamicArray<Offer> FilteringPrice::filter(DynamicArray<Offer>& other)
{
	DynamicArray<Offer> a;
	
	for (int i = 0; i < other.getLength(); ++i) 
		if (other.get(i).getprice() <= this->price)
			a.append(other.get(i));
		
	return a;
}

FilteringPrice::FilteringPrice(const FilteringPrice& other)
{
	price = other.price;
}

FilteringPrice::FilteringPrice(int price)
{
	price = -1;
}

FilteringPrice& FilteringPrice::operator=(const FilteringPrice& other)
{
	this->price = other.price;
	return *this;
}

FilteringPrice::FilteringPrice(int p)
{
	price = p;
}

int FilteringPrice::getprice()
{
	return price;
}

///TYPE/////////////////////////

DynamicArray<Offer> FilteringType::filter(DynamicArray<Offer>& data)//doesn't work cuz my type of data is string? const char
{
	DynamicArray<Offer> a;
	
	for (int i = 0; i < data.getLength(); ++i) 
		if (data.get(i).gettype() == this->type)
			a.append(data.get(i));
		
	return a;
}

FilteringType::FilteringType(string type)
{
	type = -1;
}


FilteringType::FilteringType(const FilteringType& ft)
{
	type = ft.type;
}

FilteringType& FilteringType::operator=(const FilteringType& of)
{
	this->type = of.type;
	return *this;
}

FilteringType::FilteringType(string t)
{
	type = t;
}

string FilteringType::gettype()
{
	return type;
}

///TYPE AND PRICE//////////////////////


DynamicArray<Offer> FilteringCriteriaTypeAndPrice::filter(DynamicArray<Offer>& data)
{
	DynamicArray<Offer> a;	
	for (int i = 0; i < data.getLength(); ++i) 
		if (data.get(i).getprice() <= objprice.getprice() && data.get(i).gettype() == objtype.gettype()) 
			a.append(data.get(i));
		
	return a;
	
}

DynamicArray<Offer> FilteringCriteriaTypeAndPrice::filter(DynamicArray<Offer>& data)
{
	this->objprice = p;
	this->objtype = t;
}
