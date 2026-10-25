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
