CREATE database if not exists bookStore_db;
use bookStore_db;

CREATE table if not exists Books (
	BookID int unsigned auto_increment, 
    Author varchar(30) not null,
    Title varchar(50) not null,
    Discount float(2),
    RetailPrice float (2) unsigned,
    Stock int unsigned,
    PRIMARY KEY (BookID)
);

ALTER table Books auto_increment=100;

insert into Books (Author, Title, Discount, RetailPrice, Stock)
	values ('Miki', 'First', 0.2, 90, 0);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Lev', 'Second', 0.1, 110, 10);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Yossi', 'Third', 0.1, 40, 20);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Shlomi', 'Fourth', 0.1, 50, 30);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
	values ('Shooki', 'First', 0.2, 25, 40);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Miki', 'Second', 0.1, 130, 50);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Ori', 'Third', 0.1, 100, 60);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Dor', 'Fourth', 0.1, 55, 70);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
	values ('Guy', 'First', 0.2, 60, 80);
insert into Books (Author, Title, Discount, RetailPrice, Stock)
    values ('Yam', 'Second', 0.1, 120, 90);

CREATE table if not exists Vendor (
	VendorID int unsigned auto_increment, 
    VendorName varchar(50) not null,
    PRIMARY KEY (VendorID)
);

ALTER table Vendor auto_increment=200;

insert into Vendor (VendorName)
	values ('Salah');
insert into Vendor (VendorName)
	values ('Shmekel');
insert into Vendor (VendorName)
	values ('Walid');
insert into Vendor (VendorName)
	values ('Yocheved');
insert into Vendor (VendorName)
	values ('Yocheved');
insert into Vendor (VendorName)
	values ('Salah');
insert into Vendor (VendorName)
	values ('Walid');
insert into Vendor (VendorName)
	values ('Shlumper');
insert into Vendor (VendorName)
	values ('Portal'); 
insert into Vendor (VendorName)
	values ('GOT');
    
    
CREATE table if not exists Customer (
	CustomerID int unsigned auto_increment, 
    FirstName varchar(20) not null,
    LastName varchar(20) not null,
    Phone varchar(10) UNIQUE,
    JoinDate date,
    PRIMARY KEY (CustomerID)
);

ALTER table Customer auto_increment=300;

insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Shmuel', 'Shmuel', '0547881728', '2001-11-29');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Jack', 'Black', '0549802928', '2010-10-20');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('John', 'Cena', '0522222928', '2017-07-10');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Sasha', 'Grey', '0537641728', '2001-11-29');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Shlomit', 'Malka', '0549801118', '2015-06-20');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Jesus', 'Shmuel', '0549332928', '1999-01-01');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Snoop', 'Dogg', '0543531728', '2018-02-28');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Paul', 'Cena', '0549800098', '2010-10-20');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Paul', 'Sean', '0500122928', '2017-07-10');
insert into Customer (FirstName, LastName, Phone, JoinDate)
	values ('Shira', 'Star', '0547812345', '2001-11-29');
    
CREATE table if not exists Seller (
	SellerID int unsigned auto_increment, 
    FirstName varchar(20) not null,
    LastName varchar(20) not null,
    PRIMARY KEY (SellerID)
);

ALTER table Seller auto_increment=900;

insert into Seller (FirstName, LastName)
	values ('Asli', 'Linden');
insert into Seller (FirstName, LastName)
	values ('Dagon', 'Berg');
insert into Seller (FirstName, LastName)
	values ('Nikolett', 'Hurst');
insert into Seller (FirstName, LastName)
	values ('Evdokiya', 'Junge');
insert into Seller (FirstName, LastName)
	values ('Corina', 'West');
insert into Seller (FirstName, LastName)
	values ('Kumar', 'Andres');
insert into Seller (FirstName, LastName)
	values ('Lyuba', 'Kavanagh');
insert into Seller (FirstName, LastName)
	values ('Dante', 'Marko');
insert into Seller (FirstName, LastName)
	values ('Hiba', 'Thwaite');
insert into Seller (FirstName, LastName)
	values ('Rena', 'Varela');
    
CREATE table if not exists Reservation (
	ReservationID int unsigned auto_increment, 
    RStatus tinyint unsigned not null,
    RDate date,
    CustomerID int unsigned,
    SellerID int unsigned,
    PRIMARY KEY (ReservationID),
    CONSTRAINT FK_CustomerID
		FOREIGN KEY (CustomerID)
        REFERENCES Customer (CustomerID)
			ON DELETE RESTRICT
            ON UPDATE CASCADE,
	CONSTRAINT FK_SellerID
		FOREIGN KEY (SellerID)
        REFERENCES Seller (SellerID)
			ON DELETE RESTRICT
            ON UPDATE CASCADE
);

