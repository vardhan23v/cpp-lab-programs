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
