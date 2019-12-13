#include "feedback.h"
#include <string.h>

Feedback::Feedback(const char * name, Date date, const char * description)
{
	//main c'tor
	setName(name);
	setDate(date);
	setDescription(description);
}
//----------------------------------------------------------------------------------------//

Feedback::Feedback(const Feedback & other)
{ //copy c'tor
	setName(other.getName());
	setDate(other.getDate());
	setDescription(other.getDescription());
}
//----------------------------------------------------------------------------------------//
Feedback::Feedback(Feedback && other)
{ //move c'tor
	strcpy(this->f_name, other.f_name);
	f_date = other.f_date;
	strcpy(this->f_description, other.f_description);
}
//----------------------------------------------------------------------------------------//
void Feedback::setName(const char * name)
{
	//the function sets the feedback's name
	strcpy(this->f_name, name);
}
//----------------------------------------------------------------------------------------//
void Feedback::setDescription(const char * desc)
{
	//the function sets the feedback's description
	strcpy(this->f_description, desc);
}
//----------------------------------------------------------------------------------------//

inline void Feedback::setDate(Date date)
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
Date Feedback::getDate() const
{
	return f_date;
}