ALTER table Reservation auto_increment=400;

insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (1, '2011-11-29', 301, 900);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (4, '2015-02-22', 303, 901);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (2, '2017-10-01', 300, 907);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (3, '2015-02-28', 302, 905);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (1, '2011-11-29', 305, 900);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (4, '2016-06-26', 306, 901);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (2, '2017-10-11', 307, 902);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (3, '2015-03-29', 308, 909);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (2, '2016-12-01', 301, 907);
insert into Reservation (RStatus, RDate, CustomerID, SellerID)
	values (3, '2015-01-01', 308, 905);

CREATE table if not exists Sale (
	SaleID int unsigned auto_increment, 
    SDate date,
    CustomerID int unsigned,
    SellerID int unsigned,
    TotalPrice float(2),
    PRIMARY KEY (SaleID),
    CONSTRAINT SFK_CustomerID
		FOREIGN KEY (CustomerID)
        REFERENCES Customer (CustomerID)
			ON DELETE RESTRICT
            ON UPDATE CASCADE,
	CONSTRAINT SFK_SellerID
		FOREIGN KEY (SellerID)
        REFERENCES Seller (SellerID)
			ON DELETE RESTRICT
            ON UPDATE CASCADE
);

ALTER table Sale auto_increment=500;

insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2011-11-29', 301, 900, 7200);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2015-02-22', 303, 901, 990);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2017-10-01', 300, 907, 5400);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2015-02-28', 302, 905, 2250);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2011-11-29', 305, 900, 100);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2016-06-26', 306, 901, 11700);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2017-10-11', 307, 902, 900);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2015-03-29', 308, 909, 7425);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2016-12-01', 301, 907, 2400);
insert into Sale (SDate, CustomerID, SellerID, TotalPrice)
	values ('2015-01-01', 308, 905, 540);


