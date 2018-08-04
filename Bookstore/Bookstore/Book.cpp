#include "Book.h"

Book::Book(unsigned int bookID, string author, string title, float retailPrice, float discount, bool isInStoke)
{
	this->bookID = bookID;
	this->author = author;
	this->title = title;
	this->retailPrice = retailPrice;
	this->discount = discount;
	this->isInStoke = isInStoke;
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
			bool temp_isInStoke = rset->getBoolean("isInStock");

			Book tempBook(temp_bookID, temp_author, temp_title, temp_retailPrice, temp_discount, temp_isInStoke);
			tempBook.printBook();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

bool Book::checkIfBookIsInStoke(const unsigned int bookID)
{
	Book tempBook(getBookById(bookID));
	return tempBook.isInStoke;
}

void Book::totalCopiesOfBookSoldSince(const unsigned int bookID, date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sales WHERE BookID=? AND Date>=?");
		pstmt->setInt(1, bookID);
		pstmt->setDateTime(2, to_simple_string(date));
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int copiesSold = 0;

		while (rset->next())
		{
			copiesSold++;
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Copies sold: " << copiesSold << endl;
	}
}

//Book::~Book()
//{
//	delete this;
//}

unsigned int Book::getBookID() const
{
	return this->bookID;
}

string Book::getAuthor() const
{
	return this->author;
}

string Book::getTitle() const
{
	return this->title;
}

float Book::getRetailPrice() const
{
	return this->retailPrice;
}

float Book::getDiscount() const
{
	return this->discount;
}

bool Book::getIsInStoke() const
{
	return this->isInStoke;
}

void Book::printBook() const
{
	cout << "Book Title: " << this->title << endl;
}
