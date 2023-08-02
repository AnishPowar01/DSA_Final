#include <bits/stdc++.h>
using namespace std;
class dard
{
public:
    static int x, y;

  static void print() 
    {
        // hidden parameter is passed or we can say pointer is passed konow as this pointer;
        // it denote the particular instant of object
        // cout<<this<<endl;
        cout << x << " " << y << " " << endl;
    }
};

int dard::x;
int dard::y;

int main()
{
    // static variable are the varibale that going to share memory with all class instances...
    dard obj1;
    obj1.x = 1;
    obj1.y = 2;

    // obj1.print();
    dard::print();

    dard obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj2.print();


    obj1.print();

    

    // obj2.print();
    return 0;
}