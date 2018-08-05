#include "Vendor.h"

Vendor::Vendor(unsigned int vendorID, string vendorName)
{
	this->vendorID = vendorID;
	this->vendorName = vendorName;
}

void Vendor::printAllVendors()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Vendor");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_vendorID = rset->getUInt("VendorID");
			string temp_vendorName = rset->getString("VendorName");

			Vendor tempVendor(temp_vendorID, temp_vendorName);
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

void Vendor::vendorWithMostOrdersSince(date date)
{
}

void Vendor::totalWorthOfOrdersFromVendorBetween(unsigned int vendorID, string start, string end)
{
}
