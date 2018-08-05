#include "Reservation.h"

Reservation::Reservation(unsigned int reservationID, unsigned int customerID, unsigned int sellerID, date reservationDate, int status)
{
	this->reservationID = reservationID;
	this->customerID = customerID;
	this->sellerID = sellerID;
	this->reservationDate = reservationDate;
	this->status = status;
}

void Reservation::printAllReservations()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservation");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_reservationID = rset->getUInt("ReservationID");
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			unsigned int temp_sellerID = rset->getUInt("SellerID");
			date temp_reservationDate = from_simple_string(rset->getString("RDate"));
			int temp_status = rset->getInt("RStatus");

			Reservation tempReservation(temp_reservationID, temp_customerID, temp_sellerID, temp_reservationDate, temp_status);
			tempReservation.printReservation();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Reservation::printReservation()
{
	cout << "Reservation ID: " << this->reservationID;

	switch (this->status)
	{
	case 1:
		cout << " Status: Pending" << endl;
		break;

	case 2:
		cout << " Status: Arrived" << endl;
		break;

	case 3:
		cout << " Status: CustomerNotified" << endl;
		break;

	case 4:
		cout << " Status: Sold" << endl;
		break;
	default:
		break;
	}
}

void Reservation::amountOfReservationsBetween(string start, string end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservation WHERE RDate BETWEEN ? AND ?");
		pstmt->setString(1, start);
		pstmt->setString(2, end);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int reservationsCount = 0;

		while (rset->next())
		{
			reservationsCount++;
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Resrevation between: " << reservationsCount << endl;
	}
}

void Reservation::amountOfReservationsTurnedToSalesBetween(string start, string end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservation WHERE RDate BETWEEN ? AND ? AND RStatus = 4");
		pstmt->setString(1, start);
		pstmt->setString(2, end);
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		int reservationsCount = 0;

		while (rset->next())
		{
			reservationsCount++;
		}

		delete rset;
		delete pstmt;
		delete con;
		cout << "Resrevation turned to sale: " << reservationsCount << endl;
	}
}
