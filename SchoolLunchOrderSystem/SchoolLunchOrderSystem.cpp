//Programmer:			Jakob Frederikson, Jay Anino   
//Student ID:			Jakob's ID: 270029667, Jay's ID: 270115050
//School:				Yoobee College
//Due Date:				28/06/2021
//Project Reference:	Group Project School Lunch Ordering System
//Project Description:  N/A

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>
using namespace std;

// Structures written by Jakob and Jay
struct BulkPayment {
	string bulkID;
	int orderCount;

	BulkPayment(int defBulkID = 0, int defOrderCount = 0) {
		bulkID = defBulkID;
		orderCount = defOrderCount;
	}
};

struct Login {
	string loginID;
	string userForeignID;
	string username;
	string password;

	Login(string def = "Def") {
		loginID = def;
		userForeignID = def;
		username = def;
		password = def;
	}
};

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

struct Order {
	int orderNum;
	string orderID, foreignKey;
	string orderDate;
	string itemName;
	int quantity;
	float price;
	bool paymentStatus;

	Order(int defOrderNum = 0, string defOrderDate = "00/00/000", string defItemName = "Default", int defQuantity = 0,
		float defPrice = 0, bool defPaymentStatus = false) {
		orderNum = defOrderNum;
		orderDate = defOrderDate;
		itemName = defItemName;
		quantity = defQuantity;
		price = defPrice;
		orderID = defItemName;
		foreignKey = defItemName;
		paymentStatus = defPaymentStatus;
	}
};

struct Complaint {
	int complaintID;
	string reason;
	string complaintDescription;
	bool actionStatus;

	Complaint(int defComplaintID = 0, string defItemOrdered = "Default Reason", string defComplaintDesc = "Default Complaint",
		bool defActionStatus = false) {

		complaintID = defComplaintID;
		reason = defItemOrdered;
		complaintDescription = defComplaintDesc;
		actionStatus = defActionStatus;
	}
};

struct Payment {
	float totalPrice, GST, GSTAmount;
	string paymentID, GSTNumber, foreignKey;
	string typeOfPayment;
	string date;

	Payment(float defNum = 0.00, float defGST = 0.15, string defTxt = "default") {
		paymentID = defTxt;
		GST = defGST, totalPrice = defNum, GSTAmount = defNum;
		typeOfPayment = defTxt, date = defTxt, foreignKey = defTxt;
	}
};
struct Parent {
	string parentID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	string contactNum;
	string childFullName;
	string childRoomNum;
	string visaCardNo;
	string visaCardExpiry;
	string email;
	vector<Order> order;
	struct Login login;
	struct Complaint;
	struct BulkPayment bulk;
	vector<Payment> payment;

	Parent(int defID = 0, bool defAccountStatus = false, string defFullName = "Default Parent", string defGender = "Default Gender",
		string defDOB = "00/00/0000", string defCountNum = "000", string defChildName = "Default Child", int defRoomNum = 0,
		string defVisaNum = "Default Visa Num", string defVisaExpiry = "Def Expiry", string defEmail = "default@email.com") {

		parentID = defID;
		accountStatus = defAccountStatus;
		fullName = defFullName;
		gender = defGender;
		dob = defDOB;
		contactNum = defCountNum;
		childFullName = defChildName;
		childRoomNum = defRoomNum;
		visaCardNo = defVisaNum;
		visaCardExpiry = defVisaExpiry;
		email = defEmail;
	}
};

struct Staff {
	string staffID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	string contactNum;
	string visaCardNo;
	string visaCardExpiry;
	string email;
	vector<Order> order;
	struct Login login;
	struct Complaint;
	struct BulkPayment bulk;
	vector<Payment> payment;

	Staff(int defID = 0, bool defAccountStatus = false, string defFullName = "Default Staff", string defGender = "Default Gender",
		string defDOB = "00/00/0000", string defCountNum = "000", string defVisaNum = "Default Visa Num", string defVisaExpiry = "Def Expiry",
		string defEmail = "default@email.com") {

		staffID = defID;
		accountStatus = defAccountStatus;
		fullName = defFullName;
		gender = defGender;
		dob = defDOB;
		contactNum = defCountNum;
		visaCardNo = defVisaNum;
		visaCardExpiry = defVisaExpiry;
		email = defEmail;
	}
};

struct FoodMenuList {
	int foodNum;
	string foodName;
	string foodDescription;
	string foodDietary;
	float foodPrice;

	FoodMenuList(string def = "default", float defNum = 0) {
		foodNum = defNum, foodPrice = defNum, foodName = def, foodDescription = def, foodDietary = def;
	}
};

void schoolTitle();
void programDescription();
void loadingScreen();
int printMenuList();
void printBulkDiscounts();
void printContactLocationDetails();
void printWeeklyMenu();
void loginRegistrationScreen();
void registerStaff();
void registerParent();
void adminLogin();
string generateID(int);
bool checkUniqueID(int, string);
bool checkPassword(string);
bool checkUsername(string);
bool doesFileExist(const char*);
void loginScreen();
string checkLoginInput(string);
string checkAdminInput(string);
vector<string> checkAccount(string);
void printMainMenu(vector<string>);
vector<string> getAccountDetails(string);
void makeComplaint(vector<string>);
void chooseBulkOrder(vector<string>);
string getCurrentDate();
void createFoodMenuList();
void updateMenuList();
void getFoodMenuList(string(*)[10][3]);
void createFiles();
void adminScreen();
bool checkBulkFile(vector<string>);
int updateBulkOrderCount(vector<string>, int);
void printWeeklyComplaint();
vector<string> getWeeklyComplaint();
void changeActionStatus(vector<string>);
void printWeeklySales();
void orderFood(vector<string>);
vector<Order>getFoodOrderDetails(vector<Order>, int);
vector<Order> removeOrder(vector<Order>);
void printAllOrders(vector<Order> order);
vector<Order> checkoutOrder(vector<Order> order, vector<string>);
void printWeeklyOrderReport(char);
vector<Parent> getAllParentDetails();
vector<Staff> getAllStaffDetails();
void printAllParentDetails(char);
void printAllStaffDetails(char);
vector<Order>getAllOrderDetails();
vector<Payment>getAllPaymentDetails();
vector<Login>& getAllLoginDetails(vector<Login>*);
void updateParentDetails(string, string);
void updateStaffDetails(string, string);
vector<BulkPayment> getAllBulkDetails();
void printSpaces(int, int);
vector<Order> getAllUnpaidOrders(string);
void removeAllUnpaidOrders(string);
void forgotPassword();
string printUpdateDetailsMenu();
void updateWeeklyComplaint(string, string, string, string);

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // set console window to full screen
	loadingScreen();
	programDescription();
	createFiles();
	return printMenuList();
}

void schoolTitle() {
	string line, tempstr;
	ifstream txtFile;

	txtFile.open("schoolText.txt", ios::in);
	while (getline(txtFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempstr);
			cout << "\t\t\t\t\t\t" << tempstr;
		}
		cout << endl;
	}
	txtFile.close();

	cout << endl << endl;
}

void loadingScreen() {
	string line, tempstr;
	ifstream txtFile;

	system("Color 0A");
	txtFile.open("loadingScreen.txt", ios::in);
	while (getline(txtFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempstr);
			cout << "\t\t\t\t\t\t" << tempstr;
			Sleep(150);
		}
		cout << endl;
	}
	txtFile.close();

	// Project Details
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tProgrammers: Jay Anino and Jakob Frederikson";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tClass: Bachelor of Software Engineering, first year";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tPaper: CS103";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\tSchool: Yoobee College";
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t© Copyright 2021, all rights reserved.";
	cout << endl;
	cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t";
	system("pause");
}

// Written by Jakob
// This function explains the reasoning behind the program.
void programDescription() {
	string line, tempstr;
	ifstream txtFile;

	system("cls");
	txtFile.open("programDescription.txt", ios::in);
	while (getline(txtFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempstr);
			cout << "\t\t\t\t\t\t\t\t" << tempstr;
			Sleep(150);
		}
		cout << endl;
	}
	txtFile.close();

	// Project Description
	cout << "\n\t\t\t\t\t\t\t\tThis program was written for the Bachelor of Software Engineering CS103 paper at Yoobee College.";

	cout << "\n\n\t\t\t\t\t\t\t\tWe were tasked with creating a school lunch ordering system that allows users to create their own";
	cout << "\n\t\t\t\t\t\t\t\taccount, view the schools menu, and order food. Users are also able to file complaints and update";
	cout << "\n\t\t\t\t\t\t\t\ttheir own account if they wish. An admin side also exists for viewing reports (view complaints, view";
	cout << "\n\t\t\t\t\t\t\t\ttotal pay, view all members etc).";
	cout << "\n\n\t\t\t\t\t\t\t\tA huge thank you to everyone who has tested/is testing the program. You're feedback is incredibly valuable.";
	cout << "\n\t\t\t\t\t\t\t\tAs for the programming language, it was written entirely in C++.";

	cout << "\n\n\t\t\t\t\t\t\t\tThe following is not a complete build and errors may occur. We thank you for trying out our program!";

	cout << "\n\n\t\t\t\t\t\t\t\t";
	system("pause");
}

// Code written by Jay and Jakob
// This function prints the main menu to the user
int printMenuList() {
	int choice;

	do {
		system("cls");
		system("Color 0F");
		schoolTitle();
		cout << "\n" << string(7, '\t') << "|-----------------------------------------|"
			<< "\n" << string(7, '\t') << "|         Ultra Academy High School       |"
			<< "\n" << string(7, '\t') << "|-----------------------------------------|"
			<< "\n" << string(7, '\t') << "| 1. Weekly Menu                          |"
			<< "\n" << string(7, '\t') << "| 2. Bulk Booking Discounts               | "
			<< "\n" << string(7, '\t') << "| 3. Contact Details and Office Locations |"
			<< "\n" << string(7, '\t') << "| 4. Login or Register                    |"
			<< "\n" << string(7, '\t') << "| 5. Exit Program                         |"
			<< "\n" << string(7, '\t') << "|-----------------------------------------|"
			<< "\n" << string(7, '\t') << "| Enter option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			schoolTitle();
			printWeeklyMenu();
			cout << "\n\n\t\tHas the menu got your interest? Register now to order!";
			cout << "\n\n\t\t";
			system("pause");
			break;
		case 2:
			system("cls");
			schoolTitle();
			printBulkDiscounts();
			break;
		case 3:
			system("cls");
			schoolTitle();
			printContactLocationDetails();
			break;
		case 4: // Written by Jakob
			loginRegistrationScreen();
			break;
		case 5:
			return 0;
		case 1234:
			adminLogin(); // Written by Jakob
			break;
		}
	} while (true);
}

//Written by Jay
//This function prints out the details of bulk discounts
void printBulkDiscounts() {
	cout << "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|"
		<< "\n" << string(6, '\t') << "|                                   BULK BOOKING DISCOUNTS                                     |"
		<< "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|"
		<< "\n" << string(6, '\t') << "|    1. GOLD FOOD PASS         |     2. SILVER FOOD PASS      |      3. COPPER FOOD PASS       |"
		<< "\n" << string(6, '\t') << "|------------------------------|------------------------------|--------------------------------|"
		<< "\n" << string(6, '\t') << "|    Pay for 30 days and       |     Pay for 15 days and      |      Pay for 7 days and        |"
		<< "\n" << string(6, '\t') << "|    receive a 15% discount.   |     receive a 10% discount.  |      receive a 5% discount.    |"
		<< "\n" << string(6, '\t') << "|    Without food pass: $150   |     Without food pass: $75   |      Without food pass: $35    |"
		<< "\n" << string(6, '\t') << "|    With food pass: $127.5    |     With food pass: $67.50   |      With food pass: $33.25    |"
		<< "\n" << string(6, '\t') << "|    Save $22.50               |     Save $7.50               |      Save $1.75                |"
		<< "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|" << "\n\n" << string(7, '\t');
	system("pause");
}

//Written by Jay
//This function prints out the details of the school 
void printContactLocationDetails() {
	cout << "\n" << string(7, '\t') << "|------------------------------------------------------------|"
		<< "\n" << string(7, '\t') << "| CONTACT DETAILS                |      OFFICE LOCATION      |"
		<< "\n" << string(7, '\t') << "|--------------------------------|---------------------------|"
		<< "\n" << string(7, '\t') << "| Email: admin@schoolname.co.nz  |      Main office:         |"
		<< "\n" << string(7, '\t') << "| Phone: 0800 83 83 83           |      A Block, School Name |"
		<< "\n" << string(7, '\t') << "|                                |      Suburb               |"
		<< "\n" << string(7, '\t') << "|                                |      City                 |"
		<< "\n" << string(7, '\t') << "|                                |      Region               |"
		<< "\n" << string(7, '\t') << "|                                |      Country              |"
		<< "\n" << string(7, '\t') << "|------------------------------------------------------------|" << "\n\n" << string(7, '\t');
	system("pause");
}

void loginRegistrationScreen() { // Code written by Jakob
	int choice, registerChoice;

	do {
		system("cls");
		schoolTitle();
		cout << "\n" << string(7, '\t') << "|----------------------------|"
			<< "\n" << string(7, '\t') << "|     LOG IN / REGISTER      |"
			<< "\n" << string(7, '\t') << "|----------------------------|"
			<< "\n" << string(7, '\t') << "|1. Login                    |"
			<< "\n" << string(7, '\t') << "|2. Register                 |"
			<< "\n" << string(7, '\t') << "|3. Forgot Password          |"
			<< "\n" << string(7, '\t') << "|4. Back                     |"
			<< "\n" << string(7, '\t') << "|                            |"
			<< "\n" << string(7, '\t') << "|Enter choice                |: ";
		cin >> choice;

		if (choice == 1) {
			loginScreen();
			break;
		}
		else if (choice == 2) {
			system("cls");
			schoolTitle();
			cout << "\n" << string(7, '\t') << "|----------------------------|"
				<< "\n" << string(7, '\t') << "|      REGISTER ACCOUNT      |"
				<< "\n" << string(7, '\t') << "|----------------------------|"
				<< "\n" << string(7, '\t') << "|1. Staff account            |"
				<< "\n" << string(7, '\t') << "|2. Parent account           |"
				<< "\n" << string(7, '\t') << "|3. Back                     |"
				<< "\n" << string(7, '\t') << "|                            |"
				<< "\n" << string(7, '\t') << "|Enter choice                |: ";
			cin >> registerChoice;

			if (registerChoice == 1) {
				registerStaff();
				break;
			}
			else if (registerChoice == 2) {
				registerParent();
				break;
			}
			else if (registerChoice == 3) {
				continue;
			}
			else {
				cout << "\n" << string(7, '\t') << "Please enter a number relevant to the given menu.\n";
			}
		}
		else if (choice == 3) {
			forgotPassword();
			break;
		}
		else if (choice == 4) {
			break;
		}
		else {
			cout << "\n" << string(7, '\t') << "Please enter a number relevant to the given menu.\n";
		}
	} while (true);
}

//Code by Jay
//This function lets the user change there password if they have forgotten it
void forgotPassword() {
	vector<Parent> parent;
	vector<Staff> staff;
	vector<Login> login;
	vector<Login>* ptrVectLogin;
	ptrVectLogin = &login;
	int choice, userVectLocation = 0;
	bool isTrue, isFound = false;
	string password, verifyPassword, userID;

	staff = getAllStaffDetails();
	parent = getAllParentDetails();
	login = getAllLoginDetails(ptrVectLogin);

	do {
		system("cls");
		schoolTitle();
		cout << "\n" << string(8, '\t') << "|---------------------------------|"
			<< "\n" << string(8, '\t') << "|          Forgot Password        |"
			<< "\n" << string(8, '\t') << "|---------------------------------|"
			<< "\n" << string(8, '\t') << "|--------------------------------------------|"
			<< "\n" << string(8, '\t') << "| Type: quit@ to exit from password          |"
			<< "\n" << string(8, '\t') << "|--------------------------------------------|"
			<< "\n" << string(8, '\t') << "| Enter your ID: ";
		cin >> userID;
		cin.ignore();

		if (userID == "quit@")
			break;
		else {
			//get user location in vector
			//check if id is parent
			if (userID.substr(0, 3) == "270") {
				for (int i = 0; i < parent.size(); i++) {
					if (parent[i].parentID == userID) {
						isFound = true;
						userVectLocation = i;
					}
					else {
						cout << "\n" << string(8, '\t') << "Invalid User ID. Please Try Again..\n" << "\n" << string(8, '\t');
						isFound = false;
						system("pause");
					}
				}
			}
			//check if id is staff
			else {
				for (int i = 0; i < staff.size(); i++) {
					if (staff[i].staffID == userID) {
						isFound = true;
						userVectLocation = i;
						break;
					}
					else {
						cout << "\n" << string(8, '\t') << "Invalid User ID. Please Try Again..\n" << "\n" << string(8, '\t');
						isFound = false;
						system("pause");
					}
				}
			}
		}
	} while (!isFound);

	if (isFound) {
		isTrue = true;
		do {
			do {
				cout << "" << string(8, '\t') << "|-------------------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "| Use 8 or more characters with a mix of letters, numbers & symbols |"
					<< "\n" << string(8, '\t') << "|-------------------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "|Enter New Password" << setw(17) << "|: ";
				getline(cin, password);

				if (checkPassword(password))
					break;
				else {
					cout << "\n" << string(8, '\t') << "Invalid password, Please try again\n" << "\n" << string(8, '\t');
					system("pause");
				}
				system("cls");
			} while (true);

			//verify password
			do {
				cout << "" << string(8, '\t') << "|Enter Verify Password" << setw(10) << "|: ";
				getline(cin, verifyPassword);

				if (verifyPassword == "") {
					cout << "\n" << string(8, '\t') << "Password did not match, Please try again\n" << "\n" << string(8, '\t');
					system("pause");;
				}
				else
					break;
			} while (true);

			if (password != verifyPassword) {
				cout << "\n" << string(8, '\t') << "Password did not match please try again...\n" << "\n" << string(8, '\t');
				system("pause");
			}
			else {
				//parent password change
				if (userID.substr(0, 3) == "270") {
					parent[userVectLocation].login.password = password;
					for (int i = 0; i < login.size(); i++) {
						if (parent[userVectLocation].login.userForeignID == login[i].userForeignID) {
							login[i].password = parent[userVectLocation].login.password;
						}
					}
				}
				//staff paswword change
				else {
					staff[userVectLocation].login.password = password;
					for (int i = 0; i < login.size(); i++) {
						if (staff[userVectLocation].login.userForeignID == login[i].userForeignID) {
							login[i].password = staff[userVectLocation].login.password;
						}
					}
				}

				ofstream loginFile("Login_file.csv", ios::out);
				//ADD HEADERS TO CSV
				loginFile << "PRIMARY_KEY" << "," << "FOREIGN_KEY" << "," << "USERNAME" << "," << "PASSWORD" << endl;
				for (int i = 0; i < login.size(); i++) {
					loginFile << login[i].loginID << "," << login[i].userForeignID << "," << login[i].username << "," << login[i].password << endl;
				}
				loginFile.close();

				cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
					<< "\n" << string(8, '\t') << "|   Password has been successfully changed   |"
					<< "\n" << string(8, '\t') << "|--------------------------------------------|" << "\n" << string(8, '\t');
				isTrue = false;
				system("pause");
			}
			system("cls");
		} while (isTrue);
	}
}

