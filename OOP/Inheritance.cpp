#include<bits/stdc++.h> 
using namespace std; 

class Animal{ // Define a class named 'Animal'.

    private: // Declare private members of the class.
    int age; // Declare a private integer member variable 'age'.

    public: // Declare public members of the class.
    int weight; // Declare a public integer member variable 'weight'.
    string name; // Declare a public string member variable 'name'.

    Animal() // Default constructor of the 'Animal' class.
    {
        this->age = 20; // Set the default value of 'age' to 20.
        this->weight = 60; // Set the default value of 'weight' to 60.
        this->name = ""; // Set the default value of 'name' to an empty string.
    }

    void Eat() // Method to simulate the action of an animal eating.
    {
        cout << "Eating";
    }

    void Sleeping() // Method to simulate the action of an animal sleeping.
    {
        cout << "Sleeping" << endl;
    }

    void setter(int age) // Setter method to set the 'age' member variable.
    {
        this->age = age; // Set the 'age' to the provided 'age'.
    }

    int getter() // Getter method to access the private member 'age'.
    {
        return this->age; // Return the value of 'age' to the caller.
    }

};

class Dog : public Animal // Define a class 'Dog' that inherits from the 'Animal' class.
{

    public: // Declare public members of the 'Dog' class.
    int color; // Declare a public integer member variable 'color'.

    void barking() // Method to simulate the action of a dog barking.
    {
        cout << "Barking" << endl;
    }

};

class Germanshepherd : public Dog // Define a class 'Germanshepherd' that inherits from the 'Dog' class.
{

};

class Tiger : public Animal // Define a class 'Tiger' that inherits from the 'Animal' class.
{
    public: // Declare public members of the 'Tiger' class.

    void speciality() // Method to display the speciality of a tiger.
    {
        cout << "Hunt Alone" << endl;
    }

    void Tname() // Method to display the name of the animal as "Tiger".
    {
        cout << "I am Tiger" << endl;
    }
};

class Lion : public Animal // Define a class 'Lion' that inherits from the 'Animal' class.
{

    public: // Declare public members of the 'Lion' class.

    void speciality() // Method to display the speciality of a lion.
    {
        cout << "Hunt in Group" << endl;
    }

    void name() // Method to display the name of the animal as "Lion".
    {
        cout << "I am Lion" << endl;
    }
};

class Liger : public Tiger, public Lion // Define a class 'Liger' that inherits from both 'Tiger' and 'Lion'.
{

    public: // Declare public members of the 'Liger' class.

    void lName() // Method to display the name of the animal as "Liger".
    {
        cout << "My name is Liger" << endl;
    }

};

int main() // Main function, entry point of the program.
{

//     Animal an; // Create an object 'an' of class 'Animal' using the default constructor.

//     an.setter(15); // Set the 'age' member variable of 'an' to 15 using the setter method.
//     int ag = an.getter(); // Get the 'age' member variable of 'an' using the getter method and store it in 'ag'.

//     // cout<<ag<<""; // Print the value of 'ag' (age).

//     // Inheritance demonstration:
//     Dog dg; // Create an object 'dg' of class 'Dog'.
//     dg.Eat(); // Call the 'Eat' method of the 'Dog' class, inherited from the 'Animal' class.

//    Germanshepherd gs; // Create an object 'gs' of class 'Germanshepherd'.

//    gs.barking(); // Call the 'barking' method of the 'Germanshepherd' class.
//    gs.setter(45); // Set the 'age' member variable of 'gs' to 45 using the 'setter' method.
//    cout<<gs.getter()<<""; // Get the 'age' member variable of 'gs' using the 'getter' method and print it.

   Liger lg; // Create an object 'lg' of class 'Liger'.

   lg.lName(); // Call the 'lName' method of the 'Liger' class.
//    lg.speciality(); // Ambiguous call: Both 'Tiger' and 'Lion' classes have 'speciality' method.
   lg.Lion::speciality(); // Use scope resolution to call the 'speciality' method of the 'Lion' class.

    return 0; // Return 0 to indicate successful program execution.
}
