#include "date.h"
Date::Date(int day, int month,int year)
{
	//main c'tor
	setDay(day);
	setMonth(month);
	setYear(year);
}
//----------------------------------------------------------------------------------------//
Date::Date(const Date & other)
{ //copy c'tor
	setDay(other.day);
	setMonth(other.month);
	setYear(other.year);

}
//----------------------------------------------------------------------------------------//
void Date::setDay(const int day)
{
	//the function sets the date's day
	this->day = day;
}
//----------------------------------------------------------------------------------------//
void Date::setMonth(const int month)
{
	//the function sets the date's day
	this->month = month;
}
//----------------------------------------------------------------------------------------//
void Date::setYear(const int year)
{
	//the function sets the date's day
	this->year = year;
}
//----------------------------------------------------------------------------------------//
const int Date::getDay() const
{//the function return the date's day
	return this->day;
}
//----------------------------------------------------------------------------------------//
const int Date::getMonth() const
{//the function return the date's month
	return this->month;
}
//----------------------------------------------------------------------------------------//
const int Date::getYear() const
{
	//the function sets the date's year
	return this->year;
}
//----------------------------------------------------------------------------------------//
void Date::show() const
{//the function prints the current dae
	cout << day << " : " << month;
}