// Code written by Jakob
// This allows staff to register an account, create a username + password and also generate a unique ID.
void registerStaff() {
	struct Staff staffRegister;
	char choice = ' ', choice2 = ' ';
	string password, verifyPass, uniqueID;


	do { // Taking input for staff details
		cin.ignore();
		system("cls");
		schoolTitle();
		cout << "\n\t\t\t|----------------------------------|"
			<< "\n\t\t\t|        Staff REGISTRATION        |"
			<< "\n\t\t\t|----------------------------------|";
		do {
			cout << "\n\t\t\t|Enter Full name" << setw(22) << "|: ";
			getline(cin, staffRegister.fullName);
			if (staffRegister.fullName.length() < 4 || staffRegister.fullName.length() > 22) {
				cout << "\n\t\t\tName was less than 4 characters or greater than 22 characters. Please try again.\n";
			}
			else if (staffRegister.fullName == "")
				cout << "\n\t\t\tInvalid input, please Enter your name.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Gender" << setw(23) << "|";
			cout << "\n\t\t\t|E.g: Non-binary, Male, Female etc.|: ";
			getline(cin, staffRegister.gender);
			if (staffRegister.gender == "")
				cout << "\n\t\t\tInvalid input, please Enter your gender.\n";
			else if (staffRegister.gender.length() < 2 || staffRegister.gender.length() > 13)
				cout << "\n\t\t\tYou entered less than 2 characters or more than 13 characters. Please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Date of birth               |"
				<< "\n\t\t\t|E.g: 01/06/2003                   |"
				<< "\n\t\t\t|DD/MM/YYYY                        |: " << setw(18);
			getline(cin, staffRegister.dob);
			if (staffRegister.dob == "")
				cout << "\n\t\t\tInvalid input, please Enter your date of birth.\n";
			else if (staffRegister.dob.length() > 10 || staffRegister.dob.length() < 10)
				cout << "\n\t\t\tYou entered less than 10 characters or more than 10 characters. Please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Contact Number" << setw(17) << "|: ";
			getline(cin, staffRegister.contactNum);
			//cin.ignore();
			if (staffRegister.contactNum.length() < 9 || staffRegister.contactNum.length() > 12) {
				cout << "\n\t\t\tInvalid input, please enter your contact number.\n";
			}
			else {
				break;
			}
		} while (true);


		do {
			cout << "\t\t\t|Enter Email Address" << setw(18) << "|: ";
			getline(cin, staffRegister.email);
			if (staffRegister.email == "")
				cout << "\n\t\t\tInvalid input, please Enter your email address.\n";
			else if (staffRegister.email.length() < 4 || staffRegister.email.length() > 40)
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Number" << setw(15) << "|: ";
			getline(cin, staffRegister.visaCardNo);
			if (staffRegister.visaCardNo == "")
				cout << "\n\t\t\tInvalid input, please Enter your visa card number.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Expiry Date       |"
				<< "\n\t\t\t|MM/YY                             |: ";
			getline(cin, staffRegister.visaCardExpiry);
			if (staffRegister.visaCardExpiry == "")
				cout << "\n\t\t\tInvalid input, please Enter your visa card expiry date.\n";
			else
				break;
		} while (true);

		// USERNAME AND PASSWORD DETAILS
		do {
			cout << "\t\t\t|---------------------------------------|"
				<< "\n\t\t\t| Use 8 or more characters for Username |"
				<< "\n\t\t\t|---------------------------------------|"
				<< "\n\t\t\t|Enter Username" << setw(17) << "|: ";
			getline(cin, staffRegister.login.username);

			if (staffRegister.login.username.length() >= 8) {
				if (checkUsername(staffRegister.login.username))
					break;
				else
					cout << "\n\t\t\tSorry Username is already taken, Please try again..\n";
			}
			else if (staffRegister.login.username == "back" || staffRegister.login.username == "BACK") {
				cout << "\n\t\t\tSorry, this is a keyword used in the program. Please try again. . . \n";
			}
			else
				cout << "\n\t\t\tInvalid Username, Please Try Again...\n";
		} while (true);

		do {
			do {
				cout << "\t\t\t|-------------------------------------------------------------------|"
					<< "\n\t\t\t| Use 8 or more characters with a mix of letters, numbers & symbols |"
					<< "\n\t\t\t|-------------------------------------------------------------------|"
					<< "\n\t\t\t|Enter Password" << setw(17) << "|: ";
				getline(cin, password);

				if (checkPassword(password))
					break;
				else
					cout << "\n\t\t\tInvalid password, Please try again\n";
			} while (true);

			do {
				cout << "\t\t\t|Verify Password      " << setw(10) << "|: ";
				getline(cin, verifyPass);

				if (verifyPass == "")
					cout << "\n\t\t\tPassword did not match, Please try again\n";
				else
					break;
			} while (true);

			if (password != verifyPass)
				cout << "\n\t\t\tPassword did not match please try again...\n";
			else {
				staffRegister.login.password = password;
				break;
			}
		} while (true);

		// CONFIRM REGISTRATION OR OTHER OPTIONS
		do {
			cout << "\n\t\t\t|-----------------------------------|"
				<< "\n\t\t\t|  Press Y to confirm Registration  |"
				<< "\n\t\t\t|  Press N to choose other options  |"
				<< "\n\t\t\t|-----------------------------------|"
				<< "\n\t\t\t|Please enter your option: ";
			cin >> choice;
			cin.ignore();

			if (tolower(choice) == 'y') {
				do {//generate a unique id for staff and check if id is unique
					uniqueID = generateID(2);
					if (checkUniqueID(2, uniqueID)) {
						staffRegister.staffID = uniqueID;
						break;
					}
				} while (true);

				do {//generate a unique id for login and check if id is unique
					uniqueID = generateID(3);
					if (checkUniqueID(3, uniqueID)) {
						staffRegister.login.loginID = uniqueID;
						staffRegister.login.userForeignID = staffRegister.staffID;
						break;
					}
				} while (true);

				// Writing Staff details to the staff file
				//activate account
				staffRegister.accountStatus = true;
				ofstream staffFile("Staff_file.csv", ios::app);
				staffFile << staffRegister.staffID << "," << staffRegister.fullName << "," << staffRegister.gender << "," << staffRegister.dob << "," << staffRegister.contactNum << ","
					<< staffRegister.email << "," << staffRegister.visaCardNo << "," << staffRegister.visaCardExpiry << "," << staffRegister.accountStatus << endl;
				staffFile.close();

				// Writing the staff login details to the login file
				ofstream loginFile("Login_file.csv", ios::app);
				loginFile << staffRegister.login.loginID << "," << staffRegister.login.userForeignID << "," << staffRegister.login.username << "," << staffRegister.login.password << endl;
				loginFile.close();

				cout << "\n\t\t\tAccount has been successfully created\n\t\t\t";
				system("pause");
				break;
			}
			else if (tolower(choice) == 'n') {
				do {
					cout << "\n\t\t\t|---------------------------------|"
						<< "\n\t\t\t|Enter 'M' to go back to Main menu|"
						<< "\n\t\t\t|Enter 'N'to re-enter your details|"
						<< "\n\t\t\t|---------------------------------|"
						<< "\n\t\t\t|Please enter your option: ";
					cin >> choice;

					if (tolower(choice) == 'm' || tolower(choice) == 'n')
						break;
				} while (true);
				break;
			}
			else
				cout << "\n\t\t\tInvalid input, Please try again...\n";
		} while (true);
	} while (choice == 'n');
}

//This Function lets the user logged in
//Code by Jay and Jakob
void loginScreen() {
	string username, pass, accPass;
	bool notExist = true;
	ifstream loginFile;

	// Code by Jakob
	int loginAttempt = 0;
	int maxLoginAttempt = 3;

	vector<string> accDetails;
	string userID;
	// =====================

	cin.ignore();
	system("cls");
	schoolTitle();
	cout << "\n" << string(7, '\t') << "|----------------------------|"
		<< "\n" << string(7, '\t') << "|        LOGIN SCREEN        |"
		<< "\n" << string(7, '\t') << "|   Type 'back' to go back   |"
		<< "\n" << string(7, '\t') << "|----------------------------|";

	do {
		loginFile.open("Login_file.csv", ios::in);
		cout << "\n" << string(7, '\t') << "|Username" << setw(8) << "|: ";
		getline(cin, username);

		// giving user option to leave login screen
		if (username == "back") {
			cout << "\n" << string(7, '\t') << "You have canceled your login.";
			cout << "\n" << string(7, '\t') << "";
			system("pause");
			loginRegistrationScreen();
			break;
		}

		accPass = checkLoginInput(username);
		if (accPass == " ")
			cout << "\n" << string(7, '\t') << "Couldn't find your account, Please try again...\n";
		else {
			loginFile.close();
			do {
				cout << "\n" << string(7, '\t') << "|Password" << setw(8) << "|: ";
				getline(cin, pass);

				if (pass != accPass) {
					// Code by Jakob - This checks how many times the user has attempted
					// to log in. Pauses program for 2 seconds after 3 attempts.
					loginAttempt++;
					if (loginAttempt < maxLoginAttempt) {
						cout << "\n" << string(7, '\t') << "Wrong password. You have " << maxLoginAttempt - loginAttempt << " attempts left. Please try again...\n";
					}
					else if (loginAttempt == maxLoginAttempt) {
						// block login for 10 seconds
						cout << "\n" << string(7, '\t') << "Please try again after 2 seconds." << "\n" << string(7, '\t');
						this_thread::sleep_for(chrono::seconds(2)); // sleep for two seconds
						maxLoginAttempt = maxLoginAttempt + 3;
						system("pause");
					}
					else {
						cout << "\n" << string(7, '\t') << "\nLogin attempts will be blocked for two seconds. Please try again later!\n";
					}
				}
				else {
					accDetails = checkAccount(username); // Find staff or parent account
					printMainMenu(accDetails);
					break;
				}
			} while (true);
			break;
		}
		loginFile.close();
	} while (notExist);
}

//Code by jay
//This function allows the user to register an account
void registerParent() {
	struct Parent parentRegister;
	char choice = ' ', choice2 = ' ';
	string password, verifyPass, uniqueID;
	system("cls");
	do {
		schoolTitle();
		cin.ignore();
		cout << "\n\t\t\t|----------------------------------|"
			<< "\n\t\t\t|        Parent REGISTRATION       |"
			<< "\n\t\t\t|----------------------------------|";
		do {
			cout << "\n\t\t\t|Enter Full name" << setw(22) << "|: ";
			getline(cin, parentRegister.fullName);
			if (parentRegister.fullName == "")
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else if (parentRegister.fullName.length() < 3 || parentRegister.fullName.length() > 22)
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Gender" << setw(23) << "|";
			cout << "\n\t\t\t|E.g. Non-binary, Male, Female etc.|: ";
			getline(cin, parentRegister.gender);
			if (parentRegister.gender == "")
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else if (parentRegister.gender.length() < 2 || parentRegister.gender.length() > 13)
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Date of birth" << setw(17) << "| "
				<< "\n\t\t\t|E.g: 01/06/2003                   |"
				<< "\n\t\t\t|DD/MM/YYYY" << setw(27) << "|: ";
			getline(cin, parentRegister.dob);
			if (parentRegister.dob == "")
				cout << "\n\t\t\tInvalid input, please enter your date of birth\n";
			else if (parentRegister.dob.length() < 10 || parentRegister.dob.length() > 10)
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Contact Number" << setw(17) << "|: ";
			getline(cin, parentRegister.contactNum);
			if (parentRegister.contactNum.length() < 9 || parentRegister.contactNum.length() > 12)
				cout << "\n\t\t\tInvalid input, Please Enter your contact number.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Email Address" << setw(18) << "|: ";
			getline(cin, parentRegister.email);
			if (parentRegister.email == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Email Address\n";
			else if (parentRegister.email.length() < 3 || parentRegister.email.length() > 40)
				cout << "\n\t\t\tInvalid input, please try again.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Child's name" << setw(19) << "|: ";
			getline(cin, parentRegister.childFullName);
			if (parentRegister.childFullName == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Child's name\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Child's Room Number" << setw(12) << "|: ";
			getline(cin, parentRegister.childRoomNum);
			if (parentRegister.childRoomNum == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Child's Room Number\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Number" << setw(15) << "|: ";
			getline(cin, parentRegister.visaCardNo);
			if (parentRegister.visaCardNo == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Number\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Expiry Date       | "
				<< "\n\t\t\t|MM/YY" << setw(32) << "|: ";
			getline(cin, parentRegister.visaCardExpiry);
			if (parentRegister.visaCardExpiry == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Expiry Date\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|---------------------------------------|"
				<< "\n\t\t\t| Use 8 or more characters for Username |"
				<< "\n\t\t\t|---------------------------------------|"
				<< "\n\t\t\t|Enter Username" << setw(17) << "|: ";
			getline(cin, parentRegister.login.username);

			if (parentRegister.login.username.length() >= 8) {
				if (checkUsername(parentRegister.login.username))
					break;
				else
					cout << "\n\t\t\tSorry Username is already taken, Please try again..\n";
			}
			else if (parentRegister.login.username == "back" || parentRegister.login.username == "BACK") {
				cout << "\n\t\t\tSorry, this is a keyword used in the program. Please try again. . . \n";
			}
			else
				cout << "\n\t\t\tInvalid Username, Please Try Again...\n";
		} while (true);

		do {
			do {
				cout << "\t\t\t|-------------------------------------------------------------------|"
					<< "\n\t\t\t| Use 8 or more characters with a mix of letters, numbers & symbols |"
					<< "\n\t\t\t|-------------------------------------------------------------------|"
					<< "\n\t\t\t|Enter Password" << setw(17) << "|: ";
				getline(cin, password);

				if (checkPassword(password))
					break;
				else
					cout << "\n\t\t\tInvalid password, Please try again\n";
			} while (true);

			do {
				cout << "\t\t\t|Enter Verify Password" << setw(10) << "|: ";
				getline(cin, verifyPass);

				if (verifyPass == "")
					cout << "\n\t\t\tPassword did not match, Please try again\n";
				else
					break;
			} while (true);

			if (password != verifyPass)
				cout << "\n\t\t\tPassword did not match please try again...\n";
			else {
				parentRegister.login.password = password;
				break;
			}
		} while (true);

		do {
			cout << "\n\t\t\t|-----------------------------------|"
				<< "\n\t\t\t|  Press Y to confirm Registration  |"
				<< "\n\t\t\t|  Press N to choose other options  |"
				<< "\n\t\t\t|-----------------------------------|"
				<< "\n\t\t\t|Please enter your option: ";
			cin >> choice;
			cin.ignore();

			if (tolower(choice) == 'y') {
				do {//generate a unique id for parent and check if id is unique
					uniqueID = generateID(1);
					if (checkUniqueID(1, uniqueID)) {
						parentRegister.parentID = uniqueID;
						break;
					}
				} while (true);

				do {//generate a unique id for login and check if id is unique
					uniqueID = generateID(3);
					if (checkUniqueID(3, uniqueID)) {
						parentRegister.login.loginID = uniqueID;
						parentRegister.login.userForeignID = parentRegister.parentID;
						break;
					}
				} while (true);

				ofstream parentFile("Parent_file.csv", ios::app);
				//activate account
				parentRegister.accountStatus = true;
				parentFile << parentRegister.parentID << "," << parentRegister.fullName << "," << parentRegister.gender << "," << parentRegister.dob << "," << parentRegister.contactNum << ","
					<< parentRegister.email << "," << parentRegister.childFullName << "," << parentRegister.childRoomNum << "," << parentRegister.visaCardNo << ","
					<< parentRegister.visaCardExpiry << "," << parentRegister.accountStatus << endl;
				parentFile.close();

				ofstream loginFile("Login_file.csv", ios::app);
				loginFile << parentRegister.login.loginID << "," << parentRegister.login.userForeignID << "," << parentRegister.login.username << "," << parentRegister.login.password << endl;
				loginFile.close();

				cout << "\n\t\t\tAccount has been successfully created";
				cout << "\n\t\t\t";
				system("pause");
				break;
			}
			else if (tolower(choice) == 'n') {
				do {
					cout << "\n\t\t\t|---------------------------------|"
						<< "\n\t\t\t|Press 'M' to go back to Main menu|"
						<< "\n\t\t\t|Press 'N'to re-enter your details|"
						<< "\n\t\t\t|---------------------------------|"
						<< "\n\t\t\t|Please enter your option: ";
					cin >> choice;

					if (tolower(choice) == 'm' || tolower(choice) == 'n')
						break;
				} while (true);
				break;
			}
			else
				cout << "\n\t\t\tInvalid input, Please try again...\n";
		} while (true);
		system("cls");
	} while (choice == 'n');
}

//Code by jay
//This function generates an ID for the user
//To use this function you need 1 integer argument, for example if you want to generate a unique id for staff you mass pass number 2 *generateID(2)* as an argument to generate a unique id for staff
string generateID(int choice) {
	int randNum = 0, randLetter1, randLetter2;
	string uniqueID;

	srand(time(0));
	randNum = (rand() % 101) + 100;//generates random number between 100-200
	randLetter1 = (rand() % 26) + 65;//generates random number between 65-90 which is then converted to char A-Z
	randLetter2 = (rand() % 26) + 65;

	switch (choice) {
	case 1://Unique ID for Parents
		uniqueID = "270" + to_string(randNum) + (char)randLetter1 + (char)randLetter2;
		break;
	case 2://Unique ID for Staff
		uniqueID = "280" + to_string(randNum) + (char)randLetter1 + (char)randLetter2;
		break;
	case 3://Unique ID for Login
		uniqueID = "210" + to_string(randNum) + (char)randLetter1 + (char)randLetter2;
		break;
	case 4://Unique ID for Order
		uniqueID = "220" + to_string(randNum) + to_string(randNum);
		break;
	case 5://Unique ID for Payment 
		uniqueID = "230" + to_string(randNum) + (char)randLetter1 + (char)randLetter2;
		break;
	case 6://Unique ID for Payment GST
		uniqueID = "63" + to_string(randNum) + to_string(randNum);
	default:
		break;
	}

	return uniqueID;
}

//Code by jay
//To use this function you need to pass the generated ID and a case number to which ID you want to verify it with i.e., case 1 for parent
//This function checks if the ID is unique
bool checkUniqueID(int choice, string id) {
	bool isUnique = true;
	string line, tempStr;
	ifstream staffFile, loginFile, parentfile;

	switch (choice) {
	case 1://Checks all unique ID for Parents
		parentfile.open("Parent_file.csv", ios::in);
		while (getline(parentfile, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (tempStr == id)
					return false;
			}
		}
		parentfile.close();
		break;
	case 2://Checks all unique ID for Staff
		staffFile.open("Staff_file.csv", ios::in);
		while (getline(staffFile, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (tempStr == id)
					return false;
			}
		}
		staffFile.close();
		break;
	case 3://Checks all unique ID for Login
		loginFile.open("Login_file.csv", ios::in);
		while (getline(loginFile, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (tempStr == id)
					return false;
			}
		}
		loginFile.close();
		break;
	case 4://Checks all unique ID for Login
		loginFile.open("Order_file.csv", ios::in);
		while (getline(loginFile, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (tempStr == id)
					return false;
			}
		}
		loginFile.close();
		break;
	case 5://Checks all unique ID for Login
		loginFile.open("Payment_file.csv", ios::in);
		while (getline(loginFile, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (tempStr == id)
					return false;
			}
		}
		loginFile.close();
		break;

	default:
		return false;
		break;
	}
	return isUnique;
}

//Code by jay
//This function checks if username is unique
bool checkUsername(string username) {
	bool isUnique = true;
	string line, tempStr;
	ifstream loginFile;

	//Checks all username in login file
	loginFile.open("Login_file.csv", ios::in);
	while (getline(loginFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == username)
				return false;
		}
	}
	loginFile.close();

	return isUnique;
}

//Code by jay
//This function checks if the password has met the requirements
bool checkPassword(string pass) {
	int strLength = 0, numUniqueChar = 0, numCapLetters = 0, numSmallLetters = 0, nums = 0;

	strLength = pass.length();
	for (int i = 0; i < pass.length(); i++) {
		if (isupper(pass[i]))
			numCapLetters++;
		if (!isalpha(pass[i]))
			numUniqueChar++;
		if (isdigit(pass[i]))
			nums++;
		if (tolower(pass[i]))
			numSmallLetters++;
	}
	if (strLength >= 8 && numUniqueChar >= 1 && numCapLetters >= 1 && numSmallLetters >= 1 && nums >= 1)
		return true;
	else
		return false;
}

//This functions checks if username exist and if it exist return the password
//Code by Jay
string checkLoginInput(string input) {
	vector<Parent> vectParent;
	vector<Staff> vectStaff;
	bool isUnique = true, isActive = false;
	string line, tempStr;
	ifstream loginFile;

	vectParent = getAllParentDetails();
	vectStaff = getAllStaffDetails();

	//check if account is active		
	for (int i = 0; i < vectParent.size(); i++) {
		if (vectParent[i].login.username == input) {
			if (vectParent[i].accountStatus)
				isActive = true;
			else
				isActive = false;
			break;
		}
	}

	for (int i = 0; i < vectStaff.size(); i++) {
		if (vectStaff[i].login.username == input) {
			if (vectStaff[i].accountStatus)
				isActive = true;
			else
				isActive = false;
			break;
		}
	}

	//Checks all username in login file
	loginFile.open("Login_file.csv", ios::in);
	while (getline(loginFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == input && isActive) { //check if username matches
				getline(ss, tempStr, ',');//get next data which is pass and return it
				return tempStr;
			}
		}
	}
	loginFile.close();
	return " ";
}

// Code by Jakob
// This function can only be accessed after the user has entered 1234 in printMenuList().
// The function allows the user to enter the admin login to access admin only functions in the application.
void adminLogin() {
	const char admin_file[15] = "Admin_file.csv";
	const char* adminptr;
	adminptr = admin_file;

	struct Admin admin;
	string accPass, pass, username;

	int loginAttempt = 0;
	int maxLoginAttempt = 3;

	system("cls");
	ifstream adminFile;
	cout << "\n" << string(7, '\t') << "|----------------------------|"
		<< "\n" << string(7, '\t') << "|        ADMIN LOGIN         |"
		<< "\n" << string(7, '\t') << "|----------------------------|";

	do {
		adminFile.open("Admin_file.csv", ios::in);
		cout << "\n" << string(7, '\t') << "|Enter admin username" << setw(8) << "        |: ";
		cin >> username;

		accPass = checkAdminInput(username);
		if (accPass == " ") {
			cout << "\n" << string(7, '\t') << "Couldn't find that username, please try again...\n";
		}
		else {
			adminFile.close();
			break;
		}
	} while (true);

	do {
		cout << "\n" << string(7, '\t') << "|Enter admin password" << setw(8) << "        |: ";
		cin >> pass;

		if (pass != accPass) {
			loginAttempt++;
			if (loginAttempt < maxLoginAttempt) {
				cout << "\n" << string(7, '\t') << "tWrong password. You have " << (maxLoginAttempt - loginAttempt) << " attempts left. Please try again...\n";
			}
			else if (loginAttempt == maxLoginAttempt) {
				cout << "\n" << string(7, '\t') << "Please try again after 2 seconds.\n" << string(7, '\t');
				this_thread::sleep_for(chrono::seconds(2));
				maxLoginAttempt = maxLoginAttempt + 3;
				system("pause");
			}

		}
		else {
			adminScreen();
			break;
		}
	} while (true);

	adminFile.close();
}

// Code by Jakob
// This function works the same as checkLoginInput() but checks for the admin input instead.
string checkAdminInput(string input) {
	bool isUnique = true;
	string line, tempStr;
	ifstream adminFile;

	adminFile.open("Admin_file.csv", ios::in);
	while (getline(adminFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == input) {
				getline(ss, tempStr, ',');
				return tempStr;
			}
		}
	}
	adminFile.close();

	return " ";
}

// Code by Jakob
// This function checks whether the admin file exists. If yes, it returns true and nothing happens.
// Otherwise returns false and will prompt the program to create the admin file.
bool doesFileExist(const char* fileptr) {
	ifstream adminFile("Admin_file.csv");
	return adminFile.good();
}

// Code by Jakob
// This function is used after a successful user login attempt. It will check whether the account is a staff or parent account and then return their ID.
vector<string> checkAccount(string username) {
	ifstream loginFile;
	string line, tempStr;
	vector<string> accDetails;

	loginFile.open("Login_file.csv", ios::in);
	while (getline(loginFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == username) { // find line with the users login details
				cout << "\n\t\t\tUsername found\n";
				stringstream ss(line); // get that specific line where the username was stored
				while (getline(ss, tempStr, ',')) {
					if (tempStr.substr(0, 3) == "270") { // Parent account
						cout << "\n\t\t\tPARENT ACCOUNT\n";
						accDetails = getAccountDetails(tempStr); // get users details from their respective file
						return accDetails;
						break;
					}
					else if (tempStr.substr(0, 3) == "280") { // Staff account
						cout << "\n\t\t\tSTAFF ACCOUNT\n";
						accDetails = getAccountDetails(tempStr); // get users details from their respective file
						return accDetails;
						break;
					}
				}
			}
		}
	}
	loginFile.close();
}

// Code by Jakob
// This function gathers user details from their respective account file (Parent_file.csv or Staff_file.csv) and returns it in a vector.
// Thank you to Jay for doing research on vectors and sending me the information in a txt file.
vector<string> getAccountDetails(string userID) {

	ifstream readFile;
	string line, tempStr;
	vector<string> fileData;

	if (userID.substr(0, 3) == "270") {
		readFile.open("Parent_file.csv");
	}
	else if (userID.substr(0, 3) == "280") {
		readFile.open("Staff_file.csv");
	}

	while (getline(readFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == userID) {
				stringstream ss(line);
				while (getline(ss, tempStr, ',')) {
					fileData.push_back(tempStr);
				}
			}
		}
	}
	readFile.close();
	return fileData;
}

