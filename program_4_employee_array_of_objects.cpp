#include <iostream>
using namespace std;

class Employee
{
    char ename[20];
    int eno;
    float esalary;

public:
    void read()
    {
        cout << "Enter employee name: ";
        cin >> ename;
        cout << "Enter employee number: ";
        cin >> eno;
        cout << "Enter employee salary: ";
        cin >> esalary;
    }

    void print()
    {
        cout << "\nEmployee Name: " << ename;
        cout << "\nEmployee Number: " << eno;
        cout << "\nEmployee Salary: " << esalary;
    }
};

int main()
{
    Employee e[10];
    int n, i;
    cout << "Enter number of employees: ";
    cin >> n;

    for (i = 0; i < n; i++)
        e[i].read();

    for (i = 0; i < n; i++)
        e[i].print();

    return 0;
}
