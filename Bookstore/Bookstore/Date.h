#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	bool setDay(int);
	bool setMonth(int);
	bool setYear(int);
	inline int getDay() const { return this->day; }
	inline int getMonth() const { return this->month; }
	inline int getYear() const { return this->year; }
	void printDate();
};

Date convertStringtoDate(char*);

#endif 