// Code by Jakob
// This function displays the main menu for users that have logged in.
void printMainMenu(vector<string> accDetails) {
	int flag;
	string userAccount, userAccount2;
	int i, choice;
	bool runMenu = true;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (accDetails[0].substr(0, 3) == "270") { // parent
		flag = 1;
		userAccount = "parent";
		userAccount2 = "Parent";
		SetConsoleTextAttribute(h, 11);
	}
	else { // staff
		flag = 2;
		userAccount = "staff";
		userAccount2 = "Staff";
		SetConsoleTextAttribute(h, 14);
	}

	do {
		system("cls");
		cout << "\n" << string(7, '\t') << "========================================";
		cout << "\n" << string(7, '\t') << "" << accDetails[1];
		cout << "\n" << string(7, '\t') << "You are logged in with a " << userAccount << " account.";
		cout << "\n" << string(7, '\t') << "" << userAccount2 << " ID: " << accDetails[0];
		cout << "\n" << string(7, '\t') << "========================================";

		cout << "\n\n" << string(7, '\t') << "1. Order food/View Menu";
		cout << "\n" << string(7, '\t') << "2. Make Complaint";
		cout << "\n" << string(7, '\t') << "3. Bulk Payment";
		cout << "\n" << string(7, '\t') << "4. Update Details";
		cout << "\n" << string(7, '\t') << "5. Logout";

		cout << "\n\n" << string(7, '\t') << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			orderFood(accDetails);
			break;
		case 2: // Code by Jakob
			makeComplaint(accDetails);
			break;
		case 3:
			// bulk payment
			chooseBulkOrder(accDetails);
			break;
		case 4:
			if (accDetails[0].substr(0, 3) == "270") 
				updateParentDetails(accDetails[0], "user");
			else 
				updateStaffDetails(accDetails[0], "user");
				
			break;
		case 5:
			SetConsoleTextAttribute(h, 7);
			runMenu = false;
			break;
		default:
			cout << "\n" << string(7, '\t') << "Please enter a number relevant to the menu.";
			break;
		}
	} while (runMenu);
}

// code by jakob
// Function allows user to write a complaint about an order.
// It will also generate a complaint ID based on the previous complaint ID in the Complaint_file.csv
void makeComplaint(vector<string> accDetails) {

	ifstream readFile;
	ofstream compFile;
	string line;
	int complaintID, reason, lineNumber = 0, lastLine = 0;
	bool isTrue = true;

	char choice, tryAgain;
	struct Complaint complaint;

	string date = getCurrentDate();

	do {
		system("cls");
		schoolTitle();
		cout << "\n\t\t\t|----------------------------|";
		cout << "\n\t\t\t| Enter the complaint reason |";
		cout << "\n\t\t\t|----------------------------|";
		cout << "\n\t\t\t|1. Food issue               |";
		cout << "\n\t\t\t|2. Payment issue            |";
		cout << "\n\t\t\t|3. Other                    |";
		cout << "\n\t\t\t|4. Back                     |";
		cout << "\n\t\t\t|____________________________|";
		cout << "\n\t\t\t|Enter choice: ";
		cin >> reason;

		switch (reason) {
		case 1:
			complaint.reason = "Food_issue";
			isTrue = false;
			break;
		case 2:
			complaint.reason = "Payment_issue";
			isTrue = false;
			break;
		case 3:
			complaint.reason = "Misc_issue";
			isTrue = false;
			break;
		case 4:
			isTrue = false;
			break;
		default:
			cout << "\n\t\t\tPlease enter 1, 2 or 3. Try again.\n";
		}
	} while (isTrue);

	if (reason != 4) {
		isTrue = true;
		system("cls");

		// find how many lines there are in the file
		readFile.open("Complaint_file.csv");
		while (getline(readFile, line)) {
			lineNumber++;
		}
		readFile.close();

		// go to the last line and get the id
		readFile.open("Complaint_file.csv");
		do {
			while (getline(readFile, line)) {
				lastLine++;
				if (lastLine == lineNumber) {
					while (!readFile.eof()) {
						stringstream ss(line);

						try {
							complaint.complaintID = stoi(ss.str()) + 1;  // convert stringstream to string and then to int
						}
						catch (...) {
							complaint.complaintID = 1;
							isTrue = false;
							break;
						}

						isTrue = false;
						break;
					}
				}
			}
		} while (isTrue);
		readFile.close();

		cout << "\n\n\t\t\tComplaint ID:      " << complaint.complaintID;
		cout << "\n\t\t\tName:              " << accDetails[1];
		cout << "\n\t\t\tDate of complaint: " << date;
		cout << "\n\t\t\tComplaint reason:  " << complaint.reason;

		cout << "\n\n\t\t\t|------------------------|";
		cout << "\n\t\t\t| Complaint Description: |";
		cout << "\n\t\t\t|------------------------|";
		cout << "\n\n\t\t\t";
		cin.ignore();
		getline(cin, complaint.complaintDescription);

		cout << "\n\t\t\t|Confirm and place complaint? Y/N|: ";
		cin >> choice;

		do {
			if (tolower(choice) == 'y') {
				compFile.open("Complaint_file.csv", ios::app);
				if (compFile.is_open() == true) {
					// accDetails[0] = User ID
					// accDetails[1] = Person Name
					// accDetails[4] = Contact Number
					// accDetails[5] = Email
					compFile << complaint.complaintID << "," << accDetails[0] << "," << accDetails[1] << "," << date << "," << complaint.reason << ","
						<< complaint.complaintDescription << "," << accDetails[4] << "," << accDetails[5] << "," << complaint.actionStatus << endl;
					break;
				}
				else {
					cout << "\n\n\t\t\tError: Could not open complaint file. Please check if the complaint file is currently open.";
					cout << "\n\t\t\tTry again? y/n: ";
					cin >> tryAgain;
					if (tolower(tryAgain) == 'y') {
						continue;
					}
					else {
						compFile.close();
						break;
					}
				}
			}
			else {
				cout << "\n\t\t\tYou have canceled your complaint.";
				break;
			}
		} while (true);

		compFile.close();
	}

	cout << "\n\t\t\t";
	system("pause");
}

// Code by Jakob
void chooseBulkOrder(vector<string> accDetails) {

	int choice, flag;
	int orderCount = 0, i = 0;
	int totalBulkOrderCount;
	float purchaseAmount;
	ofstream bulkOrderFile;
	ifstream infile;
	char errorChoice;
	char confirmOrder;
	bool isTrue = true;
	bool accountExists = false;

	do {
		do {
			system("cls");
			schoolTitle();
			cout << "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|"
				<< "\n" << string(6, '\t') << "|                                   BULK BOOKING DISCOUNTS                                     |"
				<< "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|"
				<< "\n" << string(6, '\t') << "|    1. GOLD FOOD PASS         |     2. SILVER FOOD PASS      |      3. COPPER FOOD PASS       |"
				<< "\n" << string(6, '\t') << "|------------------------------|------------------------------|--------------------------------|"
				<< "\n" << string(6, '\t') << "|    Pay for 30 days and       |     Pay for 15 days and      |      Pay for 7 days and        |"
				<< "\n" << string(6, '\t') << "|    receive a 15% discount.   |     receive a 10% discount.  |      receive a 5% discount.    |"
				<< "\n" << string(6, '\t') << "|    Without food pass: $150   |     Without food pass: $75   |      Without food pass: $35    |"
				<< "\n" << string(6, '\t') << "|    With food pass: $127.5    |     With food pass: $67.50   |      With food pass: $33.25    |"
				<< "\n" << string(6, '\t') << "|    Save $22.50               |     Save $7.50               |      Save $1.75                |"
				<< "\n" << string(6, '\t') << "|----------------------------------------------------------------------------------------------|" << "\n\n" << string(7, '\t');

			cout << "\n" << string(6, '\t') << "Enter a pass number to purchase or 0 to exit: ";
			cin >> choice;

			if (choice == 0) {
				isTrue = false;
				break;
			}

			// Asking user to confirm bulk purchase
			cout << "\n" << string(6, '\t') << "Confirm bulk purchase? Y/N: ";
			cin >> confirmOrder;

			if (tolower(confirmOrder) == 'n') {
				cout << "\n" << string(6, '\t') << "You have canceled your bulk purchase.";
				cout << "\n" << string(6, '\t') << "Enter 1 to continue bulk purchase or 0 to exit: ";
				char cancelChoice;
				cin >> cancelChoice;
				if (cancelChoice == '0') {
					isTrue = false;
					break;
				}
				else if (cancelChoice == '1') {
					continue;
				}
			}
		} while (true);

		switch (choice) {
		case 1:
			orderCount = 30;
			isTrue = false;
			break;
		case 2:
			orderCount = 15;
			isTrue = false;
			break;
		case 3:
			orderCount = 7;
			isTrue = false;
			break;
		default:
			cout << "\n\t\t\tPlease enter a number relevant to the menu...";
		}
	} while (isTrue);

	if (bulkOrderFile.good()) {
		if (orderCount > 0) {
			do {
				accountExists = checkBulkFile(accDetails);

				if (accountExists == false) { // if account doesnt exist in file yet
					bulkOrderFile.open("BulkOrder_file.csv", ios::app);
					if (bulkOrderFile.good()) {
						bulkOrderFile << accDetails[0] << "," << orderCount << endl;
						cout << "\n\t\t\tYour purchase of option " << choice << " was successful! You now have " << orderCount << " free meals.";
						cout << "\n\t\t\t";
						system("pause");
						break;
					}
					else { // error message
						cout << "\n\t\t\tError: Could not open bulk order file. Please check if the bulk order file is currently open.";
						cout << "\n\t\t\tTry again? Y/N: ";
						cin >> errorChoice;
						if (tolower(errorChoice) == 'y') {
							continue;
						}
						else {
							cout << "\n\t\t\tYou canceled your bulk order.";
							cout << "\n\t\t\t";
							system("pause");
							break;
						}
					}
				}
				else { // if user already has
					totalBulkOrderCount = updateBulkOrderCount(accDetails, orderCount);
					cout << "\n\t\t\tPurchase successful! Your total bulk order count is: " << totalBulkOrderCount;
					cout << "\n\n\t\t\t";
					system("pause");
					break;
				}

			} while (true);
		}
	}
	else {
		cout << "\n\t\t\tCouldn't open bulk file. Please check that it isn't currently open.";
		cout << "\n\t\t\t";
		system("pause");
	}

	bulkOrderFile.close();
}

// Code by Jakob
// This function checks the order file to see if the user has already ordered a bulk order before.
bool checkBulkFile(vector<string> accDetails) {
	ifstream bulkOrderFile;
	string line, tempStr;
	bulkOrderFile.open("BulkOrder_file.csv", ios::in);

	while (getline(bulkOrderFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == accDetails[0]) {
				bulkOrderFile.close();
				return true;
			}
		}
	}
	return false;
	bulkOrderFile.close();
}

// Code by Jakob
// This function updates the users bulk order count
int updateBulkOrderCount(vector<string> accDetails, int orderCount) {
	ifstream bulkOrderFile;
	string line, tempStr;
	vector<string> originalFile;
	vector<string> updatedFile;
	int returnValue = 0;
	bulkOrderFile.open("BulkOrder_file.csv", ios::in);

	// get bulk order file into vector
	while (getline(bulkOrderFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			originalFile.push_back(tempStr);
		}
	}

	updatedFile = originalFile;
	originalFile.clear(); // clear this vector in case a user logs out and another person logs in to add to their bulk order :D
	bulkOrderFile.close();

	// update users order count in the vector
	for (int i = 0; i < updatedFile.size(); i++) {
		if (updatedFile[i] == accDetails[0]) {
			returnValue = stoi(updatedFile[i + 1]) + orderCount;
			updatedFile[i + 1] = to_string(returnValue);
			break;
		}
	}

	// upate users order count in the file
	ofstream updateFile;
	updateFile.open("BulkOrder_file.csv", ios::out);
	for (int i = 0; i < updatedFile.size();) {
		updateFile << updatedFile[i] << "," << updatedFile[i + 1] << endl;
		i = i + 2;
	}
	updateFile.close();
	return returnValue;
}

// Code by Jakob
// This function gets the current date and converts it to a string.
string getCurrentDate() {
	tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;
	int month = newtime.tm_mon + 1;
	int year = newtime.tm_year + 1900;

	string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

	return date;
}

// Code by Jay
//creates a csv file for food  menu
void createFoodMenuList() {
	string foodDetails[][3] = { {"1.","2.","3."},
								{"Beef Noodles", "Chicken Burger", "Fruit Salad"},
								{"Noodles cooked with luxruious beef.", "Grilled chicken with lettuce and ketchup that will make the ladies want you!","Fruit Salad with orange pineapple kiwi melon and apple."},
								{"Vegan:No Gluten:No","Vegan:No Gluten:Yes","Vegan:Yes Gluten:Yes"},
								{"$5.00","$5.00","$5.00"},
								{"4.","5.","6."},
								{"Eggs Benedict", "Egg Fried Rice", "French Toast Wee Wee"},
								{"Poached egg with bacon and hollandaise sauce on a muffin with a sprinkle of love.", "Rice with egg and MSG just how Uncle Roger likes.","Just toast and diabetes. Oui oui!"},
								{"Vegan:No Gluten:Yes","Vegan:No Gluten:No","Vegan:Yes Gluten:Yes"},
								{"$5.00","$5.00","$5.00"} };

	//creating food menu file
	ofstream createFoodMenu("FoodMenu_File.csv", ios::out);
	for (int j = 0; j < 3; j++) {
		for (int x = 0; x < 5; x++) {
			createFoodMenu << foodDetails[x][j] << ",";
		}
		createFoodMenu << endl;
	}
	for (int i = 0; i < 3; i++) {
		for (int h = 5; h < 10; h++)
		{
			createFoodMenu << foodDetails[h][i] << ",";
		}
		createFoodMenu << endl;
	}
	createFoodMenu.close();
}

// Code by Jay
//This function updates the food menu list
void updateMenuList() {
	int choice = 0, id = 0, foodNum, col = 0, nxt = 0;
	float foodPrice;
	string isVegan, isGlutten, foodName, foodDescription, foodDietary;
	FoodMenuList fml[6];
	string foodDetails[10][3];
	string(*ptrFD)[10][3] = &foodDetails;
	bool isTrue;

	getFoodMenuList(ptrFD);
	system("cls");
	for (int i = 0; i < 6; i++) {
		fml[i].foodNum = stoi(foodDetails[0 + nxt][col]);
		fml[i].foodName = foodDetails[1 + nxt][col];
		fml[i].foodDescription = foodDetails[2 + nxt][col];
		fml[i].foodDietary = foodDetails[3 + nxt][col];
		fml[i].foodPrice = stof(foodDetails[4 + nxt][col].substr(1, foodDetails[4 + nxt][col].length()));
		col++;
		if (col == 3) {
			col = 0;
			nxt = 5;
		}
	}

	do {
		isTrue = true;
		schoolTitle();
		printWeeklyMenu();
		cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
			<< "\n" << string(6, '\t') << "|                 Update Food Menu               |"
			<< "\n" << string(6, '\t') << "|------------------------------------------------|"
			<< "\n" << string(6, '\t') << "| Press 1 to change Menu 1                       |"
			<< "\n" << string(6, '\t') << "| Press 2 to change Menu 2                       |"
			<< "\n" << string(6, '\t') << "| Press 3 to change Menu 3                       |"
			<< "\n" << string(6, '\t') << "| Press 4 to change Menu 4                       |"
			<< "\n" << string(6, '\t') << "| Press 5 to change Menu 5                       |"
			<< "\n" << string(6, '\t') << "| Press 6 to change Menu 6                       |"
			<< "\n" << string(6, '\t') << "| Press 7 to exit                                |"
			<< "\n" << string(6, '\t') << "|------------------------------------------------|"
			<< "\n" << string(6, '\t') << "| Choose which menu you want to change: ";
		cin >> id;
		cin.ignore();
		if (id >= 1 && id <= 6) {
			isTrue = false;
		}
		else if (id == 7) {
			id = 0;
			isTrue = false;
		}
		else {
			cout << "\n" << string(8, '\t') << "|-----------------------------------|"
				<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
				<< "\n" << string(8, '\t') << "|-----------------------------------|\n\t\t\t";
			system("pause");
		}
		system("cls");
	} while (isTrue);

	if (id != 0) {
		do {
			isTrue = true;
			cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
				<< "\n" << string(6, '\t') << "|                 Update Food Menu               |"
				<< "\n" << string(6, '\t') << "|------------------------------------------------|"
				<< "\n" << string(6, '\t') << "| Current Food Name:           " << fml[id].foodName
				<< "\n" << string(6, '\t') << "| Current Food Description:    " << fml[id].foodDescription
				<< "\n" << string(6, '\t') << "| Current Food Dietary Option: " << fml[id].foodDietary
				<< "\n" << string(6, '\t') << "| Current Food Price:          " << fml[id].foodPrice
				<< "\n\n" << string(6, '\t') << "|------------------------------------------------|"
				<< "\n" << string(6, '\t') << "|                 Update Food Menu               |"
				<< "\n" << string(6, '\t') << "|------------------------------------------------|"
				<< "\n" << string(6, '\t') << "| Press 1 to change food name                    |"
				<< "\n" << string(6, '\t') << "| Press 2 to change food description             |"
				<< "\n" << string(6, '\t') << "| Press 3 to change food dietary option          |"
				<< "\n" << string(6, '\t') << "| Press 4 to change food price                   |"
				<< "\n" << string(6, '\t') << "| Press 5 to exit.                               |"
				<< "\n" << string(6, '\t') << "|------------------------------------------------|"
				<< "\n" << string(6, '\t') << "|Choose which food detail to change: ";
			cin >> choice;
			cin.ignore();

			id -= 1;
			switch (choice) {
			case 1:
				do {
					do {
						cout << "\n" << string(6, '\t') << "|----------------------------------------------------"
							<< "\n" << string(6, '\t') << "| Current Food name: " << fml[id].foodName
							<< "\n" << string(6, '\t') << "| Enter food name: ";
						getline(cin, foodName);
						if (foodName != "" && foodName != " ")
							break;
						else {
							cout << "\n" << string(6, '\t') << "Invalid input, Please enter food name.." << "\n" << string(6, '\t');
							system("pause");
						}
						system("cls");
					} while (true);
					fml[id].foodName = foodName;
					cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
						<< "\n" << string(6, '\t') << "|             Food Menu has been updated         |"
						<< "\n" << string(6, '\t') << "|------------------------------------------------|" << "\n" << string(8, '\t');
					system("pause");
					isTrue = false;
					break;
				} while (true);
				break;
			case 2:
				do {
					do {
						cout << "\n" << string(6, '\t') << "|----------------------------------------------------"
							<< "\n" << string(6, '\t') << "| Current food description: " << fml[id].foodDescription
							<< "\n" << string(6, '\t') << "| Enter food description: ";
						getline(cin, foodName);
						if (foodName != "" && foodName != " ")
							break;
						else {
							cout << "\n" << string(6, '\t') << "Invalid input, Please enter food name.." << "\n" << string(6, '\t');
							system("pause");
						}
						system("cls");
					} while (true);
					fml[id].foodDescription = foodDescription;
					cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
						<< "\n" << string(6, '\t') << "|             Food Menu has been updated         |"
						<< "\n" << string(6, '\t') << "|------------------------------------------------|" << "\n" << string(8, '\t');
					system("pause");
					isTrue = false;
					break;
				} while (true);
				break;

			case 3:
				do {
					do {
						cout << "\n" << string(6, '\t') << "|-------------------------------------|"
							<< "\n" << string(6, '\t') << "| Current Dietary option: " << fml[id].foodDietary
							<< "\n" << string(6, '\t') << "| Press Y if food is vegan            "
							<< "\n" << string(6, '\t') << "| Press N if food is not vegan        "
							<< "\n" << string(6, '\t') << "|-------------------------------------|"
							<< "\n" << string(6, '\t') << "| Please enter your option: ";
						getline(cin, isVegan);
						if (isVegan != " " || isVegan.length() == 1)
							break;
						else {
							cout << "\n" << string(6, '\t') << "Invalid input, Please enter food name.." << "\n" << string(6, '\t');
							system("pause");
						}
						system("cls");
					} while (true);
					do {
						cout << "\n" << string(6, '\t') << "|-------------------------------------|"
							<< "\n" << string(6, '\t') << "| Current Dietary option: " << fml[id].foodDietary
							<< "\n" << string(6, '\t') << "| Press Y if food is Glutten free     "
							<< "\n" << string(6, '\t') << "| Press N if food is not Glutten free "
							<< "\n" << string(6, '\t') << "|-------------------------------------|"
							<< "\n" << string(6, '\t') << "| Please enter your option: ";
						getline(cin, isGlutten);
						if (isGlutten != " " || isGlutten.length() == 1)
							break;
						else {
							cout << "\n" << string(6, '\t') << "Invalid input, Please enter food name.." << "\n" << string(6, '\t');
							system("pause");
						}
						system("cls");
					} while (true);
					if (tolower(isVegan[0]) == 'y')
						isVegan = "Yes";
					else
						isVegan = "No";
					if (tolower(isGlutten[0]) == 'y')
						isGlutten = "Yes";
					else
						isGlutten = "No";
					fml[id].foodDietary = "Vegan: " + isVegan + " Gluten: " + isGlutten;
					break;
				} while (true);
				cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
					<< "\n" << string(6, '\t') << "|             Food Menu has been updated         |"
					<< "\n" << string(6, '\t') << "|------------------------------------------------|" << "\n" << string(8, '\t');
				system("pause");
				isTrue = false;
				break;
			case 4:
				do {
					do {
						cout << "\n" << string(6, '\t') << "|-------------------------------------|"
							<< "\n" << string(6, '\t') << "| Current Food price: " << fml[id].foodPrice
							<< "\n" << string(6, '\t') << "| Enter food Price: ";
						cin >> foodPrice;
						cin.ignore();
						if (foodPrice != 0)
							break;
						else {
							cout << "\n" << string(6, '\t') << "Invalid input, Please enter food name.." << "\n" << string(6, '\t');
							system("pause");
						}
						system("cls");
					} while (true);
					fml[id].foodPrice = foodPrice;
					break;
				} while (true);
				cout << "\n" << string(6, '\t') << "|------------------------------------------------|"
					<< "\n" << string(6, '\t') << "|             Food Menu has been updated         |"
					<< "\n" << string(6, '\t') << "|------------------------------------------------|" << "\n" << string(8, '\t');
				system("pause");
				isTrue = false;
				break;
			case 5:
				cout << "\n\t\t\tUser has not been updated...";
				system("pause");
				isTrue = false;
				break;
			default:
				cout << "\n" << string(8, '\t') << "|-----------------------------------|"
					<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
					<< "\n" << string(8, '\t') << "|-----------------------------------|" << "\n" << string(8, '\t');
				system("pause");
				break;
			}
			system("cls");
		} while (isTrue);
	}

	ofstream updateFoodMenu("FoodMenu_File.csv", ios::out);
	for (int i = 0; i < 6; i++) {
		updateFoodMenu << fml[i].foodNum << "," << fml[i].foodName << ","
			<< fml[i].foodDescription << "," << fml[i].foodDietary << ","
			<< "$" + to_string(fml[i].foodPrice) << endl;
	}
	updateFoodMenu.close();
}

