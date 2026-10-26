# C++ Programming Lab – 8 Programs: Code, Explanations & Expected Output

This repository documents the eight standard C++ Programming Laboratory programs. Each program includes:
- **Aim & Concept:** Core objective and OOP concept being demonstrated.
- **Complete Formatted Source Code:** Clean, standard-compliant C++ code.
- **Detailed Step-by-Step Explanation:** Line-by-line / section-by-section breakdown of logic, syntax, and execution flow.
- **Sample Input & Expected Output:** Realistic terminal I/O walkthroughs so you know exactly what prints on screen.
- **Viva Questions & Key Takeaways:** Essential concepts frequently asked by examiners.

---

## Table of Contents
1. [Program 1: Bank Account (Class, Data Abstraction & Encapsulation)](#1-bank-account)
2. [Program 2: Function Overloading and Friend Function (`COMPLEX` Addition)](#2-complex-number-function-overloading-and-friend-functions)
3. [Program 3: Time Addition Using Objects as Arguments](#3-time-addition-objects-as-arguments)
4. [Program 4: Array of Objects – Employee Details](#4-employee-array-of-objects)
5. [Program 5: Multiple Inheritance (`Alpha`, `Beta`, `Gama` with Constructors)](#5-constructors-in-a-derived-class)
6. [Program 6: Constructor Overloading (Default, Parameterized, Copy & Default Arguments)](#6-constructor-overloading)
7. [Program 7: Dynamic Constructors and String Concatenation (`STRNG`)](#7-dynamic-constructor-and-string-concatenation)
8. [Program 8: Hierarchical Inheritance (`STUDENT` → `MEDICAL`, `ENGINEERING`)](#8-hierarchical-inheritance)
9. [How to Compile and Run](#how-to-compile-and-run)
10. [Quick Viva Cheat Sheet](#quick-viva-cheat-sheet)

---

## 1. Bank Account

**Aim:** Create a class to represent a bank account, read customer details, perform deposit and withdrawal operations with validation, and display the account balance.

### Source Code
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

### Detailed Explanation
1. **Class and Encapsulation:**
   - The class `BankAccount` bundles data (`name`, `accno`, `balance`) and the member functions that operate on that data.
   - By default in C++, members declared before any access specifier are **private**. Therefore, `name`, `accno`, and `balance` cannot be directly manipulated outside the class, preventing unauthorized modification (data hiding).
2. **Member Functions (`public:`):**
   - `read()`: Prompts the user to enter customer name, account number, and initial balance via `cin`.
   - `print()`: Displays the basic account details.
   - `deposit()`: Reads a positive deposit amount and increments `balance = balance + amount`.
   - `withdraw()`: Checks if requested withdrawal `amount <= balance`. If true, deducts the amount; otherwise, prints `"Insufficient balance"` leaving the balance untouched.
   - `put_balance()`: Outputs the current updated balance.
3. **Execution Flow in `main()`:**
   - `BankAccount b1;` creates an object of class `BankAccount` on the stack.
   - `b1.read()` collects initial data.
   - `b1.deposit()` deposits cash into `b1`.
   - `b1.withdraw()` tests validation and processes withdrawal.

### Sample Input & Expected Output
```text
Enter name: Rahul
Enter account number: 10245
Enter balance: 5000

Name: Rahul
Account Number: 10245
Balance: 5000
Enter amount to deposit: 2000

Current Balance: 7000
Enter amount to withdraw: 3000

Current Balance: 4000
```

*(If withdrawal exceeds balance, e.g., withdrawing 9000 when balance is 7000:)*
```text
Enter amount to withdraw: 9000

Insufficient balance
Current Balance: 7000
```

### Viva Points
- **What is Encapsulation?** Wrapping data members and member functions into a single unit (class).
- **Default access specifier:** Members in a C++ `class` are `private` by default, whereas in a `struct` they are `public`.
- **Limitation to note:** `cin >> name` stops reading at whitespace (e.g., entering "John Doe" only reads "John").

---

## 2. Complex Number: Function Overloading and Friend Functions

**Aim:** Perform addition of an integer to a complex number and addition of two complex numbers using non-member overloaded friend functions.

### Source Code
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

### Detailed Explanation
1. **Representing Complex Numbers:**
   - `r` represents the real component and `i` represents the imaginary component ($r + i\cdot \text{i}$).
   - `read()` inputs values for `r` and `i`; `disp()` prints in standard format `r+ii` (e.g., `3+4i`).
2. **Friend Functions:**
   - Normal non-member functions cannot access `private` members `r` and `i`.
   - The declarations `friend COMPLEX ADD(...)` inside `COMPLEX` grant the external `ADD` functions direct access to `r` and `i` of any `COMPLEX` instance.
3. **Function Overloading:**
   - Two functions share the identical name `ADD`, but possess distinct parameter signatures:
     - `ADD(int x, COMPLEX c)`: Adds scalar integer `x` to `c.r`, keeping `c.i` intact.
     - `ADD(COMPLEX c1, COMPLEX c2)`: Performs vector addition: `c1.r + c2.r` and `c1.i + c2.i`.
   - The compiler resolves which function to call at compile-time based on the types and order of supplied arguments (compile-time polymorphism).
4. **Execution Flow in `main()`:**
   - Reads `c1` (e.g., `2 3`), `c2` (e.g., `4 5`), and scalar integer `a` (e.g., `10`).
   - `c3 = ADD(a, c2)` yields $(10 + 4) + 5\text{i} = 14 + 5\text{i}$.
   - `c4 = ADD(c1, c2)` yields $(2 + 4) + (3 + 5)\text{i} = 6 + 8\text{i}$.
   - All four objects are displayed sequentially.

### Sample Input & Expected Output
**Sample Input:**
```text
2 3
4 5
10
```

**Expected Output:**
```text
2+3i4+5i14+5i6+8i
```
*(Note: Because the original `disp()` does not output spaces or newline characters (`\n`), the outputs appear concatenated together on the terminal screen).*

### Viva Points
- **What is a Friend Function?** A non-member function granted privileged access to `private` and `protected` class members.
- **Can a friend function be invoked with `.` operator?** No, it is not a member function. It is invoked like a regular C function: `ADD(a, b)`.
- **Rules of Function Overloading:** Functions must differ in their parameter count or argument types; differing only by return type is illegal.

---

## 3. Time Addition: Objects as Arguments

**Aim:** Add two time values (in hours and minutes) by passing objects as arguments to a member function and handling the minutes-to-hours carryover.

### Source Code
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

### Detailed Explanation
1. **Data Members:**
   - `hours` and `minutes` represent time.
2. **Passing Objects as Arguments:**
   - In `compute(Time t1, Time t2)`, two objects of type `Time` are passed **by value**.
   - Inside `compute`, `t1.minutes` and `t2.minutes` are accessed directly since member functions of a class can access private members of any object of the same class.
3. **Carryover Arithmetic Logic:**
   - `(t1.minutes + t2.minutes) / 60` calculates how many full hours are contributed by total minutes (integer division).
     - Example: $40 + 40 = 80 \implies 80 / 60 = 1$ hour.
   - `(t1.minutes + t2.minutes) % 60` calculates remaining minutes using modulus:
     - Example: $80 \% 60 = 20$ minutes.
   - `hours = t1.hours + t2.hours + h` sums the base hours plus the carried hour:
     - Example: $4 + 4 + 1 = 9$ hours.
   - The result is stored into the calling object (`t3`'s `hours` and `minutes`).

### Expected Output
```text
First Time: 4:40
Second Time: 4:40
Result: 9:20
```

### Viva Points
- **What is Pass by Value for Objects?** Copies of `t1` and `t2` are passed into `compute()`. Changes made to parameters inside the function do not affect the original arguments in caller.
- **Difference between `/` and `%`:** `/` yields the integer quotient (carried hours), while `%` yields the remainder (leftover minutes).

---

## 4. Employee: Array of Objects

**Aim:** Define an `Employee` class and manage records for multiple employees using an array of objects.

### Source Code
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

### Detailed Explanation
1. **Class Design:**
   - Data members: `ename` (string/char array), `eno` (integer ID), and `esalary` (float salary).
   - Member functions `read()` and `print()` handle individual record input and formatted output.
2. **Array of Objects:**
   - `Employee e[10];` allocates contiguous memory for 10 distinct `Employee` objects.
   - Each element `e[i]` contains its own independent copy of `ename`, `eno`, and `esalary`.
3. **Loop Traversal:**
   - The user inputs `n` (the count of employees to process, up to 10).
   - The first `for` loop `(i = 0; i < n; i++)` calls `e[i].read()` to populate each record.
   - The second `for` loop `(i = 0; i < n; i++)` calls `e[i].print()` to display each record sequentially.

### Sample Input & Expected Output
**Sample Input:**
```text
Enter number of employees: 2
Enter employee name: Alice
Enter employee number: 101
Enter employee salary: 55000.50
Enter employee name: Bob
Enter employee number: 102
Enter employee salary: 62000.00
```

**Expected Output:**
```text
Employee Name: Alice
Employee Number: 101
Employee Salary: 55000.5
Employee Name: Bob
Employee Number: 102
Employee Salary: 62000
```

### Viva Points
- **What is an Array of Objects?** A collection of multiple objects of the same class stored in contiguous memory locations, indexed from `0` to `size - 1`.
- **Memory consumption:** Total memory = `number_of_elements * sizeof(Employee)`.
- **Boundary precaution:** Array size is fixed at `10`; entering $n > 10$ causes array index out-of-bounds (undefined behavior).

---

## 5. Constructors in a Derived Class

**Aim:** Demonstrate multiple inheritance and passing arguments from a derived class constructor to base class parameterized constructors using an initialization list.

### Source Code
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

### Detailed Explanation
1. **Multiple Inheritance Architecture:**
   - `Alpha` and `Beta` are two independent base classes, each holding a `protected` variable (`n1` and `n2`).
   - `class Gama : public Alpha, public Beta` inherits from both `Alpha` and `Beta`.
2. **Order of Constructor Invocation:**
   - In multiple inheritance, base class constructors are executed **in the order they are listed in the class derivation header**, NOT the order in the constructor initializer list:
     1. `Alpha(x)` is executed first (`cout << "Alpha constructed"`).
     2. `Beta(y)` is executed second (`cout << "Beta Constructed"`).
     3. Derived class constructor `Gama` body executes last (`cout << "Gama Constructed"`).
3. **Constructor Initializer List:**
   - Syntax: `: Alpha(x), Beta(y)` passes parameter `x` to `Alpha` and `y` to `Beta`.
   - `n3 = z;` initializes `Gama`'s own data member.
4. **Member Function Access:**
   - `g1.putAlpha()`, `g1.putBeta()`, and `g1.putGama()` display `n1: 10`, `n2: 20`, and `n3: 30`.

### Expected Output
```text
Alpha constructed
Beta Constructed
Gama Constructed
n1: 10
n2: 20
n3: 30
```

### Viva Points
- **What is Multiple Inheritance?** When a single derived class inherits from two or more base classes simultaneously.
- **Destructor execution order:** The reverse of constructor execution order (Derived `~Gama`, then Base `~Beta`, then Base `~Alpha`).
- **Protected Access Specifier:** Accessible within the defining class and all derived classes, but inaccessible to the outside world.

---

## 6. Constructor Overloading

**Aim:** Illustrate constructor overloading using default, parameterized, copy, and default-argument constructors within a single class.

### Source Code
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

### Detailed Explanation
1. **Concept of Constructor Overloading:**
   - Defining more than one constructor in the same class with different parameter types or counts.
2. **Breakdown of the 4 Constructors:**
   - **Default Constructor (`Sample()`):** Takes zero arguments; sets `i = 0`, `c = '\0'`, `d = 0.0`. Invoked by `Sample s1;`.
   - **Parameterized Constructor (`Sample(int, char, double)`):** Explicitly initializes all three fields with passed arguments `10`, `'a'`, `5.6`. Invoked by `Sample s2(10, 'a', 5.6);`.
   - **Default-Argument Constructor (`Sample(int x, double z, char y = 's')`):** The third parameter `y` has a default value `'s'`. When invoked with only two arguments `Sample s3(30, 4.54);`, `y` automatically defaults to `'s'`.
   - **Copy Constructor (`Sample(Sample &s)`):** Accepts a reference to an existing object of the same class. Invoked by `Sample s4(s2);`, which clones all member values from `s2` into `s4`.
3. **Display:**
   - Notice that for `s1`, `c` is initialized to the null character `'\0'`, which prints as blank/non-printable on the terminal.

### Expected Output
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

### Viva Points
- **Why pass by reference in copy constructor (`Sample &s`)?** If passed by value (`Sample s`), it would require another call to the copy constructor to copy the argument, creating infinite recursion.
- **What is a Default Argument?** A default value specified in function/constructor parameter list that is used if the caller omits that parameter.

---

## 7. Dynamic Constructor and String Concatenation

**Aim:** Demonstrate dynamic memory allocation inside constructors (`new` operator) and perform string concatenation.

### Source Code
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

### Detailed Explanation
1. **Dynamic Constructor Concept:**
   - A dynamic constructor allocates memory from free store (heap) dynamically using the `new` operator at runtime when an object is created.
   - `char *name` is a pointer to dynamically allocated character storage.
2. **Length and Null Termination:**
   - `strlen(s)` computes the character length excluding the null terminator `'\0'`.
   - `new char[length + 1]` reserves additional 1 byte specifically to store the null terminator `'\0'`.
   - `strcpy(name, s)` copies the string contents into the allocated buffer.
3. **The `join()` Function:**
   - Takes two `String` objects `A` and `B`.
   - Total length is computed: `A.length + B.length`.
   - Allocates new heap memory: `name = new char[length + 1]`.
   - Copies `A.name` using `strcpy` and appends `B.name` using `strcat`.
4. **Program Flow:**
   - `s1` = `"wel"`, `s2` = `"fare"` $\implies$ `s3` becomes `"welfare"`.
   - `s1` = `"wel"`, `s4` = `"come"` $\implies$ `s5` becomes `"welcome"`.
   - `s1` = `"wel"`, `s6` = `"done"` $\implies$ `s7` becomes `"weldone"`.

### Expected Output
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

### Viva Points & Memory Management
- **What is `new` and `delete[]`?** `new` allocates dynamic heap memory; `delete[]` deallocates array memory.
- **Good practice:** A class utilizing dynamic memory should implement a destructor (`~String() { delete[] name; }`) to prevent memory leaks, and a deep copy constructor.
- **Why `+ 1` in `new char[length + 1]`?** To hold the null-terminating character `'\0'`, which marks the end of C-style strings.

---

## 8. Hierarchical Inheritance

**Aim:** Demonstrate hierarchical inheritance where a single base class (`student`) is inherited by multiple derived classes (`medical` and `engineering`).

### Source Code
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

### Detailed Explanation
1. **Hierarchical Inheritance Architecture:**
   - One common base class (`student`) serves as the parent for two separate derived classes (`medical` and `engineering`).
   - ```
             [ student ]  (Base)
             /         \
            /           \
     [ medical ]    [ engineering ] (Derived)
     ```
2. **Code Reusability:**
   - Properties common to every student (`name`, `age`, `usn`) and the method to input them (`getstudent()`) are written once inside `student`.
   - Both `medical` and `engineering` inherit these members without redundant code duplication.
3. **Specialization:**
   - `medical` adds specialization member `year` and method `getmedical()`.
   - `engineering` adds specialization members `sem` and `branch` and method `getengineering()`.
4. **Protected Members:**
   - `name`, `age`, and `usn` are `protected` in `student`, which allows derived classes `medical` and `engineering` to directly print them in their respective `display()` functions.

### Sample Input & Expected Output
**Sample Input:**
```text
Arun
21
101
3
Kavya
19
205
4
CSE
```

**Expected Output:**
```text
Enter medical student details
Enter name
Enter age
Enter usn
Enter year
Medical student details:
Name: Arun
Age: 21
USN: 101
Year: 3
Enter engineering student details
Enter name
Enter age
Enter usn
Enter sem
Enter branch
Engineering student details:
Name: Kavya
Age: 19
USN: 205
Semester: 4
Branch: CSE
```

### Viva Points
- **What is Hierarchical Inheritance?** An inheritance model where multiple derived classes inherit from a single common base class.
- **Why use `protected` instead of `private`?** Private members of a base class are not accessible inside derived class member functions; protected members remain accessible to derived classes while staying private to outside code.

---

## How to Compile and Run

All programs can be compiled and executed using any standard C++ compiler, such as `g++` or `clang++`.

### General Instructions
```bash
# Compile any program
g++ -std=c++11 <filename>.cpp -o <executable_name>

# Execute
./<executable_name>
```

### Run Commands for Each Program
1. **Program 1: Bank Account**
   ```bash
   g++ program_1_bank_account.cpp -o program_1 && ./program_1
   ```
2. **Program 2: Complex Number Addition (Friend Functions)**
   ```bash
   g++ program_2_complex_number_function_overloading_and_friend_functions.cpp -o program_2 && ./program_2
   ```
3. **Program 3: Time Addition (Objects as Arguments)**
   ```bash
   g++ program_3_time_addition_objects_as_arguments.cpp -o program_3 && ./program_3
   ```
4. **Program 4: Employee Database (Array of Objects)**
   ```bash
   g++ program_4_employee_array_of_objects.cpp -o program_4 && ./program_4
   ```
5. **Program 5: Constructors in Derived Classes (Multiple Inheritance)**
   ```bash
   g++ program_5_constructors_in_a_derived_class.cpp -o program_5 && ./program_5
   ```
6. **Program 6: Constructor Overloading**
   ```bash
   g++ program_6_constructor_overloading.cpp -o program_6 && ./program_6
   ```
7. **Program 7: Dynamic Constructor and String Concatenation**
   ```bash
   g++ program_7_dynamic_constructor_and_string_concatenation.cpp -o program_7 && ./program_7
   ```
8. **Program 8: Hierarchical Inheritance**
   ```bash
   g++ program_8_hierarchical_inheritance.cpp -o program_8 && ./program_8
   ```

---

## Quick Viva Cheat Sheet

| Program | Core Concept | Key Syntax / Mechanism | Common Viva Question |
|---|---|---|---|
| **1. Bank Account** | Data Encapsulation & Abstraction | `class` with `private` members and `public` methods | Why are data members kept private? (Data security) |
| **2. Complex Addition** | Friend Functions & Function Overloading | `friend COMPLEX ADD(...)` | Why is friend function used? (Access private data without member semantics) |
| **3. Time Addition** | Objects as Arguments & Modulus Math | `t3.compute(t1, t2)` with `/ 60` and `% 60` | What is pass-by-value vs pass-by-reference? |
| **4. Employee** | Array of Objects | `Employee e[10];` in loops | How is memory allocated for an array of objects? |
| **5. Derived Constructors** | Multiple Inheritance & Init Lists | `Gama(...) : Alpha(x), Beta(y)` | What is the constructor execution order in multiple inheritance? |
| **6. Overloading Constructors** | Default, Parameterized, Copy, Default Args | `Sample(Sample &s)`, `char y = 's'` | Why must copy constructor parameter be a reference? |
| **7. Dynamic Constructor** | Dynamic Memory (`new`) & String Ops | `name = new char[len + 1];` | What happens if you forget `+ 1` in `new char[len + 1]`? |
| **8. Student Hierarchy** | Hierarchical Inheritance | `medical : public student`, `engineering : public student` | What is the difference between hierarchical and multiple inheritance? |

---


