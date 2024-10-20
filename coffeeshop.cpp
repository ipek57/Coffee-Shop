#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CUSTOMER {
    string name;
    string surname;
    int customerID;
    string favoriteCoffee;
};

void displayMenu() {
    cout << "---Welcome to the coffee shop system!---\n";
    cout << "1. Add new customer\n";
    cout << "2. Remove customer\n";
    cout << "3. Update customer's information\n";
    cout << "4. Display registered customers\n";
    cout << "5. Exit\n";
    cout << "Please choose an option: ";
}

void addCustomer(vector<CUSTOMER>& customers) {
    CUSTOMER newCustomer;
    cout << "Enter name: ";
    cin >> newCustomer.name;
    cout << "Enter surname: ";
    cin >> newCustomer.surname;
    cout << "Enter customer id: ";
    cin >> newCustomer.customerID;
    cout << "Enter favorite coffee: ";
    cin >> newCustomer.favoriteCoffee;

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].customerID == newCustomer.customerID) {
            cout << "Error! That id is already taken!";
            return;
        }
    }

    customers.push_back(newCustomer);
    cout << "Customer's information added to the system.\n";
}

void removeCustomer(vector<CUSTOMER>& customers) {
    int deleteID;
    cout << "Enter the id that you want to delete: ";
    cin >> deleteID;

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].customerID == deleteID) {
            customers.erase(customers.begin() + i);
            cout << "The customer's information deleted.\n";
            return;
        }
    }

    cout << "Error! The customer's id not found!\n";
}

void updateCustomer(vector<CUSTOMER>& customers) {
    int updateID;
    cout << "Enter the id that you want to update: ";
    cin >> updateID;

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].customerID == updateID) {
            cout << "Enter name: ";
            cin >> customers[i].name;
            cout << "Enter surname: ";
            cin >> customers[i].surname;
            cout << "Enter customer id: ";
            cin >> customers[i].customerID;
            cout << "Enter favorite coffee: ";
            cin >> customers[i].favoriteCoffee;
            cout << "The customer's information updated.\n";
            return;
        }
    }

    cout << "Error! ID not found!\n";
}

void displayCustomer(vector<CUSTOMER>& customers) {
    cout << "Customer list: \n";
    for (int i = 0; i < customers.size(); i++) {
        cout << customers[i].name << " - ";
        cout << customers[i].surname << " - ";
        cout << customers[i].customerID << " - ";
        cout << customers[i].favoriteCoffee << "\n";
    }
}

int main() {
    vector<CUSTOMER> customers;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer(customers);
            break;
        case 2:
            removeCustomer(customers);
            break;
        case 3:
            updateCustomer(customers);
            break;
        case 4:
            displayCustomer(customers);
            break;
        case 5:
            cout << "Exiting from the system...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
