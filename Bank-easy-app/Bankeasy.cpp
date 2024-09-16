#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance; 

public:
    // Constructor 
    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: $" << amount << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw function // 
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
        }
        else {
            cout << "Invalid or insufficient funds for withdrawal!" << endl;
        }
    }

    // Display account details // عرض معلومات الحساب
    void displayAccountInfo() {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    int choice, accNum;
    string name;
    double initialDeposit, amount;

    cout << "--------------------------------- Welcome to the Bank Management System! ----------------------------------" << endl;

    // Create account
    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter initial deposit amount: $";
    cin >> initialDeposit;

    BankAccount myAccount(name, accNum, initialDeposit);

    do {
        cout << "\n--------------------------------------------- Menu ----------------------------------------------------------:\n";
        cout << "1. Display account information\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myAccount.displayAccountInfo();
            break;
        case 2:
            cout << "Enter deposit amount: $";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 3:
            cout << "Enter withdrawal amount: $";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 4:
            cout << "Thank you for using the Bank Management System!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}