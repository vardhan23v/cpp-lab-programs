# C++ Lab Programs 1–8: Code and Explanations

This README documents the eight programs supplied in the chat. The code is reproduced in formatted C++ blocks, followed by simple explanations and viva points.

## Contents
1. Bank Account
2. Complex Number: Function Overloading and Friend Functions
3. Time Addition: Objects as Arguments
4. Employee: Array of Objects
5. Constructors in a Derived Class
6. Constructor Overloading
7. Dynamic Constructor and String Concatenation
8. Hierarchical Inheritance

---

## 1. Bank Account

**Aim:** Read account details, deposit money, withdraw money, and display the balance.

```cpp
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
```

**Explanation**
- `BankAccount` is a class; `name`, `accno`, and `balance` are its data members.
- `read()` gets account details; `print()` displays them.
- `deposit()` adds the entered amount to `balance`.
- `withdraw()` subtracts the amount only if the balance is sufficient.
- `put_balance()` prints the updated balance.
- `BankAccount b1;` creates an object; calls such as `b1.deposit()` invoke its member functions.

**Viva:** A class groups data and functions. An object is an instance of a class. Members before `public:` are private by default.

---

## 2. Complex Number: Function Overloading and Friend Functions

**Aim:** Add an integer to a complex number or add two complex numbers using overloaded `ADD()` functions.

```cpp
#include <iostream>
using namespace std;

class COMPLEX
{
private:
    int r, i;

public:
    void read();
    void disp();
    friend COMPLEX ADD(int x, COMPLEX c);
    friend COMPLEX ADD(COMPLEX c1, COMPLEX c2);
};

void COMPLEX::read()
{
    cin >> r >> i;
}

void COMPLEX::disp()
{
    cout << r << "+" << i << "i";
}

COMPLEX ADD(int x, COMPLEX c)
{
    COMPLEX t;
    t.r = x + c.r;
    t.i = c.i;
    return t;
}

COMPLEX ADD(COMPLEX c1, COMPLEX c2)
{
    COMPLEX t;
    t.r = c1.r + c2.r;
    t.i = c1.i + c2.i;
    return t;
}

int main()
{
    COMPLEX c1, c2, c3, c4;
    int a;
    c1.read();
    c2.read();
    cin >> a;
    c3 = ADD(a, c2);
    c4 = ADD(c1, c2);
    c1.disp();
    c2.disp();
    c3.disp();
    c4.disp();
    return 0;
}
```

**Explanation**
- `r` is the real part and `i` is the imaginary part.
- `read()` inputs both parts; `disp()` prints them.
- `ADD(int x, COMPLEX c)` adds an integer to the real part and preserves the imaginary part.
- `ADD(COMPLEX c1, COMPLEX c2)` adds corresponding real and imaginary parts.
- The functions are declared `friend`, allowing them to access private members.
- The same function name with different parameter lists demonstrates **function overloading**.

**Viva:** A friend function is not a member function, but can access private/protected members. Return type alone cannot overload a function. The four `disp()` calls have no labels or line breaks between them, so their output appears joined.

---

## 3. Time Addition: Objects as Arguments

**Aim:** Add two times using a member function that accepts two `Time` objects.

```cpp
#include <iostream>
using namespace std;

class Time
{
    int hours, minutes;

public:
    void read(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    void put()
    {
        cout << hours << ":" << minutes;
    }

    void compute(Time t1, Time t2)
    {
        int h;
        h = (t1.minutes + t2.minutes) / 60;
        minutes = (t1.minutes + t2.minutes) % 60;
        hours = t1.hours + t2.hours + h;
    }
};

int main()
{
    Time t1, t2, t3;
    t1.read(4, 40);
    t2.read(4, 40);
    t3.compute(t1, t2);
    cout << "First Time: ";
    t1.put();
    cout << "\nSecond Time: ";
    t2.put();
    cout << "\nResult: ";
    t3.put();
    return 0;
}
```

**Explanation**
- `read(h, m)` initializes the object's hours and minutes.
- `compute(t1, t2)` receives two objects and stores their sum in the calling object, `t3`.
- Integer division by 60 calculates the extra hour from the combined minutes.
- `% 60` gives the remaining minutes.
- Example: `4:40 + 4:40 = 9:20`.