//Code by Jay
//This function gets the details of the food in cvs and stores it in matrix array
void getFoodMenuList(string(*ptrFD)[10][3]) {
	string line, tempStr;
	ifstream myfile;

	myfile.open("FoodMenu_File.csv", ios::in);

	int j = 0, i = 0;
	while (getline(myfile, line)) {
		stringstream ss(line);
		if (j <= 2) {
			for (int x = 0; x < 5; x++) {
				while (!ss.eof()) {
					getline(ss, tempStr, ',');
					(*ptrFD)[x][j] = tempStr;
					if (x != 9)
						x++;
				}
			}
		}
		j++;
		if (j >= 3) {
			while (getline(myfile, line)) {
				stringstream ss(line);
				for (int x = 5; x < 10; x++) {
					while (!ss.eof()) {
						getline(ss, tempStr, ',');
						if (tempStr != "")
							(*ptrFD)[x][i] = tempStr;
						if (x != 9)
							x++;
					}
				}
				i++;
			}
		}
	}
	myfile.close();
}

//Code by Jay
//This function prints out the food menu to the user
void printWeeklyMenu() {
	string foodDetails[10][3];
	string(*ptrFD)[10][3] = &foodDetails;

	getFoodMenuList(ptrFD);

	int lastPos[3] = { 0,0,0 };
	int count = 0;
	int wordSpace = 0;
	bool rowIsDone[3] = { 0,0,0 };

	for (int row = 0; row < 10; row++) {
		if (row == 2 || row == 3 || row == 7 || row == 8) {	//print line to separte food name, description and price		
			for (int print = 0; print < 3; print++) {
				cout << "\t\t----------------------\t\t";
				if (print == 2)
					cout << endl;
			}
		}
		for (int reset = 0; reset < 3; reset++) {
			rowIsDone[reset] = 0;
			lastPos[reset] = 0;
		}

		for (int col = 0; col < 3; col++) {
			while (!rowIsDone[0] || !rowIsDone[1] || !rowIsDone[2]) // loop while all rows are done printing
			{
				int column = 0;
				while (column < 3) {
					cout << "\t\t";
					if (rowIsDone[column]) {
						for (int i = 0; i < 21; i++)
							cout << " ";
					}
					for (int letter = lastPos[column]; letter < (*ptrFD)[row][column].length(); letter++) {
						if (count < 21) {
							if ((*ptrFD)[row][column][letter] == ' ') { //if next char is space 
								int p = letter + 1;
								while ((*ptrFD)[row][column][p] != ' ' && p < (*ptrFD)[row][column].length()) { //loop while next index is space
									wordSpace++;
									p++;
								}
							}

							cout << (*ptrFD)[row][column][letter]; //print next char

							int space = 21 - count; //check how many space left in the row if there is no more space for the word goto next line
							if (wordSpace >= space) {
								for (int i = 0; i < space; i++)//if there is no more room to print letters stop and go to next coloumn
									cout << " ";
								count = 21;
							}
							else
								wordSpace = 0;

							if (letter == (*ptrFD)[row][column].length() - 1) {//print spaces 
								rowIsDone[column] = true;
								for (int i = 0; i < space; i++)
									cout << " ";
							}
							count++;
							lastPos[column] = letter + 1;
						}
					}
					cout << "\t\t";
					count = 0;
					if ((*ptrFD)[row][column][lastPos[column]] == ' ')//if the last character in the range of 21 characters is space increment by one
						lastPos[column]++;
					column++;
				}
				cout << endl;
			}
		}
		if (row == 4)
			cout << "\n\n";
	}
	cout << endl;
}

void createFiles() {
	ifstream adminFile("Admin_file.csv");
	ifstream loginFile("Login_file.csv");
	ifstream parentFile("Parent_file.csv");
	ifstream staffFile("Staff_file.csv");
	ifstream compFile("Complaint_file.csv");
	ifstream orderFile("Order_file.csv");
	ifstream FoodMenu_file("FoodMenu_file.csv");
	ifstream bulkOrderFile("BulkOrder_file.csv");
	ifstream paymentFile("Payment_file.csv");

	if (!adminFile.good()) {
		ofstream adminFile;
		adminFile.open("Admin_file.csv", ios::out);
		adminFile << "USERNAME" << "," << "PASSWORD" << endl;
		adminFile << "admin" << "," << "cs103" << endl; // ADMIN USERNAME AND PASSWORD HERE
		adminFile.close();
	}

	if (!loginFile.good()) {
		ofstream loginFile;
		loginFile.open("Login_file.csv", ios::out);
		loginFile << "PRIMARY_KEY" << "," << "FOREIGN_KEY" << "," << "USERNAME" << "," << "PASSWORD" << endl;
		loginFile.close();
	}

	if (!parentFile.good()) {
		ofstream parentFile;
		parentFile.open("Parent_file.csv", ios::out);
		parentFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
			<< "," << "CHILD_NAME" << "," << "ROOM_NUM" << "," << "VISA_NUM" << "," << "VISA_EXPIRY" << "," << "ACC_STATUS" << endl;
		parentFile.close();
	}

	if (!staffFile.good()) {
		ofstream staffFile;
		staffFile.open("Staff_file.csv", ios::out);
		staffFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
			<< "," << "VISA_NUM" << "," << "VISA_EXPIRY" << "," << "ACC_STATUS" << endl;
		staffFile.close();
	}

	if (!compFile.good()) {
		ofstream compFile;
		compFile.open("Complaint_file.csv", ios::out);
		compFile << "COMP_ID" << "," << "USER_ID" << "," << "NAME" << "," << "DATE" << "," << "REASON" << "," << "DESC." << "," << "CONTACT NUM"
			<< "," << "EMAIL" << "," << "ACTION_STATUS" << endl;
	}

	// order file, dont add child name or classroom number
	if (!orderFile.good()) {
		ofstream orderFile;
		orderFile.open("Order_file.csv", ios::out);
		orderFile << "ORDER_ID" << "," << "FOREIGN_KEY" << "," << "DATE" << "," << "ITEM_NAME" << "," << "QUANTITY" << "," << "PRICE" << "," << "PAYMENT_STATUS" << "," << "ORDER_NUM" << endl;
	}

	if (!FoodMenu_file.good()) {
		createFoodMenuList();
	}

	if (!bulkOrderFile.good()) {
		ofstream bulkOrderFile;
		bulkOrderFile.open("BulkOrder_file.csv");
		bulkOrderFile << "USER_ID" << "," << "ORDER_COUNT" << endl;
	}

	if (!paymentFile.good()) {
		ofstream paymentFile;
		paymentFile.open("Payment_file.csv");
		paymentFile << "PAYMENT_ID" << "," << "FOREIGN_KEY" << "," << "GST_NUMBER" << "," << "GST_AMOUNT" << "," << "TYPE_OF_PAYMENT" << "," << "BULK_PAYMENT_DISCOUNT" << "," << "TOTAL_PRICE" << "," << "DATE" << endl;
	}
}

//Code by Jay
//This function lets the user order food
void orderFood(vector<string> user) {
	int orderNum;
	bool isTrue = true, isTrue2 = true;
	char choice = 'n';
	string orderName;
	vector<Order> order;
	vector<Order> unpaidOrders;
	vector<Order> ord;

	system("cls");
	//gohere
	unpaidOrders.clear();
	unpaidOrders = getAllUnpaidOrders(user[0]); //check if user has unpaid orders

	if (unpaidOrders.size() != 0) { //if user has unpaid order prompt user if they want to pay it
		schoolTitle();
		printAllOrders(unpaidOrders); //print unpaid orders
		do {//ask user if they want to keep the saved order or delete it			
			cout << "\n\t\t\t\t\t\t\t|-----------------------------------------------------------------------| "
				<< "\n\t\t\t\t\t\t\t| You have a saved order from a previous session!"
				<< "\n\t\t\t\t\t\t\t| Would you like to proceed with your saved order(s) or delete them?"
				<< "\n\t\t\t\t\t\t\t| (You can add more to your order if you choose to proceed!)"
				<< "\n\t\t\t\t\t\t\t| Press 'Y' to proceed with saved orders"
				<< "\n\t\t\t\t\t\t\t| Press 'N' to delete saved orders"
				<< "\n\t\t\t\t\t\t\t| Enter option: ";
			cin >> choice;

			if (tolower(choice) == 'y') {
				order = unpaidOrders;
				do {
					cout << "\n\t\t\t\t\t\t\t|-----------------------------------------------------------------| "
						<< "\n\t\t\t\t\t\t\t| Would you like to proceed to checkout with your current order?"
						<< "\n\t\t\t\t\t\t\t| Press 'Y' to proceed to checkout"
						<< "\n\t\t\t\t\t\t\t| Press 'N' to add more items"
						<< "\n\t\t\t\t\t\t\t| Enter option: ";
					cin >> choice;

					if (tolower(choice) == 'y') {
						order = checkoutOrder(order, user);
						isTrue2 = false;
						break;
					}
					else if (tolower(choice) == 'n') {
						isTrue2 = false;
						isTrue2 = false;
						break;
					}
					else {
						cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
							<< "\n\t\t\t\t\t\t\t| Invalid Input! Please try again. |"
							<< "\n\t\t\t\t\t\t\t|-----------------------------------|";
					}
					system("cls");
					printAllOrders(order);
				} while (true);
			}
			else if (tolower(choice) == 'n') {
				removeAllUnpaidOrders(user[0]);
				isTrue2 = false;
			}
			else {
				cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
					<< "\n\t\t\t\t\t\t\t| Invalid Input! Please try again. |"
					<< "\n\t\t\t\t\t\t\t|-----------------------------------|";
			}
			system("cls");
			printAllOrders(order);
		} while (isTrue2);
	}
	if (tolower(choice) == 'n') {
		do {
			system("cls");
			schoolTitle();
			printWeeklyMenu();
			cout << "\n\t\t\t\t\t\t\t Date: " << getCurrentDate()
				<< "\n\t\t\t\t\t\t\t|---------------------------------|"
				<< "\n\t\t\t\t\t\t\t|           School Name           |"
				<< "\n\t\t\t\t\t\t\t|---------------------------------|"
				<< "\n\t\t\t\t\t\t\t|            ORDER FOR            |"
				<< "\n\t\t\t\t\t\t\t|---------------------------------|";
			if (user[0].substr(0, 3) == "270") {
				cout << "\n\t\t\t\t\t\t\t| Student Name:     " << user[1]
					<< "\n\t\t\t\t\t\t\t| Student Room no.: " << user[7];
			}
			else {
				cout << "\n\t\t\t\t\t\t\t| Staff Name:   " << user[1];
			}
			cout << "\n\t\t\t\t\t\t\t|---------------------------------|"
				<< "\n\t\t\t\t\t\t\t| Press 1 to order meal           |"
				<< "\n\t\t\t\t\t\t\t| Press 2 to remove order         |"
				<< "\n\t\t\t\t\t\t\t| Press 3 to print order details  |"
				<< "\n\t\t\t\t\t\t\t| Press 4 to checkout             |"
				<< "\n\t\t\t\t\t\t\t| Press 5 to exit                 |"
				<< "\n\t\t\t\t\t\t\t|---------------------------------|"
				<< "\n\t\t\t\t\t\t\t| Enter option: ";
			cin >> orderNum;
			switch (orderNum) {
			case 1:
				do {
					do {
						cout << "\n\t\t\t\t\t\t\t|--------------------------"
							<< "\n\t\t\t\t\t\t\t| Enter meal number: ";
						cin >> orderNum;
						if (orderNum >= 1 && orderNum <= 6)
							break;
						else {
							cout << "\n\t\t\t\t\t\t\t|-------------------------------------------|"
								<< "\n\t\t\t\t\t\t\t| Invalid meal number, Please try again...  |"
								<< "\n\t\t\t\t\t\t\t|-------------------------------------------|\n";
						}
					} while (true);

					ord = getFoodOrderDetails(ord, orderNum);
					cout << ord.size();
					cout << "\n\t\t\t\t\t\t\t|------------------------------------|"
						<< "\n\t\t\t\t\t\t\t| Order ID:        " << ord[0].orderNum
						<< "\n\t\t\t\t\t\t\t| Item Name:       " << ord[0].itemName
						<< "\n\t\t\t\t\t\t\t| Price:           $" << ord[0].price
						<< "\n\t\t\t\t\t\t\t|------------------------------------|" << endl;
					ord.clear(); //clear after showing the order

					cout << "\n\t\t\t\t\t\t\t|--------------------------------------|"
						<< "\n\t\t\t\t\t\t\t| Do you want to confirm this order?   |"
						<< "\n\t\t\t\t\t\t\t| Press 'Y' to confirm order           |"
						<< "\n\t\t\t\t\t\t\t| Press 'N' to change the order        |"
						<< "\n\t\t\t\t\t\t\t| Press 'Q' to quit from order         |"
						<< "\n\t\t\t\t\t\t\t|--------------------------------------|"
						<< "\n\t\t\t\t\t\t\t| Enter option: ";
					cin >> choice;

					if (tolower(choice) == 'y') {
						cout << "\n\t\t\t\t\t\t\t|---------------------|"
							<< "\n\t\t\t\t\t\t\t|   Order confirmed   |"
							<< "\n\t\t\t\t\t\t\t|---------------------|\n\t\t\t\t\t\t";
						order = getFoodOrderDetails(order, orderNum);
						break;
					}
					else if (tolower(choice) == 'n') {
						cout << "\n\t\t\t\t\t\t\t|---------------------|"
							<< "\n\t\t\t\t\t\t\t|   Order cancelled   |"
							<< "\n\t\t\t\t\t\t\t|---------------------|\n";
					}
					else if (tolower(choice) == 'q') {
						cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
							<< "\n\t\t\t\t\t\t\t|     Exiting from order menu...    |"
							<< "\n\t\t\t\t\t\t\t|-----------------------------------|\n\t\t\t\t\t\t";
						break;
					}
					else {
						cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
							<< "\n\t\t\t\t\t\t\t| Invalid Input! Please try again.. |"
							<< "\n\t\t\t\t\t\t\t|-----------------------------------|";
					}
					system("cls");
					printWeeklyMenu();
					cout << "\n\t\t\t\t\t\t\t Date: " << getCurrentDate()
						<< "\n\t\t\t\t\t\t\t|---------------------------------|"
						<< "\n\t\t\t\t\t\t\t|           School Name           |"
						<< "\n\t\t\t\t\t\t\t|---------------------------------|"
						<< "\n\t\t\t\t\t\t\t|            ORDER FOR            |"
						<< "\n\t\t\t\t\t\t\t|---------------------------------|";
					if (user[0].substr(0, 3) == "270") {
						cout << "\n\t\t\t\t\t\t\t| Student Name:     " << user[6]
							<< "\n\t\t\t\t\t\t\t| Student Room no.: " << user[7];
					}
					else {
						cout << "\n\t\t\t\t\t\t\t| Staff Name:   " << user[1];
					}
				} while (true);
				system("pause");
				break;
			case 2:
				order = removeOrder(order);
				break;
			case 3:
				system("cls");
				schoolTitle();
				printAllOrders(order);
				system("pause");
				break;
			case 4:
				order = checkoutOrder(order, user);
				break;
			case 5:
				cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
					<< "\n\t\t\t\t\t\t\t|     Exiting from order menu...    |"
					<< "\n\t\t\t\t\t\t\t|-----------------------------------|\n\t\t\t\t\t\t";
				isTrue = false;
				system("pause");
				break;
			default:
				cout << "\n\t\t\t\t\t\t\t|-----------------------------------|"
					<< "\n\t\t\t\t\t\t\t| Invalid Input! Please try again.. |"
					<< "\n\t\t\t\t\t\t\t|-----------------------------------|";
				system("pause");
				break;
			}
			system("cls");
		} while (isTrue);
	}
}

//Code by Jay
//This function prints out all of the user order from the menu
void printAllOrders(vector<Order> order) {
	float total = 0;

	cout << setprecision(3);
	if (order.size() == 0) {
		cout << "\n" << string(4, '\t') << "|--------------------|"
			<< "\n" << string(4, '\t') << "|   No Data Found    |"
			<< "\n" << string(4, '\t') << "|--------------------|\n" << string(4, '\t');
	}

	cout << "\n" << string(4, '\t');
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << "\n" << string(9, '\t') << "Order Details\n" << string(4, '\t');
	for (int i = 0; i < 100; i++)
		cout << "-";

	cout << "\n" << string(4, '\t') << "| Order Number | Date \t\t| Name\t\t\t| Order Quantity |  Price  | Total  \n" << string(4, '\t');
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < order.size(); i++) {
		total += order[i].price * order[i].quantity;
		cout << string(4, '\t') << "  " << order[i].orderNum;
		printSpaces(to_string(order[i].orderNum).length(), 15);
		cout << order[i].orderDate;
		printSpaces(order[i].orderDate.length(), 17);
		cout << order[i].itemName;
		printSpaces(order[i].itemName.length(), 30);
		cout << order[i].quantity;
		printSpaces(to_string(order[i].quantity).length(), 12);
		cout << "$" << order[i].price;
		printSpaces(to_string(order[i].price).length(), 15);
		cout << "$" << total;
		cout << endl;
		total = 0;
	}
	cout << endl;
	/*cout << setprecision(3);
	if (order.size() == 0) {
		cout << "\n\t\t\t|--------------------|"
			<< "\n\t\t\t|   No Data Found    |"
			<< "\n\t\t\t|--------------------|\n\t\t\t";
	}
	for (int i = 0; i < order.size(); i++) {
		total += order[i].price * order[i].quantity;
		cout << "\n\t\t\t|------------------------------------|"
			<< "\n\t\t\t| Order ID:        " << order[i].orderNum
			<< "\n\t\t\t| Order Date:      " << order[i].orderDate
			<< "\n\t\t\t| Item Name:       " << order[i].itemName
			<< "\n\t\t\t| Order Quantity:  " << order[i].quantity
			<< "\n\t\t\t| Price:           $" << order[i].price
			<< "\n\t\t\t|------------------------------------|" << endl;
	}
	cout << "\n\t\t\t|-----------------------|"
		<< "\n\t\t\t| TOTAL: $" << total
		<< "\n\t\t\t|-----------------------|\n\t\t\t";*/
}

