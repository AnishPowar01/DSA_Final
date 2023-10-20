#include <iostream>
#include <string>

class Person {
public:
    // Default constructor
    Person() : name_("Unknown"), age_(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Person(const std::string& name, int age) : name_(name), age_(age) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    // Constructor chaining using initializer list
    Person(const std::string& name) : Person(name, 0) {
        std::cout << "Chained constructor called." << std::endl;
    }

    void DisplayInfo() {
        std::cout << "Name: " << name_ << ", Age: " << age_ << std::endl;
    }

private:
    std::string name_;
    int age_;
};

int main() {
    Person person1;             // Calls default constructor
    Person person2("Alice");    // Calls chained constructor
    Person person3("Bob", 30);  // Calls parameterized constructor

    person1.DisplayInfo();
    person2.DisplayInfo();
    person3.DisplayInfo();

    return 0;
}
