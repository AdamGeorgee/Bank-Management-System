#include <iostream>
using namespace std;

class Account {
    public:
        Account();
        ~Account();
        Account(const Account&);
        void operator=(const Account&);
        Account(const char*, int, double);

        const char* GetName() const;
        int GetAccNum();
        double GetBalance();
        void SetName(const char*);
        void SetAccNum(int);
        void SetBalance(double);

        void PrintAcc();

    private:
        char* Name;
        int accNum;
        double Balance;
};

class Bank {
    public:
        Bank();
        ~Bank();

        Account& FindAcc(int);
        void EditName(int, const char*);
        void EditBalance(int, double);
        void Grow();
        void AddAcc(const Account&);
        void RemoveAcc(int);

        friend ostream& operator<<(ostream&, const Bank&);

    private:
        Account* accList;
        int currSize;
        int maxSize;
};
