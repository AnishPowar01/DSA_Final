#include <bits/stdc++.h>
using namespace std;
class Retangle
{
    double _length;
    double _breadth;

public:
    Retangle(double l, double b)
    {
        this->_length = l;
        this->_breadth = b;
    }

    double Area()
    {
        return this->_length * this->_breadth;
    }

    int compare(Retangle rectangle)
    {
        return this->Area() > rectangle.Area();
    }
};
int main()
{
    Retangle h1(3.0, 3.0);
    Retangle h2(4.0, 4.0);

    if (h1.compare(h2))
    {
        cout << "H2 is smaller";
    }
    else
    {
        cout << "h2 is bigger";
    }

    return 0;
}