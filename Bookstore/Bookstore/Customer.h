#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Database.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

class Customer
{
	unsigned int customerID;
	string firstName;
	string lastName;
	long phone;
	float totalpurchases;
	date joinDate;
	unsigned int purchasesCount;

public:
	Customer(unsigned int customerID, string firstName, string lastName, long phone, float totalpurchases, Date joinDate, unsigned int purchasesCount = 0);
	static void printAllCustomers();
	void printCustomer();
	static unsigned int AmountOfPurchasesByCustomerSince(unsigned int customerID, Date date);
	static void OurBestCustomerSince(Date date);
	static Customer getCustomerById(const unsigned int customerID);
	static void amountOfCustomersJoinedSince(Date date);
};

#endif 