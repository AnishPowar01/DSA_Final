#include <bits/stdc++.h> 

using namespace std; 

class Parameter // Define a class named 'Parameter'.
{
public: // Declare public members of the class.

    int val; // Declare a public integer member variable 'val'.

    void operator+(Parameter &b) // Overload the '+' operator as a member function.
    {
        int val1 = this->val; // Get the value of 'val' from the current object ('this' points to the current object).
        int val2 = b.val; // Get the value of 'val' from the object passed as a reference ('b').

        cout << val1 - val2 << " "; // Print the result of subtracting 'val2' from 'val1'.
    }
};

int main() // Main function, entry point of the program.
{
    Parameter a, b; // Create two objects 'a' and 'b' of class 'Parameter'.

    a.val = 79; // Set the 'val' member variable of 'a' to 79.
    b.val = 10; // Set the 'val' member variable of 'b' to 10.

    a + b; // Call the overloaded '+' operator method for the object 'a', passing 'b' as a reference.

    return 0; 
}