**Expected output**
```text
First Time: 4:40
Second Time: 4:40
Result: 9:20
```

**Viva:** This demonstrates passing objects as arguments. `%` is the modulus operator. The code assumes valid time values.

---

## 4. Employee: Array of Objects

**Aim:** Read and display details for multiple employees.

```cpp
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
```

**Explanation**
- `Employee` stores a name, employee number, and salary.
- `Employee e[10]` creates an array of 10 objects.
- The first loop reads each employee; the second prints each employee.
- Each `e[i]` is a separate object.

**Viva:** This demonstrates an array of objects. Enter `n` from 1 to 10, because the array has only 10 elements. `cin >> ename` reads a single word only.


---

## 5. Constructors in a Derived Class

**Aim:** Demonstrate parameterized base-class constructors and multiple inheritance.

```cpp
#include <iostream>
using namespace std;

class Alpha
{
protected:
    int n1;

public:
    Alpha(int x)
    {
        cout << "Alpha constructed" << endl;
        n1 = x;
    }

    void putAlpha()
    {
        cout << "n1: " << n1 << endl;
    }
};

class Beta
{
protected:
    int n2;

public:
    Beta(int x)
    {
        cout << "Beta Constructed" << endl;
        n2 = x;
    }

    void putBeta()
    {
        cout << "n2: " << n2 << endl;
    }
};

class Gama : public Alpha, public Beta
{
    int n3;

public:
    Gama(int x, int y, int z)
        : Alpha(x), Beta(y)
    {
        cout << "Gama Constructed" << endl;
        n3 = z;
    }

    void putGama()
    {
        cout << "n3: " << n3 << endl;
    }
};

int main()
{
    Gama g1(10, 20, 30);
    g1.putAlpha();
    g1.putBeta();
    g1.putGama();
    return 0;
}
```

**Explanation**
- `Alpha` and `Beta` are base classes; each has a parameterized constructor.
- `Gama` inherits from both classes, which is multiple inheritance.
- `: Alpha(x), Beta(y)` is a constructor initializer list that sends values to the base constructors.
- Construction order is `Alpha`, then `Beta`, then the body of `Gama`.
- The object stores `10`, `20`, and `30` in `n1`, `n2`, and `n3`.

**Expected output**
```text
Alpha constructed
Beta Constructed
Gama Constructed
n1: 10
n2: 20
n3: 30
```

**Viva:** A constructor initializes an object. `protected` members can be accessed by derived classes. Multiple inheritance means one derived class inherits from more than one base class.

---

## 6. Constructor Overloading

**Aim:** Demonstrate default, parameterized, copy, and default-argument constructors.

```cpp
#include <iostream>
using namespace std;

class Sample
{
    int i;
    char c;
    double d;

public:
    Sample()
    {
        i = 0;
        c = '\0';
        d = 0.0;
    }

    Sample(int x, char y, double z)
    {
        i = x;
        c = y;
        d = z;
    }

    Sample(Sample &s)
    {
        i = s.i;
        c = s.c;
        d = s.d;
    }

    Sample(int x, double z, char y = 's')
    {
        i = x;
        c = y;
        d = z;
    }

    void display()
    {
        cout << "i= " << i << endl;
        cout << "c= " << c << endl;
        cout << "f= " << d << endl;
    }
};

int main()
{
    Sample s1;
    cout << "S1:" << endl;
    s1.display();

    Sample s2(10, 'a', 5.6);
    cout << "S2:" << endl;
    s2.display();

    Sample s3(30, 4.54);
    cout << "S3:" << endl;
    s3.display();

    Sample s4(s2);
    cout << "S4:" << endl;
    s4.display();

    return 0;
}
```

**Explanation**
- `Sample()` is the default constructor; it initializes all members.
- `Sample(int, char, double)` is a parameterized constructor.
- `Sample(Sample &s)` is a copy constructor that copies values from another object.
- `Sample(int, double, char y = 's')` uses `'s'` when its third argument is omitted.
- `s1` uses the default constructor, `s2` the three-argument constructor, `s3` the default-argument constructor, and `s4` the copy constructor.

