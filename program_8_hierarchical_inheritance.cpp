#include <iostream>
using namespace std;

class student
{
protected:
    char name[30];
    int age;
    int usn;

public:
    void getstudent()
    {
        cout << "Enter name" << endl;
        cin >> name;

        cout << "Enter age" << endl;
        cin >> age;

        cout << "Enter usn" << endl;
        cin >> usn;
    }
};

class medical : public student
{
    int year;

public:
    void getmedical()
    {
        cout << "Enter year" << endl;
        cin >> year;
    }

    void display()
    {
        cout << "Medical student details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "USN: " << usn << endl;
        cout << "Year: " << year << endl;
    }
};

class engineering : public student
{
    int sem;
    char branch[30];

public:
    void getengineering()
    {
        cout << "Enter sem" << endl;
        cin >> sem;

        cout << "Enter branch" << endl;
        cin >> branch;
    }

    void display()
    {
        cout << "Engineering student details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "USN: " << usn << endl;
        cout << "Semester: " << sem << endl;
        cout << "Branch: " << branch << endl;
    }
};

int main()
{
    medical m1;
    cout << "Enter medical student details" << endl;
    m1.getstudent();
    m1.getmedical();
    m1.display();

    engineering e1;
    cout << "Enter engineering student details" << endl;
    e1.getstudent();
    e1.getengineering();
    e1.display();

    return 0;
}
