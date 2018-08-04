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
	unsigned int stoke;///////////////////////
	bool isInStoke;
	//vector<Vendor> vendorsList;

public:
	//void setBookID(const unsigned int id);
	//void setAuthor(const string author);
	//void setTitle(const string title);
	//void setRetailPrice(const float price);
	//void setDiscount(const float discount);
	//void setIsInStoke(const bool stoke);

	unsigned int getBookID() const;
	string getAuthor() const;
	string getTitle() const;
	float getRetailPrice() const;
	float getDiscount() const;
	bool getIsInStoke() const;
	void printBook() const;

	Book(unsigned int bookID, string author, string title, float retailPrice, float discount, bool isInStoke = false);
	//~Book();

	static Book getBookById(const unsigned int bookID)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		if (con)
		{
			PreparedStatement *pstmt = con->prepareStatement("SELECT * from Books WHERE BookID=?");
			pstmt->setInt(1, bookID);
			ResultSet *rset = pstmt->executeQuery();
			rset->beforeFirst();

			while (rset->next()) 
			{
				unsigned int temp_bookID = rset->getUInt("BookID");
				string temp_author = rset->getString("Author");
				string temp_title = rset->getString("Title");
				float temp_retailPrice = rset->getDouble("RetailPrice");
				float temp_discount = rset->getDouble("Discount");
				bool temp_isInStoke = rset->getBoolean("isInStock");

				//Book *bookPtr = new Book(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_isInStoke);
				delete rset;
				delete pstmt;
				delete con;
				return Book(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_isInStoke);
			}
		}
	}

	static void printAllBooksInStoke()
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();

		if (con) 
		{
			PreparedStatement *pstmt = con->prepareStatement("SELECT * from Books WHERE isInStock=true");
			ResultSet *rset = pstmt->executeQuery();
			rset->beforeFirst();

			while (rset->next()) 
			{
				unsigned int temp_bookID = rset->getUInt("BookID");
				string temp_author = rset->getString("Author");
				string temp_title = rset->getString("Title");
				float temp_retailPrice = rset->getDouble("RetailPrice");
				float temp_discount = rset->getDouble("Discount");
				bool temp_isInStoke = rset->getBoolean("isInStock");

				Book tempBook(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_isInStoke);
				tempBook.printBook();
			}

			delete rset;
			delete pstmt;
			delete con;
		}
	}

	static void printAllBooksInDiscount();

	static bool checkIfBookIsInStoke(const unsigned int bookID);

	static void totalCopiesOfBookSoldSince(const unsigned int bookID, date date);
};

#endif 