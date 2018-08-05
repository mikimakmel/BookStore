#ifndef SELLER_H
#define SELLER_H
#include "Menu.h"

class Seller
{
	unsigned int sellerID;
	string firstName;
	string lastName;

public:
	static void totalSalesBySellerBetween(unsigned int sellerID, string start, string end);
};

#endif 