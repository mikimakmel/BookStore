#ifndef MENU_H
#define MENU_H
//#include <iostream>
//#include <string>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;
using namespace boost::gregorian;
//#include "Customer.h"
#include "Book.h"
//#include "Vendor.h"
//#include "Seller.h"
//#include "Reservation.h"
//#include "Sale.h"
//using namespace std;

void menu()
{
	int menu_choice;
	string buffer, buffer2;
	/*date tempDate;*/
/*	date tempDate(from_simple_string(buffer));;
	std::cout << to_simple_string(d) << std::endl;
*/

	cout << "*_Makmel&Cohen Book Store_*" << endl << endl;

	while (1)
	{
		cout << endl << endl << "MENU:" << endl << "____________________________________________________________________________" << endl;
		cout << "1) View all books in stock" << endl;
		cout << "2) View open books orders (in process)" << endl;
		cout << "3) Show customers list" << endl;
		cout << "4) Show vendors list" << endl;
		cout << "5) View all books sales between (dd/mm/yyyy-dd/mm/yyyy)" << endl;
		cout << "6) Show books on sale" << endl;
		cout << "7) Check if book X is in stock" << endl;
		cout << "8) Show book X vendors list" << endl;
		cout << "9) Total copies of book X sold since (YYYY-MM-DD)" << endl;
		cout << "10) Amount of purchases made by Customer X since (dd/mm/yyyy)" << endl;
		cout << "11) Our best customer since (dd/mm/yyyy)" << endl;
		cout << "12) Vendor with the most orders since (dd/mm/yyyy)" << endl;
		cout << "13) Amount of book orders between (dd/mm/yyyy-dd/mm/yyyy)" << endl;
		cout << "14) Amount of books orders turned in to sales between (dd/mm/yyyy-dd/mm/yyyy)" << endl;
		cout << "15) Total discount for customer X since (dd/mm/yyyy)" << endl;
		cout << "16) Total store income in quarter X" << endl;
		cout << "17) Amount of customers joined since (dd/mm/yyyy)" << endl;
		cout << "18) Total worth of sales made from vendor X" << endl;
		cout << "19) Total worth of sales made by seller X" << endl;
		cout << "20) Top 10: Best seller books between (dd/mm/yyyy-dd/mm/yyyy)" << endl;
		cout << "*** To Exit type: 0" << endl << endl;
		cout << "Enter Your Choice Here: ";

		cin >> menu_choice;
		cout << endl << endl;

		switch (menu_choice)
		{
		case 1:
			Book::printAllBooksInStoke();
			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5:
			cout << "Please enter a *Starting* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			cout << "Please enter a *Ending* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 6:

			break;

		case 7:

			break;

		case 8:

			break;

		case 9:
			cout << "Please enter book ID: ";
			cin >> buffer;
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			date tempDate(from_simple_string(buffer2));
			Book::totalCopiesOfBookSoldSince(stoi(buffer), tempDate);
			break;

		case 10:
			cout << "Please enter a date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			return;

		case 11:
			cout << "Please enter a date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 12:
			cout << "Please enter a date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 13:
			cout << "Please enter a *Starting* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			cout << "Please enter a *Ending* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 14:
			cout << "Please enter a *Starting* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			cout << "Please enter a *Ending* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 15:
			cout << "Please enter a date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 16:

			break;

		case 17:
			cout << "Please enter a date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 18:

			break;

		case 19:

			break;

		case 20:
			cout << "Please enter a *Starting* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			cout << "Please enter a *Ending* date using this template dd/mm/yy: ";
			cin >> buffer;
			convertStringtoDate(buffer);
			break;

		case 0:
			cout << endl << "Good Day!";
			return;

		default:
			cout << "Error: Wrong Key... Please Try Again!" << endl << endl;
		}
	}
}

#endif