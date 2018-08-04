#include "Vendor.h"

Vendor::Vendor(unsigned int vendorID, string vendorName, float vendorPrice/*, vector<Book> booksList*/)
{
	this->vendorID = vendorID;
	this->vendorName = vendorName;
	this->vendorPrice = vendorPrice;
	this->booksList = booksList;
}

void Vendor::printAllVendors()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Vendors");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_vendorID = rset->getUInt("vendorID");
			string temp_vendorName = rset->getString("vendorName");
			float temp_vendorPrice = rset->getDouble("vendorPrice");
	/*		vector<Book> temp_booksList = rset->getUInt("PurchasesCount");*/

			Vendor tempVendor(temp_vendorID, temp_vendorName, temp_vendorPrice/*, vector<Book> booksList*/);
			tempVendor.printVendor();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Vendor::printVendor()
{
	cout << "Vendor: " << this->vendorName << endl;
}
