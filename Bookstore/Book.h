#ifndef BOOK_H
#define BOOK_H
#include "Database.h"
#include <iostream>
#include <string>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;

class Book
{
	unsigned int bookID;
	string author;
	string title;
	float retailPrice;
	float discount;
	unsigned int stock;

public:
	Book(unsigned int bookID, string author, string title, float retailPrice, float discount, unsigned int stock);

	void printBook() const;
	static Book getBookById(const unsigned int bookID);
	static void printAllBooksInStock();
	static void printAllBooksInDiscount();
	static bool checkIfBookIsInStock(const unsigned int bookID);
	static void totalCopiesOfBookSoldSince(const unsigned int bookID, string date);
	static void viewBookVendorsList(const unsigned int bookID);
	static void bestSellersBooksBetween(date start, date end);

	float getBookRetailPrice() const;
};

#endif 