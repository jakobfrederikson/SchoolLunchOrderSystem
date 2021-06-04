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

int main()
{
void printMenuList();

int main()
{
    printMenuList();

    return 0;
}

void printMenuList() {
    int choice;

    cout << "Enter option: ";
    cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }
}