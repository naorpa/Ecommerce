#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class Feedback
{
private:
	Date f_date;
	string f_name;
	string f_description;
public:
	Feedback() = default;//default c'tor
	Feedback(const string & name, Date date, const string & description);//main c'tor
	Feedback(const Feedback & other);
	Feedback(Feedback && other);
public:
	void setName(const string & fname);
	void setDescription(const string & fdesc);
	void setDate(Date other);
	const string & getName() const;
	const string & getDescription() const;
	Date & getDate();
};

#endif // __FEEDBACK_H
