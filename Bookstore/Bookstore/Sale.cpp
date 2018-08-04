#include "Sale.h"

Sale::Sale(unsigned int saleID, unsigned int customerID, unsigned int bookID, unsigned int sellerID, Date saleDate, float discount, float totalPrice)
{
	this->saleID = saleID;
	this->customerID = customerID;
	this->bookID = bookID;
	this->sellerID = sellerID;
	this->saleDate = saleDate;
	this->discount = discount;
	this->totalPrice = totalPrice;
}

void Sale::printAllBooksSalesBetween()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sales WHERE Date< && WHERE Date> ");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_saleID = rset->getUInt("SaleID");
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			unsigned int temp_bookID = rset->getUInt("BookID");
			unsigned int temp_sellerID = rset->getUInt("SellerID");
			Date temp_saleDate;/////
			float temp_discount = rset->getDouble("Discount");
			float temp_totalPrice = rset->getDouble("TotalPrice");

			Sale tempSale(temp_saleID, temp_customerID, temp_bookID, temp_sellerID, temp_saleDate, temp_discount, temp_totalPrice);
			tempSale.printSale();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Sale::printSale()
{
	cout << "Sale: " << this->saleID << " Total Price: " << this->totalPrice << endl;
}

void Sale::totalStoreIncomeInQuarter(Date year, Quarter quarter)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt;
	unsigned int totalIncome = 0;

	if (con)
	{
		switch (quarter)
		{
		case Q1:
			pstmt = con->prepareStatement("SELECT * from Sales WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case Q2:
			pstmt = con->prepareStatement("SELECT * from Sales WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case Q3:
			pstmt = con->prepareStatement("SELECT * from Sales WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case Q4:
			pstmt = con->prepareStatement("SELECT * from Sales WHERE Date< AND WHERE Date> AND Date=year");
			break;

		default:
			break;
		}

		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			totalIncome += rset->getUInt("TotalPrice");
		}

		delete rset;
		delete pstmt;
		delete con;
	}

	cout << "Total income in " << quarter << ": " << totalIncome << endl;
}