CREATE table if not exists SaleDiscount (
	SaleID int unsigned, 
    Discount float(2),
    PRIMARY KEY (SaleID),
    CONSTRAINT FK_SaleID
		FOREIGN KEY (SaleID)
        REFERENCES Sale (SaleID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT
);

insert into SaleDiscount (SaleID, Discount)
	values (500, 0);
insert into SaleDiscount (SaleID, Discount)
	values (501, 0);
insert into SaleDiscount (SaleID, Discount)
	values (502, 0.1);
insert into SaleDiscount (SaleID, Discount)
	values (503, 0);
insert into SaleDiscount (SaleID, Discount)
	values (504, 0);
insert into SaleDiscount (SaleID, Discount)
	values (505, 0);
insert into SaleDiscount (SaleID, Discount)
	values (506, 0.1);
insert into SaleDiscount (SaleID, Discount)
	values (507, 0);
insert into SaleDiscount (SaleID, Discount)
	values (508, 0);
insert into SaleDiscount (SaleID, Discount)
	values (509, 0);
    
CREATE table if not exists RContains (
	ReservationID int unsigned, 
    BookID int unsigned,
    Amount int unsigned,
    PRIMARY KEY (ReservationID, BookID),
    CONSTRAINT RCFK_ReservationID
		FOREIGN KEY (ReservationID)
        REFERENCES Reservation (ReservationID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT,
	CONSTRAINT RCFK_BookID
		FOREIGN KEY (BookID)
        REFERENCES Books (BookID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT
);

insert into RContains (ReservationID, BookID, Amount)
	values (400, 100, 100);
insert into RContains (ReservationID, BookID, Amount)
	values (401, 101, 10);
insert into RContains (ReservationID, BookID, Amount)
	values (402, 102, 150);
insert into RContains (ReservationID, BookID, Amount)
	values (403, 103, 50);
insert into RContains (ReservationID, BookID, Amount)
	values (404, 104, 5);
insert into RContains (ReservationID, BookID, Amount)
	values (405, 105, 100);
insert into RContains (ReservationID, BookID, Amount)
	values (406, 106, 10);
insert into RContains (ReservationID, BookID, Amount)
	values (407, 107, 150);
insert into RContains (ReservationID, BookID, Amount)
	values (408, 108, 50);
insert into RContains (ReservationID, BookID, Amount)
	values (409, 109, 5);
    
CREATE table if not exists SContains (
	SaleID int unsigned, 
    BookID int unsigned,
    Amount int unsigned,
    PRIMARY KEY (SaleID, BookID),
    CONSTRAINT SCFK_SaleID
		FOREIGN KEY (SaleID)
        REFERENCES Sale (SaleID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT,
	CONSTRAINT SCFK_BookID
		FOREIGN KEY (BookID)
        REFERENCES Books (BookID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT
);

insert into SContains (SaleID, BookID, Amount)
	values (500, 100, 100);
insert into SContains (SaleID, BookID, Amount)
	values (501, 101, 10);
insert into SContains (SaleID, BookID, Amount)
	values (502, 102, 150);
insert into SContains (SaleID, BookID, Amount)
	values (503, 103, 50);
insert into SContains (SaleID, BookID, Amount)
	values (504, 104, 5);
insert into SContains (SaleID, BookID, Amount)
	values (505, 105, 100);
insert into SContains (SaleID, BookID, Amount)
	values (506, 106, 10);
insert into SContains (SaleID, BookID, Amount)
	values (507, 107, 150);
insert into SContains (SaleID, BookID, Amount)
	values (508, 108, 50);
insert into SContains (SaleID, BookID, Amount)
	values (509, 109, 5);

CREATE table if not exists SupPricing (
	VendorID int unsigned, 
    BookID int unsigned,
    Price int unsigned,
    PRIMARY KEY (VendorID, BookID),
    CONSTRAINT SPFK_VendorID
		FOREIGN KEY (VendorID)
        REFERENCES Vendor (VendorID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT,
	CONSTRAINT SPFK_BookID
		FOREIGN KEY (BookID)
        REFERENCES Books (BookID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT
);

insert into SupPricing (VendorID, BookID, Price)
	values (200, 100, 40);
insert into SupPricing (VendorID, BookID, Price)
	values (201, 101, 50);
insert into SupPricing (VendorID, BookID, Price)
	values (202, 102, 10);
insert into SupPricing (VendorID, BookID, Price)
	values (203, 103, 15);
insert into SupPricing (VendorID, BookID, Price)
	values (204, 104, 10);
insert into SupPricing (VendorID, BookID, Price)
	values (205, 105, 45);
insert into SupPricing (VendorID, BookID, Price)
	values (206, 106, 10);
insert into SupPricing (VendorID, BookID, Price)
	values (207, 107, 15);
insert into SupPricing (VendorID, BookID, Price)
	values (208, 108, 30);
insert into SupPricing (VendorID, BookID, Price)
	values (209, 109, 45);
insert into SupPricing (VendorID, BookID, Price)
	values (207, 101, 30);
insert into SupPricing (VendorID, BookID, Price)
	values (208, 102, 10);
insert into SupPricing (VendorID, BookID, Price)
	values (209, 103, 20);

CREATE table if not exists SupAmount (
	VendorID int unsigned,
    BookID int unsigned,
	Amount int unsigned,
    PRIMARY KEY (VendorID, BookID),
    CONSTRAINT SSFK_VendorID
		FOREIGN KEY (VendorID)
        REFERENCES Vendor (VendorID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT,
	CONSTRAINT SSFK_BookID
		FOREIGN KEY (BookID)
        REFERENCES Books (BookID)
			ON DELETE RESTRICT
            ON UPDATE RESTRICT
);

insert into SupAmount (VendorID, BookID, Amount)
	values (200, 100, 10);
insert into SupAmount (VendorID, BookID, Amount)
	values (201, 101, 20);
insert into SupAmount (VendorID, BookID, Amount)
	values (202, 102, 10);
insert into SupAmount (VendorID, BookID, Amount)
	values (203, 103, 20);
insert into SupAmount (VendorID, BookID, Amount)
	values (204, 104, 15);
insert into SupAmount (VendorID, BookID, Amount)
	values (205, 105, 45);
insert into SupAmount (VendorID, BookID, Amount)
	values (206, 106, 10);
insert into SupAmount (VendorID, BookID, Amount)
	values (207, 107, 15);
insert into SupAmount (VendorID, BookID, Amount)
	values (208, 108, 10);
insert into SupAmount (VendorID, BookID, Amount)
	values (209, 109, 20);
insert into SupAmount (VendorID, BookID, Amount)
	values (207, 101, 5);
insert into SupAmount (VendorID, BookID, Amount)
	values (208, 102, 10);
insert into SupAmount (VendorID, BookID, Amount)
	values (209, 103, 5);