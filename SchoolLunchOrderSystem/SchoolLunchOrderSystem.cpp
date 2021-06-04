#include <iostream>
#include <string>
using namespace std;

// Structures written by Jakob, originally by Jay in an excel sheet
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
void printWeeklyMenu();
void loginRegistrationScreen();

int main()
{
	// Code written by Jay
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


// Code written by Jay

void printMenuList() {
	int choice;

	// Code written by Jakob
	cout << "SCHOOL LUNCH ORDER SYSTEM\n";
	cout << "*************************\n";
	cout << "1. Weekly Menu\n";
	cout << "2. Bulk Booking Discounts\n";
	cout << "3. Contact Details and Office Locations\n";
	cout << "4. Login or Register\n";
	cout << "5. Exit Program\n";
	cout << "\nEnter option: ";
	cin >> choice;


	switch (choice) {
		// Code written by Jay
	case 1: // Case 1 written by Jakob
		printWeeklyMenu();
		break;
	case 2:
		printBulkDiscounts();
		break;
	case 3:
		printContactLocationDetails();
		break;
	case 4: // Case 4 written by Jakob
		loginRegistrationScreen();
		break;
	case 5:
		break;
	}
}

// Code written by Jakob
void printWeeklyMenu() {
	cout << "\nWEEKLY MENU\n";
	cout << "***********\n";

	
	cout << "1.\t\t\t\t2.\t\t\t\t3.\n";
	cout << "BEEF NOODLES\t\t\tCHICKEN BURGER\t\t\tCHICKEN BURGER\n";
	cout << "---------------------\t\t---------------------\t\t---------------------\n";
	cout << "Noodles cooked with\t\tGrilled chicken with\t\tGrilled chicken with\n";
	cout << "beautiful beef.\t\t\tlettuce and ketchup.\t\tlettuce and ketchup.\n";
	cout << "VEGAN: No  GLUTEN: No\t\tVEGAN: No  GLUTEN: No\t\tVEGAN: No  GLUTEN: No\n";
	cout << "---------------------\t\t---------------------\t\t---------------------\n";
	cout << "$5.00\t\t\t\t$5.00\t\t\t\t$5.00\n\n";

	cout << "4.\t\t\t\t5.\t\t\t\t6.\n";
	cout << "FRUIT SALAD\t\t\tCRAZY FOOD\t\t\tCHICKEN BURGER\n";
	cout << "---------------------\t\t---------------------\t\t---------------------\n";
	cout << "Mixed fruit with some\t\tGrilled chicken with\t\tGrilled chicken with\n";
	cout << "leaf and stick.\t\t\tlettuce and ketchup.\t\tlettuce and ketchup.\n";
	cout << "VEGAN: Yes  GLUTEN: Yes\t\tVEGAN: No  GLUTEN: No\t\tVEGAN: No  GLUTEN: No\n";
	cout << "---------------------\t\t---------------------\t\t---------------------\n";
	cout << "$5.00\t\t\t\t$5.00\t\t\t\t$5.00\n\n";
	system("pause");
}

// Code written by Jakob
void loginRegistrationScreen() {
	int choice;

	system("cls");
	cout << "1. Login\n";
	cout << "2. Register\n\n";
	cout << "Enter choice: ";
	cin >> choice;

	if (choice == 1) {
		system("cls");
		cout << "LOGIN SCREEN\n";
		cout << "************\n";
		cout << "Username: \n";
		cout << "Password: \n";
		cout << "Login successful.\n";
	}
	else if (choice == 2) {
		system("cls");
		cout << "\nREGISTER SCREEN\n";
		cout << "1. Staff account\n";
		cout << "2. Parent account\n\n";
		cout << "Enter choice: ";
		cout << "\n\n";
	}
	else {
		cout << "\nPlease enter a number relevant to the given menu.\n";
	}
}