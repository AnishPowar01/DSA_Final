#include<bits/stdc++.h>
using namespace std;

int x = 2;


int main()
{
    // local variable high priority.. most recent local variable
    x = 4;
    int x = 20;
    cout<<"Accessing the local variable "<<x<<endl;
    cout<< ::x <<endl;   // printing global variable
    return 0;
}