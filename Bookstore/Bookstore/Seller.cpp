#include "Seller.h"

void Seller::totalSalesBySeller(unsigned int sellerID, Date start, Date end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sales WHERE SellerID=? AND Date=>? AND Date<=?");
		pstmt->setInt(1, sellerID);
		pstmt->setInt(2, start);
		pstmt->setInt(3, end);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		double totalSales = 0;

		while (rset->next())
		{
			totalSales += rset->getDouble("TotalPrice");;
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Seller total saled between: " << totalSales << endl;
	}
}
