#include <iostream>
using namespace std;

class sample
{
    int i;
    char c;
    float f;

public:
    sample()
    {
        i = 0;
        c = '\0';
        f = 0.0;
    }

    sample(int x, char y, float z)
    {
        i = x;
        c = y;
        f = z;
    }

    sample(sample &s)
    {
        i = s.i;
        c = s.c;
        f = s.f;
    }

    sample(int x, float z, char y = 's')
    {
        i = x;
        c = y;
        f = z;
    }

    void display()
    {
        cout << "i= " << i << endl;
        cout << "c= " << c << endl;
        cout << "f= " << f << endl;
    }
};

int main()
{
    sample s1;
    cout << "S1:" << endl;
    s1.display();

    sample s2(10, 'a', 5.6);
    cout << "S2:" << endl;
    s2.display();

    sample s3(30, 4.54);
    cout << "S3:" << endl;
    s3.display();

    sample s4(s2);
    cout << "S4:" << endl;
    s4.display();

    return 0;
}