**Expected output**
```text
S1:
i= 0
c=
f= 0
S2:
i= 10
c= a
f= 5.6
S3:
i= 30
c= s
f= 4.54
S4:
i= 10
c= a
f= 5.6
```
The null character in `s1.c` is generally not visible when printed.

**Viva:** Constructor overloading means multiple constructors with different parameter lists. A copy constructor initializes an object from another object of the same class. A default argument is used when an argument is omitted.

---

## 7. Dynamic Constructor and String Concatenation

**Aim:** Allocate string memory dynamically and concatenate strings.

```cpp
#include <iostream>
#include <string.h>
using namespace std;

class String
{
    int length;
    char *name;

public:
    String()
    {
    }

    String(char s[])
    {
        length = strlen(s);
        name = new char[length + 1];
        strcpy(name, s);
    }

    void join(String A, String B)
    {
        length = A.length + B.length;
        name = new char[length + 1];

        strcpy(name, A.name);
        strcat(name, B.name);
    }

    void display()
    {
        cout << "name= " << name << endl;
    }
};

int main()
{
    String s1("wel");
    String s2("fare");

    cout << "s1:" << endl;
    s1.display();

    cout << "s2:" << endl;
    s2.display();

    String s3;
    s3.join(s1, s2);
    cout << "s3:" << endl;
    s3.display();

    String s4("come");
    cout << "s4:" << endl;
    s4.display();

    String s5;
    s5.join(s1, s4);
    cout << "s5:" << endl;
    s5.display();

    String s6("done");
    cout << "s6:" << endl;
    s6.display();

    String s7;
    s7.join(s1, s6);
    cout << "s7:" << endl;
    s7.display();

    return 0;
}
```

**Explanation**
- `char *name` points to dynamically allocated character storage.
- `strlen(s)` counts characters, excluding the null terminator.
- `new char[length + 1]` allocates enough space for the characters plus `\0`.
- `strcpy()` copies a string; `strcat()` appends one string to another.
- `join()` combines the two strings and stores the result in the object on which it is called.

**Expected output**
```text
s1:
name= wel
s2:
name= fare
s3:
name= welfare
s4:
name= come
s5:
name= welcome
s6:
name= done
s7:
name= weldone
```

**Viva and code caveats**
- A dynamic constructor allocates memory during object construction.
- The empty default constructor leaves `length` and `name` uninitialized. In this example, `s3`, `s5`, and `s7` are populated by `join()` before being displayed.
- The allocated memory is not released with `delete[]`, so this educational example leaks memory. A modern implementation should manage memory safely.
- `#include <string.h>` supplies the C-style string functions used here.

---

## 8. Hierarchical Inheritance

**Aim:** Use one base class (`student`) and two derived classes (`medical` and `engineering`).

```cpp
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
```

**Explanation**
- `student` stores the common fields `name`, `age`, and `usn`.
- `medical` and `engineering` both publicly inherit from `student`.
- `medical` adds `year`; `engineering` adds `sem` and `branch`.
- The base-class function `getstudent()` reads the common details. Each derived class has its own extra input function and `display()` function.
- `m1` is a medical student object; `e1` is an engineering student object.

**Viva:** Hierarchical inheritance means two or more derived classes inherit from one base class. `protected` members can be accessed in derived classes.

**Code caveats:** The supplied code declares `usn` as `int`; if the USN contains letters, a string or character array is more appropriate. `cin >> name` and `cin >> branch` only read one word.

---

## Last-Minute Viva Revision

| Program | Main concept | Key line or idea |
|---|---|---|
| 1 | Class and member functions | `balance = balance + amount` |
| 2 | Function overloading and friend functions | Two `ADD()` signatures |
| 3 | Objects as arguments | `t3.compute(t1, t2)` |
| 4 | Array of objects | `Employee e[10]` |
| 5 | Base/derived constructors; multiple inheritance | `: Alpha(x), Beta(y)` |
| 6 | Constructor overloading | Default, parameterized, copy, default argument |
| 7 | Dynamic memory and string operations | `new`, `strcpy()`, `strcat()` |
| 8 | Hierarchical inheritance | `medical` and `engineering` inherit from `student` |

**Study tip:** For each program, practise stating its aim, identifying its class and main function, and explaining the main concept in two or three sentences.
