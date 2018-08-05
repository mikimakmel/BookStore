#include "Book.h"

Book::Book(unsigned int bookID, string author, string title, float retailPrice, float discount, unsigned int stock)
{
	this->bookID = bookID;
	this->author = author;
	this->title = title;
	this->retailPrice = retailPrice;
	this->discount = discount;
	this->stock = stock;
}

Book Book::getBookById(const unsigned int bookID)
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
			unsigned int temp_stock = rset->getUInt("Stock");

			delete rset;
			delete pstmt;
			delete con;
			return Book(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_stock);
		}
	}
}

void Book::printAllBooksInStock()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Books WHERE Stock>0");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_bookID = rset->getUInt("BookID");
			string temp_author = rset->getString("Author");
			string temp_title = rset->getString("Title");
			float temp_retailPrice = rset->getDouble("RetailPrice");
			float temp_discount = rset->getDouble("Discount");
			unsigned int temp_stock = rset->getUInt("Stock");

			Book tempBook(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_stock);
			tempBook.printBook();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Book::printAllBooksInDiscount()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Books WHERE Discount>0");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_bookID = rset->getUInt("BookID");
			string temp_author = rset->getString("Author");
			string temp_title = rset->getString("Title");
			float temp_retailPrice = rset->getDouble("RetailPrice");
			float temp_discount = rset->getDouble("Discount");
			unsigned int temp_stock = rset->getUInt("Stock");

			Book tempBook(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_stock);
			tempBook.printBook();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

bool Book::checkIfBookIsInStock(const unsigned int bookID)
{
	Book tempBook(getBookById(bookID));
	if (tempBook.stock > 0) return true;
	else return false;
}

void Book::totalCopiesOfBookSoldSince(const unsigned int bookID, string date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sale WHERE SDate>=?");
		pstmt->setString(1, date);
		//pstmt->setString(2, date);

		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int copiesSold = 0;

		while (rset->next())
		{
			copiesSold += rset->getInt("Amount");
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Copies sold: " << copiesSold << endl;
	}
}

void Book::viewBookVendorsList(const unsigned int bookID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from SupPricing WHERE BookID=?");
		pstmt->setInt(1, bookID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_vendorID = rset->getUInt("VendorID");
			cout << "Vendor ID: " << temp_vendorID << endl;
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Book::bestSellersBooksBetween(date start, date end)
{
}

float Book::getBookRetailPrice() const
{
	return this->retailPrice;
}

void Book::printBook() const
{
	cout << "Book Title: " << this->title << endl;
}
