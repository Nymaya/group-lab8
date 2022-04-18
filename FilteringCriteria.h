#pragma once
#include <string>
#include <iostream>
#include "DynamicArray.h"
#include "Offer.h"
using std::string;


// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
	virtual DynamicArray<Offer> filter(DynamicArray<Offer>& data) = 0;
};

class FilteringPrice : virtual public FilteringCriteria
{
private:
	int price;
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data)override;
	FilteringPrice(int p);
	int getprice();
};

class FilteringType : virtual public FilteringCriteria
{
private:
	string type;
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data)override;
	FilteringType(string t);
	string gettype();
};

class FilteringCriteriaTypeAndPrice: virtual public FilteringCriteria
{
private:
	FilteringPrice objprice;
	FilteringType objtype;
	///filter returns all offers that comply with both conditions
public:
	DynamicArray<Offer> filter(DynamicArray<Offer>& data)override;
	DynamicArray<Offer> filter(DynamicArray<Offer>& data, DynamicArray<Offer>& data1);
	FilteringCriteriaTypeAndPrice(FilteringPrice p, FilteringType t);
};
