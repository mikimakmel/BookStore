#include "Sale.h"

Sale::Sale(unsigned int saleID, unsigned int customerID, vector<unsigned int> bookList, unsigned int sellerID, date saleDate, float discount, float totalPrice)
{
	this->saleID = saleID;
	this->customerID = customerID;
	this->bookList = bookList;
	this->sellerID = sellerID;
	this->saleDate = saleDate;
	this->discount = discount;
	this->totalPrice = totalPrice;
}

void Sale::printAllBooksSalesBetween(string start, string end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sale WHERE SDate BETWEEN ? AND ?");
		pstmt->setString(1, start);
		pstmt->setString(2, end);

		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_saleID = rset->getUInt("SaleID");
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			unsigned int temp_sellerID = rset->getUInt("SellerID");
			date temp_saleDate = from_simple_string(rset->getString("SDate"));

			float temp_totalPrice = getSaleTotalPrice(temp_saleID);
			float temp_discount = getSaleDiscount(temp_saleID);
			vector<unsigned int> temp_bookList = getSaleBookList(temp_saleID);

			Sale tempSale(temp_saleID, temp_customerID, temp_bookList, temp_sellerID, temp_saleDate, temp_discount, temp_totalPrice);
			tempSale.printSale();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Sale::printSale()
{
	cout << "Sale: " << this->saleID << "	Total Price: " << this->totalPrice << endl;
}

void Sale::totalStoreIncomeInQuarter(date year, int quarter)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt;
	unsigned int totalIncome = 0;

	if (con)
	{
		switch (quarter)
		{
		case 1:
			pstmt = con->prepareStatement("SELECT * from Sale WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case 2:
			pstmt = con->prepareStatement("SELECT * from Sale WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case 3:
			pstmt = con->prepareStatement("SELECT * from Sale WHERE Date< AND WHERE Date> AND Date=year");
			break;

		case 4:
			pstmt = con->prepareStatement("SELECT * from Sale WHERE Date< AND WHERE Date> AND Date=year");
			break;

		default:
			cout << "Error: Wrong Key... Please Try Again!" << endl << endl;
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

float Sale::getSaleDiscount(unsigned int saleID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from SaleDiscount WHERE SaleID=?");
		pstmt->setInt(1, saleID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		float temp_discount = 0;
		while (rset->next())
		{
			temp_discount = rset->getDouble("Discount");
		}

		delete rset;
		delete pstmt;
		delete con;
		return temp_discount;
	}
}

float Sale::getSaleTotalPrice(unsigned int saleID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from SContains WHERE SaleID=?");
		pstmt->setInt(1, saleID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		float temp_totalPrice = 0;
		while (rset->next())
		{
			unsigned int temp_bookID = rset->getUInt("BookID");
			temp_totalPrice += (rset->getUInt("Amount") * (Book::getBookById(temp_bookID).getBookRetailPrice()));
		}

		delete rset;
		delete pstmt;
		delete con;
		return temp_totalPrice;
	}
}

Sale Sale::getSaleAmount(unsigned int saleID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from SContains WHERE SaleID=?");
		pstmt->setInt(1, saleID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int total_amount = 0;
		while (rset->next())
		{
			unsigned int temp_amount = rset->getUInt("Amount");
			total_amount += temp_amount;
		}

		delete rset;
		delete pstmt;
		delete con;

		vector<unsigned int> bookList;
		date saleDate;
		return Sale(total_amount, 0, bookList, 0, saleDate, 0, 0);
	}
}

vector<unsigned int> Sale::getSaleBookList(unsigned int saleID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from SContains WHERE SaleID=?");
		pstmt->setInt(1, saleID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		vector<unsigned int> temp_bookList;
		while (rset->next())
		{
			unsigned int temp_bookID = rset->getUInt("BookID");
			temp_bookList.push_back(temp_bookID);
		}

		delete rset;
		delete pstmt;
		delete con;
		return temp_bookList;
	}
}
