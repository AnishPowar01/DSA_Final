#include <bits/stdc++.h>
using namespace std;

class User
{
private:
    int _secret = 22;

public:
    string name = "default";

    void classMessage();

    void setter(const int &data)
    {
        this->_secret = data;
    }
    int getter() const;
};

int User::getter() const
{
    return _secret;
}

void User ::classMessage()
{
    cout << "CLass is Greate, " << name << endl;
}

int main()
{
    User us;
    User ap;

    us.name = "Anish";
    us.setter(34);
    cout << us.getter() << "" << endl;
    us.classMessage();

    const User rock;
    cout << rock.getter() << " "<<endl;
     

    cout<<"Peter is called"<<endl;
    User peter = us;
    cout<<peter.name<<endl;
    return 0;
}