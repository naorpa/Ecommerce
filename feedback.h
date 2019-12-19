#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class Feedback
{
private:
	Date f_date;
	char * f_name;
	char * f_description;
public:
	Feedback() = default;//default c'tor
	Feedback(const char * name, Date date, const char * description);//main c'tor
	Feedback(const Feedback & other);
	Feedback(Feedback && other);
	~Feedback();
public:
	void setName(const char * fname);
	void setDescription(const char * fdesc);
	void setDate(Date other);
	const char * getName() const;
	const char * getDescription() const;
	Date getDate() const;
};

#endif // __FEEDBACK_H
