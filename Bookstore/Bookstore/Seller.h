#ifndef SELLER_H
#define SELLER_H
#include "Menu.h"

class Seller
{
	unsigned int sellerID;
	string firstName;
	string lastName;

public:
	static void totalSalesBySeller(unsigned int sellerID, Date start, Date end);
};

#endif 