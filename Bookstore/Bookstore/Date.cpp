#include "Date.h"

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(int day, int month, int year)
{
	if ((day > 0 && day < 32) && (month > 0 && month < 13) && (year >= 0))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		std::cout << "Invalid Date entered" << endl;
	}
}

bool Date::setDay(int day)
{
	if (day > 0 && day < 32)
	{
		this->day = day;
		return true;
	}
	else
	{
		std::cout << "Invalid Date entered" << endl;
		return false;
	}
}

bool Date::setMonth(int month)
{
	if (month > 0 && month < 13)
	{
		this->month = month;
		return true;
	}
	else {
		std::cout << "Invalid Date entered" << endl;
		return false;
	}
}

bool Date::setYear(int year)
{
	if (year > 0)
	{
		this->year = year;
		return true;
	}
	else {
		std::cout << "Invalid Date entered" << endl;
		return false;
	}
}

void Date::printDate()
{
	cout << this->getDay() << "/" << this->getMonth() << "/" << this->getYear() << endl;
}

Date convertStringtoDate(char* tempString)
{
	int day, month, year;
	char* tok;

	tok = strtok(tempString, "/");
	day = atoi(tok);
	tok = strtok(NULL, "/");
	month = atoi(tok);
	tok = strtok(NULL, "/");
	year = atoi(tok);

	return Date(day, month, year);
}