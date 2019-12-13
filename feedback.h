#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
class Feedback
{
public:
	static constexpr int MAX_ARR_SIZE = 256;
private:
	Date f_date;
	char f_name[MAX_ARR_SIZE];
	char f_description[MAX_ARR_SIZE];
public:
	Feedback() = default;//default c'tor
	Feedback(const char * name, Date date, const char * description);//main c'tor
	Feedback(const Feedback & other);
	Feedback(Feedback && other);
public:
	void setName(const char * fname);
	void setDescription(const char * fdesc);
	void setDate(Date other);
	const char * getName() const;
	const char * getDescription() const;
	Date getDate() const;
};

#endif // __FEEDBACK_H
