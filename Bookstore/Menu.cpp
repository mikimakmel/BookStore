#include "Menu.h"

void menu()
{
	int menu_choice;
	bool check;
	string buffer, buffer2, buffer3;

	cout << "*_Makmel&Cohen Book Store_*" << endl << endl;

	while (1)
	{
		cout << endl << endl << "MENU:" << endl << "____________________________________________________________________________" << endl;
		cout << "1) View all books in stock" << endl;
		cout << "2) View all books reservations" << endl;
		cout << "3) Show customers list" << endl;
		cout << "4) Show vendors list" << endl;
		cout << "5) View all books sales between dates..." << endl;
		cout << "6) Show all books on sale" << endl;
		cout << "7) Check if book X is in stock" << endl;
		cout << "8) View book X vendors list" << endl;
		cout << "9) Total copies of book X sold since..." << endl;
		cout << "10) Amount of purchases made by Customer X since..." << endl;
		cout << "11) Our best customer since..." << endl;
		cout << "12) Vendor with the most orders since..." << endl;
		cout << "13) Total of books reservations between dates..." << endl;
		cout << "14) Amount of books reservations turned in to sales between dates..." << endl;
		cout << "15) Total discount for customer X since..." << endl;
		cout << "16) Total store income in quarter X" << endl;
		cout << "17) Amount of customers joined since..." << endl;
		cout << "18) Total worth of orders made from vendor X between dates..." << endl;
		cout << "19) Total worth of sales made by seller X between dates..." << endl;
		cout << "20) Top 10: Best seller books between dates..." << endl;
		cout << "*** To Exit type: 0" << endl << endl;
		cout << "Enter Your Choice Here: ";

		cin >> menu_choice;
		cout << endl << endl;

		switch (menu_choice)
		{
		case 1://
			cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Book::printAllBooksInStock();
			cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 2://
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Reservation::printAllReservations();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
			
		case 3://
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Customer::printAllCustomers();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 4://
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Vendor::printAllVendors();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 5: //
		{
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Sale::printAllBooksSalesBetween(buffer, buffer2);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 6: //
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Book::printAllBooksInDiscount();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 7: //
			cout << "Please enter book ID: ";
			cin >> buffer;
			check = Book::checkIfBookIsInStock(stoi(buffer));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			if(check) cout << "YES" << endl;
			else cout << "NO" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 8: //
			cout << "Please enter book ID: ";
			cin >> buffer;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Book::viewBookVendorsList(stoi(buffer));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		case 9: //*************************************************************************************//
		{
			cout << "Please enter book ID: ";
			cin >> buffer;
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Book::totalCopiesOfBookSoldSince(stoi(buffer), buffer2);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 10: // 
		{
			cout << "Please enter customer ID: ";
			cin >> buffer;
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			date tempDate(from_simple_string(buffer2));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << Customer::AmountOfPurchasesByCustomerSince(stoi(buffer), tempDate) << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 11: //
		{
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer;
			date tempDate(from_simple_string(buffer));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Customer::OurBestCustomerSince(tempDate);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 12: //*************************************************************************************//
		{
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer;
			date tempDate(from_simple_string(buffer));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Vendor::vendorWithMostOrdersSince(tempDate);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 13: //
		{
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Reservation::amountOfReservationsBetween(buffer, buffer2);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 14: //
		{
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Reservation::amountOfReservationsTurnedToSalesBetween(buffer, buffer2);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 15: //
		{
			cout << "Please enter customer ID: ";
			cin >> buffer;
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Customer::totalDiscountForCustomerSince(stoi(buffer), buffer2);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 16: //*************************************************************************************//
		{
			cout << "Please enter a year YYYY: ";
			cin >> buffer;
			cout << "Please enter quarter (1/2/3/4): ";
			cin >> buffer2;
			date tempDate(stoi(buffer2), 1, 1);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Sale::totalStoreIncomeInQuarter(tempDate, stoi(buffer));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 17: //
		{
			cout << "Please enter a date using this template YYYY-MM-DD: ";
			cin >> buffer;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Customer::amountOfCustomersJoinedSince(buffer);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 18: //*************************************************************************************//
		{
			cout << "Please enter vendor ID: ";
			cin >> buffer;
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer3;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Vendor::totalWorthOfOrdersFromVendorBetween(stoi(buffer), buffer2, buffer3);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 19: //
		{
			cout << "Please enter seller ID: ";
			cin >> buffer;
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer3;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Seller::totalSalesBySellerBetween(stoi(buffer), buffer2, buffer3);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 20: //*************************************************************************************//
		{
			cout << "Please enter a *Starting* date using this template YYYY-MM-DD: ";
			cin >> buffer;
			cout << "Please enter a *Ending* date using this template YYYY-MM-DD: ";
			cin >> buffer2;
			date startDate(from_simple_string(buffer));
			date endDate(from_simple_string(buffer2));
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			Book::bestSellersBooksBetween(startDate, endDate);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}

		case 0:
			cout << endl << "Good Day!";
			return;

		default:
			cout << "Error: Wrong Key... Please Try Again!" << endl << endl;
		}
	}
}
