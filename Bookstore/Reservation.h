#ifndef RESERVATION_H
#define RESERVATION_H
#include "Book.h"

enum Status {Pending = 1, Arrived, CustomerNotified, Sold};

class Reservation
{
	unsigned int reservationID;
	unsigned int customerID;
	unsigned int sellerID;
	date reservationDate;
	int status;

public:
	Reservation(unsigned int reservationID, unsigned int customerID, unsigned int sellerID, date reservationDate, int status);
	static void printAllReservations();
	void printReservation();
	static void amountOfReservationsBetween(string start, string end);
	static void amountOfReservationsTurnedToSalesBetween(string start, string end);
};

#endif 