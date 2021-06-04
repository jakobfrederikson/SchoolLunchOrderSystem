#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Structures written by Jakob, originally by Jay in an excel sheet
struct Admin {
	int adminID;
	string fullName;
	struct Parent;
	struct Staff;

	Admin(int defAdminID = 0, string defFullName = "Default Admin") {
		adminID = defAdminID;
		fullName = defFullName;
	}
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
	string visaCardNo;
	string visaCardExpiry;
	string email;
	struct Order;
	struct Login;
	struct Complaint;
	struct BulkPayment;
	struct Payment;

	Parent(int defID = 0, bool defAccountStatus = false, string defFullName = "Default Parent", string defGender = "Default Gender",
		   string defDOB = "00/00/0000", int defCountNum = 0, string defChildName = "Default Child", int defRoomNum = 0,
		   string defVisaNum = "Default Visa Num", string defVisaExpiry = "Def Expiry", string defEmail = "default@email.com") {

		parentID = defID;
		accountStatus = defAccountStatus;
		fullName = defFullName;
		gender = defGender;
		dob = defDOB;
		countNum = defCountNum;
		childFullName = defChildName;
		childRoomNum = defRoomNum;
		visaCardNo = defVisaNum;
		visaCardExpiry = defVisaExpiry;
		email = defEmail;
	}
};

struct Staff {
	int staffID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	string visaCardNo;
	string visaCardExpiry;
	struct Order;
	struct Login;
	struct Complaint;
	struct BulkPayment;
	struct Payment;

	Staff(int defID = 0, bool defAccountStatus = false, string defFullName = "Default Staff", string defGender = "Default Gender",
	      string defDOB = "00/00/0000", string defVisaNum = "Default Visa Num", string defVisaExpiry = "Def Expiry") {

		staffID = defID;
		accountStatus = defAccountStatus;
		fullName = defFullName;
		gender = defGender;
		dob = defDOB;
		visaCardNo = defVisaNum;
		visaCardExpiry = defVisaExpiry;
	}
};

struct Order {
	int orderNum;
	string orderDate;
	string itemName;
	int quantity;
	float price;
	float totalPrice;
	bool paymentStatus;

	Order(int defOrderNum = 0, string defOrderDate = "00/00/000", string defItemName = "Default Item Name", int defQuantity = 0,
		float defPrice = 0, float defTotalPrice = 0, bool defPaymentStatus = false) {
		orderNum = defOrderNum;
		orderDate = defOrderDate;
		itemName = defItemName;
		quantity = defQuantity;
		price = defPrice;
		totalPrice = defTotalPrice;
		paymentStatus = defPaymentStatus;
	}
};

struct Complaint {
	int complaintID;
	string itemOrdered;
	string complaintDescription;
	bool actionStatus;

	Complaint(int defComplaintID = 0, string defItemOrdered = "Default Item Ordered", string defComplaintDesc = "Default Complaint",
		bool defActionStatus = false) {

		complaintID = defComplaintID;
		itemOrdered = defItemOrdered;
		complaintDescription = defComplaintDesc;
		actionStatus = defActionStatus;
	}
};

struct Login {
	int loginID;
	string username;
	string password;

	Login(int defLoginID = 0, string defUsername = "Def Username", string defPassword = "Def Password") {

		loginID = defLoginID;
		username = defUsername;
		password = defPassword;
	}
};

struct Payment {
	int paymentID;
	float GST;
	string typeOfPayment;

	Payment(int defPaymentID = 0, float defGST = 0.15, string defPaymentType = "def payment type") {
		paymentID = defPaymentID;
		GST = defGST;
		typeOfPayment = defPaymentType;
	}
};

//code written by Jay
void printMenuList();
void printBulkDiscounts();
void printContactLocationDetails();
void printWeeklyMenu();
void loginRegistrationScreen();
void registerUser(struct Staff staffRegister);

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
	int choice, registerChoice;
	struct Staff staffRegister;

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
		cout << "REGISTER SCREEN\n";
		cout << "***************\n";
		cout << "1. Staff account\n";
		cout << "2. Parent account\n";
		cout << "\nEnter choice: ";
		cin >> registerChoice;

		if (registerChoice == 1) {
			registerUser(staffRegister);		
		}
		else if (registerChoice == 2) {

		}
		else {
			cout << "\nPlease enter a number relevant to the given menu.\n";
		}

	}
	else {
		cout << "\nPlease enter a number relevant to the given menu.\n";
	}
}

void registerUser(struct Staff staffRegister) {
	char ans;

	system("cls");
	cout << "STAFF REGISTRATION";
	cout << "\n******************";
	cout << "\nFull name: ";
	cin.ignore();
	getline(cin, staffRegister.fullName);
	cout << "Gender: ";
	cin >> staffRegister.gender;
	cout << "Date of birth: ";
	cin >> staffRegister.dob;
	cout << "Visa Card Number: ";
	cin >> staffRegister.visaCardNo;
	cout << "Visa Card Expiry Date: ";
	cin >> staffRegister.visaCardExpiry;
	cout << "\nConfirm registration(y/n): ";
	cin >> ans;

	if (ans == 'y') {
		ofstream staffFile;
		staffFile.open("staff_file.csv", ios::app);
		cout << "\nWriting to file\n";
		
		staffFile << staffRegister.fullName << ", " << staffRegister.gender << ", " << staffRegister.dob << ", " << staffRegister.visaCardNo << ", " << staffRegister.visaCardExpiry << endl;

		staffFile.close();
	}
	else if (ans == 'n') {
		cout << "\nRegistration canceled.\n";
	}
	else {
		cout << "\nPlease enter a character relevant to the given menu.\n";
	}
}