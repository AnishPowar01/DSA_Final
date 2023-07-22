#include<bits/stdc++.h> // Include the entire standard library to get access to various functionalities.

using namespace std; // Use the standard namespace to avoid writing 'std::' before standard library elements.

class Animal{ // Define a class named 'Animal'.

    int age; // Declare a private integer member variable 'age'.
    
    public: // Declare public members of the class.
    int weight; // Declare a public integer member variable 'weight'.
    string ch; // Declare a public string member variable 'ch'.

    // Parameterized constructor
    Animal(int age, int w, string name) // Constructor with parameters 'age', 'w', and 'name'.
    {
        this->ch = name; // Set the 'ch' member variable to the provided 'name'.
        this->age = age; // Set the 'age' member variable to the provided 'age'.
        this->weight = w; // Set the 'weight' member variable to the provided 'w'.
    }

    // Default constructor
    Animal() // Default constructor with no parameters.
    {
        this->ch = ""; // Initialize 'ch' to an empty string.
        this->age = 0; // Initialize 'age' to 0.
        this->weight = 0; // Initialize 'weight' to 0.
    }

    // Copy constructor
    Animal(Animal &obj) // Constructor that takes a reference to another 'Animal' object as input.
    {
        this->age = obj.age; // Set 'age' to the value of 'age' in the passed object.
        this->ch = obj.ch; // Set 'ch' to the value of 'ch' in the passed object.
        this->weight = obj.weight; // Set 'weight' to the value of 'weight' in the passed object.
    }

    // Destructor
    ~Animal() // Destructor, executed when an 'Animal' object is destroyed (e.g., when it goes out of scope).
    {
        cout << "Inside Destructor" << endl; // Print a message to indicate that the destructor is called.
    }

    // Getter method to access the private member 'age'
    int getter()
    {
        return this->age; // Return the value of 'age' to the caller.
    }

    // Methods or functions

    void eat() // Method to simulate the action of an animal eating.
    {
        cout << "I am Eating" << endl; // Print a message to indicate the action.
    }

    void sleep() // Method to simulate the action of an animal sleeping.
    {
        cout << "I am Sleeping" << endl; // Print a message to indicate the action.
    }
};

int main()
{
    Animal a(20, 56, "Anish"); // Create an object 'a' of class 'Animal' using the parameterized constructor.

    Animal* an = new Animal(); // Create a dynamic object 'an' of class 'Animal' using the default constructor.
    // We have to explicitly delete the dynamically allocated object using 'delete an;' to avoid memory leaks.

    // cout<<a.getter()<<"";
    // (*an).eat();

    // Animal b = a; // Create a new object 'b' of class 'Animal' using the copy constructor and initialize it with 'a'.
    // b.eat(); // Call the 'eat' method of object 'b'.

    // Animal demo(a); // Create a new object 'demo' of class 'Animal' using the copy constructor and initialize it with 'a'.
    // cout<<demo.weight<<""; // Print the value of the 'weight' member variable of object 'demo'.

    delete an; // Delete the dynamically allocated object to free the memory.

    return 0; // Return 0 to indicate successful program execution.
}
