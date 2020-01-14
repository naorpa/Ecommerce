#include "feedback.h"
#include <string.h>

Feedback::Feedback(const char * name, Date date, const char * description) : f_date(date)
{
	//main c'tor
	setName(name);
	setDescription(description);
}
//----------------------------------------------------------------------------------------//

Feedback::Feedback(const Feedback & other) : f_date(other.f_date)
{ //copy c'tor
	setName(other.getName());
	setDescription(other.getDescription());
}
//----------------------------------------------------------------------------------------//
Feedback::Feedback(Feedback && other) : f_date(other.f_date)
{ //move c'tor
	this->f_name = other.f_name;
	this->f_description= other.f_description;
	other.f_name = nullptr;
	other.f_description = nullptr;
}
//----------------------------------------------------------------------------------------//
Feedback::~Feedback()
{
	delete[] this->f_description;
	delete[] this->f_name;
}
//----------------------------------------------------------------------------------------//
void Feedback::setName(const char * name)
{
	//the function sets the feedback's name
	this->f_name = strdup(name);
}
//----------------------------------------------------------------------------------------//
void Feedback::setDescription(const char * desc)
{
	//the function sets the feedback's description
	this->f_description = strdup(desc);
}
//----------------------------------------------------------------------------------------//

void Feedback::setDate(Date date)
{
	this->f_date.setDay(date.getDay());
	this->f_date.setMonth(date.getMonth());
	this->f_date.setYear(date.getYear());

}
//----------------------------------------------------------------------------------------//
const char * Feedback::getName() const
{
	return f_name;
}
//----------------------------------------------------------------------------------------//
const char * Feedback::getDescription() const
{
	return f_description;
}
//----------------------------------------------------------------------------------------//
Date & Feedback::getDate()
{
	return f_date;
}

