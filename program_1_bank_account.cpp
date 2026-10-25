#include <iostream>
using namespace std;

class BankAccount
{
    char name[20];
    int accno;
    int balance;

public:
    void read()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accno;
        cout << "Enter balance: ";
        cin >> balance;
    }

    void print()
    {
        cout << "\nName: " << name;
        cout << "\nAccount Number: " << accno;
        cout << "\nBalance: " << balance;
    }

    void deposit()
    {
        int amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        balance = balance + amount;
    }

    void withdraw()
    {
        int amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance)
            balance = balance - amount;
        else
            cout << "\nInsufficient balance";
    }

    void put_balance()
    {
        cout << "\nCurrent Balance: " << balance;
    }
};

int main()
{
    BankAccount b1;
    b1.read();
    b1.print();
    b1.deposit();
    b1.put_balance();
    b1.withdraw();
    b1.put_balance();
    return 0;
}
