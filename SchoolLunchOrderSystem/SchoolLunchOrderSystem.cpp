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

	BulkPayment(int defBulkID = 0) {
		bulkID = defBulkID;
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
int generateComplaintNum();
int writeComplaintToFile(vector<string>, struct Complaint);
void chooseBulkOrder(int);
string getCurrentDate();

int main()
{
	// Code written by Jay
	//createFiles();
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

void printWeeklyMenu() { // Code written by Jakob
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

	string getch;
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

		cout << "\t\t\t|Enter Contact Number" << setw(11) << "|: ";
		cin >> parentRegister.countNum;
		cin.ignore();

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
	bool file_check = doesFileExist(adminptr);
	if (file_check == 0) {
		system("cls");
		cout << "\n\t\t\tADMIN FILE DOESN'T EXIST . . .";
		ofstream adminFile;
		adminFile.open("Admin_file.csv", ios::out);
		adminFile << "admin" << "," << "cs103" << endl; // ADMIN USERNAME AND PASSWORD HERE
		adminFile.close();
		cout << "\n\t\t\t";
		system("pause");
	}

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
			if (tempStr == userID) { // Once 
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
			
		case 2: // Code by Jakob
			makeComplaint(accDetails);
			break;
		case 3:
			// bulk payment
			chooseBulkOrder(flag);
		case 4:
			// update details
		case 5:
			printMenuList();
		default:
			cout << "\n\t\t\tPlease enter a number relevant to the menu.";
		}
	} while (true);
}

// code by jakob
// Function allows user to write a complaint about an order.
void makeComplaint(vector<string> accDetails) {
	system("cls");
	int writeFile;
	struct Complaint complaint;
	string date = getCurrentDate();

	complaint.complaintID = generateComplaintNum(); // could generate this by reading the complaint file 
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

	writeFile = writeComplaintToFile(accDetails, complaint);
	if (writeFile == 0) {
		cout << "\n\t\t\tError: Could not open Complaint_file.csv";
	}
	cout << "\n\t\t\t";
	system("pause");
}

// Code by Jakob
// Generates random number between 1-1000 for a complaint id.
// Testing purposes only at the moment. Will potentially generate an id based on the complaint file later on.
int generateComplaintNum() {
	int randNum;
	srand(time(0));
	randNum = rand() % 999 + 1;
	return randNum;
}

// Code by Jakob
// Writes complaint details to the Complaint_file.csv
int writeComplaintToFile(vector<string>accDetails, struct Complaint complaint) {
	ofstream compFile;
	int fileStatus;

	string date = getCurrentDate();

	compFile.open("Complaint_file.csv", ios::app);

	if (compFile.is_open() == true) {
		// accDetails[1] = Person Name
		// accDetails[4] = Contact Number
		// accDetails[5] = Email
		compFile << complaint.complaintID << "," << accDetails[1] << "," << date << "," << "item ordered" << ","
			<< complaint.complaintDescription << "," << accDetails[4] << "," << accDetails[5] << "," << complaint.actionStatus << endl;
		return 1;
	}
	else {
		return 0;
	}

	compFile.close();
}

void chooseBulkOrder(int flag) {

	int choice;

	cout << "\nBULK BOOKING DISCOUNTS\n"
		<< "**********************\n"
		<< "1. GOLD FOOD PASS \t\t 2. SILVER FOOD PASS \t\t 3. COPPER FOOD PASS\n"
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