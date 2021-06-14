#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>
#include <vector>
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

	Login(int defLoginID = 0, string defUsername = "Def Username", string defPassword = "Def Password") {

		loginID = defLoginID;
		userForeignID = defLoginID;
		username = defUsername;
		password = defPassword;
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
	int countNum;
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
	string staffID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	int countNum;
	string visaCardNo;
	string visaCardExpiry;
	string email;
	vector<Order> order;
	struct Login login;
	struct Complaint;
	struct BulkPayment bulk;
	vector<Payment> payment;

	Staff(int defID = 0, bool defAccountStatus = false, string defFullName = "Default Staff", string defGender = "Default Gender",
		string defDOB = "00/00/0000", int defCountNum = 0, string defVisaNum = "Default Visa Num", string defVisaExpiry = "Def Expiry",
		string defEmail = "default@email.com") {

		staffID = defID;
		accountStatus = defAccountStatus;
		fullName = defFullName;
		gender = defGender;
		dob = defDOB;
		countNum = defCountNum;
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

void orderFood(vector<string>);
vector<Order>getFoodOrderDetails(vector<Order>, int);
vector<Order> removeOrder(vector<Order>);
void printAllOrders(vector<Order> order);
void checkoutOrder(vector<Order> order, vector<string>);
void printWeeklyOrderReport();
vector<Parent> getAllParentDetails();
vector<Staff> getAllStaffDetails();
void printAllParentDetails();
void printAllStaffDetails();
vector<Order>getAllOrderDetails();
vector<Payment>getAllPaymentDetails();
vector<Login> getAllLoginDetails();
void updateParentDetails(string);
void updateStaffDetails(string userID);
vector<BulkPayment> getAllBulkDetails();

int main()
{
	createFiles();
	return printMenuList();
}

// Code written by Jay and Jakob
// This function prints the main menu to the user
int printMenuList() {
	int choice;

	do {
		system("cls");
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
		case 1:
			printWeeklyMenu();
			system("pause");
			break;
		case 2:
			printBulkDiscounts();
			break;
		case 3:
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
void printBulkDiscounts() { // Jay's code
	cout << "\nBULK BOOKING DISCOUNTS\n"
		<< "**********************\n"
		<< "1. GOLD FOOD PASS \t\t 2. SILVER FOOD PASS \t\t 3. COPPER FOOD PASS\n"
		<< "   ----------------- \t\t    ---------------- \t\t    ----------------\n"
		<< "   Pay for 30 days and \t\t    Pay for 15 days and \t    Pay for 7 days and \n"
		<< "   receive a 15% discount. \t    receive a 10% discount. \t    receive a 5% discount.\n\n"
		<< "   Without food pass: $150 \t    Without food pass: $75 \t    Without food pass: $35 \n"
		<< "   With food pass: $127.5 \t    With food pass: $67.50 \t    With food pass: $33.25 \n"
		<< "   Save $22.50 \t\t\t    Save $7.50 \t\t\t    Save $1.75\n\n";
	system("pause");
}

//Written by Jay
//This function prints out the details of the school
void printContactLocationDetails() { // Jay's code
	cout << "\nCONTACT DETAILS \t\t\t OFFICE LOCATION\n"
		<< "*************** \t\t\t ***************\n"
		<< "Email: admin@schoolname.co.nz \t\t Main office: \n"
		<< "Phone: 0800 83 83 83 \t\t\t A Block, School Name\n"
		<< "\t\t\t\t\t Suburb\n"
		<< "\t\t\t\t\t City\n"
		<< "\t\t\t\t\t Region\n"
		<< "\t\t\t\t\t Country\n\n";
	system("pause");
}

void loginRegistrationScreen() { // Code written by Jakob
	int choice, registerChoice;

	do {
		system("cls");
		cout << "\n\t\t\t|----------------------------|"
			<< "\n\t\t\t|     LOG IN / REGISTER      |"
			<< "\n\t\t\t|----------------------------|";
		cout << "\n\t\t\t|1. Login                    |";
		cout << "\n\t\t\t|2. Register                 |";
		cout << "\n\t\t\t|3. Back                     |";
		cout << "\n\t\t\t|                            |";
		cout << "\n\t\t\t|Enter choice                |: ";
		cin >> choice;

		if (choice == 1) {
			loginScreen();
			break;
		}
		else if (choice == 2) {
			system("cls");
			cout << "\n\t\t\t|----------------------------|"
				<< "\n\t\t\t|      REGISTER ACCOUNT      |"
				<< "\n\t\t\t|----------------------------|";
			cout << "\n\t\t\t|1. Staff account            |";
			cout << "\n\t\t\t|2. Parent account           |";
			cout << "\n\t\t\t|3. Back                     |";
			cout << "\n\t\t\t|                            |";
			cout << "\n\t\t\t|Enter choice                |: ";
			cin >> registerChoice;

			if (registerChoice == 1) {
				registerStaff();
				break;
			}
			else if (registerChoice == 2) {
				registerParent(); //code by jay
				break;
			}
			else if (registerChoice == 3) {
				continue;
			}
			else {
				cout << "\n\t\t\tPlease enter a number relevant to the given menu.\n";
			}
		}
		else if (choice == 3) {
			break;
		}
		else {
			cout << "\n\t\t\tPlease enter a number relevant to the given menu.\n";
		}
	} while (true);
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
		cout << "\n\t\t\t|----------------------------|"
			<< "\n\t\t\t|     Staff REGISTRATION     |"
			<< "\n\t\t\t|----------------------------|";
		do {
			cout << "\n\t\t\t|Enter Full name" << setw(16) << "|: ";
			getline(cin, staffRegister.fullName);
			if (staffRegister.fullName == "")
				cout << "\n\t\t\tInvalid input, please Enter your name.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Gender" << setw(19) << "|: ";
			getline(cin, staffRegister.gender);
			if (staffRegister.gender == "")
				cout << "\n\t\t\tInvalid input, please Enter your gender.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Date of birth         |"
				<< "\n\t\t\t|DD/MM/YYYY                  |: " << setw(12);
			getline(cin, staffRegister.dob);
			if (staffRegister.dob == "")
				cout << "\n\t\t\tInvalid input, please Enter your date of birth.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Contact Number" << setw(11) << "|: ";
			cin >> staffRegister.countNum;
			cin.ignore();
			if (staffRegister.countNum == 0) {
				cout << "\n\t\t\tInvalid input, please enter your contact number.\n";
			}
			else {
				break;
			}
		} while (true);


		do {
			cout << "\t\t\t|Enter Email Address" << setw(12) << "|: ";
			getline(cin, staffRegister.email);
			if (staffRegister.email == "")
				cout << "\n\t\t\tInvalid input, please Enter your email address.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Number" << setw(9) << "|: ";
			getline(cin, staffRegister.visaCardNo);
			if (staffRegister.visaCardNo == "")
				cout << "\n\t\t\tInvalid input, please Enter your visa card number.\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Expiry Date |"
				<< "\n\t\t\t|DD/MM/YYYY                  |: ";
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
				<< "\n\t\t\t|  Press N to choose other option   |"
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
				ofstream staffFile("Staff_file.csv", ios::app);
				staffFile << staffRegister.staffID << "," << staffRegister.fullName << "," << staffRegister.gender << "," << staffRegister.dob << "," << staffRegister.countNum << ","
					<< staffRegister.email << "," << staffRegister.visaCardNo << "," << staffRegister.visaCardExpiry << endl;
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
//Code by Jay
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
	cout << "\n\t\t\t|----------------------------|"
		<< "\n\t\t\t|        LOGIN SCREEN        |"
		<< "\n\t\t\t|   Type 'back' to go back   |"
		<< "\n\t\t\t|----------------------------|";

	do {
		loginFile.open("Login_file.csv", ios::in);
		cout << "\n\t\t\t|Username" << setw(8) << "|: ";
		getline(cin, username);

		// giving user option to leave login screen
		if (username == "back") {
			cout << "\n\t\t\tYou have canceled your login.";
			cout << "\n\t\t\t";
			system("pause");
			loginRegistrationScreen();
			break;
		}

		accPass = checkLoginInput(username);
		if (accPass == " ")
			cout << "\n\t\t\tCouldn't find your account, Please try again...\n";
		else {
			loginFile.close();
			break;
		}
		loginFile.close();
	} while (notExist);

	do {
		cout << "\n\t\t\t|Password" << setw(8) << "|: ";
		getline(cin, pass);

		if (pass != accPass) {
			// Code by Jakob - This checks how many times the user has attempted
			// to log in. Pauses program for 2 seconds after 3 attempts.
			loginAttempt++;
			if (loginAttempt < maxLoginAttempt) {
				cout << "\n\t\t\tWrong password. You have " << maxLoginAttempt - loginAttempt << " attempts left. Please try again...\n";
			}
			else if (loginAttempt == maxLoginAttempt) {
				// block login for 10 seconds
				cout << "\n\t\t\tPlease try again after 2 seconds.";
				this_thread::sleep_for(chrono::seconds(2)); // sleep for two seconds
				maxLoginAttempt = maxLoginAttempt + 3;
				system("pause");
			}
			else {
				cout << "\n\t\t\tLogin attempts will be blocked for two seconds. Please try again later!\n";
			}
		}
		else {
			accDetails = checkAccount(username); // Find staff or parent account
			printMainMenu(accDetails);
			break;
		}
	} while (true);

	cout << "\n\t\t\t";
	system("pause");
}

//Code by jay
//This function allows the user to register an account
void registerParent() {
	struct Parent parentRegister;
	char choice = ' ', choice2 = ' ';
	string password, verifyPass, uniqueID;
	system("cls");
	do {
		cin.ignore();
		cout << "\n\t\t\t|----------------------------|"
			<< "\n\t\t\t|     Parent REGISTRATION    |"
			<< "\n\t\t\t|----------------------------|";
		do {
			cout << "\n\t\t\t|Enter Full name" << setw(16) << "|: ";
			getline(cin, parentRegister.fullName);
			if (parentRegister.fullName == "")
				cout << "\n\t\t\tInvalid input, Please Enter your name\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Gender" << setw(19) << "|: ";
			getline(cin, parentRegister.gender);
			if (parentRegister.gender == "")
				cout << "\n\t\t\tInvalid input, Please Enter your gender\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Date of birth" << setw(11) << "| "
				<< "\n\t\t\t|DD/MM/YYYY" << setw(21) << "|: ";
			getline(cin, parentRegister.dob);
			if (parentRegister.dob == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Date of birth\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Contact Number" << setw(11) << "|: ";
			cin >> parentRegister.countNum;

			if (to_string(parentRegister.countNum).length() < 9 && to_string(parentRegister.countNum).length() > 10) {
				cout << "\n\t\t\tInvalid input, Please Enter your contact number.\n";
			}
			else {
				cin.ignore();
				break;
			}
			cin.ignore();
		} while (true);

		do {
			cout << "\t\t\t|Enter Email Address" << setw(12) << "|: ";
			getline(cin, parentRegister.email);
			if (parentRegister.email == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Email Address\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Child's name" << setw(13) << "|: ";
			getline(cin, parentRegister.childFullName);
			if (parentRegister.childFullName == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Child's name\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Child's Room Number" << setw(6) << "|: ";
			getline(cin, parentRegister.childRoomNum);
			if (parentRegister.childRoomNum == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Child's Room Number\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Number" << setw(9) << "|: ";
			getline(cin, parentRegister.visaCardNo);
			if (parentRegister.visaCardNo == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Number\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Visa Card Expiry Date | "
				<< "\n\t\t\t|DD/MM/YYYY" << setw(21) << "|: ";
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
				<< "\n\t\t\t|  Press N to choose other option   |"
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
				parentFile << parentRegister.parentID << "," << parentRegister.fullName << "," << parentRegister.gender << "," << parentRegister.dob << "," << parentRegister.countNum << ","
					<< parentRegister.email << "," << parentRegister.childFullName << "," << parentRegister.childRoomNum << "," << parentRegister.visaCardNo << ","
					<< parentRegister.visaCardExpiry << endl;
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
	bool isUnique = true;
	string line, tempStr;
	ifstream loginFile;

	//Checks all username in login file
	loginFile.open("Login_file.csv", ios::in);
	while (getline(loginFile, line)) {
		stringstream ss(line);
		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			if (tempStr == input) { //check if username matches
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
	cout << "\n\t\t\t|----------------------------|"
		<< "\n\t\t\t|        ADMIN LOGIN         |"
		<< "\n\t\t\t|----------------------------|";

	do {
		adminFile.open("Admin_file.csv", ios::in);
		cout << "\n\t\t\t|Enter admin username" << setw(8) << "        |: ";
		cin >> username;

		accPass = checkAdminInput(username);
		if (accPass == " ") {
			cout << "\n\t\t\tCouldn't find that username, please try again...\n";
		}
		else {
			adminFile.close();
			break;
		}
	} while (true);

	do {
		cout << "\n\t\t\t|Enter admin password" << setw(8) << "        |: ";
		cin >> pass;

		if (pass != accPass) {
			loginAttempt++;
			if (loginAttempt < maxLoginAttempt) {
				cout << "\n\t\t\tWrong password. You have " << (maxLoginAttempt - loginAttempt) << " attempts left. Please try again...\n";
			}
			else if (loginAttempt == maxLoginAttempt) {
				cout << "\n\t\t\tPlease try again after 2 seconds.\n\t\t\t";
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

	if (accDetails[0].substr(0, 3) == "270") { // parent
		flag = 1;
		userAccount = "parent";
		userAccount2 = "Parent";
	}
	else { // staff
		flag = 2;
		userAccount = "staff";
		userAccount2 = "Staff";
	}

	do {
		system("cls");
		cout << "\n\t\t\t========================================";
		cout << "\n\t\t\t" << accDetails[1];
		cout << "\n\t\t\tYou are logged in with a " << userAccount << " account.";
		cout << "\n\t\t\t" << userAccount2 << " ID: " << accDetails[0];
		cout << "\n\t\t\t========================================";

		cout << "\n\n\t\t\t1. Order food/View Menu";
		cout << "\n\t\t\t2. Make Complaint";
		cout << "\n\t\t\t3. Bulk Payment";
		cout << "\n\t\t\t4. Update Details";
		cout << "\n\t\t\t5. Logout";

		cout << "\n\n\t\t\tEnter choice: ";
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
				updateParentDetails(accDetails[0]);
			else
				updateStaffDetails(accDetails[0]);
			break;
		case 5:
			runMenu = false;
			break;
		default:
			cout << "\n\t\t\tPlease enter a number relevant to the menu.";
			break;
		}
	} while (runMenu);
}

// code by jakob
// Function allows user to write a complaint about an order.
// It will also generate a complaint ID based on the previous complaint ID in the Complaint_file.csv
void makeComplaint(vector<string> accDetails) {

	system("cls");

	ifstream readFile;
	ofstream compFile;
	string line;
	int complaintID, lineNumber = 0, lastLine = 0;
	bool isTrue = true;

	char choice, tryAgain;
	struct Complaint complaint;

	string date = getCurrentDate();

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
						//complaint.complaintID = complaint.complaintID + 1;
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

	cout << "\n\n\t\t\tComplaint ID: " << complaint.complaintID;
	cout << "\n\t\t\tName: " << accDetails[1];
	cout << "\n\t\t\tDate of order: " << date;
	cout << "\n\t\t\tItem Ordered: Chicken Burger";

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
				// accDetails[1] = Person Name
				// accDetails[4] = Contact Number
				// accDetails[5] = Email
				compFile << complaint.complaintID << "," << accDetails[1] << "," << date << "," << "item ordered" << ","
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
	cout << "\n\t\t\t";
	system("pause");
}

// Code by Jakob
void chooseBulkOrder(vector<string> accDetails) {

	int choice, flag;
	int orderCount = 0, i = 0;
	int totalBulkOrderCount;
	ofstream bulkOrderFile;
	ifstream infile;
	char errorChoice;
	bool isTrue = true;
	bool accountExists = false;

	do {
		system("cls");
		cout << "\n\t\t\tBULK BOOKING DISCOUNTS"
			<< "\n\t\t\t**********************\n"
			<< "\n\t\t\t1. GREEN FOOD PASS \t\t 2. BLUE FOOD PASS \t\t 3. RED FOOD PASS"
			<< "\n\t\t\t   ----------------- \t\t    ---------------- \t\t    ----------------"
			<< "\n\t\t\t   Pay for 30 days and \t\t    Pay for 15 days and \t    Pay for 7 days and"
			<< "\n\t\t\t   receive a 15% discount. \t    receive a 10% discount. \t    receive a 5% discount.\n"
			<< "\n\t\t\t   Without food pass: $150 \t    Without food pass: $75 \t    Without food pass: $35"
			<< "\n\t\t\t   With food pass: $127.5 \t    With food pass: $67.50 \t    With food pass: $33.25"
			<< "\n\t\t\t   Save $22.50 \t\t\t    Save $7.50 \t\t\t    Save $1.75\n\n";

		cout << "\n\t\t\tEnter 1/2/3 for bulk order or 4 to go back: ";
		cin >> choice;

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
		case 4:
			isTrue = false;
			break;
		default:
			cout << "\n\t\t\tPlease enter a number relevant to the menu...";
		}
	} while (isTrue);

	if (orderCount > 0) {
		do {
			accountExists = checkBulkFile(accDetails);

			if (accountExists == false) { // if account doesnt exist in file yet
				bulkOrderFile.open("BulkOrder_file.csv", ios::app);
				if (bulkOrderFile.good()) {
					bulkOrderFile << accDetails[0] << "," << orderCount << endl;
					cout << "\n\t\t\tYour purchase of option " << choice << " was successful! You now have " << orderCount << " days of free meals.";
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
								{"Noodles cooked with beautiful sexy beef.", "Grilled chicken with lettuce and ketchup that will make the ladies want you.","Fruit Salad with Orange Pineapple Kiwi Melon and apple pen"},
								{"Vegan:No Gluten:No","Vegan:No Gluten:Yes","Vegan:Yes Gluten:Yes"},
								{"$5.00","$5.00","$5.00"},
								{"4.","5.","6."},
								{"Eggs Benedict", "Egg Fried Rice", "French Toast Wee Wee"},
								{"Pouched egg with bacon muffin and hollandaise sauce with a springkle of love", "Rice Egg and MSG just how Uncle Roger likes","Just toast and diabetes Wee Wee"},
								{"Vegan: No Gluten:Yes","Vegan:No Gluten:No","Vegan:YES Gluten:Yes"},
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

	getFoodMenuList(ptrFD);

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

	cout << "\n\t\t\tPress 1 to change Menu 1"
		<< "\n\t\t\tPress 2 to change Menu 2"
		<< "\n\t\t\tPress 3 to change Menu 3"
		<< "\n\t\t\tPress 4 to change Menu 4"
		<< "\n\t\t\tPress 5 to change Menu 5"
		<< "\n\t\t\tPress 6 to change Menu 6"
		<< "\n\t\t\tChoose which menu you want to change: ";
	cin >> id;
	cin.ignore();

	cout << "\n\t\t\tPress 1 to change food name"
		<< "\n\t\t\tPress 2 to change food description"
		<< "\n\t\t\tPress 3 to change food dietary option"
		<< "\n\t\t\tPress 4 to change food price"
		<< "\n\t\t\tPress 5 to exit."
		<< "\n\t\t\tChoose which food detail to change: ";
	cin >> choice;
	cin.ignore();

	id -= 1;
	switch (choice) {
	case 1:
		do {
			do {
				cout << "\n\t\t\tEnter food name: ";
				getline(cin, foodName);
				if (foodName != " ")
					break;
				else
					cout << "\n\t\t\tInvalid input, Please enter food name..";
			} while (true);
			fml[id].foodName = foodName;
			break;
		} while (true);
		break;
	case 2:
		do {
			do {
				cout << "\n\t\t\tEnter food Description: ";
				getline(cin, foodName);
				if (foodName != " ")
					break;
				else
					cout << "\n\t\t\tInvalid input, Please enter food description..";
			} while (true);
			fml[id].foodDescription = foodDescription;
			break;
		} while (true);
		break;

	case 3:
		do {
			do {
				cout << "\n\t\t\tPress Y if food is vegan: "
					<< "\n\t\t\tPress N if food is not vegan: "
					<< "\n\t\t\tPlease enter your option: ";
				getline(cin, isVegan);
				if (isVegan != " " || isVegan.length() == 1)
					break;
				else
					cout << "\n\t\t\tInvalid input, Please enter food dietary..";
			} while (true);
			do {
				cout << "\n\t\t\tPress Y if food is Glutten free: "
					<< "\n\t\t\tPress N if food is not Glutten free: "
					<< "\n\t\t\tPlease enter your option: ";
				getline(cin, isGlutten);
				if (isGlutten != " " || isGlutten.length() == 1)
					break;
				else
					cout << "\n\t\t\tInvalid input, Please enter food dietary..";
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
		break;
	case 4:
		do {
			do {
				cout << "\n\t\t\tEnter food Price: ";
				cin >> foodPrice;
				cin.ignore();
				if (foodPrice != 0)
					break;
				else
					cout << "\n\t\t\tInvalid input, Please enter food price..";
			} while (true);
			fml[id].foodPrice = foodPrice;
			break;
		} while (true);
		break;
	case 5:
		cout << "\n\t\t\tUser has not been updated...";
		system("pause");
		break;
	default:
		cout << "\n\t\t\tInvalid Input.. Please try again...";
		break;
	}
	ofstream updateFoodMenu("FoodMenu_File.csv", ios::out);
	for (int i = 0; i < 6; i++) {
		updateFoodMenu << fml[i].foodNum << "," << fml[i].foodName << ","
			<< fml[i].foodDescription << "," << fml[i].foodDietary << ","
			<< "$" + to_string(fml[i].foodPrice) << endl;
	}
	updateFoodMenu.close();

	cout << "\n\t\t\t*****Food Menu has been updated*****\n";
	system("pause");
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

		if (row == 1 || row == 4 || row == 6 || row == 8) {
			for (int print = 0; print < 3; print++) {
				cout << "----------------------" << "\t\t\t";
				if (print == 2)
					cout << endl;
			}
		}
		for (int reset = 0; reset < 3; reset++) {
			rowIsDone[reset] = 0;
			lastPos[reset] = 0;
		}

		for (int col = 0; col < 3; col++) {
			while (!rowIsDone[0] || !rowIsDone[1] || !rowIsDone[2])
			{
				int column = 0;
				while (column < 3) {
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
							if (wordSpace > space) {
								for (int i = 0; i < space; i++)
									cout << " ";
								count = 21;
							}
							else
								wordSpace = 0;

							if (letter == (*ptrFD)[row][column].length() - 1) {
								rowIsDone[column] = true;
								for (int i = 0; i < space; i++)
									cout << " ";
							}
							count++;
							lastPos[column] = letter + 1;
						}
					}
					cout << "\t\t\t";
					count = 0;
					if ((*ptrFD)[row][column][lastPos[column]] == ' ')
						lastPos[column]++;
					column++;
				}
				cout << endl;
			}
		}
		if (row == 4)
			cout << "\n\n";
	}
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
			<< "," << "CHILD_NAME" << "," << "ROOM_NUM" << "," << "VISA_NUM" << "," << "VISA_EXPIRY" << endl;
		parentFile.close();
	}

	if (!staffFile.good()) {
		ofstream staffFile;
		staffFile.open("Staff_file.csv", ios::out);
		staffFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
			<< "," << "VISA_NUM" << "," << "VISA_EXPIRY" << endl;
		staffFile.close();
	}

	if (!compFile.good()) {
		ofstream compFile;
		compFile.open("Complaint_file.csv", ios::out);
		compFile << "COMP_ID" << "," << "NAME" << "," << "DATE" << "," << "ITEM_ORDERED" << "," << "DESC." << "," << "CONTACT NUM"
			<< "," << "EMAIL" << "," << "ACTION STATUS" << endl;
	}

	// order file, dont add child name or classroom number
	if (!orderFile.good()) {
		ofstream orderFile;
		orderFile.open("Order_file.csv", ios::out);
		orderFile << "ORDER_NUM" << "," << "FOREIGN_KEY" << "," << "DATE" << "," << "ITEM_NAME" << "," << "QUANTITY" << "," << "PAYMENT_STATUS" << endl;
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
	bool isTrue = true;
	char choice;
	string orderName;
	vector<Order> order;

	do {
		system("cls");
		printWeeklyMenu();
		cout << "\n\t\t\t Date: " << getCurrentDate() << endl
			<< "\n\t\t\t-----------------------------------"
			<< "\n\t\t\t|           School Name           |"
			<< "\n\t\t\t|---------------------------------|"
			<< "\n\t\t\t|            ORDER FOR            |"
			<< "\n\t\t\t|---------------------------------|";
		if (user[0].substr(0, 3) == "270") {
			cout << "\n\t\t\t| Student Name: " << user[6]
				<< "\n\t\t\t| Student Room no.: " << user[7];
		}
		else {
			cout << "\n\t\t\t| Staff Name: " << user[1];
		}
		cout << "\n\t\t\t|---------------------------------|"
			<< "\n\t\t\tPress 1 to order meal"
			<< "\n\t\t\tPress 2 to remove order"
			<< "\n\t\t\tPress 3 to print order details"
			<< "\n\t\t\tPress 4 to checkout"
			<< "\n\t\t\tPress 5 to exit"
			<< "\n\t\t\tChoose option: ";
		cin >> orderNum;

		switch (orderNum) {
		case 1:
			do {
				do {
					cout << "\n\t\t\tEnter meal number: ";
					cin >> orderNum;
					if (orderNum >= 1 && orderNum <= 6)
						break;
					else
						cout << "\n\t\t\tInvalid meal number, Please try again...\n";
				} while (true);

				cout << "\n\t\t\tDo you want to confirm this odrder?"
					<< "\n\t\t\tPress 'Y' to confirm order"
					<< "\n\t\t\tPress 'N' to change the order"
					<< "\n\t\t\tPress 'Q' to quit from order"
					<< "\n\t\t\tChoose option: ";
				cin >> choice;

				if (tolower(choice) == 'y') {
					cout << "\n\t\t\tOrder confirmed\n\t\t\t";
					order = getFoodOrderDetails(order, orderNum);
					break;
				}
				else if (tolower(choice) == 'n')
					cout << "\n\t\t\tOrder cancelled\n";
				else if (tolower(choice) == 'q') {
					cout << "\n\t\t\tExiting order menu\n";
					break;
				}
				else
					cout << "\n\t\t\tInvalid Input, Please try again...\n";
			} while (true);
			system("pause");
			break;
		case 2:
			order = removeOrder(order);
			break;
		case 3:
			system("cls");
			printAllOrders(order);
			system("pause");
			break;
		case 4:
			checkoutOrder(order, user);
			break;
		case 5:
			cout << "\n\t\t\tExiting from order menu...\n\t\t\t";
			isTrue = false;
			system("pause");
			break;
		default:
			cout << "\n\t\t\tInvalid Input.. Please try again...\n";
			system("pause");
			break;
		}
		system("cls");
	} while (isTrue);
}

//Code by Jay
//This function prints out all of the user order from the menu
void printAllOrders(vector<Order> order) {
	float total = 0;
	cout << setprecision(3);
	if (order.size() == 0) {
		cout << "\n\t\t\t*****No Data Found*****\n\t\t\t";
	}
	for (int i = 0; i < order.size(); i++) {
		total += order[i].price * order[i].quantity;
		cout << "\n\t\t\tOrder ID: " << order[i].orderNum << endl
			<< "\n\t\t\tOrder Date: " << order[i].orderDate << endl
			<< "\n\t\t\tItem Name: " << order[i].itemName << endl
			<< "\n\t\t\tOrder Quantity: " << order[i].quantity << endl
			<< "\n\t\t\tPrice: $" << order[i].price << endl
			<< "\n\t\t\t------------------------------------" << endl;
	}
	cout << "\n\t\t\tTOTAL: $" << total << "\n\t\t\t";
}

//Code by Jay
//This function lets the user remove orders 
vector<Order> removeOrder(vector<Order> order) {
	int orderID, vectOrderLoc;
	bool isTrue, isTrue2, isTrue3;
	int numChoice;

	do {
		system("cls");
		printAllOrders(order);
		isTrue = true, isTrue2 = true, isTrue3 = true;
		do {
			system("cls");
			cout << "\n\t\t\tPress 1 to remove orders"
				<< "\n\t\t\tPress 2 to quit..."
				<< "\n\t\t\tChoose Option: ";
			cin >> numChoice;

			switch (numChoice) {
			case 1:
				if (order.size() > 0) {
					do {
						printAllOrders(order);
						cout << "\n\t\t\tPlease enter order ID you wish to remove: ";
						cin >> orderID;
						for (int i = 0; i < order.size(); i++) {
							if (order[i].orderNum == orderID) {
								isTrue = false;
								vectOrderLoc = i;
								break;
							}
						}
						if (isTrue) {
							cout << "\n\t\t\tInvalid order ID.. Please try again...\n";
							system("pause");
						}
					} while (isTrue);

					system("cls");
					do {
						cout << "\n\t\t\tOrder ID: " << order[vectOrderLoc].orderNum << endl
							<< "\n\t\t\tOrder Date: " << order[vectOrderLoc].orderDate << endl
							<< "\n\t\t\tItem Name: " << order[vectOrderLoc].itemName << endl
							<< "\n\t\t\tOrder Quantity: " << order[vectOrderLoc].quantity << endl
							<< "\n\t\t\tPrice: " << order[vectOrderLoc].price << endl
							<< "\n\t\t\t------------------------------------" << endl
							<< "\n\t\t\tPress 1 to subract order quantity"
							<< "\n\t\t\tPress 2 to remove order completely"
							<< "\n\t\t\tPress 3 to exit..."
							<< "\n\t\t\tChoose Option: ";
						cin >> numChoice;

						switch (numChoice) {
						case 1:
							order[vectOrderLoc].quantity -= 1;
							if (order[vectOrderLoc].quantity == 0) {
								cout << "\n\t\t\tOrder has been removed\n\t\t\t";
								order.erase(order.begin() + vectOrderLoc);
								isTrue2 = false;
								cout << order.size() << endl;
								system("pause");
							}
							break;
						case 2:
							order.erase(order.begin() + vectOrderLoc);
							cout << "\n\t\t\tOrder has been removed\n\t\t\t";
							system("pause");
							isTrue2 = false;
							break;
						case 3:
							isTrue2 = false;
							break;
						default:
							cout << "\n\t\t\tInvalid Input.. Please try again..\n";
							system("pause");
							break;
						}
					} while (isTrue2);
				}
				else {
					cout << "\n\t\t\t******There are no orders to show******\n\t\t\t";
					system("pause");
				}
				break;
			case 2:
				cout << "\n\t\t\tExiting from remove order menu...\n\t\t\t";
				system("pause");
				numChoice = 69;
				isTrue3 = false;
				break;

			default:
				cout << "\n\t\t\tInvalid Input.. Please try again..\n";
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
void checkoutOrder(vector<Order> order, vector<string> user) {
	float subTotal = 0, gstAmount = 0, discount = 0.00, foodPass = 5.00;
	int numChoice, num;
	bool isTrue, isTrue2, isTrue3, isTrue4, isTrue5, usedFoodPass;
	string uniqueID = "", gstNumber, gstID;
	vector<BulkPayment> vectBulk;
	struct Payment payment;
	struct Order ord;
	char choice;

	//vectBulk = getAllBulkDetails();

	system("cls");
	cout << setprecision(2);
	if (order.size() == 0) {
		cout << "\n\t\t\t*****No Data Found*****\n\t\t\t";
	}
	else {
		do {
			system("cls");
			cout << "\n\t\t\t Date: " << getCurrentDate() << endl
				<< "\n\t\t\t-----------------------------------"
				<< "\n\t\t\t|           School Name           |"
				<< "\n\t\t\t|---------------------------------|"
				<< "\n\t\t\t|            ORDER FOR            |";
			if (user[0].substr(0, 3) == "270") {
				cout << "\n\t\t\t| Student Name: " << user[6]
					<< "\n\t\t\t| Student Room no.: " << user[7];
			}
			else {
				cout << "\n\t\t\t| Staff Name: " << user[1];
			}
			cout << "\n\t\t\t|---------------------------------|";
			for (int i = 0; i < order.size(); i++) {
				payment.totalPrice += order[i].price * order[i].quantity;
				cout << "\n\t\t\tOrder Date: " << order[i].orderDate << endl
					<< "\n\t\t\tItem Name: " << order[i].itemName << endl
					<< "\n\t\t\tOrder Quantity: " << order[i].quantity << endl
					<< "\n\t\t\tPrice: $" << order[i].price << endl
					<< "\n\t\t\t------------------------------------" << endl;
			}
			cout << "\n\t\t\tTOTAL: $" << payment.totalPrice << "\n\t\t\t";


			isTrue = true, isTrue2 = true, isTrue3 = true, isTrue4 = true, isTrue5 = true, usedFoodPass = false;
			cout << "\n\t\t\t|---------------------------------|"
				<< "\n\t\t\t| Press 1 to proceed to checkout  |"
				<< "\n\t\t\t| Press 2 to exit                 |"
				<< "\n\t\t\t|---------------------------------|"
				<< "\n\t\t\t| Choose option: ";
			cin >> numChoice;

			switch (numChoice) {
			case 1:
				do {
					cout << "\n\t\t\t|------------------------|"
						<< "\n\t\t\t| Press 1 to pay now     |"
						<< "\n\t\t\t| Press 2 to exit        |"
						<< "\n\t\t\t|------------------------|"
						<< "\n\t\t\t| Choose option: ";
					cin >> numChoice;

					if (numChoice == 1) {
						if (foodPass > 0) {
							do {
								cout << "\n\t\t\t|-------------------------------------------------------------|"
									<< "\n\t\t\t| You have " << foodPass << " free food pass in your account  |"
									<< "\n\t\t\t| Press 1 to use food pass                                    |"
									<< "\n\t\t\t| Press 2 to proceed without using food pass                  |"
									<< "\n\t\t\t|-------------------------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> numChoice;
								if (numChoice == 1) {
									do {
										cout << "\n\t\t\t|-------------------------------------------------------|"
											<< "\n\t\t\t| Press Y to pay all using Bulk Payment                 |"
											<< "\n\t\t\t| Press N to enter amount of food pass you wish to use  |"
											<< "\n\t\t\t| Press Q to go back                                    |"
											<< "\n\t\t\t|-------------------------------------------------------|"
											<< "\n\t\t\t| Choose option: ";
										cin >> choice;

										if (tolower(choice) == 'y') {//pay in full
											do {
												cout << "\n\t\t\t|-------------------------------|"
													<< "\n\t\t\t| Press Y to confirm Payment    |"
													<< "\n\t\t\t| Press N to go back            |"
													<< "\n\t\t\t|-------------------------------|"
													<< "\n\t\t\t| Choose option: ";
												cin >> choice;
												if (tolower(choice) == 'y') {
													discount = payment.totalPrice;
													payment.totalPrice -= discount;
													usedFoodPass = true;
													payment.typeOfPayment = "BULK PAYMENT";
													isTrue4 = false;
													isTrue3 = false;
													break;
												}
												else if (tolower(choice) == 'n') {
													isTrue4 = false;
													break;
												}
												else
													cout << "\n\t\t\tInvalid Input.. Please try again..";
											} while (true);
										}
										else if (tolower(choice) == 'n') {
											do {
												do {
													cout << "\n\t\t\t|-------------------------------------------------------------|"
														<< "\n\t\t\t| Please enter the amount of food pass you wish to use: ";
													cin >> num;

													if (num > payment.totalPrice / 5) // check if amount entered doesn't exceed the amount needed to pay
														cout << "Invalid amount! Max amount you can use is: " << payment.totalPrice / 5 << endl;
													else
														break;
												} while (true);

												cout << "\n\t\t\t|-------------------------------|"
													<< "\n\t\t\t| Press Y to confirm Payment    |"
													<< "\n\t\t\t| Press N to go back            |"
													<< "\n\t\t\t|-------------------------------|"
													<< "\n\t\t\t| Choose option: ";
												cin >> choice;

												if (tolower(choice) == 'y') {
													discount = 5.00 * num;

													if (discount == payment.totalPrice) {//if amount of bulk payment used is equal to the amount need to pay
														do {
															cout << "\n\t\t\t|-----------------------------------------------|"
																<< "\n\t\t\t| You opted to pay for all using Bulk Payment   |"
																<< "\n\t\t\t| Do you wish to proceed with this payment?     |"
																<< "\n\t\t\t|-------------------------------------------------------------------------------------------|"
																<< "\n\t\t\t| Press 1 to proceed payment ***WARNING THERE IS NO GOING BACK AT THIS POINT THIS POINT***  |"
																<< "\n\t\t\t| Press 2 to exit from payment                                                              |"
																<< "\n\t\t\t|-------------------------------------------------------------------------------------------|"
																<< "\n\t\t\t| Choose option: ";
															cin >> numChoice;

															if (numChoice == 1) {
																usedFoodPass = true;
																payment.typeOfPayment = "BULK PAYMENT";
																payment.totalPrice -= discount;
																isTrue5 = false;
																isTrue4 = false;
																isTrue3 = false;
																break;
															}
															else if (numChoice == 2) {
																isTrue5 = false;
																break;
															}
															else
																cout << "\n\t\t\tInvalid Input.. Please try again..";
														} while (true);
													}
													else {
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
												else
													cout << "\n\t\t\tInvalid Input.. Please try again..";
											} while (isTrue5);
										}
										else if (tolower(choice) == 'q') {
											break;
										}
										else //if wrong input
											cout << "\n\t\t\tInvalid Input.. Please try again..";
									} while (isTrue4);
								}
								else if (numChoice == 2) {
									usedFoodPass = false;
									isTrue3 = false;//break main loop
								}
								//add exit
								else
									cout << "\n\t\t\tInvalid Input.. Please try again..";

							} while (isTrue3);//main loop
						}

						//gohere
						if (discount <= payment.totalPrice) {//if there is still remaing amount to pay
							do {
								payment.totalPrice = payment.totalPrice + (payment.totalPrice * payment.GST); // apply GST
								payment.GSTAmount = payment.totalPrice * payment.GST;
								cout << "\n\t\t\t|------------------------------------------|"
									<< "\n\t\t\t| Amount left to pay: $" << payment.totalPrice
									<< "\n\t\t\t| Choose type of Payment"
									<< "\n\t\t\t|------------------------------------------|"
									<< "\n\t\t\t| Press 1 VISA                             |"
									<< "\n\t\t\t| Press 2 American Express                 |"
									<< "\n\t\t\t| Press 3 Mastercard                       |"
									<< "\n\t\t\t| Press 4 to exit                          |"
									<< "\n\t\t\t|------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> numChoice;

								switch (numChoice) {
								case 1:
									if (usedFoodPass)
										payment.typeOfPayment = "BULK PAYMENT / VISA";
									else
										payment.typeOfPayment = "BULK PAYMENT";
									isTrue2 = false;
									break;
								case 2:
									if (usedFoodPass)
										payment.typeOfPayment = "BULK PAYMENT / American Express";
									else
										payment.typeOfPayment = "American Express";
									isTrue2 = false;
									break;
								case 3:
									if (usedFoodPass)
										payment.typeOfPayment = "BULK PAYMENT / Mastercard";
									else
										payment.typeOfPayment = "Mastercard";
									isTrue2 = false;
									break;
								case 4:
									isTrue2 = false;
									break;
								default:
									cout << "\n\t\t\tInvalid Input.. Please try again..";
									system("pause");
									break;
								}
							} while (isTrue2);
						}

						payment.date = getCurrentDate();
						cout << "\n\t\t\t Date: " << payment.date << endl
							<< "\n\t\t\t-----------------------------------"
							<< "\n\t\t\t|           School Name           |"
							<< "\n\t\t\t|---------------------------------|"
							<< "\n\t\t\t|     A Block, School Name        |"
							<< "\n\t\t\t|     Phone: 0800 83 83 83        |"
							<< "\n\t\t\t|---------------------------------|";

						for (int i = 0; i < order.size(); i++) {
							subTotal = order[i].price * order[i].quantity;
							cout << "\n\t\t\t----------------------------------------"
								<< "\n\t\t\tItem Name:       " << order[i].itemName
								<< "\n\t\t\tNumber of items: " << order[i].quantity
								<< "\n\t\t\tOrder ID:        " << order[i].orderNum << "\t" << "\n\t\t\tPrice: $" << order[i].price
								<< "\n\t\t\t----------------------------------------"
								<< "\n\t\t\t|SUBTOTAL:       " << subTotal << endl;
							subTotal = 0;
						}
						if (usedFoodPass) {
							cout << "\n\t\t\t|------------------------------------------|"
								<< "\n\t\t\t|Food Pass Discount: $" << discount;
						}

						do {//generate a unique GST number and check if id is unique
							gstNumber = generateID(6);
							if (checkUniqueID(5, gstNumber)) {
								payment.GSTNumber = gstNumber;
								break;
							}
						} while (true);
						cout << "\n\t\t\t|------------------------------------------|"
							<< "\n\t\t\t|TOTAL PRICE:     $" << payment.totalPrice
							<< "\n\t\t\t|------------------------------------------|"
							<< "\n\t\t\t|Type of Payment:  " << payment.typeOfPayment
							<< "\n\t\t\t|Change:          $ 0.00"
							<< "\n\t\t\t|GST Included     $" << payment.GSTAmount
							<< "\n\t\t\t|GST Number:       " << payment.GSTNumber
							<< "\n\t\t\t|------------------------------------------|\n\n\t\t\t";

						//save order to csv
						ofstream saveOrder("Order_file.csv", ios::app);
						do {//generate a unique id for order and check if id is unique
							ord.orderID = generateID(4);
							if (checkUniqueID(4, ord.orderID))
								break;
						} while (true);
						ord.foreignKey = user[0];
						for (int i = 0; i < order.size(); i++) {
							saveOrder << ord.orderID << ", " << ord.foreignKey << "," << getCurrentDate() << "," << order[i].itemName << "," << order[i].quantity << "," << order[i].price << endl;
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

						cout << "\n\t\t\t|---------------------------------|"
							<< "\n\t\t\t|   PAYMENT CONFIRMED THANK YOU   |"
							<< "\n\t\t\t|---------------------------------|\n\t\t\t";

						isTrue = false;
						order.clear();//clear order after paying
						cout << order.size();
						system("pause");
						break;
					}
					else if (numChoice == 2)
						break;
					else {
						cout << "\n\t\t\tInvalid Input.. Please try again..";
						system("pause");
					}
				} while (true);
				break;
			case 2:
				cout << "\n\t\t\tExiting from checkout\n\t\t\t";
				system("pause");
				isTrue = false;
				break;
			default:
				cout << "\n\t\t\tInvalid Input.. Please try again..";
				system("pause");
				break;
			}
		} while (isTrue);
	}
}

//Code by Jay
//This function gets all the order data from csv and prints it out to user
void printWeeklyOrderReport() {
	vector<Parent> parent;
	vector<Staff> staff;

	staff = getAllStaffDetails();
	parent = getAllParentDetails();

	cout << "\n\t\t\t|---------------------------------------------|"
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
	cout << "\n\t\t\t";
}

//Code by Jay
//This function prints all of the parents details
void printAllParentDetails() {
	vector<Parent> vectParent;

	vectParent = getAllParentDetails();
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
	cout << "\n\t\t\t";
}

//Code by Jay
//This function prints all of the staffs details
void printAllStaffDetails() {
	vector<Staff> vectStaff;

	vectStaff = getAllStaffDetails();
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
	cout << "\n\t\t\t";
}

//Code by Jay
//This function gets all the parent data(order,payment) from csv and stores it in a vector and returns it
vector<Parent> getAllParentDetails() {

	vector<Parent> vectParent;
	vector<Order> vectOrder;
	vector<Payment> vectPayment;
	vector<Login> vectLogin;
	vector<string> parentData;
	Parent parent;
	string tempStr, line;
	char storeChar[8];
	ifstream myfile;
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
			parent.countNum = stoi(parentData[4]);
			parent.email = parentData[5];
			parent.childFullName = parentData[6];
			parent.childRoomNum = parentData[7];
			parent.visaCardNo = parentData[8];
			parent.visaCardExpiry = parentData[9];
		}


		vectParent.push_back(parent);
		parentData.clear();
	}
	myfile.close();
	vectOrder = getAllOrderDetails();
	vectPayment = getAllPaymentDetails();
	vectLogin = getAllLoginDetails();

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
			vectPayment[x].foreignKey.erase(remove(vectPayment[x].foreignKey.begin(), vectPayment[x].foreignKey.end(), ' '), vectPayment[x].foreignKey.end());//remove spaces in the string
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
			staff.countNum = stoi(staffData[4]);
			staff.email = staffData[5];
			staff.visaCardNo = staffData[6];
			staff.visaCardExpiry = staffData[7];
		}
		vectStaff.push_back(staff);
		staffData.clear();
	}
	myfile.close();

	vectOrder = getAllOrderDetails();
	vectPayment = getAllPaymentDetails();
	vectLogin = getAllLoginDetails();

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
			vectPayment[x].foreignKey.erase(remove(vectPayment[x].foreignKey.begin(), vectPayment[x].foreignKey.end(), ' '), vectPayment[x].foreignKey.end());//remove spaces in the string
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
		if (orderData[0] != "ORDER_NUM") {
			order.orderID = orderData[0];
			order.foreignKey = orderData[1];
			order.orderDate = orderData[2];
			order.itemName = orderData[3];
			order.quantity = stoi(orderData[4]);
			order.price = stof(orderData[5]);
		}

		vectOrder.push_back(order);
		orderData.clear();
	}
	myfile.close();

	return vectOrder;
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
		}

		vectPayment.push_back(payment);
		paymentData.clear();
	}
	myfile.close();

	return vectPayment;
}

//Code by Jay
//This function gets all Login data from csv and stores it in vector
vector<Login> getAllLoginDetails() {

	vector<string> loginData;
	vector<Login> vectLogin;
	Login login;
	string tempStr, line;

	ifstream myfile;
	myfile.open("Login_file.csv", ios::in);

	cout << setprecision(2);
	while (getline(myfile, line)) {
		stringstream ss(line);

		while (!ss.eof()) {
			getline(ss, tempStr, ',');
			loginData.push_back(tempStr);
		}
		if (loginData.size() != 0) {
			if (loginData[0] != "PRIMARY_KEY") {
				login.loginID = loginData[0];
				login.userForeignID = loginData[1];
				login.username = loginData[2];
				login.password = loginData[3];
				vectLogin.push_back(login);
			}
		}

		loginData.clear();
	}
	myfile.close();

	return vectLogin;
}

vector<BulkPayment> getAllBulkDetails() {

	vector<string> bulkData;//gohere2
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

	system("pause");
	return vectBulk;
}

//Code by Jay
//This function updates the parents details
void updateParentDetails(string userID) {
	vector<Parent> parent;
	vector<Login> login;
	int choice, userVectLocation = 0, tempContactNo;
	bool isTrue, isTrue2, isTrue3, isFound = true;
	string password, verifyPassword, tempData;

	parent = getAllParentDetails();
	login = getAllLoginDetails();
	//get user location in vector
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
			cout << "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t|                PARENT USER                 |"
				<< "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t| Press 1 to update Parent Details           |"
				<< "\n\t\t\t| Press 2 to change password                 |"
				<< "\n\t\t\t| Press 3 to exit                            |"
				<< "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t| Choose option: ";
			cin >> choice;
			if (choice == 1) {
				isTrue = true;
				do {
					system("cls");
					cout << "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t|            UPDATE PARENT DETAILS           |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Press 1 to update Parent Name              |"
						<< "\n\t\t\t| Press 2 to update Parent Gender            |"
						<< "\n\t\t\t| Press 3 to update Parent Date of Birth     |"
						<< "\n\t\t\t| Press 4 to update Parent Contact Number    |"
						<< "\n\t\t\t| Press 5 to update Parent Email             |"
						<< "\n\t\t\t| Press 6 to update Parent Child's Name      |"
						<< "\n\t\t\t| Press 7 to update Parent Child's Room No.  |"
						<< "\n\t\t\t| Press 8 to update Parent Visa Card No.     |"
						<< "\n\t\t\t| Press 9 to update Parent Visa Expiry Date  |"
						<< "\n\t\t\t| Press 0 to exit                            |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Choose option: ";
					cin >> choice;
					cin.ignore();

					switch (choice) {
						cout << "\n\t\t\t|--------------------------------------------|"
							<< "\n\t\t\t|            UPDATE PARENT DETAILS           |"
							<< "\n\t\t\t|--------------------------------------------|";
					case 1:
						cout << "\n\t\t\t| Current Name: " << parent[userVectLocation].fullName;
						do {
							cout << "\n\t\t\t| Enter Full name" << setw(16) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid Input.. Please Enter your name..\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Name                    |"
									<< "\n\t\t\t| Press 2 to Re-enter Name                   |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								cin.ignore();
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|            NAME HAS BEEN UPDATED            |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									parent[userVectLocation].fullName = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 2:
						cout << "\n\t\t\t| Current Gender: " << parent[userVectLocation].gender;
						do {
							cout << "\n\t\t\t| Enter Gender" << setw(19) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your gender\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Gender                  |"
									<< "\n\t\t\t| Press 2 to Re-enter Gender                 |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|           GENDER HAS BEEN UPDATED           |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									parent[userVectLocation].gender = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 3:
						cout << "\n\t\t\t| Current Date of Birth: " << parent[userVectLocation].dob;
						do {
							cout << "\n\t\t\t| Enter Date of birth" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Date of birth\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Date of Birth           |"
									<< "\n\t\t\t| Press 2 to Re-enter Date of Birth          |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|        DATE OF BIRTH HAS BEEN UPDATED       |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									parent[userVectLocation].dob = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 4:
						cout << "\n\t\t\t| Current Contact No: " << parent[userVectLocation].countNum;
						do {
							cout << "\n\t\t\t| Enter Contact Number" << setw(11) << "|: ";
							cin >> tempContactNo;
							if (to_string(tempContactNo).length() < 9 || to_string(tempContactNo).length() > 10)
								cout << "\n\t\t\tInvalid input, Please Enter your contact number.\n";
							else {
								cin.ignore();
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Confirm Contact No              |"
										<< "\n\t\t\t| Press 2 to Re-enter Contact No             |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|        CONTACT NO. HAS BEEN UPDATED         |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].countNum = tempContactNo;
										system("pause");
										cin.ignore();
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										cin.ignore();
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
							cin.ignore();
						} while (true);
						break;
					case 5:
						cout << "\n\t\t\t| Current Email: " << parent[userVectLocation].email;
						do {
							cout << "\n\t\t\t| Enter Email Address" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Email Address\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Confirm Email                   |"
										<< "\n\t\t\t| Press 2 to Re-enter Email                  |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|            EMAIL HAS BEEN UPDATED           |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].email = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 6:
						cout << "\n\t\t\t| Current Child's name: " << parent[userVectLocation].childFullName;
						do {
							cout << "\n\t\t\t| Enter Child's name" << setw(13) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Child's name\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Child's name                    |"
										<< "\n\t\t\t| Press 2 to Re-enter Child's name           |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|        CHILD'S NAME HAS BEEN UPDATED        |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].childFullName = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 7:
						cout << "\n\t\t\t| Current Child's Room Number: " << parent[userVectLocation].childRoomNum;
						do {
							cout << "\n\t\t\t| Enter Child's Room Number" << setw(6) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Child's Room Number\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Child's Room Number             |"
										<< "\n\t\t\t| Press 2 to Re-enter Child's Room Number    |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|     CHILD'S ROOM NUMBER HAS BEEN UPDATED    |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].childRoomNum = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 8:
						cout << "\n\t\t\t| Current Visa Card Number: " << parent[userVectLocation].visaCardNo;
						do {
							cout << "\n\t\t\t| Enter Visa Card Number" << setw(9) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Number\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Visa Card Number                |"
										<< "\n\t\t\t| Press 2 to Re-enter Visa Card Number       |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|      VISA CARD NUMBER HAS BEEN UPDATED      |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].visaCardNo = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 9:
						cout << "\n\t\t\t| Current Visa Card Expiry Date: " << parent[userVectLocation].visaCardExpiry;
						do {
							cout << "\n\t\t\t| Enter Visa Card Expiry Date |: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Expiry Date\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Visa Card Expiry Date           |"
										<< "\n\t\t\t| Press 2 to Re-enter Visa Card Expiry Date  |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|      VISA EXPIRY DATE HAS BEEN UPDATED      |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										parent[userVectLocation].visaCardExpiry = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 0:
						isTrue = false;
						break;
					default:
						cout << "\n\t\t\tInvalid input, Please try again\n\t\t\t";
						system("pause");
						break;
					}
					ofstream parentFile("Parent_file.csv", ios::out);
					//ADD HEADERS TO CSV
					parentFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
						<< "," << "CHILD_NAME" << "," << "ROOM_NUM" << "," << "VISA_NUM" << "," << "VISA_EXPIRY" << endl;
					for (int i = 0; i < parent.size(); i++) {
						parentFile << parent[i].parentID << "," << parent[i].fullName << "," << parent[i].gender << "," << parent[i].dob << "," << parent[i].countNum << ","
							<< parent[i].email << "," << parent[i].childFullName << "," << parent[i].childRoomNum << "," << parent[i].visaCardNo << ","
							<< parent[i].visaCardExpiry << endl;
					}
					parentFile.close();
				} while (isTrue);
			}
			else if (choice == 2) {
				isTrue2 = true;
				do {
					cout << "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Press 1 to Change Password                 |"
						<< "\n\t\t\t| Press 2 to exit                            |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Choose option: ";
					cin >> choice;
					cin.ignore();
					if (choice == 1) {
						//enter current password
						do {
							cout << parent[userVectLocation].login.password << endl;
							cout << "\n\t\t\t|--------------------------------------------|"
								<< "\n\t\t\t| Type: quit@ to exit from password          |"
								<< "\n\t\t\t|--------------------------------------------|"
								<< "\n\t\t\t| Enter current password: ";
							getline(cin, password);

							if (password == parent[userVectLocation].login.password)
								break;
							else if (password == "quit@") {
								isTrue2 = false;
								break;
							}
							else
								cout << "\n\t\t\tPassword did not match.. Please Try Again..\n";
						} while (true);

						//enter new password
						if (password != "quit@") {
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

								//verify password
								do {
									cout << "\t\t\t|Enter Verify Password" << setw(10) << "|: ";
									getline(cin, verifyPassword);

									if (verifyPassword == "")
										cout << "\n\t\t\tPassword did not match, Please try again\n";
									else
										break;
								} while (true);

								if (password != verifyPassword)
									cout << "\n\t\t\tPassword did not match please try again...\n";
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

									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t|   Password has been successfully changed   |"
										<< "\n\t\t\t|--------------------------------------------|";
									break;
								}
							} while (true);
						}
					}
					else if (choice == 2)
						isTrue2 = false;
					else
						cout << "\n\t\t\tInvalid input, Please Try Again\n\t\t\t";

					cout << "\n\t\t\t";
					system("pause");
				} while (isTrue2);
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "\n\t\t\tInvalid Input.. Please try again...\n\t\t\t";
				system("pause");
			}
		} while (true);
	}
	else {
		cout << "\n\t\t\t|--------------------------------------------|"
			<< "\n\t\t\t|               INVALID USER ID              |"
			<< "\n\t\t\t|               CANT FIND USER               |"
			<< "\n\t\t\t|--------------------------------------------|\n\t\t\t";
		system("pause");
	}
}

//Code by Jay
//This function is used to update Staff details
void updateStaffDetails(string userID) {
	vector<Staff> staff;
	vector<Login> login;
	int choice, userVectLocation = 0, tempContactNo;
	bool isTrue, isTrue2, isTrue3, isFound = true;
	string password, verifyPassword, tempData;

	staff = getAllStaffDetails();
	login = getAllLoginDetails();

	//get staff location in vector
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
			cout << "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t|                STAFF USER                  |"
				<< "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t| Press 1 to update Staff Details            |"
				<< "\n\t\t\t| Press 2 to change password                 |"
				<< "\n\t\t\t| Press 3 to exit                            |"
				<< "\n\t\t\t|--------------------------------------------|"
				<< "\n\t\t\t| Choose option: ";
			cin >> choice;
			if (choice == 1) {
				isTrue = true;
				do {
					system("cls");
					cout << "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t|             UPDATE STAFF DETAILS           |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Press 1 to update Staff Name               |"
						<< "\n\t\t\t| Press 2 to update Staff Gender             |"
						<< "\n\t\t\t| Press 3 to update Staff Date of Birth      |"
						<< "\n\t\t\t| Press 4 to update Staff Contact Number     |"
						<< "\n\t\t\t| Press 5 to update Staff Email              |"
						<< "\n\t\t\t| Press 6 to update Staff Visa Card No.      |"
						<< "\n\t\t\t| Press 7 to update Staff Visa Expiry Date   |"
						<< "\n\t\t\t| Press 0 to exit                            |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Choose option: ";
					cin >> choice;
					cin.ignore();

					switch (choice) {
						cout << "\n\t\t\t|--------------------------------------------|"
							<< "\n\t\t\t|             UPDATE STAFF DETAILS           |"
							<< "\n\t\t\t|--------------------------------------------|";
					case 1:
						cout << "\n\t\t\t| Current Name: " << staff[userVectLocation].fullName;
						do {
							cout << "\n\t\t\t| Enter Full name" << setw(16) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid Input.. Please Enter your name..\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Name                    |"
									<< "\n\t\t\t| Press 2 to Re-enter Name                   |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								cin.ignore();
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|            NAME HAS BEEN UPDATED            |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									staff[userVectLocation].fullName = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 2:
						cout << "\n\t\t\t| Current Gender: " << staff[userVectLocation].gender;
						do {
							cout << "\n\t\t\t| Enter Gender" << setw(19) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your gender\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Gender                  |"
									<< "\n\t\t\t| Press 2 to Re-enter Gender                 |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|           GENDER HAS BEEN UPDATED           |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									staff[userVectLocation].gender = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 3:
						cout << "\n\t\t\t| Current Date of Birth: " << staff[userVectLocation].dob;
						do {
							cout << "\n\t\t\t| Enter Date of birth" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Date of birth\n";
							else {
								cout << "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Press 1 to Confirm Date of Birth           |"
									<< "\n\t\t\t| Press 2 to Re-enter Date of Birth          |"
									<< "\n\t\t\t| Press 3 to exit                            |"
									<< "\n\t\t\t|--------------------------------------------|"
									<< "\n\t\t\t| Choose option: ";
								cin >> choice;
								if (choice == 1) {
									cout << "\n\t\t\t|---------------------------------------------|"
										<< "\n\t\t\t|        DATE OF BIRTH HAS BEEN UPDATED       |"
										<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
									staff[userVectLocation].dob = tempData;
									system("pause");
									break;
								}
								else if (choice == 2) {
									cout << "\n\t\t\t|---------------------------------------------|";
								}
								else if (choice == 3) {
									break;
								}
								else
									cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
							}
						} while (true);
						break;
					case 4:
						cout << "\n\t\t\t| Current Contact No: " << staff[userVectLocation].countNum;
						do {
							cout << "\n\t\t\t| Enter Contact Number" << setw(11) << "|: ";
							cin >> tempContactNo;
							if (to_string(tempContactNo).length() < 9 || to_string(tempContactNo).length() > 10)
								cout << "\n\t\t\tInvalid input, Please Enter your contact number.\n";
							else {
								cin.ignore();
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Confirm Contact No              |"
										<< "\n\t\t\t| Press 2 to Re-enter Contact No             |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|        CONTACT NO. HAS BEEN UPDATED         |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										staff[userVectLocation].countNum = tempContactNo;
										system("pause");
										cin.ignore();
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										cin.ignore();
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
							cin.ignore();
						} while (true);
						break;
					case 5:
						cout << "\n\t\t\t| Current Email: " << staff[userVectLocation].email;
						do {
							cout << "\n\t\t\t| Enter Email Address" << setw(12) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Email Address\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Confirm Email                   |"
										<< "\n\t\t\t| Press 2 to Re-enter Email                  |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|            EMAIL HAS BEEN UPDATED           |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										staff[userVectLocation].email = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 6:
						cout << "\n\t\t\t| Current Visa Card Number: " << staff[userVectLocation].visaCardNo;
						do {
							cout << "\n\t\t\t| Enter Visa Card Number" << setw(9) << "|: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Number\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Visa Card Number                |"
										<< "\n\t\t\t| Press 2 to Re-enter Visa Card Number       |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|      VISA CARD NUMBER HAS BEEN UPDATED      |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										staff[userVectLocation].visaCardNo = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 7:
						cout << "\n\t\t\t| Current Visa Card Expiry Date: " << staff[userVectLocation].visaCardExpiry;
						do {
							cout << "\n\t\t\t| Enter Visa Card Expiry Date |: ";
							getline(cin, tempData);
							if (tempData == "")
								cout << "\n\t\t\tInvalid input, Please Enter your Visa Card Expiry Date\n";
							else {
								{
									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Press 1 to Visa Card Expiry Date           |"
										<< "\n\t\t\t| Press 2 to Re-enter Visa Card Expiry Date  |"
										<< "\n\t\t\t| Press 3 to exit                            |"
										<< "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t| Choose option: ";
									cin >> choice;
									if (choice == 1) {
										cout << "\n\t\t\t|---------------------------------------------|"
											<< "\n\t\t\t|      VISA EXPIRY DATE HAS BEEN UPDATED      |"
											<< "\n\t\t\t|---------------------------------------------|\n\t\t\t";
										staff[userVectLocation].visaCardExpiry = tempData;
										system("pause");
										break;
									}
									else if (choice == 2) {
										cout << "\n\t\t\t|---------------------------------------------|";
									}
									else if (choice == 3) {
										break;
									}
									else
										cout << "\n\t\t\tInvalid Input.. Please Try Again..\n";
								}
							}
						} while (true);
						break;
					case 0:
						isTrue = false;
						break;
					default:
						cout << "\n\t\t\tInvalid input, Please try again\n\t\t\t";
						system("pause");
						break;
					}
					ofstream staffFile("Staff_file.csv", ios::out);
					//ADD HEADERS TO CSV
					staffFile << "LOGIN_ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT_NUM" << "," << "EMAIL"
						<< "," << "VISA_NUM" << "," << "VISA_EXPIRY" << endl;
					for (int i = 0; i < staff.size(); i++) {
						staffFile << staff[i].staffID << "," << staff[i].fullName << "," << staff[i].gender << "," << staff[i].dob << "," << staff[i].countNum << ","
							<< staff[i].email << "," << staff[i].visaCardNo << "," << staff[i].visaCardExpiry << endl;
					}
					staffFile.close();
				} while (isTrue);
			}
			else if (choice == 2) {
				isTrue2 = true;
				do {
					cout << "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Press 1 to Change Password                 |"
						<< "\n\t\t\t| Press 2 to exit                            |"
						<< "\n\t\t\t|--------------------------------------------|"
						<< "\n\t\t\t| Choose option: ";
					cin >> choice;
					cin.ignore();
					if (choice == 1) {
						//enter current password
						do {
							cout << staff[userVectLocation].login.password << endl;
							cout << "\n\t\t\t|--------------------------------------------|"
								<< "\n\t\t\t| Type: quit@ to exit from password          |"
								<< "\n\t\t\t|--------------------------------------------|"
								<< "\n\t\t\t| Enter current password: ";
							getline(cin, password);

							if (password == staff[userVectLocation].login.password)
								break;
							else if (password == "quit@") {
								isTrue2 = false;
								break;
							}
							else
								cout << "\n\t\t\tPassword did not match.. Please Try Again..\n";
						} while (true);

						//enter new password
						if (password != "quit@") {
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

								//verify password
								do {
									cout << "\t\t\t|Enter Verify Password" << setw(10) << "|: ";
									getline(cin, verifyPassword);

									if (verifyPassword == "")
										cout << "\n\t\t\tPassword did not match, Please try again\n";
									else
										break;
								} while (true);

								if (password != verifyPassword)
									cout << "\n\t\t\tPassword did not match please try again...\n";

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

									cout << "\n\t\t\t|--------------------------------------------|"
										<< "\n\t\t\t|   Password has been successfully changed   |"
										<< "\n\t\t\t|--------------------------------------------|";
									break;
								}
							} while (true);
						}
					}
					else if (choice == 2)
						isTrue2 = false;
					else
						cout << "\n\t\t\tInvalid input, Please Try Again\n\t\t\t";

					cout << "\n\t\t\t";
					system("pause");
				} while (isTrue2);
			}
			else if (choice == 3) {
				break;
			}
			else {
				cout << "\n\t\t\tInvalid Input.. Please try again...\n\t\t\t";
				system("pause");
			}
		} while (true);
	}
	else {
		cout << "\n\t\t\t|--------------------------------------------|"
			<< "\n\t\t\t|               INVALID USER ID              |"
			<< "\n\t\t\t|               CANT FIND USER               |"
			<< "\n\t\t\t|--------------------------------------------|\n\t\t\t";
		system("pause");
	}
}

// Code by Jakob
// this function shows the different options for the admin once they've logged in.
void adminScreen() {
	system("cls");
	int choice;
	bool isTrue = true;

	do {
		system("cls");
		cout << "\n\t\t\t|---------------------------|";
		cout << "\n\t\t\t|        ADMIN SCREEN       |";
		cout << "\n\t\t\t|---------------------------|";
		cout << "\n\t\t\t|1. Menu Update             |";
		cout << "\n\t\t\t|2. Daily Order Report      |";
		cout << "\n\t\t\t|3. Weekly Sales Report     |";
		cout << "\n\t\t\t|4. Pending Payment Report  |";
		cout << "\n\t\t\t|5. Weekly Complaint        |";
		cout << "\n\t\t\t|6. Exit                    |";
		cout << "\n\t\t\t|---------------------------|";
		cout << "\n\t\t\t Enter option: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\n\t\t\tMenu update";
			cout << "\n\t\t\t";
			system("pause");
			break;
		case 2:
			cout << "\n\t\t\tDaily Order Report";
			cout << "\n\t\t\t";
			system("pause");
			break;
		case 3:
			cout << "\n\t\t\tWeekly sales report";
			cout << "\n\t\t\t";
			system("pause");
			break;
		case 4: // Written by Jakob
			cout << "\n\t\t\tPending payment report";
			cout << "\n\t\t\t";
			system("pause");
			break;
		case 5:
			cout << "\n\t\t\tWeekly Complaint";
			cout << "\n\t\t\t";
			system("pause");
			break;
		case 6:
			isTrue = false;
			break;
		}
	} while (isTrue);
}
