#include "Seller.h"

void Seller::totalSalesBySellerBetween(unsigned int sellerID, string start, string end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Sale WHERE SDate BETWEEN ? AND ? AND SellerID = ?");
		pstmt->setString(1, start);
		pstmt->setString(2, end);
		pstmt->setInt(3, sellerID);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		double totalSales = 0;

		while (rset->next())
		{
			unsigned int temp_saleID = rset->getUInt("SaleID");
			totalSales += Sale::getSaleTotalPrice(temp_saleID);
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Seller total sale between: " << totalSales << endl;
	}
}
