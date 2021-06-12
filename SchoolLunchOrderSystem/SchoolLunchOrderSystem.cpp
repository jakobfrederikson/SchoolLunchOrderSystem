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

// Structures written by Jakob, originally by Jay in an excel sheet
struct BulkPayment {
	int bulkID;
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
	struct Order;
	struct Login login;
	struct Complaint;
	struct BulkPayment bulk;
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
	string staffID;
	bool accountStatus;
	string fullName;
	string gender;
	string dob;
	int countNum;
	string visaCardNo;
	string visaCardExpiry;
	string email;
	struct Order;
	struct Login login;
	struct Complaint;
	struct BulkPayment bulk;
	struct Payment;

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

//code written by Jay
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
void chooseBulkOrder(int);
string getCurrentDate();
void createFoodMenuList();
void updateMenuList();
void getFoodMenuList(string(*)[10][3]);
void createFiles();

int main()
{
	// Code written by Jay
	createFiles();
	createFoodMenuList();
	return printMenuList();
}

// Code written by Jay
int printMenuList() {
	int choice;

	do {//loop written by Jay
		system("cls");
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
		case 1: // Written by Jakob
			printWeeklyMenu();
			break;
		case 2:
			printBulkDiscounts(); //Written by Jay
			break;
		case 3:
			printContactLocationDetails(); //Written by Jay
			break;
		case 4: // Written by Jakob
			loginRegistrationScreen();
			break;
		case 5:
			return 0; //written by Jay
		case 1234:
			adminLogin(); // Written by Jakob
			break;
		}
	} while (true);
}

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

	system("cls");
	cout << "1. Login\n";
	cout << "2. Register\n\n";
	cout << "Enter choice: ";
	cin >> choice;

	if (choice == 1) {
		loginScreen();
	}
	else if (choice == 2) {
		system("cls");
		cout << "\n\t\t\t|----------------------------|"
			<< "\n\t\t\t|      REGISTER ACCOUNT      |"
			<< "\n\t\t\t|----------------------------|";
		cout << "\n\t\t\t|1. Staff account            |";
		cout << "\n\t\t\t|2. Parent account           |";
		cout << "\n\t\t\t|                            |";
		cout << "\n\t\t\t|Enter choice                |: ";
		cin >> registerChoice;

		if (registerChoice == 1) {
			registerStaff();
		}
		else if (registerChoice == 2) {
			registerParent(); //code by jay
		}
		else {
			cout << "\nPlease enter a number relevant to the given menu.\n";
		}
	}
	else {
		cout << "\nPlease enter a number relevant to the given menu.\n";
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
		<< "\n\t\t\t|----------------------------|";

	do {
		loginFile.open("Login_file.csv", ios::in);
		cout << "\n\t\t\t|Username" << setw(8) << "|: ";
		getline(cin, username);

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
			cout << "\t\t\t|Enter Date of birth" << setw(12) << "|: ";
			getline(cin, parentRegister.dob);
			if (parentRegister.dob == "")
				cout << "\n\t\t\tInvalid input, Please Enter your Date of birth\n";
			else
				break;
		} while (true);

		do {
			cout << "\t\t\t|Enter Contact Number" << setw(11) << "|: ";
			cin >> parentRegister.countNum;
			cin.ignore();
			if (parentRegister.countNum != 0) {
				if (to_string(parentRegister.countNum).length() == 10)
					break;
			}
			else
				cout << "Invalid input, Please Enter your contact number.";
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
			cout << "\t\t\t|Enter Visa Card Expiry Date |: ";
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

				cout << "\n\t\t\tAccount has been successfully created\n";
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

	// Check if admin file exists.
	//bool file_check = doesFileExist(adminptr);
	//if (file_check == 0) {
	//	system("cls");
	//	cout << "\n\t\t\tADMIN FILE DOESN'T EXIST . . .";
	//	ofstream adminFile;
	//	adminFile.open("Admin_file.csv", ios::out);
	//	adminFile << "admin" << "," << "cs103" << endl; // ADMIN USERNAME AND PASSWORD HERE
	//	adminFile.close();
	//	cout << "\n\t\t\t";
	//	system("pause");
	//}

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
			cout << "\n\t\t\tYou have logged in with an admin account.\n\n\t\t\t";
			system("pause");
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
	struct Complaint complaint;
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
			// order food
			break;
		case 2: // Code by Jakob
			makeComplaint(accDetails);
			break;
		case 3:
			// bulk payment
			chooseBulkOrder(flag);
			break;
		case 4:
			// update details
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
				cout << "we are reading line " << lastLine << "\n";
				while (!readFile.eof()) {
					stringstream ss(line);

					try {
						complaint.complaintID = stoi(ss.str());  // convert stringstream to string and then to int
						complaint.complaintID = complaint.complaintID + 1;
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

	cout << "\n\t\t\tConfirm and place complaint? y/n: ";
	cin >> choice;

	do {
		compFile.open("Complaint_file.csv", ios::app);
		if (tolower(choice) == 'y') {
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

void chooseBulkOrder(int flag) {

	int choice;

	cout << "\nBULK BOOKING DISCOUNTS\n"
		<< "**********************\n"
		<< "1. GREEN FOOD PASS \t\t 2. BLUE FOOD PASS \t\t 3. RED FOOD PASS\n"
		<< "   ----------------- \t\t    ---------------- \t\t    ----------------\n"
		<< "   Pay for 30 days and \t\t    Pay for 15 days and \t    Pay for 7 days and \n"
		<< "   receive a 15% discount. \t    receive a 10% discount. \t    receive a 5% discount.\n\n"
		<< "   Without food pass: $150 \t    Without food pass: $75 \t    Without food pass: $35 \n"
		<< "   With food pass: $127.5 \t    With food pass: $67.50 \t    With food pass: $33.25 \n"
		<< "   Save $22.50 \t\t\t    Save $7.50 \t\t\t    Save $1.75\n\n";

	cout << "Enter choice or enter b to go back: ";
	system("pause");
}

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
		cout << endl;
		if (row == 4)
			cout << "\n\n";
	}
	system("pause");
}

void createFiles() {
	ifstream adminFile("Admin_file.csv");
	ifstream loginFile("Login_file.csv");
	ifstream parentFile("Parent_file.csv");
	ifstream staffFile("Staff_file.csv");
	ifstream compFile("Complaint_file.csv");
	ifstream orderFile("Order_file.csv");
	ifstream FoodMenu_file("FoodMenu_file.csv");


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
		loginFile << "PRIMARY KEY" << "," << "FOREIGN KEY" << "," << "USERNAME" << "," << "PASSWORD" << endl;
		loginFile.close();
	}

	if (!parentFile.good()) {
		ofstream parentFile;
		parentFile.open("Parent_file.csv", ios::out);
		parentFile << "LOGIN ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT NUM" << "," << "EMAIL"
			<< "," << "CHILD NAME" << "," << "ROOM NUM" << "," << "VISA NUM" << "," << "VISA EXPIRY" << endl;
		parentFile.close();
	}

	if (!staffFile.good()) {
		ofstream staffFile;
		staffFile.open("Staff_file.csv", ios::out);
		staffFile << "LOGIN ID" << "," << "NAME" << "," << "GENDER" << "," << "D.O.B" << "," << "CONTACT NUM" << "," << "EMAIL"
			<< "," << "VISA NUM" << "," << "VISA EXPIRY" << endl;
		staffFile.close();
	}

	if (!compFile.good()) {
		ofstream compFile;
		compFile.open("Complaint_file.csv", ios::out);
		compFile << "COMP_ID" << "," << "NAME" << "," << "DATE" << "," << "ITEM ORDERED" << "," << "DESC." << "," << "CONTACT NUM"
			<< "," << "EMAIL" << "," << "ACTION STATUS" << endl;
	}

	// order file, dont add child name or classroom number
	if (!orderFile.good()) {
		ofstream orderFile;
		orderFile.open("Order_file.csv", ios::out);
		orderFile << "ORDER NUM" << "," << "ORDER DATE" << "," << "MEAL NAME" << "," << "QUANTITY" << "," << "PRICE"
			<< "," << "PAYMENT STATUS" << "," << "DIETARY PREF" << endl;
	}

	if (!FoodMenu_file.good()) {
		createFoodMenuList();
	}
}