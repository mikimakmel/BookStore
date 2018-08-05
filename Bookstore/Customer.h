#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Database.h"
#include "Sale.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

class Customer
{
	unsigned int customerID;
	string firstName;
	string lastName;
	string phone;
	date joinDate;

public:
	Customer(unsigned int customerID, string firstName, string lastName, string phone, date joinDate);
	static void printAllCustomers();
	void printCustomer();
	static int AmountOfPurchasesByCustomerSince(unsigned int customerID, date date);
	static void OurBestCustomerSince(date date);
	static Customer getCustomerById(const unsigned int customerID);
	static void amountOfCustomersJoinedSince(string date);
	static void totalDiscountForCustomerSince(unsigned int customerID, string date);
};

#endif 