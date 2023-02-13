#include "bank.h"
#include <iostream>
using namespace std;

int main() {
    Bank b;
    int choice;
    bool exit = false;
    bool loop = false;

    cout << "----------------------" << endl;
    cout << "BANK MANAGEMENT SYSTEM" << endl;
    cout << "----------------------" << endl << endl;

    while (!exit) {
    cout << "MENU" << endl;
    cout << "1. Add Account" << endl;
    cout << "2. View Account Information" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. View all Accounts" << endl;
    cout << "6. Modify Account" << endl;
    cout << "7. Remove Account" << endl;
    cout << "8. Exit" << endl;
    cout << "Select an option (1-8): ";
    cin >> choice;

    do {
    loop = false;
    switch (choice) {
        case 1: {
            int num;
            char* name = new char[50];
            double balance;
            cout << endl << endl;
            cout << "----CREATE AN ACCOUNT----" << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << "Enter the account holder name: ";
            cin.ignore();
            cin.getline(name, 49);
            cout << "Enter initial balance amount: ";
            cin >> balance;
            cout << endl;

            Account a(name, num, balance);
            b.AddAcc(a);

            cout << "Account Created Successfully!" << endl << endl << endl;
        }
            break;

        case 2: {
            int num;
            cout << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << endl;
            b.FindAcc(num).PrintAcc();
            cout << endl << endl;
        }
            break;

        case 3: {
            int num;
            double deposit;
            double newBalance;
            cout << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << endl;
            b.FindAcc(num).PrintAcc();
            cout << endl;
        
            cout << "Enter the amount to deposit: ";
            cin >> deposit;
            newBalance = b.FindAcc(num).GetBalance() + deposit;
            b.EditBalance(num, newBalance);
            cout << endl;
            cout << "Deposited Successfully!" << endl << endl << endl;
        }
            break;

        case 4: {
            int num;
            double withdraw;
            double newBalance;
            cout << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << endl;
            b.FindAcc(num).PrintAcc();
            cout << endl;
        
            cout << "Enter the amount to withdraw: ";
            cin >> withdraw;
            newBalance = b.FindAcc(num).GetBalance() - withdraw;
            b.EditBalance(num, newBalance);
            cout << endl;
            cout << "Withdrew Successfully!" << endl << endl << endl;
        }
            break;

        case 5: {
            cout << endl << endl;
            cout << b << endl << endl;
        }
            break;

        case 6: {
            int num;
            char* newname = new char[50];
            double newbalance;
            cout << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << endl;
            b.FindAcc(num).PrintAcc();
            cout << endl << endl;

            cout << "Enter Updated Information" << endl;
            cout << "-------------------------" << endl;
            cout << endl;

            cout << "New holder name: ";
            cin.ignore();
            cin.getline(newname, 49);
            b.EditName(num, newname);
            cout << "New balance: ";
            cin >> newbalance;
            b.EditBalance(num, newbalance);

            cout << endl;
            cout << "Account Updated Successfully!" << endl << endl << endl;
        }
            break;

        case 7: {
            int num;
            cout << endl << endl;
            cout << "Enter the account number: ";
            cin >> num;
            cout << endl;
            b.RemoveAcc(num);

            cout << "Account Removed" << endl << endl << endl;
        }
            break;

        case 8: {
            exit = true;
        }
            return 0;

        default:
            cout << "Invalid Entry. Please Try Again: ";
            cin >> choice;
            loop = true;
    }
    }
    while (loop);
    }
}