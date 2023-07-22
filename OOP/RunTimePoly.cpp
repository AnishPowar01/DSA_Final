#include<bits/stdc++.h> 

using namespace std; 

class Animal{ // Define a class named 'Animal'.
public: // Declare public members of the class.

    // Virtual function 'speak' defined in the base class.
    // Virtual functions are used to achieve dynamic polymorphism.
    // When a derived class overrides a virtual function, the overridden function will be called
    // when an object of the derived class is accessed through a pointer or reference of the base class.
    virtual void speak() // Virtual function to simulate speaking of an animal.
    {
        cout << "Speaking" << endl;
    }
};

class Lion : public Animal // Define a class 'Lion' that inherits from the 'Animal' class.
{
public: // Declare public members of the 'Lion' class.

    // Overridden virtual function 'speak' in the derived class 'Lion'.
    // When 'speak' is called on a Lion object or through a pointer/reference of the base class Animal,
    // this function will be executed instead of the one in the base class.
    void speak() // Overridden virtual function to simulate the lion roaring.
    {
        cout << "Roaring" << endl;
    }
};

int main() // Main function, entry point of the program.
{
    Animal an; // Create an object 'an' of class 'Animal'.
    // an.speak(); // Call the 'speak' method of 'Animal', which prints "Speaking".

    Lion li; // Create an object 'li' of class 'Lion'.
    // li.speak(); // Call the 'speak' method of 'Lion', which prints "Roaring".

    // Now, let's explore polymorphism using pointers and virtual functions:

    Animal* a = new Animal(); // Create a pointer 'a' of type 'Animal*' pointing to an 'Animal' object.
    // a->speak(); // Call the 'speak' method using the 'a' pointer, which prints "Speaking".
    // Since 'a' points to an 'Animal' object, the 'Animal' version of 'speak' is called.

    Lion* l = new Lion(); // Create a pointer 'l' of type 'Lion*' pointing to a 'Lion' object.
    // l->speak(); // Call the 'speak' method using the 'l' pointer, which prints "Roaring".
    // Since 'l' points to a 'Lion' object, the 'Lion' version of 'speak' is called.

    // Upcasting:
    Animal* ani = new Lion(); // Create a pointer 'ani' of type 'Animal*' pointing to a 'Lion' object.
    // ani->speak(); // Call the 'speak' method using the 'ani' pointer, which prints "Roaring".
    // Even though 'ani' points to a 'Lion' object, the 'Lion' version of 'speak' is called.
    // This is an example of polymorphism achieved through virtual functions.

    // The following line is not recommended and can lead to undefined behavior:
    Lion* lio = (Lion*) new Animal(); // Create a pointer 'lio' of type 'Lion*' pointing to an 'Animal' object.
    // lio->speak(); // Call the 'speak' method using the 'lio' pointer.
    // This is an example of downcasting, where we treat an 'Animal' object as a 'Lion' object.
    // Since 'lio' points to an 'Animal' object, but we treat it as a 'Lion' object,
    // the behavior is undefined, and it may lead to unexpected results or crashes.
    // Downcasting should be avoided unless you are sure about the actual type of the object.

    // Don't forget to deallocate the dynamically allocated objects to avoid memory leaks:
    delete a;
    delete l;
    delete ani;
    // delete lio; // This line is commented out to avoid undefined behavior due to downcasting.

    return 0; // Return 0 to indicate successful program execution.
}
