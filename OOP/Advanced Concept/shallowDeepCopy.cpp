#include <bits/stdc++.h>
using namespace std;

class abc
{

public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    void print() const
    {

        cout << "value of x and y is" << x << " " << y << " " << *y << endl;
    }

    // dumped copy constructor
    // default copy constructor => shallow copy
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

// DEEP copy constructor

    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    ~abc()
    {
        delete y;
    }
};
int main()
{
    // abc a(1, 2);

    // a.print();

    // // shallow copy
    // abc b = a; // copy contructor
    // // dumped copy constructor
    // // ****************************
    // cout << "Printing b" << endl;
    // b.print();

    // *b.y = 20;
    // // *b.y = 20;
    // b.print();
    // a.print();

    abc *a = new abc(1,2);
    abc b = *a;
    delete a;

    b.print();

    return 0;
}