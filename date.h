#ifndef __DATE_H
#define __DATE_H
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() = default; // default c'tor
	Date(int day,int month,int year); //main c'tor 
	Date(const Date & other); //copy c'tor
public:
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	const int getDay() const;
	const int getMonth() const;
	const int getYear() const;
	void show() const;
};

#endif // __DATE_H