//Code by Jay
//This function lets the user remove orders 
vector<Order> removeOrder(vector<Order> order) {
	int orderID, vectOrderLoc;
	bool isTrue, isTrue2, isTrue3;
	int numChoice;

	do {
		system("cls");
		isTrue = true, isTrue2 = true, isTrue3 = true;
		do {
			system("cls");
			schoolTitle();
			cout << "\n\n\n" << string(7, '\t') << "|---------------------------|"
				<< "\n" << string(7, '\t') << "| Press 1 to remove orders  |"
				<< "\n" << string(7, '\t') << "| Press 2 to quit           |"
				<< "\n" << string(7, '\t') << "|---------------------------|"
				<< "\n" << string(7, '\t') << "| Enter Option: ";
			cin >> numChoice;

			switch (numChoice) {
			case 1:
				if (order.size() > 0) {
					do {
						system("cls");
						schoolTitle();
						printAllOrders(order);
						cout << "\n\n\n" << string(4, '\t') << "|-------------------------------------------|"
							<< "\n" << string(4, '\t') << "| Please enter order number you wish to remove: ";
						cin >> orderID;
						for (int i = 0; i < order.size(); i++) {
							if (order[i].orderNum == orderID) {
								isTrue = false;
								vectOrderLoc = i;

								system("cls");
								do {
									schoolTitle();
									cout << "\n" << string(7, '\t') << "|------------------------------------------------|"
										<< "\n" << string(7, '\t') << "| Order ID:       " << order[vectOrderLoc].orderNum
										<< "\n" << string(7, '\t') << "| Order Date:     " << order[vectOrderLoc].orderDate
										<< "\n" << string(7, '\t') << "| Item Name:      " << order[vectOrderLoc].itemName
										<< "\n" << string(7, '\t') << "| Order Quantity: " << order[vectOrderLoc].quantity
										<< "\n" << string(7, '\t') << "| Price:          " << order[vectOrderLoc].price
										<< "\n" << string(7, '\t') << "|------------------------------------------------|"
										<< "\n" << string(7, '\t') << "| Press 1 to subract order quantity              |"
										<< "\n" << string(7, '\t') << "| Press 2 to remove order completely             |"
										<< "\n" << string(7, '\t') << "| Press 3 to exit                                |"
										<< "\n" << string(7, '\t') << "|------------------------------------------------|"
										<< "\n" << string(7, '\t') << "| Enter Option: ";
									cin >> numChoice;

									switch (numChoice) {
									case 1:
										order[vectOrderLoc].quantity -= 1;
										if (order[vectOrderLoc].quantity == 0) {
											cout << "\n" << string(7, '\t') << "|-------------------------|"
												<< "\n" << string(7, '\t') << "| Order has been removed  |"
												<< "\n" << string(7, '\t') << "|-------------------------|\n" << string(7, '\t');
											order.erase(order.begin() + vectOrderLoc);
											isTrue2 = false;
											cout << order.size() << endl;
											system("pause");
										}
										break;
									case 2:
										order.erase(order.begin() + vectOrderLoc);
										cout << "\n" << string(7, '\t') << "|-------------------------|"
											<< "\n" << string(7, '\t') << "| Order has been removed  |"
											<< "\n" << string(7, '\t') << "|-------------------------|\n" << string(7, '\t');
										system("pause");
										isTrue2 = false;
										break;
									case 3:
										isTrue2 = false;
										break;
									default:
										cout << "\n" << string(7, '\t') << "|-----------------------------------|"
											<< "\n" << string(7, '\t') << "| Invalid Input! Please try again.. |"
											<< "\n" << string(7, '\t') << "|-----------------------------------|" << string(7, '\t');
										system("pause");
										break;
									}
								} while (isTrue2);

							}
						}
						if (isTrue) {
							cout << "\n" << string(7, '\t') << "|-------------------------------------------|"
								<< "\n" << string(7, '\t') << "|   Invalid order ID.. Please try again...  |"
								<< "\n" << string(7, '\t') << "|-------------------------------------------|" << string(7, '\t');
							system("pause");
						}
					} while (isTrue);
				}
				else {
					cout << "\n" << string(7, '\t') << "|--------------------------------|"
						<< "\n" << string(7, '\t') << "| There are no orders to show    |"
						<< "\n" << string(7, '\t') << "|--------------------------------|\n" << string(7, '\t');
					system("pause");
				}
				break;
			case 2:
				cout << "\n" << string(7, '\t') << "|-----------------------------------|"
					<< "\n" << string(7, '\t') << "| Exiting from remove order menu... |"
					<< "\n" << string(7, '\t') << "|-----------------------------------|\n" << string(7, '\t');

				system("pause");
				numChoice = 69;
				isTrue3 = false;
				break;

			default:
				cout << "\n" << string(7, '\t') << "|-----------------------------------|"
					<< "\n" << string(7, '\t') << "| Invalid Input! Please try again.. |"
					<< "\n" << string(7, '\t') << "|-----------------------------------|\n" << string(7, '\t');
				system("pause");
				break;
			}
		} while (isTrue3);
	} while (numChoice != 69);
	return order;
}

//Code by Jay
//This function gets the details of the food in csv file and stores and returns it as vector struct order
vector<Order> getFoodOrderDetails(vector<Order> order, int orderNum) {
	vector<string>foodDetails;
	struct Order tempOrder;
	string line, tempStr;
	ifstream myfile;
	bool orderNotExist = true;

	myfile.open("FoodMenu_File.csv", ios::in);

	while (getline(myfile, line)) {
		stringstream ss(line);
		getline(ss, tempStr, ',');
		if (to_string(orderNum) == tempStr.substr(0, 1)) {
			foodDetails.push_back(tempStr);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				foodDetails.push_back(tempStr);
			}
		}
	}
	myfile.close();

	for (int i = 0; i < order.size(); i++) {
		if (order[i].orderNum == orderNum) {
			order[i].quantity += 1;
			orderNotExist = false;
			break;
		}
	}
	cout << setprecision(2);
	if (orderNotExist) {
		tempOrder.orderNum = stoi(foodDetails[0].substr(0, 1));
		tempOrder.orderDate = getCurrentDate();
		tempOrder.itemName = foodDetails[1];
		tempOrder.quantity = 1;
		tempOrder.price = stof(foodDetails[4].substr(1, foodDetails[4].length()));
		order.push_back(tempOrder);
	}
	return order;
}

//Code by Jay
//This function lets the user checkout there order
vector<Order> checkoutOrder(vector<Order> order, vector<string> user) {
	float subTotal = 0, gstAmount = 0, discount = 0.00;
	int numChoice = 0, num = 0, idLoc = 0, bulkNum = 0;
	bool isTrue, isTrue2, isTrue3, isTrue4, isTrue5, usedFoodPass, hasPaid;
	string uniqueID = "", gstNumber, gstID;
	vector<BulkPayment> vectBulk;
	struct Payment payment;
	struct Order ord;
	char choice;

	vectBulk = getAllBulkDetails();
	for (int i = 0; i < vectBulk.size(); i++) {
		if (vectBulk[i].bulkID == user[0]) {
			bulkNum = vectBulk[i].orderCount;
			idLoc = i;
			break;
		}
	}
	//get total price
	for (int i = 0; i < order.size(); i++) {
		payment.totalPrice += order[i].price * order[i].quantity;
	}

	system("cls");
	cout << setprecision(2);
	if (order.size() == 0) {
		cout << "\n" << string(8, '\t') << "|--------------------------|"
			<< "\n" << string(8, '\t') << "|      No Data Found       |"
			<< "\n" << string(8, '\t') << "|--------------------------|\n\t\t\t";
		system("pause");
	}
	else {
		do {
			system("cls");
			cout << "\n\n" << string(8, '\t') << " Date: " << getCurrentDate()
				<< "\n" << string(8, '\t') << "-----------------------------------"
				<< "\n" << string(8, '\t') << "|           School Name           |"
				<< "\n" << string(8, '\t') << "|---------------------------------|"
				<< "\n" << string(8, '\t') << "|            ORDER FOR            |";
			if (user[0].substr(0, 3) == "270") {
				cout << "\n" << string(8, '\t') << "| Student Name: " << user[1]
					<< "\n" << string(8, '\t') << "| Student Room no.: " << user[7];
			}
			else {
				cout << "\n" << string(8, '\t') << "| Staff Name: " << user[1];
			}
			cout << "\n" << string(8, '\t') << "-----------------------------------";
			for (int i = 0; i < order.size(); i++) {
				cout << "\n" << string(8, '\t') << "| Order Date:     " << order[i].orderDate
					<< "\n" << string(8, '\t') << "| Item Name:      " << order[i].itemName
					<< "\n" << string(8, '\t') << "| Order Quantity: " << order[i].quantity
					<< "\n" << string(8, '\t') << "| Price:          $" << order[i].price
					<< "\n" << string(8, '\t') << "-----------------------------------";
			}
			cout << "\n" << string(8, '\t') << "| TOTAL: $" << payment.totalPrice << "\n" << string(8, '\t');


			isTrue = true, isTrue2 = true, isTrue3 = true, isTrue4 = true, isTrue5 = true, usedFoodPass = false;
			cout << "\n" << string(8, '\t') << "|---------------------------------|"
				<< "\n" << string(8, '\t') << "| Press 1 to proceed to checkout  |"
				<< "\n" << string(8, '\t') << "| Press 2 to exit                 |"
				<< "\n" << string(8, '\t') << "|---------------------------------|"
				<< "\n" << string(8, '\t') << "| Enter option: ";
			cin >> numChoice;

			switch (numChoice) {
			case 1:
				do {
					cout << "\n" << string(8, '\t') << "|-------------------------------------|"//gohere
						<< "\n" << string(8, '\t') << "| Press 1 to pay now                  |"
						<< "\n" << string(8, '\t') << "| Press 2 to save order for later     |"
						<< "\n" << string(8, '\t') << "| Press 3 to exit                     |"
						<< "\n" << string(8, '\t') << "|-------------------------------------|"
						<< "\n" << string(8, '\t') << "| Enter option: ";
					cin >> numChoice;

					if (numChoice == 1) {
						if (bulkNum > 0) {
							do {
								cout << "\n\n" << string(8, '\t') << "|-------------------------------------------------------------|"
									<< "\n" << string(8, '\t') << "| You have " << vectBulk[idLoc].orderCount << " free food pass in your account"
									<< "\n" << string(8, '\t') << "|-------------------------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to use food pass                                    |"
									<< "\n" << string(8, '\t') << "| Press 2 to proceed without using food pass                  |"
									<< "\n" << string(8, '\t') << "|-------------------------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> numChoice;
								if (numChoice == 1) {
									do {
										cout << "\n" << string(8, '\t') << "|-------------------------------------------------------|"
											<< "\n" << string(8, '\t') << "| Press Y to pay all using Bulk Payment                 |"
											<< "\n" << string(8, '\t') << "| Press N to enter amount of food pass you wish to use  |"
											<< "\n" << string(8, '\t') << "| Press Q to go back                                    |"
											<< "\n" << string(8, '\t') << "|-------------------------------------------------------|"
											<< "\n" << string(8, '\t') << "| Enter option: ";
										cin >> choice;

										if (tolower(choice) == 'y') {//pay in full
											do {
												cout << "\n" << string(8, '\t') << "|-------------------------------|"
													<< "\n" << string(8, '\t') << "| Press Y to confirm Payment    |"
													<< "\n" << string(8, '\t') << "| Press N to go back            |"
													<< "\n" << string(8, '\t') << "|-------------------------------|"
													<< "\n" << string(8, '\t') << "| Enter option: ";
												cin >> choice;
												if (tolower(choice) == 'y') {//if they paid full
													vectBulk[idLoc].orderCount = vectBulk[idLoc].orderCount - (payment.totalPrice / 5);//decrement bulkpayment
													bulkNum = vectBulk[idLoc].orderCount;
													discount = payment.totalPrice;
													payment.totalPrice -= discount;
													usedFoodPass = true;
													payment.typeOfPayment = "BULK PAYMENT";
													hasPaid = true;
													isTrue4 = false;
													isTrue3 = false;
													break;
												}
												else if (tolower(choice) == 'n') {
													isTrue4 = false;
													break;
												}
												else if (tolower(choice) == 'q') {
													break;
												}
												else {
													cout << "\n" << string(8, '\t') << "|-----------------------------------|"
														<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
														<< "\n" << string(8, '\t') << "|-----------------------------------|";
												}
											} while (true);
										}
										else if (tolower(choice) == 'n') {
											do {
												do {
													cout << "\n" << string(8, '\t') << "|-------------------------------------------------------------|"
														<< "\n" << string(8, '\t') << "| Please enter the amount of food passes you wish to use: ";
													cin >> num;

													if (num > payment.totalPrice / 5 || num == 0) { // check if amount entered doesn't exceed the amount needed to pay
														cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
															<< "\n" << string(8, '\t') << "| Invalid amount! Max amount you can use is: " << payment.totalPrice / 5 << endl;
													}
													else
														break;
												} while (true);

												cout << "\n" << string(8, '\t') << "|-------------------------------|"
													<< "\n" << string(8, '\t') << "| Press Y to confirm Payment    |"
													<< "\n" << string(8, '\t') << "| Press N to go back            |"
													<< "\n" << string(8, '\t') << "|-------------------------------|"
													<< "\n" << string(8, '\t') << "| Enter option: ";
												cin >> choice;
												discount = 5.00 * num;
												if (tolower(choice) == 'y') {
													hasPaid = true;
													if (discount == payment.totalPrice) {//if amount of bulk payment used is equal to the amount need to pay
														do {
															cout << "\n" << string(7, '\t') << "|-----------------------------------------------|"
																<< "\n" << string(7, '\t') << "| You opted to pay for all using Bulk Payment   |"
																<< "\n" << string(7, '\t') << "| Do you wish to proceed with this payment?     |"
																<< "\n" << string(7, '\t') << "|-------------------------------------------------------------------------------------------|"
																<< "\n" << string(7, '\t') << "| Press 1 to proceed payment ***WARNING! THERE IS NO GOING BACK BEYOND POINT THIS POINT***  |"
																<< "\n" << string(7, '\t') << "| Press 2 to exit from payment                                                              |"
																<< "\n" << string(7, '\t') << "|-------------------------------------------------------------------------------------------|"
																<< "\n" << string(7, '\t') << "| Enter option: ";
															cin >> numChoice;

															if (numChoice == 1) {
																vectBulk[idLoc].orderCount -= num;
																bulkNum = vectBulk[idLoc].orderCount;
																usedFoodPass = true;
																payment.typeOfPayment = "BULK PAYMENT";
																payment.totalPrice -= discount;
																hasPaid = true;
																isTrue5 = false;
																isTrue4 = false;
																isTrue3 = false;
																break;
															}
															else if (numChoice == 2) {
																isTrue5 = false;
																break;
															}
															else {
																cout << "\n" << string(8, '\t') << "|-----------------------------------|"
																	<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
																	<< "\n" << string(8, '\t') << "|-----------------------------------|";
															}
														} while (true);
													}
													else {
														discount = 5.00 * num;
														vectBulk[idLoc].orderCount -= num;
														bulkNum = vectBulk[idLoc].orderCount;
														payment.totalPrice -= discount;
														usedFoodPass = true;
														isTrue5 = false;
														isTrue4 = false;
														isTrue3 = false;
													}
												}
												else if (tolower(choice) == 'n') {
													isTrue4 = false;
													isTrue5 = false;
												}
												else {
													cout << "\n" << string(8, '\t') << "|-----------------------------------|"
														<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
														<< "\n" << string(8, '\t') << "|-----------------------------------|";
												}
											} while (isTrue5);
										}
										else if (tolower(choice) == 'q') {
											break;
										}
										else { //if wrong input
											cout << "\n" << string(8, '\t') << "|-----------------------------------|"
												<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
												<< "\n" << string(8, '\t') << "|-----------------------------------|";
										}
									} while (isTrue4);
								}
								else if (numChoice == 2) {
									usedFoodPass = false;
									isTrue3 = false;//break main loop
								}
								//add exit
								else {
									cout << "\n" << string(8, '\t') << "|-----------------------------------|"
										<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
										<< "\n" << string(8, '\t') << "|-----------------------------------|";
								}
							} while (isTrue3);//main loop
						}

						if (discount <= payment.totalPrice) {//if there is still remaing amount to pay
							do {
								payment.totalPrice = payment.totalPrice + (payment.totalPrice * payment.GST); // apply GST
								payment.GSTAmount = payment.totalPrice * payment.GST;
								cout << "\n\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Amount left to pay: $" << payment.totalPrice
									<< "\n" << string(8, '\t') << "| Choose type of Payment"
									<< "\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 VISA                             |"
									<< "\n" << string(8, '\t') << "| Press 2 American Express                 |"
									<< "\n" << string(8, '\t') << "| Press 3 Mastercard                       |"
									<< "\n" << string(8, '\t') << "| Press 4 to exit                          |"
									<< "\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> numChoice;

								switch (numChoice) {
								case 1:
									if (usedFoodPass) {
										payment.typeOfPayment = "BULK PAYMENT / VISA";
										hasPaid = true;
									}
									else {
										payment.typeOfPayment = "BULK PAYMENT";
										hasPaid = true;
									}
									isTrue2 = false;
									break;
								case 2:
									if (usedFoodPass) {
										payment.typeOfPayment = "BULK PAYMENT / American Express";
										hasPaid = true;
									}
									else {
										payment.typeOfPayment = "American Express";
										hasPaid = true;
									}
									isTrue2 = false;
									break;
								case 3:
									if (usedFoodPass) {
										payment.typeOfPayment = "BULK PAYMENT / Mastercard";
										hasPaid = true;
									}
									else {
										hasPaid = true;
										payment.typeOfPayment = "Mastercard";
									}
									isTrue2 = false;
									break;
								case 4:
									hasPaid = false;
									isTrue2 = false;
									break;
								default:
									cout << "\n" << string(8, '\t') << "|-----------------------------------|"
										<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
										<< "\n" << string(8, '\t') << "|-----------------------------------|";
									system("pause");
									break;
								}
							} while (isTrue2);
						}

						if (hasPaid) {
							payment.date = getCurrentDate();
							cout << "\n\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << "|      Bulk Payment left: " << bulkNum
								<< "\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << " Date: " << payment.date << endl
								<< "\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << "|                School Name               |"
								<< "\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << "|            A Block, School Name          |"
								<< "\n" << string(8, '\t') << "|            Phone: 0800 83 83 83          |"
								<< "\n" << string(8, '\t') << "|------------------------------------------|";

							for (int i = 0; i < order.size(); i++) {
								order[i].paymentStatus = hasPaid;
								subTotal = order[i].price * order[i].quantity;
								cout << "\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Item Name:       " << order[i].itemName
									<< "\n" << string(8, '\t') << "| Number of items: " << order[i].quantity
									<< "\n" << string(8, '\t') << "| Order ID:        " << order[i].orderNum
									<< "\n" << string(8, '\t') << "| Price:          $" << order[i].price
									<< "\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "|SUBTOTAL:        $" << subTotal << endl;
								subTotal = 0;
							}
							if (usedFoodPass) {
								cout << "\n" << string(8, '\t') << "|------------------------------------------|"
									<< "\n" << string(8, '\t') << "|Food Pass Discount: $" << discount;
							}

							do {//generate a unique GST number and check if id is unique
								gstNumber = generateID(6);
								if (checkUniqueID(5, gstNumber)) {
									payment.GSTNumber = gstNumber;
									break;
								}
							} while (true);
							cout << "\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << "|TOTAL PRICE:      $" << payment.totalPrice
								<< "\n" << string(8, '\t') << "|------------------------------------------|"
								<< "\n" << string(8, '\t') << "|Type of Payment:  " << payment.typeOfPayment
								<< "\n" << string(8, '\t') << "|Change:           $0.00"
								<< "\n" << string(8, '\t') << "|GST Included      $" << payment.GSTAmount
								<< "\n" << string(8, '\t') << "|GST Number:       " << payment.GSTNumber
								<< "\n" << string(8, '\t') << "|------------------------------------------|\n\n\t\t\t";

							removeAllUnpaidOrders(user[1]);//update unpaid to paid status
							//save order to csv
							ofstream saveOrder("Order_file.csv", ios::app);
							do {//generate a unique id for order and check if id is unique
								ord.orderID = generateID(4);
								if (checkUniqueID(4, ord.orderID))
									break;
							} while (true);
							ord.foreignKey = user[0];
							for (int i = 0; i < order.size(); i++) {
								saveOrder << ord.orderID << ", " << ord.foreignKey << "," << getCurrentDate() << "," << order[i].itemName << "," << order[i].quantity << "," << order[i].price << "," << order[i].paymentStatus << "," << order[i].orderNum << endl;
							}
							saveOrder.close();

							//save payment details to csv
							ofstream savePayment("Payment_file.csv", ios::app);
							do {//generate a unique id for payment and check if id is unique
								gstID = generateID(5);
								if (checkUniqueID(5, gstID)) {
									payment.paymentID = gstID;
									break;
								}
							} while (true);
							savePayment << payment.paymentID << ", " << user[0] << "," << payment.GSTNumber << "," << payment.GSTAmount << "," << payment.typeOfPayment << "," << discount << "," << payment.totalPrice << "," << payment.date << endl;
							savePayment.close();

							//update bulk payment csv
							ofstream updateBulkPayment("BulkOrder_file.csv", ios::out);
							updateBulkPayment << "USER_ID" << "," << "ORDER_COUNT" << endl;
							for (int i = 0; i < vectBulk.size(); i++) {
								updateBulkPayment << vectBulk[i].bulkID << "," << vectBulk[i].orderCount << endl;
							}
							updateBulkPayment.close();

							cout << "\n" << string(8, '\t') << "|---------------------------------|"
								<< "\n" << string(8, '\t') << "|   PAYMENT CONFIRMED THANK YOU   |"
								<< "\n" << string(8, '\t') << "|---------------------------------|\n\t\t\t";

							isTrue = false;
							order.clear();//clear order after paying		
							system("pause");
						}
						break;
					}
					else if (numChoice == 2) {//set order to unpaid and save to csv
						hasPaid = false;
						removeAllUnpaidOrders(user[1]);
						//save order to csv
						ofstream saveOrder("Order_file.csv", ios::app);
						do {//generate a unique id for order and check if id is unique
							ord.orderID = generateID(4);
							if (checkUniqueID(4, ord.orderID))
								break;
						} while (true);
						ord.foreignKey = user[0];
						for (int i = 0; i < order.size(); i++) {
							order[i].paymentStatus = hasPaid;
							saveOrder << ord.orderID << ", " << ord.foreignKey << "," << getCurrentDate() << "," << order[i].itemName << "," << order[i].quantity << "," << order[i].price << "," << order[i].paymentStatus << "," << order[i].orderNum << endl;
						}
						saveOrder.close();

						isTrue = false;
						cout << "\n" << string(8, '\t') << "|---------------------|"
							<< "\n" << string(8, '\t') << "|     Order Saved     |"
							<< "\n" << string(8, '\t') << "|-------------------- |\n\t\t\t";
						system("pause");
						break;
					}
					else if (numChoice == 3)
						break;
					else {
						cout << "\n" << string(8, '\t') << "|-----------------------------------|"
							<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
							<< "\n" << string(8, '\t') << "|-----------------------------------|\n\t\t\t";
						system("pause");
					}
					system("cls");
				} while (true);
				break;
			case 2:
				cout << "\n" << string(8, '\t') << "|-----------------------------------|"
					<< "\n" << string(8, '\t') << "|        Exiting from checkout..    |"
					<< "\n" << string(8, '\t') << "|-----------------------------------|\n\t\t\t";
				system("pause");
				isTrue = false;
				break;
			default:
				cout << "\n" << string(8, '\t') << "|-----------------------------------|"
					<< "\n" << string(8, '\t') << "| Invalid Input! Please try again.. |"
					<< "\n" << string(8, '\t') << "|-----------------------------------|\n\t\t\t";
				system("pause");
				break;
			}
		} while (isTrue);
	}
	return order;
}

