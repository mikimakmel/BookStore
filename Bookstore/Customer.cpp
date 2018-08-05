#include "Customer.h"

Customer::Customer(unsigned int customerID, string firstName, string lastName, string phone, date joinDate)
{
	this->customerID = customerID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phone = phone;
	this->joinDate = joinDate;
}

Customer Customer::getCustomerById(const unsigned int customerID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customer WHERE CustomerID=?");
		pstmt->setInt(1, customerID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			string temp_firstName = rset->getString("FirstName");
			string temp_lastName = rset->getString("LastName");
			string temp_phone = rset->getString("Phone");
			date temp_joinDate = from_simple_string(rset->getString("JoinDate"));

			delete rset;
			delete pstmt;
			delete con;
			return Customer(temp_customerID, temp_firstName, temp_lastName, temp_phone, temp_joinDate);
		}
	}
}

void Customer::amountOfCustomersJoinedSince(string date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customer WHERE JoinDate>=?");
		pstmt->setString(1, date);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int amountOfCustomers = 0;

		while (rset->next())
		{
			amountOfCustomers++;
		}

		delete rset;
		delete pstmt;
		delete con;

		cout << "Amount of customers joined: " << amountOfCustomers << endl;
	}
}

void Customer::totalDiscountForCustomerSince(unsigned int customerID, string date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sale WHERE CustomerID=? AND SDate>=?");
		pstmt->setInt(1, customerID);
		pstmt->setString(2, date);

		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		float tempPrice = 0;
		float totalDiscount = 0;

		while (rset->next())
		{
			unsigned int temp_saleID = rset->getUInt("SaleID");
			tempPrice = Sale::getSaleTotalPrice(temp_saleID);
			totalDiscount += Sale::getSaleDiscount(temp_saleID) * tempPrice;
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Total Discount: " << totalDiscount << endl;
	}
}

void Customer::printAllCustomers()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customer");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			string temp_firstName = rset->getString("FirstName");
			string temp_lastName = rset->getString("LastName");
			string temp_phone = rset->getString("Phone");
			date temp_joinDate = from_simple_string(rset->getString("JoinDate"));

			Customer tempCustomer(temp_customerID, temp_firstName, temp_lastName, temp_phone, temp_joinDate);
			tempCustomer.printCustomer();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Customer::printCustomer()
{
	cout << "Customer: " << this->firstName << " "<< this->lastName << endl;
}

int Customer::AmountOfPurchasesByCustomerSince(unsigned int customerID, date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sale WHERE CustomerID=? AND SDate>=?");
		pstmt->setInt(1, customerID);
		pstmt->setDateTime(2, to_simple_string(date));
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int totalAmount = 0;

		while (rset->next())
		{
			vector<unsigned int> temp_bookList;
			Sale tempSale(0, 0, temp_bookList, 0, date, 0, 0);

			unsigned int temp_saleID = rset->getUInt("SaleID");

			Sale temppp(tempSale.getSaleAmount(temp_saleID));

			//int temp_amount = tempSale.getSaleAmount(temp_saleID);

			totalAmount += temppp.saleID;
		}

		delete rset;
		delete pstmt;
		delete con;

		return totalAmount;
	}
}

void Customer::OurBestCustomerSince(date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customer");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int amountOfCustomers = 0;

		while (rset->next())
		{
			amountOfCustomers++;
		}

		unsigned int temp_customerID = 0, best_customerID = 0, temp_amountOfPurchases = 0, best_amountOfPurchases = 0;

		for (int i = 300; i < 300 + amountOfCustomers; i++)
		{
			temp_amountOfPurchases = AmountOfPurchasesByCustomerSince(i, date);
			//temp_customerID = rset->getUInt("CustomerID");

			if (temp_amountOfPurchases > best_amountOfPurchases)
			{
				best_amountOfPurchases = temp_amountOfPurchases;
				best_customerID = i;
			}
		}

		delete rset;
		delete pstmt;
		delete con;

		Customer bestCustomer(getCustomerById(best_customerID));
		bestCustomer.printCustomer();
	}
}
