#include<bits/stdc++.h>
using namespace std;

class A{
int _x;

public:
    A(int _val)
    {
        this->_x = _val;
    }

    int getX() const
    {
        return this->_x;
    }

    void set(int _val)
    {
        this->_x = _val;
    }

    friend class B;

    friend void print(const A &);
};


class B{
public:
    void print(const A&a)
    {
        // cout<<a.getX()<<endl;

        cout<<a._x;
    } 

};

void print(const A&a)
{
    cout<<a._x<<endl;
}
int main()
{
    A a(5);
    B b;
    b.print(a);
    return 0;
}