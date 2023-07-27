#include <bits/stdc++.h>
using namespace std;

class Man
{
    string _name;
    int _age;
    Man() {}

protected:
    Man(const string &name, const int &age)
    {
        this->_name = name;
        this->_age = age;
    }

    void run()
    {
        puts("i can run");
    }

public:
    void sayName() const;
};
void Man ::sayName() const
{
    cout << "My name is " << _name << "and age is: "<<_age<< endl;
}


class Superman : public Man{
    bool flight;

public:
    Superman(string name) : Man(name, 26){};
    void run(){
        puts("i can run at light speed");
    }

};

class Spiderman : public Man{
    bool webbing;

public:
    Spiderman(string name) : Man(name, 19){};
    void run(){
        puts("i can run at normal speed");
    }
};


int main()
{
    // cout<<"hellp"<<endl;

    Superman clark("kent");
    clark.sayName();
    return 0;
}