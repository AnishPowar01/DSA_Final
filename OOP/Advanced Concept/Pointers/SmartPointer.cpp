#include <bits/stdc++.h>
using namespace std;
// *RAII => Resourse aquisation in initialisation.

// void func()
// {
//     for(int i = 1; i<100000; i++)
//     {
//         int*a = new int(20);

      //* explicitly we have to take care of memory leak...
//         delete a;
//     }
// }
// int main()
// {
//     func();
//     return 0;
// }

// !SMART POINTER
// sharedPtr, uniquePtr, 
//? autoPtr => deprecated, , weakPTR;
class Wrapper
{
private:
    int *mem;

public:
    Wrapper(int *a) : mem(a)
    {

        cout << "ctor\n";
        cout << *mem << "\n";
    }

    ~Wrapper()
    {
        cout << "dtor\n";
        delete mem;
    }
};

int main()
{

    Wrapper obj(new int(10));
}