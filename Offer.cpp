#include "Offer.h"
#include <string>
#include <cmath>
using namespace std;


string Offer::getid()
{
	return id;
}


string Offer::getdepart()
{
	return departure;
}

string Offer::getdestin()
{
	return destination;
}

int Offer::getprice()
{
	return price;
}

string Offer::gettype() {
	return this->type;
}

string Offer::to_string()
{
	int i;
	string str = "";
	str += "ID: " + this->id;
	string types[4] = {"cruise", "city break", "circuit", "all inclusive"};
	for (i = 0; i < 4; ++i)
		if (this->type == types[i])
			str += ", type " + this->type;
		else throw("Type doesn't exist"); 
	str += "\n";
	str += "Start date: " + this->start_date.date_to_string()+"\n";
	str += "End date: " + this->end_date.date_to_string() + "\n";
	str += "Location : " + this->departure + "\n";
	str += "Destination " + this->destination + "\n";
	str += "Price:" + std::to_string(this->price);
	return str;

}

Offer::Offer()
{
	id = " - 1";
	destination = "";
	departure = "";
	price = -1;
	type = "";
	start_date = Date{};
	end_date = Date{};
	
}

Offer::Offer(string id, string depart, string dest, Date& start, Date& end, int price, string type)
{
	id = id;
	this->departure = depart;
	this->destination = dest;
	this->price = price;
	this->type = type;
	/*
	start_date.set_day(d_s.get_day());
	start_date.set_month(d_s.get_month());
	start_date.set_year(d_s.get_year());
	end_date.set_day(d_e.get_day());
	end_date.set_month(d_e.get_month());
	end_date.set_year(d_e.get_year());
	*/
	

}

Offer::Offer(const Offer& other)
{
	departure = other.departure;
	destination = other.destination;
	id = other.id;
	price = other.price;
	type = other.type;
	start_date = other.start_date;
	end_date = other.end_date;
	
}

Offer& Offer::operator=(Offer other)
{
	departure = other.departure;
	destination = other.destination;
	id = other.id;
	price = other.price;
	type = other.type;
	start_date = other.start_date;
	end_date = other.end_date;
	
	return *this;
}

bool Offer::operator==(const Offer& other)
{
	return ((this->departure == other.departure) && (this->destination == other.destination) && (this->id == other.id)
		&& (this->type == other.type) && (fabs(this->price - other.price) < 0.005) &&
		(this->start_date == other.start_date) && (this->end_date == other.end_date));
	//fabs = modul
}
