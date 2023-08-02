#include<bits/stdc++.h>
using namespace std;

class BOX{
private:
    int _widht;

    // BOX(int val)
    // {
    //     this->_widht = val;
    // }
    BOX(int _v) : _widht(_v){};

public:

    
    int get() const
    {
      return this->_widht;
    }

    void set(int val)
    {
        this->_widht = val;
    }

    friend class factory;

};


class factory{
private:
    int _counter;
public:
    BOX getBox(int _v)
    {
        return BOX(_v);
    }


};

int main()
{
    // BOX bx(6);
    // cout<<bx.get();
    // bx.set(10);
    // cout<<bx.get();

    factory fac;
   BOX b =  fac.getBox(10);


    return 0;
}