#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;
#include "Customer.h"
#include "Book.h"
#include "Vendor.h"
#include "Seller.h"
#include "Reservation.h"
#include "Sale.h"
using namespace std;

void menu();

#endif