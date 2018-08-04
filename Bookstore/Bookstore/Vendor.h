#ifndef VENDOR_H
#define VENDOR_H
#include "Date.h"
#include "Book.h"

class Vendor
{
	unsigned int vendorID;
	string vendorName;
	float vendorPrice;
	vector<Book> booksList;

public:
	Vendor(unsigned int vendorID, string vendorName, float vendorPrice/*, vector<Book> booksList*/);
	static void printAllVendors();
	void printVendor();
};

#endif 