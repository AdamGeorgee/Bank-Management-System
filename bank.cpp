#include "bank.h"
#include <iostream>
#include <cstring>
using namespace std;

//Account Class
Account::Account() {
    Name = new char[1];
    Name[0] = '\0';
    accNum = 0;
    Balance = 0;
}

Account::~Account() {
    delete [] Name;
}

Account::Account(const Account& a) {
    SetName(a.Name);
    SetAccNum(a.accNum);
    SetBalance(a.Balance);
}

void Account::operator=(const Account& a) {
    SetName(a.Name);
    SetAccNum(a.accNum);
    SetBalance(a.Balance);
}

Account::Account(const char* name, int num, double balance) {
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
    accNum = num;
    Balance = balance;
}

const char* Account::GetName() const{
    return Name;
}

int Account::GetAccNum() {
    return accNum;
}

double Account::GetBalance() {
    return Balance;
}

void Account::SetName(const char* name) {
    Name = new char[strlen(name) + 1];
    strcpy(Name, name);
}

void Account::SetAccNum(int num) {
    accNum = num;
}

void Account::SetBalance(double balance) {
    Balance = balance;
}

void Account::PrintAcc() {
    cout << "----ACCOUNT INFORMATION----" << endl;
    cout << endl;
    cout << "Account No.: " << accNum << endl;
    cout << "Account Holder Name: " << Name << endl;
    cout << "Balance: $" << Balance << endl;
}


//Bank Class
Bank::Bank() {
    currSize = 0;
    maxSize = 5;
    accList = new Account[5];
}

Bank::~Bank() {
    delete [] accList;
}

Account& Bank::FindAcc(int num) {
    for (int i = 0; i < currSize; i++) {
        if (num == accList[i].GetAccNum()) {
            return accList[i];
        }
    }
}

void Bank::EditName(int accnum, const char* n) {
    for (int i = 0; i < currSize; i++) {
        if (accnum == accList[i].GetAccNum()) {
            accList[i].SetName(n);
        }
    }
}

void Bank::EditBalance(int accnum, double newBalance) {
    for (int i = 0; i < currSize; i++) {
        if (accnum == accList[i].GetAccNum()) {
            accList[i].SetBalance(newBalance);
        }
    }
}

void Bank::Grow() {
    maxSize++;

    Account* tmp = new Account[maxSize];
    for (int i = 0; i < currSize; i++) {
        tmp[i] = accList[i];
    }
    delete [] accList;
    accList = tmp;
}

void Bank::AddAcc(const Account& a) {
    accList[currSize++] = a;

    if (currSize == maxSize) {
        Grow();
    }
}

void Bank::RemoveAcc(int accnum) {
    for (int i = 0; i < currSize; i++) {
        if (accnum == accList[i].GetAccNum()) {
            for (int j = i; j < currSize; j++) {
                accList[j] = accList[j+1];
            }
            currSize--;
        }
    }
}

ostream& operator<<(ostream& output, const Bank& list) {
    output << "----ALL RECORDED ACCOUNTS----" << endl;
    output << endl;
    for (int i = 0; i < list.currSize; i++) {
        output << i + 1 << ".) Account No.: " << list.accList[i].GetAccNum() << ", Name: " << list.accList[i].GetName() << ", Balance: $" << list.accList[i].GetBalance() << endl;
    }
    return output;
}
