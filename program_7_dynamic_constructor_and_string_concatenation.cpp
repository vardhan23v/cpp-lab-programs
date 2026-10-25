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