//Code by Jay
//This function is used to print out the orders this can be paid and pending payment
void printWeeklyOrderReport(char choice) {	//fix
	vector<Order> order;
	float total = 0;

	order = getAllOrderDetails();
	cout << setprecision(3);
	schoolTitle();
	if (order.size() == 0) {
		cout << "\n" << string(4, '\t') << "|--------------------|"
			<< "\n" << string(4, '\t') << "|   No Data Found    |"
			<< "\n" << string(4, '\t') << "|--------------------|\n" << string(4, '\t');
	}

	cout << "\n" << string(4, '\t');
	for (int i = 0; i < 110; i++)
		cout << "-";
	cout << "\n" << string(9, '\t') << "Order Details\n" << string(4, '\t');
	for (int i = 0; i < 110; i++)
		cout << "-";

	cout << "\n" << string(4, '\t') << "  ID        | Date\t  | Name\t\t\t| Order Quantity |  Price  | Total   | PAYMENT STATUS\n" << string(4, '\t');
	for (int i = 0; i < 110; i++)
		cout << "-";
	cout << endl;
	if (tolower(choice) == 'y') {
		for (int i = 0; i < order.size(); i++) {
			if (order[i].paymentStatus) {
				total = order[i].price * order[i].quantity;
				cout << string(4, '\t') << "  " << order[i].orderID;
				printSpaces(order[i].orderID.length(), 12);
				cout << order[i].orderDate;
				printSpaces(order[i].orderDate.length(), 14);//fix
				cout << order[i].itemName;
				printSpaces(order[i].itemName.length(), 36);
				cout << order[i].quantity;
				printSpaces(to_string(order[i].quantity).length(), 12);
				cout << "$" << order[i].price;
				printSpaces(to_string(order[i].price).length(), 15);
				cout << "$" << total;
				printSpaces(to_string(total).length(), 17);
				cout << "PAID\n";
			}
		}
	}
	else {
		for (int i = 0; i < order.size(); i++) {
			if (!order[i].paymentStatus) {
				total = order[i].price * order[i].quantity;
				cout << string(4, '\t') << "  " << order[i].orderID;
				printSpaces(order[i].orderID.length(), 12);
				cout << order[i].orderDate;
				printSpaces(order[i].orderDate.length(), 14);
				cout << order[i].itemName;
				printSpaces(order[i].itemName.length(), 36);
				cout << order[i].quantity;
				printSpaces(to_string(order[i].quantity).length(), 12);
				cout << "$" << order[i].price;
				printSpaces(to_string(order[i].price).length(), 15);
				cout << "$" << total;
				printSpaces(to_string(total).length(), 17);
				cout << "PENDING\n";
			}
		}
	}
	cout << endl;

	/*cout << "\n\t\t\t|---------------------------------------------|"
		<< "\n\t\t\t|              Parent Order Details           |"
		<< "\n\t\t\t|---------------------------------------------|";
	for (int i = 0; i < parent.size(); i++) {
		for (int x = 0; x < parent[i].order.size(); x++) {
			cout << "\n\t\t\t| Order ID:         " << parent[i].order[x].orderID
				<< "\n\t\t\t| Order Foreign ID: " << parent[i].order[x].foreignKey
				<< "\n\t\t\t| Order date:       " << parent[i].order[x].orderDate
				<< "\n\t\t\t| Order item name:  " << parent[i].order[x].itemName
				<< "\n\t\t\t| Order quantity:   " << parent[i].order[x].quantity
				<< "\n\t\t\t| Order price:      " << parent[i].order[x].price
				<< "\n\t\t\t|-----------------------------------------------\n";
		}
	}
	cout << "\n\t\t\t|---------------------------------------------|"
		<< "\n\t\t\t|              Staff Order Details           |"
		<< "\n\t\t\t|---------------------------------------------|";
	for (int i = 0; i < staff.size(); i++) {
		for (int x = 0; x < staff[i].order.size(); x++) {
			cout << "\n\t\t\t| Order ID:         " << staff[i].order[x].orderID
				<< "\n\t\t\t| Order Foreign ID: " << staff[i].order[x].foreignKey
				<< "\n\t\t\t| Order date:       " << staff[i].order[x].orderDate
				<< "\n\t\t\t| Order item name:  " << staff[i].order[x].itemName
				<< "\n\t\t\t| Order quantity:   " << staff[i].order[x].quantity
				<< "\n\t\t\t| Order price:      " << staff[i].order[x].price
				<< "\n\t\t\t|-----------------------------------------------\n";
		}
	}
	cout << "\n\t\t\t";*/
}

//Code by Jay
//This function prints all of the parents details
void printAllParentDetails(char choice) {
	vector<Parent> vectParent;
	int lastpos = 0;

	vectParent = getAllParentDetails();
	for (int i = 0; i < 190; i++)
		cout << "-";
	cout << "\n" << string(10, '\t') << "Parent Details\n";

	for (int i = 0; i < 190; i++)
		cout << "-";
	cout << "\n| ID      | Name \t\t| Gender   | DOB \t| Contact No. \t| Email\t\t      | Child Name\t    | Class No. | Visa card no \t| Visa Expiry date   | Account Status\n";
	for (int i = 0; i < 190; i++)
		cout << "-";
	cout << endl;

	if (tolower(choice) == 'y') {//if y then print all active users
		for (int i = 0; i < vectParent.size(); i++) {
			if (vectParent[i].accountStatus) {
				cout << vectParent[i].parentID;
				cout << "   " << vectParent[i].fullName;
				printSpaces(vectParent[i].fullName.length(), 23);
				cout << vectParent[i].gender;
				printSpaces(vectParent[i].gender.length(), 11);
				cout << vectParent[i].dob;
				printSpaces(vectParent[i].dob.length(), 13);
				cout << vectParent[i].contactNum;
				printSpaces(vectParent[i].contactNum.length(), 16);
				cout << vectParent[i].email;
				printSpaces(vectParent[i].email.length(), 22);
				cout << vectParent[i].childFullName;
				printSpaces(vectParent[i].childFullName.length(), 22);
				cout << vectParent[i].childRoomNum;
				printSpaces(vectParent[i].childRoomNum.length(), 12);
				cout << vectParent[i].visaCardNo;
				printSpaces(vectParent[i].visaCardNo.length(), 16);
				cout << vectParent[i].visaCardExpiry;
				printSpaces(vectParent[i].visaCardExpiry.length(), 21);
				if (vectParent[i].accountStatus)
					cout << "ACTIVE\n";
				else
					cout << "INACTIVE\n";
			}
		}
	}
	else if (tolower(choice) == 'n') {//if n then print all inactive users
		for (int i = 0; i < vectParent.size(); i++) {
			if (!vectParent[i].accountStatus) {
				cout << vectParent[i].parentID;
				cout << "   " << vectParent[i].fullName;
				printSpaces(vectParent[i].fullName.length(), 23);
				cout << vectParent[i].gender;
				printSpaces(vectParent[i].gender.length(), 11);
				cout << vectParent[i].dob;
				printSpaces(vectParent[i].dob.length(), 13);
				cout << vectParent[i].contactNum;
				printSpaces(vectParent[i].contactNum.length(), 16);
				cout << vectParent[i].email;
				printSpaces(vectParent[i].email.length(), 22);
				cout << vectParent[i].childFullName;
				printSpaces(vectParent[i].childFullName.length(), 22);
				cout << vectParent[i].childRoomNum;
				printSpaces(vectParent[i].childRoomNum.length(), 12);
				cout << vectParent[i].visaCardNo;
				printSpaces(vectParent[i].visaCardNo.length(), 16);
				cout << vectParent[i].visaCardExpiry;
				printSpaces(vectParent[i].visaCardExpiry.length(), 21);
				if (vectParent[i].accountStatus)
					cout << "ACTIVE\n";
				else
					cout << "INACTIVE\n";
			}
		}
	}
	else {//else print all users
		for (int i = 0; i < vectParent.size(); i++) {
			cout << vectParent[i].parentID;
			cout << "   " << vectParent[i].fullName;
			printSpaces(vectParent[i].fullName.length(), 23);
			cout << vectParent[i].gender;
			printSpaces(vectParent[i].gender.length(), 11);
			cout << vectParent[i].dob;
			printSpaces(vectParent[i].dob.length(), 13);
			cout << vectParent[i].contactNum;
			printSpaces(vectParent[i].contactNum.length(), 16);
			cout << vectParent[i].email;
			printSpaces(vectParent[i].email.length(), 22);
			cout << vectParent[i].childFullName;
			printSpaces(vectParent[i].childFullName.length(), 22);
			cout << vectParent[i].childRoomNum;
			printSpaces(vectParent[i].childRoomNum.length(), 12);
			cout << vectParent[i].visaCardNo;
			printSpaces(vectParent[i].visaCardNo.length(), 16);
			cout << vectParent[i].visaCardExpiry;
			printSpaces(vectParent[i].visaCardExpiry.length(), 21);
			if (vectParent[i].accountStatus)
				cout << "ACTIVE\n";
			else
				cout << "INACTIVE\n";
		}
	}

	cout << "\n\t\t\t";

	/*vectParent = getAllParentDetails();
	cout << "\n\t\t\t|--------------------------------------------|"
		<< "\n\t\t\t|                Parent Details              |"
		<< "\n\t\t\t|--------------------------------------------|";
	for (int i = 0; i < vectParent.size(); i++) {
		cout << "\n\t\t\t| Parent ID:             " << vectParent[i].parentID
			<< "\n\t\t\t| Parent name:           " << vectParent[i].fullName
			<< "\n\t\t\t| Parent gender:         " << vectParent[i].gender
			<< "\n\t\t\t| Parent date of birth:  " << vectParent[i].dob
			<< "\n\t\t\t| Parent contact number: " << vectParent[i].countNum
			<< "\n\t\t\t| Parent email:          " << vectParent[i].email
			<< "\n\t\t\t| Child fullname:        " << vectParent[i].childFullName
			<< "\n\t\t\t| Child room number:     " << vectParent[i].childRoomNum
			<< "\n\t\t\t| Visa card no:          " << vectParent[i].visaCardNo
			<< "\n\t\t\t| Visa Expiry date:      " << vectParent[i].visaCardExpiry
			<< "\n\t\t\t|-----------------------------------------------\n";
	}
	cout << "\n\t\t\t";*/
}

//This functions prints spaces;
void printSpaces(int num, int size) {
	for (int i = num; i < size; i++)
		cout << " ";
}

//Code by Jay
//This function prints all of the staffs details
void printAllStaffDetails(char choice) {
	vector<Staff> vectStaff;

	vectStaff = getAllStaffDetails();
	int lastpos = 0;
	for (int i = 0; i < 160; i++)
		cout << "-";
	cout << "\n" << string(9, '\t') << " Staff Details\n";

	for (int i = 0; i < 160; i++)
		cout << "-";
	cout << "\n| ID      | Name     \t\t| Gender   | DOB \t| Contact No. \t| Email\t\t\t| Visa card no\t\t  | Visa Expiry date  | Account Status\n";
	for (int i = 0; i < 160; i++)
		cout << "-";
	cout << endl;
	if (tolower(choice) == 'y') {
		for (int i = 0; i < vectStaff.size(); i++) {
			if (vectStaff[i].accountStatus) {//print all active users
				cout << vectStaff[i].staffID;
				cout << "   " << vectStaff[i].fullName;
				printSpaces(vectStaff[i].fullName.length(), 23);
				cout << vectStaff[i].gender;
				printSpaces(vectStaff[i].gender.length(), 11);
				cout << vectStaff[i].dob;
				printSpaces(vectStaff[i].dob.length(), 13);
				cout << vectStaff[i].contactNum;
				printSpaces(vectStaff[i].contactNum.length(), 16);
				cout << vectStaff[i].email;
				printSpaces(vectStaff[i].email.length(), 24);
				cout << vectStaff[i].visaCardNo;
				printSpaces(vectStaff[i].visaCardNo.length(), 25);
				cout << vectStaff[i].visaCardExpiry;
				printSpaces(vectStaff[i].visaCardExpiry.length(), 20);
				if (vectStaff[i].accountStatus)
					cout << "ACTIVE\n";
				else
					cout << "INACTIVE\n";
			}
		}
	}
	else if (tolower(choice) == 'n') {
		for (int i = 0; i < vectStaff.size(); i++) {
			if (!vectStaff[i].accountStatus) {//print all inactive users
				cout << vectStaff[i].staffID;
				cout << "   " << vectStaff[i].fullName;
				printSpaces(vectStaff[i].fullName.length(), 23);
				cout << vectStaff[i].gender;
				printSpaces(vectStaff[i].gender.length(), 11);
				cout << vectStaff[i].dob;
				printSpaces(vectStaff[i].dob.length(), 13);
				cout << vectStaff[i].contactNum;
				printSpaces(vectStaff[i].contactNum.length(), 16);
				cout << vectStaff[i].email;
				printSpaces(vectStaff[i].email.length(), 24);
				cout << vectStaff[i].visaCardNo;
				printSpaces(vectStaff[i].visaCardNo.length(), 26);
				cout << vectStaff[i].visaCardExpiry;
				printSpaces(vectStaff[i].visaCardExpiry.length(), 20);
				if (vectStaff[i].accountStatus)
					cout << "ACTIVE\n";
				else
					cout << "INACTIVE\n";
			}
		}
	}
	else {//print all users
		for (int i = 0; i < vectStaff.size(); i++) {
			cout << vectStaff[i].staffID;
			cout << "   " << vectStaff[i].fullName;
			printSpaces(vectStaff[i].fullName.length(), 23);
			cout << vectStaff[i].gender;
			printSpaces(vectStaff[i].gender.length(), 11);
			cout << vectStaff[i].dob;
			printSpaces(vectStaff[i].dob.length(), 13);
			cout << vectStaff[i].contactNum;
			printSpaces(vectStaff[i].contactNum.length(), 16);
			cout << vectStaff[i].email;
			printSpaces(vectStaff[i].email.length(), 24);
			cout << vectStaff[i].visaCardNo;
			printSpaces(vectStaff[i].visaCardNo.length(), 26);
			cout << vectStaff[i].visaCardExpiry;
			printSpaces(vectStaff[i].visaCardExpiry.length(), 20);
			if (vectStaff[i].accountStatus)
				cout << "ACTIVE\n";
			else
				cout << "INACTIVE\n";
		}
	}
	/*vectStaff = getAllStaffDetails();
	cout << "\n\t\t\t|--------------------------------------------|"
		<< "\n\t\t\t|                Staff Details               |"
		<< "\n\t\t\t|--------------------------------------------|";
	for (int i = 0; i < vectStaff.size(); i++) {
		cout << "\n\t\t\t| Staff ID:             " << vectStaff[i].staffID
			<< "\n\t\t\t| Staff name:           " << vectStaff[i].fullName
			<< "\n\t\t\t| Staff gender:         " << vectStaff[i].gender
			<< "\n\t\t\t| Staff date of birth:  " << vectStaff[i].dob
			<< "\n\t\t\t| Staff contact number: " << vectStaff[i].countNum
			<< "\n\t\t\t| Staff email:          " << vectStaff[i].email
			<< "\n\t\t\t| Visa card no:         " << vectStaff[i].visaCardNo
			<< "\n\t\t\t| Visa Expiry date:     " << vectStaff[i].visaCardExpiry
			<< "\n\t\t\t|-----------------------------------------------\n";
	}
	cout << "\n\t\t\t";*/
}

//Code by Jay
//This function gets all the parent data(order,payment) from csv and stores it in a vector and returns it
vector<Parent> getAllParentDetails() {

	vector<Parent> vectParent;
	vector<Order> vectOrder;
	vector<Payment> vectPayment;
	vector<Login> vectLogin;
	vector<Login>* ptrVectLogin;
	vector<string> parentData;
	Parent parent;
	string tempStr, line;
	char storeChar[8];
	ifstream myfile;

	ptrVectLogin = &vectLogin;
	myfile.open("Parent_file.csv", ios::in);

	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			parentData.push_back(tempStr);
		}
		if (parentData[0] != "LOGIN_ID") {
			parent.parentID = parentData[0];
			parent.fullName = parentData[1];
			parent.gender = parentData[2];
			parent.dob = parentData[3];
			parent.contactNum = parentData[4];
			parent.email = parentData[5];
			parent.childFullName = parentData[6];
			parent.childRoomNum = parentData[7];
			parent.visaCardNo = parentData[8];
			parent.visaCardExpiry = parentData[9];
			parent.accountStatus = stoi(parentData[10]);
			vectParent.push_back(parent);
		}
		parentData.clear();
	}
	myfile.close();
	vectOrder = getAllOrderDetails();
	vectPayment = getAllPaymentDetails();
	getAllLoginDetails(ptrVectLogin);

	//get all order details
	for (int i = 0; i < vectParent.size(); i++) {
		for (int x = 0; x < vectOrder.size(); x++) {
			vectOrder[x].foreignKey.erase(remove(vectOrder[x].foreignKey.begin(), vectOrder[x].foreignKey.end(), ' '), vectOrder[x].foreignKey.end());//remove spaces in the string
			if (vectParent[i].parentID == vectOrder[x].foreignKey) {
				vectParent[i].order.push_back(vectOrder[x]);
			}
		}
	}
	//get all payment details
	for (int i = 0; i < vectParent.size(); i++) {
		for (int x = 0; x < vectPayment.size(); x++) {
			vectPayment[x].foreignKey.erase(remove(vectPayment[x].foreignKey.begin(), vectPayment[x].foreignKey.end(), ' '), vectPayment[x].foreignKey.end());//remove spaces in the string
			if (vectParent[i].parentID == vectPayment[x].foreignKey) {
				vectParent[i].payment.push_back(vectPayment[x]);
			}
		}
	}
	//get all login details
	for (int i = 0; i < vectParent.size(); i++) {
		for (int x = 0; x < vectLogin.size(); x++) {
			if (vectParent[i].parentID == vectLogin[x].userForeignID) {
				vectParent[i].login.loginID = vectLogin[x].loginID;
				vectParent[i].login.userForeignID = vectLogin[x].userForeignID;
				vectParent[i].login.username = vectLogin[x].username;
				vectParent[i].login.password = vectLogin[x].password;
				break;
			}
		}
	}
	return vectParent;
}

//Code by Jay
//This function gets all the staff data(order,payment) from csv and stores it in a vector and returns it
vector<Staff> getAllStaffDetails() {

	vector<Staff> vectStaff;
	vector<Order> vectOrder;
	vector<Payment> vectPayment;
	vector<Login> vectLogin;
	vector<string> staffData;
	vector<Login>* ptrVectLogin;
	ptrVectLogin = &vectLogin;
	Staff staff;
	string tempStr, line;

	ifstream myfile;
	myfile.open("Staff_file.csv", ios::in);

	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			staffData.push_back(tempStr);
		}
		if (staffData[0] != "LOGIN_ID") {
			staff.staffID = staffData[0];
			staff.fullName = staffData[1];
			staff.gender = staffData[2];
			staff.dob = staffData[3];
			staff.contactNum = staffData[4];
			staff.email = staffData[5];
			staff.visaCardNo = staffData[6];
			staff.visaCardExpiry = staffData[7];
			staff.accountStatus = stoi(staffData[8]);
			vectStaff.push_back(staff);
		}
		staffData.clear();
	}
	myfile.close();

	vectOrder = getAllOrderDetails();
	vectPayment = getAllPaymentDetails();
	vectLogin = getAllLoginDetails(ptrVectLogin);

	//get all order details
	for (int i = 0; i < vectStaff.size(); i++) {
		for (int x = 0; x < vectOrder.size(); x++) {
			vectOrder[x].foreignKey.erase(remove(vectOrder[x].foreignKey.begin(), vectOrder[x].foreignKey.end(), ' '), vectOrder[x].foreignKey.end());//remove spaces in the string
			if (vectStaff[i].staffID == vectOrder[x].foreignKey) {
				vectStaff[i].order.push_back(vectOrder[x]);
			}
		}
	}
	//get all payment details
	for (int i = 0; i < vectStaff.size(); i++) {
		for (int x = 0; x < vectPayment.size(); x++) {
			vectPayment[x].foreignKey.erase(remove(vectPayment[x].foreignKey.begin(), vectPayment[x].foreignKey.end(), ' '), vectPayment[x].foreignKey.end());//remove spaces in the string
			if (vectStaff[i].staffID == vectPayment[x].foreignKey) {
				vectStaff[i].payment.push_back(vectPayment[x]);
			}
		}
	}
	//get all login details
	for (int i = 0; i < vectStaff.size(); i++) {
		for (int x = 0; x < vectLogin.size(); x++) {
			if (vectStaff[i].staffID == vectLogin[x].userForeignID) {
				vectStaff[i].login.loginID = vectLogin[x].loginID;
				vectStaff[i].login.userForeignID = vectLogin[x].userForeignID;
				vectStaff[i].login.username = vectLogin[x].username;
				vectStaff[i].login.password = vectLogin[x].password;
				break;
			}
		}
	}
	return vectStaff;
}

