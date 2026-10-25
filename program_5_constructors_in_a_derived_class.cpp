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
