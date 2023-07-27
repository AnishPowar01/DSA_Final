#include <bits/stdc++.h>
using namespace std;

class Phone
{
    string _name = "";
    string _os = "";
    int _price = 0;
    Phone(); // default constructor
public:
    // Phone(); // default constructor

    Phone(const string &name, const string &os, const int &price); // parameter constructor;

    Phone(const Phone &); // copy constructor
    string getName()
    {
        return _os;
    }

    int getPrice();

    ~Phone(); // destructor
};

int Phone::getPrice()
{
    this->_price;
}

Phone::Phone() : _name(), _os("Andy"), _price()
{

    puts("default constructor");
}

Phone::Phone(const string &name, const string &os, const int &price) : _name(name), _os(os), _price(price)
{
    puts("this is parameter constructor");
}

Phone::Phone(const Phone &value)
{
    puts("Overwrite copy constructor");

    _name = "new-" + value._name;
    _os = "skinned-" + value._os;
    _price = value._price;
}

Phone::~Phone()
{
    cout << "Destuctor called for" << this->_name << endl;
}

int main()
{
    // Phone samsung;
    // not allowed not if constructor is private
    // cout<<samsung.getName()<<endl;

    Phone OnePlus8("OnePlus8", "Android-Oxy", 79999);

    cout << OnePlus8.getName() << endl;

    Phone OnePlus8s = OnePlus8;

    cout << OnePlus8s.getName() << endl;

    return 0;
}