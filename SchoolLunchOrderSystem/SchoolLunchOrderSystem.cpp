#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

// Structures written by Jakob, originally by Jay in an excel sheet
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
void registerUser(struct Staff staffRegister);
void registerParent();
string generateID(int);
bool checkUniqueID(int, string);
bool checkPassword(string);
bool checkUsername(string);
void loginScreen();
string checkLoginInput(string);

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
		case 1: // Case 1 written by Jakob
			printWeeklyMenu();
			break;
		case 2:
			printBulkDiscounts(); //Written by Jay
			break;
		case 3:
			printContactLocationDetails(); //Written by Jay
			break;
		case 4: // Case 4 written by Jakob
			loginRegistrationScreen();
			break;
		case 5:
			return 0; //written by Jay
		}
	} while (true);
}

void printBulkDiscounts() { // Jay's code
	cout << "\nBULK BOOKING DISCOUNTS\n"
		<< "**********************\n"
		<< "1. MONTHLY FOOD PASS \t\t 2. HALF MONTHLY FOOD PASS \t\t 3. WEEKLY FOOD PASS\n"
		<< "   ----------------- \t\t    ---------------------- \t\t    -----------------\n"
		<< "Pay for 30 days and \t\t Pay for 15 days and \t\t\t Pay for 7 days and \n"
		<< "receive a 15% discount. \t receive a 10% discount. \t\t receive a 5% discount.\n\n"
		<< "Without food pass: $150 \t Without food pass: $75 \t\t Without food pass: $35 \n"
		<< "with food pass: $127.5 \t\t with food pass: $67.50 \t\t with food pass: $33.25 \n"
		<< "Save $22.50 \t\t\t Save $7.50 \t\t\t\t Save $1.75\n";
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
	struct Staff staffRegister;

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
//This Function lets the user logged in
//Code by Jay
void loginScreen() {
	string username, pass, accPass;
	bool notExist = true;
	ifstream loginFile;

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

		if (pass != accPass)
			cout << "\n\t\t\tWrong password, Please try again...\n";
		else {
			cout << "\n\t\t\tYou have logged In\n";
			break;
		}
	} while (true);

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
		staffFile.open("staff_file.csv", ios::in);
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