//Code by Jay
//This function gets all order data from csv and stores it in vector
vector<Order> getAllOrderDetails() {

	vector<Order> vectOrder;
	vector<string> orderData;
	Order order;
	string tempStr, line;

	ifstream myfile;
	myfile.open("Order_file.csv", ios::in);

	cout << setprecision(2);
	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			orderData.push_back(tempStr);
		}
		if (orderData[0] != "ORDER_ID") {
			order.orderID = orderData[0];
			order.foreignKey = orderData[1];
			order.orderDate = orderData[2];
			order.itemName = orderData[3];
			order.quantity = stoi(orderData[4]);
			order.price = stof(orderData[5]);
			order.paymentStatus = stoi(orderData[6]);
			order.orderNum = stoi(orderData[7]);
			vectOrder.push_back(order);
		}
		orderData.clear();
	}
	myfile.close();

	return vectOrder;
}

//Code by Jay
//This function gets all the unpaid orders of the user and returns it as a vector Order
vector<Order> getAllUnpaidOrders(string userID) {

	vector<Order> vectOrder;
	vector<string> orderData;
	Order order;
	string tempStr, line;
	bool isPaid = true;

	ifstream myfile;
	myfile.open("Order_file.csv", ios::in);

	cout << setprecision(2);
	while (getline(myfile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			orderData.push_back(tempStr);
		}
		if (orderData.size() != 0) {
			if (orderData[0] != "ORDER_ID") {
				isPaid = stoi(orderData[6]);
				orderData[1].erase(remove(orderData[1].begin(), orderData[1].end(), ' '), orderData[1].end());//remove spaces in the string
				if (orderData[1] == userID && isPaid == false) {
					order.orderID = orderData[0];
					order.foreignKey = orderData[1];
					order.orderDate = orderData[2];
					order.itemName = orderData[3];
					order.quantity = stoi(orderData[4]);
					order.price = stof(orderData[5]);
					order.paymentStatus = isPaid;
					order.orderNum = stoi(orderData[7]);
					vectOrder.push_back(order);
				}
			}
		}
		orderData.clear();
	}
	myfile.close();

	return vectOrder;
}

//Code by Jay
//This function removes the saved order from the user
void removeAllUnpaidOrders(string userID) {
	vector<Order> vectOrder;
	vectOrder = getAllOrderDetails();

	ofstream orderFile("Order_file.csv", ios::out);
	orderFile << "ORDER_ID" << "," << "FOREIGN_KEY" << "," << "DATE" << "," << "ITEM_NAME" << "," << "QUANTITY" << "," << "PRICE" << "," << "PAYMENT_STATUS" << "," << "ORDER_NUM" << endl;
	for (int i = 0; i < vectOrder.size(); i++) {
		if (userID != vectOrder[i].foreignKey && vectOrder[i].paymentStatus != false) {
			orderFile << vectOrder[i].orderID << ", " << vectOrder[i].foreignKey << "," << getCurrentDate() << "," << vectOrder[i].itemName << "," << vectOrder[i].quantity << "," << vectOrder[i].price << "," << vectOrder[i].paymentStatus << "," << vectOrder[i].orderNum << endl;
		}
	}
	orderFile.close();
}

//Code by Jay
//This function gets all payment data from csv and stores it in vector
vector<Payment> getAllPaymentDetails() {

	vector<Payment> vectPayment;
	vector<string> paymentData;
	Payment payment;
	string tempStr, line;

	ifstream myfile;
	myfile.open("Payment_file.csv", ios::in);

	cout << setprecision(2);
	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			paymentData.push_back(tempStr);
		}
		if (paymentData[0] != "PAYMENT_ID") {
			payment.paymentID = paymentData[0];
			payment.foreignKey = paymentData[1];
			payment.GSTNumber = paymentData[2];
			payment.GSTAmount = stof(paymentData[3]);
			payment.typeOfPayment = paymentData[4];
			payment.totalPrice = stof(paymentData[5]);
			payment.date = paymentData[6];
			vectPayment.push_back(payment);
		}
		paymentData.clear();
	}
	myfile.close();

	return vectPayment;
}

//Code by Jay
//This function gets all Login data from csv and stores it in vector
vector<Login>& getAllLoginDetails(vector<Login>* vectLogin) {

	vector<Login>& vecRef = *vectLogin;
	vector<string> loginData;
	string tempStr, line;
	Login login;
	ifstream myfile;

	myfile.open("Login_file.csv", ios::in);

	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			loginData.push_back(tempStr);
		}
		if (loginData[0] != "PRIMARY_KEY") {
			login.loginID = loginData[0];
			login.userForeignID = loginData[1];
			login.username = loginData[2];
			login.password = loginData[3];
			vecRef.push_back(login);
		}
		loginData.clear();
	}
	myfile.close();

	return vecRef;
}

vector<BulkPayment> getAllBulkDetails() {

	vector<string> bulkData;
	vector<BulkPayment> vectBulk;
	BulkPayment bulk;
	string tempStr, line;

	ifstream myfile;
	myfile.open("BulkOrder_file.csv", ios::in);

	cout << setprecision(2);
	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			bulkData.push_back(tempStr);
		}
		if (bulkData.size() != 0) {
			if (bulkData[0] != "USER_ID") {
				bulk.bulkID = bulkData[0];
				bulk.orderCount = stoi(bulkData[1]);
				vectBulk.push_back(bulk);
			}
		}
		bulkData.clear();
	}
	myfile.close();
	return vectBulk;
}

//Code by Jay
//This function updates the parents details
void updateParentDetails(string userID, string user) {
	vector<Parent> parent;
	vector<Login> login;
	vector<Login>* ptrVectLogin;
	ptrVectLogin = &login;
	int choice, userVectLocation = 0;
	bool isTrue, isTrue2, isTrue3, isFound = true;
	string password, verifyPassword, tempData;
	char accStatus;

	// Code by Jakob
	string name = "+=-";
	string contactNum = "+=-";
	string email = "+=-";

	parent = getAllParentDetails();
	login = getAllLoginDetails(ptrVectLogin);
	//get user location in vector
	if (parent.size() == 0)
		isFound = false;
	for (int i = 0; i < parent.size(); i++) {
		if (parent[i].parentID == userID) {
			isFound = true;
			userVectLocation = i;
			break;
		}
		else
			isFound = false;
	}

	if (isFound) {
		tempData = "";
		do {
			system("cls");
			schoolTitle();
			cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "|                PARENT USER                 |"
				<< "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "| Press 1 to update Parent Details           |"
				<< "\n" << string(8, '\t') << "| Press 2 to change password                 |"
				<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
				<< "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "| Enter option: ";
			cin >> choice;
			if (choice == 1) {
				isTrue = true;
				do {
					system("cls");
					schoolTitle();
					cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
						<< "\n" << string(8, '\t') << "|            UPDATE PARENT DETAILS            |"
						<< "\n" << string(8, '\t') << "|---------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Press 1 to update Parent Name               |"
						<< "\n" << string(8, '\t') << "| Press 2 to update Parent Gender             |"
						<< "\n" << string(8, '\t') << "| Press 3 to update Parent Date of Birth      |"
						<< "\n" << string(8, '\t') << "| Press 4 to update Parent Contact Number     |"
						<< "\n" << string(8, '\t') << "| Press 5 to update Parent Email              |"
						<< "\n" << string(8, '\t') << "| Press 6 to update Parent Child's Name       |"
						<< "\n" << string(8, '\t') << "| Press 7 to update Parent Child's Room No.   |"
						<< "\n" << string(8, '\t') << "| Press 8 to update Parent Visa Card No.      |"
						<< "\n" << string(8, '\t') << "| Press 9 to update Parent Visa Expiry Date   |";
					if (user == "admin")
						cout << "\n" << string(8, '\t') << "| Press 10 to Activate/DeActivate Account     |";
					cout << "\n" << string(8, '\t') << "| Press 0 to exit                             |"
						<< "\n" << string(8, '\t') << "|---------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Enter option: ";
					cin >> choice;
					cin.ignore();

					switch (choice) {
						cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
							<< "\n" << string(8, '\t') << "|            UPDATE PARENT DETAILS           |"
							<< "\n" << string(8, '\t') << "|--------------------------------------------|";
					case 1:
						cout << "\n" << string(8, '\t') << "| Current Name: " << parent[userVectLocation].fullName;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Full name" << setw(16) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid Input.. Please Enter your name..\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Name                    |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Name                   |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								cin.ignore();
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|            NAME HAS BEEN UPDATED            |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									parent[userVectLocation].fullName = tempData;
									name = tempData; // Code by Jakob
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 2:
						cout << "\n" << string(8, '\t') << "| Current Gender: " << parent[userVectLocation].gender;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Gender" << setw(19) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your gender\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Gender                  |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Gender                 |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|           GENDER HAS BEEN UPDATED           |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									parent[userVectLocation].gender = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 3:
						cout << "\n" << string(8, '\t') << "| Current Date of Birth: " << parent[userVectLocation].dob;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Date of birth" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, please enter your date of birth.\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Date of Birth           |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Date of Birth          |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|        DATE OF BIRTH HAS BEEN UPDATED       |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									parent[userVectLocation].dob = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 4:
						cout << "\n" << string(8, '\t') << "| Current Contact No: " << parent[userVectLocation].contactNum;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Contact Number" << setw(11) << "|: ";
							getline(cin, tempData);
							if (tempData.length() < 9 || tempData.length() > 10)
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your contact number.\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Contact No              |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Contact No             |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|        CONTACT NO. HAS BEEN UPDATED         |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									parent[userVectLocation].contactNum = tempData;
									contactNum = tempData; // Code by Jakob
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 5:
						cout << "\n" << string(8, '\t') << "| Current Email: " << parent[userVectLocation].email;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Email Address" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Email Address\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Email                   |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Email                  |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|            EMAIL HAS BEEN UPDATED           |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].email = tempData;
										email = tempData; // Code by Jakob
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 6:
						cout << "\n" << string(8, '\t') << "| Current Child's name: " << parent[userVectLocation].childFullName;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Child's name" << setw(13) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Child's name\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Child's name            |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Child's name           |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|        CHILD'S NAME HAS BEEN UPDATED        |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										parent[userVectLocation].childFullName = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 7:
						cout << "\n" << string(8, '\t') << "| Current Child's Room Number: " << parent[userVectLocation].childRoomNum;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Child's Room Number" << setw(6) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Child's Room Number\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Child's Room Number     |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Child's Room Number    |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|     CHILD'S ROOM NUMBER HAS BEEN UPDATED    |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										parent[userVectLocation].childRoomNum = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 8:
						cout << "\n" << string(8, '\t') << "| Current Visa Card Number: " << parent[userVectLocation].visaCardNo;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Visa Card Number" << setw(9) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Visa Card Number\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Visa Card Number        |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Visa Card Number       |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|      VISA CARD NUMBER HAS BEEN UPDATED      |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										parent[userVectLocation].visaCardNo = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 9:
						cout << "\n" << string(8, '\t') << "| Current Visa Card Expiry Date: " << parent[userVectLocation].visaCardExpiry;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Visa Card Expiry Date |: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Visa Card Expiry Date\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Visa Card Expiry Date   |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Visa Card Expiry Date  |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|      VISA EXPIRY DATE HAS BEEN UPDATED      |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										parent[userVectLocation].visaCardExpiry = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 10:
						if (user == "admin") {
							cout << "\n" << string(8, '\t') << "| Current User Status: ";
							if (parent[userVectLocation].accountStatus) cout << "ACTIVE"; else cout << "INACTIVE";
							do {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press Y to Activate User Account           |"
									<< "\n" << string(8, '\t') << "| Press N to De-Activate User Account        |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> accStatus;
								if (tolower(accStatus) != 'y' && tolower(accStatus) != 'n')
									cout << "\n" << string(8, '\t') << "Invalid input... Try Again...\n";
								else {
									{
										cout << "\n" << string(8, '\t') << "|-----------------------------|"
											<< "\n" << string(8, '\t') << "| Press 1 to Confirm           |"
											<< "\n" << string(8, '\t') << "| Press 2 to Re-enter          |"
											<< "\n" << string(8, '\t') << "| Press 3 to exit              |"
											<< "\n" << string(8, '\t') << "|------------------------------|"
											<< "\n" << string(8, '\t') << "| Enter option: ";
										cin >> choice;
										if (choice == 1) {
											cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
												<< "\n" << string(8, '\t') << "|     USER ACCOUNT STATUS HAS BEEN UPDATED    |"
												<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t');
											if (tolower(accStatus) == 'y')//activate account
												parent[userVectLocation].accountStatus = true;
											else if (tolower(accStatus) == 'n')//deactivate account
												parent[userVectLocation].accountStatus = false;
											system("pause");
											break;
										}
										else if (choice == 2) {
											cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
										}
										else if (choice == 3) {
											break;
										}
										else
											cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
									}
								}
							} while (true);
						}
						else {
							cout << "\n" << string(8, '\t') << "Invalid input, Please try again\n" << string(8, '\t');
							system("pause");
						}
						break;
					case 0:
						isTrue = false;
						break;
					default:
						cout << "\n" << string(8, '\t') << "Invalid input, Please try again\n" << string(8, '\t');
						system("pause");
						break;
					}
					ofstream parentFile("Parent_file.csv", ios::out);
					//ADD HEADERS TO CSV
					parentFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
						<< "," << "CHILD_NAME" << "," << "ROOM_NUM" << "," << "VISA_NUM" << "," << "VISA_EXPIRY" << "," << "ACC_STATUS" << endl;
					for (int i = 0; i < parent.size(); i++) {
						parentFile << parent[i].parentID << "," << parent[i].fullName << "," << parent[i].gender << "," << parent[i].dob << "," << parent[i].contactNum << ","
							<< parent[i].email << "," << parent[i].childFullName << "," << parent[i].childRoomNum << "," << parent[i].visaCardNo << ","
							<< parent[i].visaCardExpiry << "," << parent[i].accountStatus << endl;
					}
					parentFile.close();
				} while (isTrue);
			}
			else if (choice == 2) {
				isTrue2 = true;
				do {
					cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Press 1 to Change Password                 |"
						<< "\n" << string(8, '\t') << "| Press 2 to exit                            |"
						<< "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Enter option: ";
					cin >> choice;
					cin.ignore();
					if (choice == 1) {
						//enter current password
						do {
							cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
								<< "\n" << string(8, '\t') << "| Type: quit@ to exit from password          |"
								<< "\n" << string(8, '\t') << "|--------------------------------------------|"
								<< "\n" << string(8, '\t') << "| Enter current password: ";
							getline(cin, password);

							if (password == parent[userVectLocation].login.password)
								break;
							else if (password == "quit@") {
								isTrue2 = false;
								break;
							}
							else
								cout << "\n" << string(8, '\t') << "Password did not match.. Please Try Again..\n";
						} while (true);

						//enter new password
						if (password != "quit@") {
							do {
								do {
									cout << "" << string(8, '\t') << "|-------------------------------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Use 8 or more characters with a mix of letters, numbers & symbols |"
										<< "\n" << string(8, '\t') << "|-------------------------------------------------------------------|"
										<< "\n" << string(8, '\t') << "|Enter Password" << setw(17) << "|: ";
									getline(cin, password);

									if (checkPassword(password))
										break;
									else
										cout << "\n" << string(8, '\t') << "Invalid password, Please try again\n";
								} while (true);

								//verify password
								do {
									cout << "" << string(8, '\t') << "|Enter Verify Password" << setw(10) << "|: ";
									getline(cin, verifyPassword);

									if (verifyPassword == "")
										cout << "\n" << string(8, '\t') << "Password did not match, Please try again\n";
									else
										break;
								} while (true);

								if (password != verifyPassword)
									cout << "\n" << string(8, '\t') << "Password did not match please try again...\n";
								else {
									parent[userVectLocation].login.password = password;

									for (int i = 0; i < login.size(); i++) {
										if (parent[userVectLocation].login.userForeignID == login[i].userForeignID) {
											login[i].password = parent[userVectLocation].login.password;
										}
									}
									ofstream loginFile("Login_file.csv", ios::out);
									//ADD HEADERS TO CSV
									loginFile << "PRIMARY_KEY" << "," << "FOREIGN_KEY" << "," << "USERNAME" << "," << "PASSWORD" << endl;
									for (int i = 0; i < login.size(); i++) {
										loginFile << login[i].loginID << "," << login[i].userForeignID << "," << login[i].username << "," << login[i].password << endl;
									}
									loginFile.close();

									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "|   Password has been successfully changed   |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|";
									break;
								}
							} while (true);
						}
					}
					else if (choice == 2)
						isTrue2 = false;
					else
						cout << "\n" << string(8, '\t') << "Invalid input, Please Try Again\n" << string(8, '\t') << "";

					cout << "\n" << string(8, '\t') << "";
					system("pause");
				} while (isTrue2);
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "\n" << string(8, '\t') << "Invalid Input.. Please try again...\n" << string(8, '\t') << "";
				system("pause");
			}
		} while (true);
	}
	else {
		cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
			<< "\n" << string(8, '\t') << "|               INVALID USER ID              |"
			<< "\n" << string(8, '\t') << "|               CANT FIND USER               |"
			<< "\n" << string(8, '\t') << "|--------------------------------------------|\n" << string(8, '\t') << "";
		system("pause");
	}

	// Code by Jakob
	if (name != "+=-" || contactNum != "+=-" || email != "+=-") {
		updateWeeklyComplaint(userID, name, contactNum, email);
	}
}

