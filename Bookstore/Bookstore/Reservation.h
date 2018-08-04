#ifndef RESERVATION_H
#define RESERVATION_H
#include "Book.h"
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;

enum Status {Pending, Arrived, CustomerNotified, sold};

class Reservation
{
	unsigned int customerID;
	unsigned int bookID;
	date reservationDate;
	string status;

public:
	Reservation(unsigned int customerID, unsigned int bookID, Date reservationDate, string status);
	static void printAllReservations();
	void printReservation();
	static void amountOfReservationsBetween(Date start, Date end);
	static void amountOfReservationsTurnedToSalesBetween(Date start, Date end);
};

#endif 