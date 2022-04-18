#pragma once
#include <string>
#include <ostream>
#include "Date.h"
using namespace std;


class Offer
{
public:

	string getid();
	string getdepart();
	string getdestin();
	int getprice();
	string gettype();
	string to_string();
	Offer();
	Offer(string id, string depart, string dest, Date& start, Date& end, int price, string type);
	//copy constr
	Offer(const Offer& oferta);
	Offer& operator=(const Offer oferta);
	friend std::ostream operator<<(std::ostream out, Offer oferta);
	bool operator==(const Offer& other);


private:
	string id;
	string departure;
	string destination;
	int price;
	string type;
	Date start_date;
	Date end_date;

};
/*
Class Date
{
public:
	int day();
	int month();
	int year();
	Date();
	Date(int dd, int mm, int yyyy);
	Date(const Date& other);
	~Date();
	Date& operator=(const Date& other);
	bool operator==(const Date& other);
	string to_string();

private:
	int day;
	int month;
	int year;						
};*/	
