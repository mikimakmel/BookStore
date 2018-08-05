#ifndef SALE_H
#define SALE_H
#include "Menu.h"
#include <vector>

class Sale
{
	unsigned int customerID;
	vector<unsigned int> bookList;
	unsigned int sellerID;
	date saleDate;
	float discount;
	float totalPrice;

public:
	unsigned int saleID;
	Sale(unsigned int saleID, unsigned int customerID, vector<unsigned int> bookList, unsigned int sellerID, date saleDate, float discount, float totalPrice);
	static void printAllBooksSalesBetween(string start, string end);
	void printSale();
	static void totalStoreIncomeInQuarter(date year, int quarter);
	static float getSaleDiscount(unsigned int saleID);
	static float getSaleTotalPrice(unsigned int saleID);
	Sale getSaleAmount(unsigned int saleID);
	static vector<unsigned int> getSaleBookList(unsigned int saleID);

};

#endif 