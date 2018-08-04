#include "Customer.h"

Customer::Customer(unsigned int customerID, string firstName, string lastName, long phone, float totalpurchases, Date joinDate, unsigned int purchasesCount)
{
	this->customerID = customerID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->phone = phone;
	this->totalpurchases = totalpurchases;
	this->joinDate = joinDate;
	this->purchasesCount = purchasesCount;
}

Customer Customer::getCustomerById(const unsigned int customerID)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customers WHERE customerID=?");
		pstmt->setInt(1, customerID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			string temp_firstName = rset->getString("FirstName");
			string temp_lastName = rset->getString("LastName");
			long temp_phone = rset->getInt64("Phone");
			float temp_totalpurchases = rset->getDouble("Totalpurchases");
			Date temp_joinDate;/////
			unsigned int temp_purchasesCount = rset->getUInt("PurchasesCount");

			delete rset;
			delete pstmt;
			delete con;
			return Customer(temp_customerID, temp_firstName, temp_lastName, temp_phone, temp_totalpurchases, temp_joinDate, temp_purchasesCount);
		}
	}
}

void Customer::amountOfCustomersJoinedSince(Date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customers WHERE JoinsDate>?");
		pstmt->setInt(1, date);
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

		cout << "Amount of customers joined: " << amountOfCustomers;
	}
}

void Customer::printAllCustomers()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customers WHERE PurchasesCount>0");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			string temp_firstName = rset->getString("FirstName");
			string temp_lastName = rset->getString("LastName");
			long temp_phone = rset->getInt64("Phone");
			float temp_totalpurchases = rset->getDouble("Totalpurchases");
			Date temp_joinDate;/////
			unsigned int temp_purchasesCount = rset->getUInt("PurchasesCount");

			Customer tempCustomer(temp_customerID, temp_firstName, temp_lastName, temp_phone, temp_totalpurchases, temp_joinDate, temp_purchasesCount);
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

unsigned int Customer::AmountOfPurchasesByCustomerSince(unsigned int customerID, Date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sales WHERE CustomerID=? AND Date>?");
		pstmt->setInt(1, customerID);
		//pstmt->setDateTime(2, date);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int totalAmount = 0;

		while (rset->next())
		{
			totalAmount += rset->getUInt("Amount");
		}

		delete rset;
		delete pstmt;
		delete con;

		return totalAmount;
	}
}

void Customer::OurBestCustomerSince(Date date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Customers");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int amountOfCustomers = 0;

		while (rset->next())
		{
			amountOfCustomers++;
		}

		unsigned int temp_customerID = 0, best_customerID = 0, temp_amountOfPurchases = 0, best_amountOfPurchases = 0;

		for (int i = 100; i < 100 + amountOfCustomers; i++)
		{
			temp_amountOfPurchases = AmountOfPurchasesByCustomerSince(i, date);
			temp_customerID = rset->getUInt("CustomerID");

			if (temp_amountOfPurchases > best_amountOfPurchases)
			{
				best_amountOfPurchases = temp_amountOfPurchases;
				best_customerID = temp_customerID;
			}
		}

		delete rset;
		delete pstmt;
		delete con;

		Customer bestCustomer(getCustomerById(best_customerID));
		bestCustomer.printCustomer();
	}
}
