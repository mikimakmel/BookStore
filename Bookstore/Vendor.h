#ifndef VENDOR_H
#define VENDOR_H
#include "Book.h"

class Vendor
{
	unsigned int vendorID;
	string vendorName;

public:
	Vendor(unsigned int vendorID, string vendorName);
	static void printAllVendors();
	void printVendor();
	static void vendorWithMostOrdersSince(date date);
	static void totalWorthOfOrdersFromVendorBetween(unsigned int vendorID, string start, string end);
};

#endif 