//Code by Jay
//This function is used to update Staff details
void updateStaffDetails(string userID, string user) {
	vector<Staff> staff;
	vector<Login> login;
	vector<Login>* ptrLogin;
	ptrLogin = &login;
	int choice, userVectLocation = 0, tempContactNo;
	bool isTrue, isTrue2, isTrue3, isFound = true;
	string password, verifyPassword, tempData;
	char accStatus;

	// Code by Jakob
	string name = "+=-";
	string contactNum = "+=-";
	string email = "+=-";

	staff = getAllStaffDetails();
	login = getAllLoginDetails(ptrLogin);

	//get staff location in vector
	if (staff.size() == 0)
		isFound = false;
	for (int i = 0; i < staff.size(); i++) {
		if (staff[i].staffID == userID) {
			isFound = true;
			userVectLocation = i;
			break;
		}
		else
			isFound = false;
	}

	if (isFound) {
		tempData = "";
		do {
			system("cls");
			schoolTitle();
			cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "|                STAFF USER                  |"
				<< "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "| Press 1 to update Staff Details            |"
				<< "\n" << string(8, '\t') << "| Press 2 to change password                 |"
				<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
				<< "\n" << string(8, '\t') << "|--------------------------------------------|"
				<< "\n" << string(8, '\t') << "| Enter option: ";
			cin >> choice;
			if (choice == 1) {
				isTrue = true;
				do {
					system("cls");
					schoolTitle();
					cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "|             UPDATE STAFF DETAILS           |"
						<< "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Press 1 to update Staff Name               |"
						<< "\n" << string(8, '\t') << "| Press 2 to update Staff Gender             |"
						<< "\n" << string(8, '\t') << "| Press 3 to update Staff Date of Birth      |"
						<< "\n" << string(8, '\t') << "| Press 4 to update Staff Contact Number     |"
						<< "\n" << string(8, '\t') << "| Press 5 to update Staff Email              |"
						<< "\n" << string(8, '\t') << "| Press 6 to update Staff Visa Card No.      |"
						<< "\n" << string(8, '\t') << "| Press 7 to update Staff Visa Expiry Date   |";
					if (user == "admin")
						cout << "\n" << string(8, '\t') << "| Press 8 to Activate/DeActivate Account     |";
					cout << "\n" << string(8, '\t') << "| Press 0 to exit                            |"
						<< "\n" << string(8, '\t') << "t|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Enter option: ";
					cin >> choice;
					cin.ignore();

					switch (choice) {
						cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
							<< "\n" << string(8, '\t') << "|             UPDATE STAFF DETAILS           |"
							<< "\n" << string(8, '\t') << "|--------------------------------------------|";
					case 1:
						cout << "\n" << string(8, '\t') << "| Current Name: " << staff[userVectLocation].fullName;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Full name" << setw(16) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid Input.. Please Enter your name..\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Name                    |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Name                   |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								cin.ignore();
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|            NAME HAS BEEN UPDATED            |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									staff[userVectLocation].fullName = tempData;
									name = tempData; // Code by Jakob
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 2:
						cout << "\n" << string(8, '\t') << "| Current Gender: " << staff[userVectLocation].gender;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Gender" << setw(19) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your gender\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Gender                  |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Gender                 |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|           GENDER HAS BEEN UPDATED           |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									staff[userVectLocation].gender = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 3:
						cout << "\n" << string(8, '\t') << "| Current Date of Birth: " << staff[userVectLocation].dob;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Date of birth" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Date of birth\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Date of Birth           |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Date of Birth          |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|        DATE OF BIRTH HAS BEEN UPDATED       |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									staff[userVectLocation].dob = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 4:
						cout << "\n" << string(8, '\t') << "| Current Contact No: " << staff[userVectLocation].contactNum;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Contact Number" << setw(11) << "|: ";
							getline(cin, tempData);
							if (tempData.length() < 9 || tempData.length() > 10)
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your contact number.\n";
							else {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press 1 to Confirm Contact No              |"
									<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Contact No             |"
									<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
										<< "\n" << string(8, '\t') << "|        CONTACT NO. HAS BEEN UPDATED         |"
										<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
									staff[userVectLocation].contactNum = tempData;
									contactNum = tempData; // Code by Jakob
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 5:
						cout << "\n" << string(8, '\t') << "| Current Email: " << staff[userVectLocation].email;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Email Address" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Email Address\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Email                   |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Email                  |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|            EMAIL HAS BEEN UPDATED           |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										staff[userVectLocation].email = tempData;
										email = tempData; // Code by Jakob
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 6:
						cout << "\n" << string(8, '\t') << "| Current Visa Card Number: " << staff[userVectLocation].visaCardNo;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Visa Card Number" << setw(9) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Visa Card Number\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Visa Card Number        |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Visa Card Number       |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|      VISA CARD NUMBER HAS BEEN UPDATED      |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										staff[userVectLocation].visaCardNo = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 7:
						cout << "\n" << string(8, '\t') << "| Current Visa Card Expiry Date: " << staff[userVectLocation].visaCardExpiry;
						do {
							cout << "\n" << string(8, '\t') << "| Enter Visa Card Expiry Date |: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n" << string(8, '\t') << "Invalid input, Please Enter your Visa Card Expiry Date\n";
							else {
								{
									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Press 1 to Confirm Visa Card Expiry Date   |"
										<< "\n" << string(8, '\t') << "| Press 2 to Re-enter Visa Card Expiry Date  |"
										<< "\n" << string(8, '\t') << "| Press 3 to exit                            |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Enter option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
											<< "\n" << string(8, '\t') << "|      VISA EXPIRY DATE HAS BEEN UPDATED      |"
											<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
										staff[userVectLocation].visaCardExpiry = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 8:
						if (user == "admin") {
							cout << "\n" << string(8, '\t') << "| Current User Status: ";
							if (staff[userVectLocation].accountStatus) cout << "ACTIVE"; else cout << "INACTIVE";
							do {
								cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Press Y to Activate User Account           |"
									<< "\n" << string(8, '\t') << "| Press N to De-Activate User Account        |"
									<< "\n" << string(8, '\t') << "|--------------------------------------------|"
									<< "\n" << string(8, '\t') << "| Enter option: ";
								cin >> accStatus;
								if (tolower(accStatus) != 'y' && tolower(accStatus) != 'n')
									cout << "\n" << string(8, '\t') << "Invalid input... Try Again...\n";
								else {
									{
										cout << "\n" << string(8, '\t') << "|-----------------------------|"
											<< "\n" << string(8, '\t') << "| Press 1 to Confirm           |"
											<< "\n" << string(8, '\t') << "| Press 2 to Re-enter          |"
											<< "\n" << string(8, '\t') << "| Press 3 to exit              |"
											<< "\n" << string(8, '\t') << "|------------------------------|"
											<< "\n" << string(8, '\t') << "| Enter option: ";
										cin >> choice;
										if (choice == 1) {
											cout << "\n" << string(8, '\t') << "|---------------------------------------------|"
												<< "\n" << string(8, '\t') << "|     USER ACCOUNT STATUS HAS BEEN UPDATED    |"
												<< "\n" << string(8, '\t') << "|---------------------------------------------|\n" << string(8, '\t') << "";
											if (tolower(accStatus) == 'y')//activate account
												staff[userVectLocation].accountStatus = true;
											else if (tolower(accStatus) == 'n')//deactivate account
												staff[userVectLocation].accountStatus = false;
											system("pause");
											break;
										}
										else if (choice == 2) {
											cout << "\n" << string(8, '\t') << "|---------------------------------------------|";
										}
										else if (choice == 3) {
											break;
										}
										else
											cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again..\n";
									}
								}
							} while (true);
						}
						else {
							cout << "\n" << string(8, '\t') << "Invalid input, Please try again\n" << string(8, '\t') << "";
							system("pause");
						}
						break;
					case 0:
						isTrue = false;
						break;
					default:
						cout << "\n" << string(8, '\t') << "Invalid input, Please try again\n" << string(8, '\t') << "";
						system("pause");
						break;
					}
					ofstream staffFile("Staff_file.csv", ios::out);
					//ADD HEADERS TO CSV
					staffFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
						<< "," << "VISA_NUM" << "," << "VISA_EXPIRY" << "," << "ACC_STATUS" << endl;
					for (int i = 0; i < staff.size(); i++) {
						staffFile << staff[i].staffID << "," << staff[i].fullName << "," << staff[i].gender << "," << staff[i].dob << "," << staff[i].contactNum << ","
							<< staff[i].email << "," << staff[i].visaCardNo << "," << staff[i].visaCardExpiry << "," << staff[i].accountStatus << endl;
					}
					staffFile.close();
				} while (isTrue);
			}
			else if (choice == 2) {
				isTrue2 = true;
				do {
					cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Press 1 to Change Password                 |"
						<< "\n" << string(8, '\t') << "| Press 2 to exit                            |"
						<< "\n" << string(8, '\t') << "|--------------------------------------------|"
						<< "\n" << string(8, '\t') << "| Enter option: ";
					cin >> choice;
					cin.ignore();
					if (choice == 1) {
						//enter current password
						do {
							cout << staff[userVectLocation].login.password << endl;
							cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
								<< "\n" << string(8, '\t') << "| Type: quit@ to exit from password          |"
								<< "\n" << string(8, '\t') << "|--------------------------------------------|"
								<< "\n" << string(8, '\t') << "| Enter current password: ";
							getline(cin, password);

							if (password == staff[userVectLocation].login.password)
								break;
							else if (password == "quit@") {
								isTrue2 = false;
								break;
							}
							else
								cout << "\n" << string(8, '\t') << "Password did not match.. Please Try Again..\n";
						} while (true);

						//enter new password
						if (password != "quit@") {
							do {
								do {
									cout << "" << string(8, '\t') << "|-------------------------------------------------------------------|"
										<< "\n" << string(8, '\t') << "| Use 8 or more characters with a mix of letters, numbers & symbols |"
										<< "\n" << string(8, '\t') << "|-------------------------------------------------------------------|"
										<< "\n" << string(8, '\t') << "|Enter Password" << setw(17) << "|: ";
									getline(cin, password);

									if (checkPassword(password))
										break;
									else
										cout << "\n" << string(8, '\t') << "Invalid password, Please try again\n";
								} while (true);

								//verify password
								do {
									cout << "" << string(8, '\t') << "|Enter Verify Password" << setw(10) << "|: ";
									getline(cin, verifyPassword);

									if (verifyPassword == "")
										cout << "\n" << string(8, '\t') << "Password did not match, Please try again\n";
									else
										break;
								} while (true);

								if (password != verifyPassword)
									cout << "\n" << string(8, '\t') << "Password did not match please try again...\n";

								else {
									staff[userVectLocation].login.password = password;

									for (int i = 0; i < login.size(); i++) {
										if (staff[userVectLocation].login.userForeignID == login[i].userForeignID) {
											login[i].password = staff[userVectLocation].login.password;
										}
									}
									ofstream loginFile("Login_file.csv", ios::out);
									//ADD HEADERS TO CSV
									loginFile << "PRIMARY_KEY" << "," << "FOREIGN_KEY" << "," << "USERNAME" << "," << "PASSWORD" << endl;
									for (int i = 0; i < login.size(); i++) {
										loginFile << login[i].loginID << "," << login[i].userForeignID << "," << login[i].username << "," << login[i].password << endl;
									}
									loginFile.close();

									cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
										<< "\n" << string(8, '\t') << "|   Password has been successfully changed   |"
										<< "\n" << string(8, '\t') << "|--------------------------------------------|";
									break;
								}
							} while (true);
						}
					}
					else if (choice == 2)
						isTrue2 = false;
					else
						cout << "\n" << string(8, '\t') << "Invalid input, Please Try Again\n" << string(8, '\t');

					cout << "\n" << string(8, '\t') << "";
					system("pause");
				} while (isTrue2);
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "\n" << string(8, '\t') << "Invalid Input.. Please try again...\n" << string(8, '\t');
				system("pause");
			}
		} while (true);
	}
	else {
		cout << "\n" << string(8, '\t') << "|--------------------------------------------|"
			<< "\n" << string(8, '\t') << "|               INVALID USER ID              |"
			<< "\n" << string(8, '\t') << "|               CANT FIND USER               |"
			<< "\n" << string(8, '\t') << "|--------------------------------------------|\n" << string(8, '\t');
		system("pause");
	}

	// Code by Jakob
	if (name != "+=-" || contactNum != "+=-" || email != "+=-") {
		updateWeeklyComplaint(userID, name, contactNum, email);
	}
}

// Code by Jakob
// this function shows the different options for the admin once they've logged in.
void adminScreen() {
	system("cls");
	int choice;
	char choice2;
	bool isTrue = true;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);

	do {
		system("cls");
		schoolTitle();
		cout << "\n" << string(8, '\t') << "|---------------------------|";
		cout << "\n" << string(8, '\t') << "|        ADMIN SCREEN       |";
		cout << "\n" << string(8, '\t') << "|---------------------------|";
		cout << "\n" << string(8, '\t') << "|1. Menu Update             |";
		cout << "\n" << string(8, '\t') << "|2. Daily Order Report      |";
		cout << "\n" << string(8, '\t') << "|3. Weekly Sales Report     |";
		cout << "\n" << string(8, '\t') << "|4. Pending Payment Report  |";
		cout << "\n" << string(8, '\t') << "|5. Weekly Complaint        |";
		cout << "\n" << string(8, '\t') << "|6. Show all Parent         |";
		cout << "\n" << string(8, '\t') << "|7. Show all Staff          |";
		cout << "\n" << string(8, '\t') << "|8. Update Parent Details   |";
		cout << "\n" << string(8, '\t') << "|9. Update Staff Deatils    |";
		cout << "\n" << string(8, '\t') << "|0. Exit                    |";
		cout << "\n" << string(8, '\t') << "|---------------------------|";
		cout << "\n" << string(8, '\t') << " Enter option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			updateMenuList();
			break;
		case 2:
			system("cls");
			printWeeklyOrderReport('y');
			system("pause");
			break;
		case 3:
			printWeeklySales(); // Written by Jakob
			break;
		case 4:
			system("cls");
			printWeeklyOrderReport('n');
			system("pause");
			break;
		case 5:
			printWeeklyComplaint(); // Written by Jakob
			break;
		case 6:
			system("cls");
			do {
				schoolTitle();
				cout << "\n" << string(8, '\t') << "|-------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "|               Print All Parent Details                |"
					<< "\n" << string(8, '\t') << "|-------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "| Press Y to print all active users                     |"
					<< "\n" << string(8, '\t') << "| Press N to print all inactive users                     |"
					<< "\n" << string(8, '\t') << "| Enter option: ";
				cin >> choice2;

				if (tolower(choice2) != 'y' && tolower(choice2) != 'n') {
					cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again.." << "\n" << string(8, '\t');
					system("pause");
				}
				else
					break;
			} while (true);
			printAllParentDetails(choice2);
			system("pause");
			break;
		case 7:
			system("cls");
			do {
				schoolTitle();
				cout << "\n" << string(8, '\t') << "|-------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "|                Print All Staff Details                |"
					<< "\n" << string(8, '\t') << "|-------------------------------------------------------|"
					<< "\n" << string(8, '\t') << "| Press Y to print all active users                     |"
					<< "\n" << string(8, '\t') << "| Press N to print all inactive users                     |"
					<< "\n" << string(8, '\t') << "| Enter option: ";
				cin >> choice2;

				if (tolower(choice2) != 'y' && tolower(choice2) != 'n') {
					cout << "\n" << string(8, '\t') << "Invalid Input.. Please Try Again.." << "\n" << string(8, '\t');
					system("pause");
				}
				else
					break;
			} while (true);
			printAllStaffDetails(choice2);
			system("pause");
			break;
		case 8:
			system("cls");
			schoolTitle();
			printAllParentDetails('a');
			updateParentDetails(printUpdateDetailsMenu(), "admin");
			break;
		case 9:
			system("cls");
			schoolTitle();
			printAllStaffDetails('a');
			updateStaffDetails(printUpdateDetailsMenu(), "admin");
			break;
		case 0:
			SetConsoleTextAttribute(h, 7);
			isTrue = false;
			break;
		}
	} while (isTrue);
}

//Code by Jay
//This function is for the admin this will ask the admin to enter the id of the user to start editing the user details
string printUpdateDetailsMenu() {
	string userID;

	cout << "\n" << string(8, '\t') << "|-------------------------------------------------------|"
		<< "\n" << string(8, '\t') << "|                    Update User Details                |"
		<< "\n" << string(8, '\t') << "|-------------------------------------------------------|"
		<< "\n" << string(8, '\t') << "| To Update User Detiails Please Provide The USER ID    |"
		<< "\n" << string(8, '\t') << "| Enter USER ID: ";
	cin >> userID;

	return userID;
}

// Code by Jakob
// This function outputs the weekly complaints and allows the admin to repsond to a complaint (change the action status).
void printWeeklyComplaint() {
	int i;
	vector<string> weeklyComplaint;
	int id;
	int flag = 0;
	bool isTrue = true;

	system("cls");
	weeklyComplaint = getWeeklyComplaint();

	if (weeklyComplaint.size() == 8) {
		flag = 1;
	}
	do {
		system("cls");
		schoolTitle();
		if (flag != 1) {
			for (int i = 0; i < weeklyComplaint.size();) {
				if (i == 0) {
					cout << "\n";
					cout << "\t" << weeklyComplaint[i];
					printSpaces(weeklyComplaint[i].size(), 10);
				}
				else {
					cout << "\t" << weeklyComplaint[i] << ".";
					printSpaces(weeklyComplaint[i].size(), 9);
				}

				cout << weeklyComplaint[i + 1];
				printSpaces(weeklyComplaint[i + 1].size(), 11);
				cout << weeklyComplaint[i + 2];
				printSpaces(weeklyComplaint[i + 2].size(), 22);
				cout << weeklyComplaint[i + 3];
				printSpaces(weeklyComplaint[i + 3].size(), 12);
				cout << weeklyComplaint[i + 7];
				printSpaces(weeklyComplaint[i + 7].size(), 30);
				cout << weeklyComplaint[i + 4];
				printSpaces(weeklyComplaint[i + 4].size(), 14);
				cout << weeklyComplaint[i + 8];

				if (i == 0) {
					cout << "\n\n";
				}
				else {
					cout << "\n";
				}
				i = i + 9;
			}

			cout << "\n\t|---------------------------------------------------|";
			cout << "\n\t| Enter a complaint ID to change its action status. |";
			cout << "\n\t| Enter 0 to return to previous menu.               |";
			cout << "\n\t|---------------------------------------------------|";
			cout << "\n\t| Enter choice: ";
			cin >> id;

			cout << "\n\n";
			do {
				if (id == 0) { // exit weekly complaint
					isTrue = false;
					break;
				}
				else {
					system("cls");
					// starting from 8 to skip the file headers
					for (i = 9; i < weeklyComplaint.size();) {
						if (stoi(weeklyComplaint[i]) == id) {
							char choice;
							cout << "\n\tComplaint ID:          " << weeklyComplaint[i];
							cout << "\n\tName:                  " << weeklyComplaint[i + 2];
							cout << "\n\tDate of complaint:     " << weeklyComplaint[i + 3];
							cout << "\n\tReason:                " << weeklyComplaint[i + 4];
							cout << "\n\tComplaint description: " << weeklyComplaint[i + 5];
							if (stoi(weeklyComplaint[i + 8]) == 0) { // If action status = 0
								cout << "\n\n\tMark complaint as resolved? y/n: ";
								cin >> choice;
								if (tolower(choice) == 'y') {
									weeklyComplaint[i + 8] = "1";
									changeActionStatus(weeklyComplaint);
									cout << "\n\tThe complaints action status has been changed from \"0\" to \"1\".";
									cout << "\n\n\t";
									system("pause");
									break;
								}
								else {
									break;
								}
							}
							else { // if actions status = 1
								cout << "\n\n\tComplaint has already been marked as resolved. Revert changes? y/n: ";
								cin >> choice;
								if (tolower(choice) == 'y') {
									weeklyComplaint[i + 8] = "0";
									changeActionStatus(weeklyComplaint);
									cout << "\n\n\tThe complaints action status has been changed from \"1\" to \"0\".";
									cout << "\n\n\t";
									system("pause");
									break;
								}
								else {
									break;
								}
							}
						}
						i = i + 9;
					}
				}
				break;
			} while (true);
		}
		else {
			cout << "\n\t[NO COMPLAINTS HAVE BEEN FOUND]\n\n\t";
			system("pause");
		}
	} while (isTrue);
}

// Code by Jakob
// If admin is looking at weekly complaints, this function gets the weekly complaint data from Complaint_file.csv and returns it as a vector.
vector<string> getWeeklyComplaint() {
	vector<string> weeklyComplaint;
	string line, tempStr;
	ifstream complaints;
	bool isTrue = true;

	do {
		complaints.open("Complaint_file.csv", ios::in);
		if (!complaints.good()) {
			cout << "\n\t\t\tError: Could not open complaint file, please check if the complaint file is currently open.";
			cout << "\n\t\t\t";
			system("pause");
		}
		while (getline(complaints, line)) {
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				weeklyComplaint.push_back(tempStr);
			}
		}
		isTrue = false;
		break;
	} while (isTrue);

	complaints.close();
	return weeklyComplaint;
}

// Code by Jakob
// This function changes the complaint file to include the new action status.
void changeActionStatus(vector<string> weeklyComplaint) {
	ofstream changeFile;
	changeFile.open("Complaint_file.csv", ios::out);
	int i, checkLine = 0;

	do {
		if (!changeFile.good()) {
			cout << "\n\t\t\tError: Could not open complaint file, please check if the complaint file is currently open.";
			cout << "\n\t\t\t";
			system("pause");
		}
		else {
			for (i = 0; i < weeklyComplaint.size();) {
				changeFile << weeklyComplaint[i] << "," << weeklyComplaint[i + 1] << "," << weeklyComplaint[i + 2] << "," << weeklyComplaint[i + 3]
					<< "," << weeklyComplaint[i + 4] << "," << weeklyComplaint[i + 5] << "," << weeklyComplaint[i + 6] << "," << weeklyComplaint[i + 7]
					<< "," << weeklyComplaint[i + 8] << endl;
				i = i + 9;
			}
		}
		changeFile.close();
		break;
	} while (true);
}

// Code by Jakob
// This function outputs the number of total orders, date and total amount received.
// This function does not currently include how much a bulk order has contributed to the total sales.
void printWeeklySales() {
	int lines = 0;
	int col;
	float grossPay = 0, totalTax = 0, totalBulk = 0;
	string line, tempStr;
	string date = getCurrentDate();

	ifstream getPayData;
	getPayData.open("Payment_file.csv");

	if (!getPayData.good()) {
		cout << "\n\t\t\tCould not open file. Please check that Payment_file.csv isn't currently open.\n";
	}
	else {

		// check week

		while (getline(getPayData, line)) {
			lines++;
			col = 0;
			stringstream ss(line);
			while (!ss.eof()) {
				getline(ss, tempStr, ',');
				if (lines == 1) {
					break;
				}

				if (col == 3) { // tax
					if (tempStr != "0") {
						totalTax = totalTax + stof(tempStr);
					}
					else { // bulk
						cout << "\n\tbulk equal 0";
						totalBulk = totalBulk + 1;
					}
				}
				else if (col == 6) {// total price
					grossPay = grossPay + stof(tempStr);
				}
				col++;
			}
		}

		getPayData.close();

		system("cls");
		schoolTitle();
		cout << "\n\t\t\t|---------------------------------------------|";
		cout << "\n\t\t\t| TOTAL SALES (Weekly coming in later builds) |";
		cout << "\n\t\t\t|---------------------------------------------|";
		cout << "\n\t\t\t|                                             ";
		cout << "\n\t\t\t|Date:                " << date;
		cout << "\n\t\t\t|Total payed orders:  " << (lines - 1) - totalBulk;
		cout << "\n\t\t\t|Total bulk orders:   " << totalBulk;    // total bulk orders
		cout << "\n\t\t\t|";
		cout << "\n\t\t\t|Gross amount earned: $" << grossPay; // gross earned
		cout << "\n\t\t\t|Total Tax deducted:  $" << totalTax;          // tax
		cout << "\n\t\t\t|Net amount earned:   $" << grossPay - totalTax;
		cout << "\n\t\t\t|---------------------------------------------";

	}
	cout << "\n\n\t\t\t";
	system("pause");
}

// Code by Jakob
// This function is called in the updateStaffDetails/updateParentDetails functions.
// If a user updates their Name/ContactNum/Email, then the weeklyComplaint file needs to be updated as well.
void updateWeeklyComplaint(string userID, string name, string contactNum, string email) {
	ifstream complaintFile;
	string line, tempStr;
	vector<string> fileData;
	int i, flag = 0;
	bool isTrue = true;

	complaintFile.open("Complaint_file.csv", ios::in);
	if (complaintFile.good()) {
		do {
			while (getline(complaintFile, line)) {
				stringstream ss(line);
				while (!ss.eof()) {
					getline(ss, tempStr, ',');
					if (tempStr == userID) {
						flag = 1;
						isTrue = false;
						break;
					}
				}
			}
		} while (isTrue);
		complaintFile.close();

		if (flag == 1) {
			isTrue = true;
			do {
				// Gather entire file into a vector (vector<string> fileData)
				complaintFile.open("Complaint_file.csv", ios::in);
				while (getline(complaintFile, line)) {
					stringstream ss(line);
					while (!ss.eof()) {
						getline(ss, tempStr, ',');
						fileData.push_back(tempStr);
					}
				}
				complaintFile.close();

				// Find where username is stored to update the details
				for (i = 0; i < fileData.size(); i++) {
					if (fileData[i] == userID) {
						if (name != "+=-") {
							fileData[i + 1] = name;
						}
						else if (contactNum != "+=-") {
							fileData[i + 5] = contactNum;
						}
						else if (email != "+=-") {
							fileData[i + 6] = email;
						}
					}
				}

				// Write updated data to complaint file
				ofstream writeFile("Complaint_file.csv", ios::out);
				if (!writeFile.good()) {
					cout << "\n\t\t\tError: Could not update complaint file with new data. Please check it is not currently open.";
				}
				else {
					for (i = 0; i < fileData.size();) {
						writeFile << fileData[i] << "," << fileData[i + 1] << "," << fileData[i + 2] << "," << fileData[i + 3] << ","
							<< fileData[i + 4] << "," << fileData[i + 5] << "," << fileData[i + 6] << "," << fileData[i + 7] << "," << fileData[i + 8] << endl;
						i = i + 9;
					}
				}
				writeFile.close();
				isTrue = false;
			} while (isTrue);
		}
	}
	else {
		cout << "\n\t\tCould not open file, please check that the complaint file is not currently open!";
		system("pause");
	}
}