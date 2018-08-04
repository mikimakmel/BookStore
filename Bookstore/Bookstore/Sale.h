#ifndef SALE_H
#define SALE_H
#include "Menu.h"

enum Quarter { Q1, Q2, Q3, Q4 };

class Sale
{
	unsigned int saleID;
	unsigned int customerID;
	unsigned int bookID;
	unsigned int sellerID;
	Date saleDate;
	float discount;
	float totalPrice;

public:
	Sale(unsigned int saleID, unsigned int customerID, unsigned int bookID, unsigned int sellerID, Date saleDate, float discount, float totalPrice);
	static void printAllBooksSalesBetween();
	void printSale();
	static void totalStoreIncomeInQuarter(Date year, Quarter quarter);
};

#endif 