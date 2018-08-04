#include "Reservation.h"

Reservation::Reservation(unsigned int customerID, unsigned int bookID, Date reservationDate, string status)
{
	this->customerID = customerID;
	this->bookID = bookID;
	this->reservationDate = reservationDate;
	this->status = status;
}

void Reservation::printAllReservations()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservations");
		ResultSet *rset = pstmt->executeQuery();
		rset->beforeFirst();

		while (rset->next())
		{
			unsigned int temp_customerID = rset->getUInt("CustomerID");
			unsigned int temp_bookID = rset->getUInt("BookID");
			Date temp_reservationDate;/////
			string temp_status = rset->getString("Status");

			Reservation tempReservation(temp_customerID, temp_bookID, temp_reservationDate, temp_status);
			tempReservation.printReservation();
		}

		delete rset;
		delete pstmt;
		delete con;
	}
}

void Reservation::printReservation()
{
	cout << "Reservation for book: " << this->bookID << " Status: " << this->status << endl;
}

void Reservation::amountOfReservationsBetween(Date start, Date end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservations WHERE Date=>? AND Date<=?");
		pstmt->setInt(1, start);
		pstmt->setInt(2, end);
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

void Reservation::amountOfReservationsTurnedToSalesBetween(Date start, Date end)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();

	if (con)
	{
		PreparedStatement *pstmt = con->prepareStatement("SELECT * from Reservations WHERE Date=>? AND Date<=? AND Status=sold");
		pstmt->setInt(1, start);
		pstmt->setInt(2, end);
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
