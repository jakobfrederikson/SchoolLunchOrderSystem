#include <iostream>
#include <string>
using namespace std;

struct Admin {
	int adminID;
	string fullName;
	struct Parent;
	struct Staff;
};

struct Parent {
	int parentID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	int countNum;
	string childFullName;
	int childRoomNum;
	int visaCardNo;
	string visaCardExpiry;
	string email;
	struct Order;
	struct Login;
	struct Complaint;
	struct BulkPayment;
	struct Payment;
};

struct Staff {
	int staffID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	int visaCardNo;
	string visaCardExpiry;
	struct Order;
	struct Login;
	struct Complaint;
	struct BulkPayment;
	struct Payment;
};

struct Order {
	int orderNum;
	string orderDate;
	string itemName;
	int quantity;
	float price;
	float totalPrice;
	bool paymentStatus;
};

struct Complaint {
	int complaintID;
	string itemOrdered;
	string complaintDescription;
	string actionStatus;
};

struct Login {
	int loginID;
	string username;
	string password;
};

struct Payment {
	int paymentID;
	float GST;
	string typeOfPayment;
};

//code written by Jay
void printMenuList();
void printBulkDiscounts();
void printContactLocationDetails();

int main()
{
    printMenuList();

    return 0;
}

// Jay's code
void printBulkDiscounts() {
	cout << "\nBULK BOOKING DISCOUNTS\n"
		<< "**********************\n"
		<< "1. MONTHLY FOOD PASS \t\t 2. HALF MONTHLY FOOD PASS \t\t 3. WEEKLY FOOD PASS\n"
		<< "   ----------------- \t\t    ---------------------- \t\t    -----------------\n"
		<< "Pay for 30 days and \t\t Pay for 15 days and \t\t\t Pay for 7 days and \n"
		<< "receive a 15% discount. \t receive a 10% discount. \t\t receive a 5% discount.\n\n"
		<< "Without food pass: $150 \t Without food pass: $75 \t\t Without food pass: $35 \n"
		<< "with food pass: $127.5 \t\t with food pass: $67.50 \t\t with food pass: $33.25 \n"
		<< "Save $22.50 \t\t\t Save $7.50 \t\t\t\t Save $1.75\n";
}

void printContactLocationDetails() {
	cout << "\nCONTACT DETAILS \t\t\t OFFICE LOCATION\n"
		<< "*************** \t\t\t ***************\n"
		<< "Email: admin@schoolname.co.nz \t\t Main office: \n"
		<< "Phone: 0800 83 83 83 \t\t\t A Block, School Name\n"
		<< "\t\t\t\t\t Suburb\n"
		<< "\t\t\t\t\t City\n"
		<< "\t\t\t\t\t Region\n"
		<< "\t\t\t\t\t Country\n\n";
}

void printMenuList() {
    int choice;

    cout << "Enter option: ";
    cin >> choice;

    switch (choice) { 
    case 1:
        break;
    case 2:
		printBulkDiscounts();
        break;
    case 3:
		printContactLocationDetails();
        break;
    case 4:
        break;
    case 5:
        break;
    }
}