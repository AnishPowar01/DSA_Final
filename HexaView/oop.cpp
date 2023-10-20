#include <bits/stdc++.h>
using namespace std;
class Animal
{

private:
    string _name;
    int _age;

public:
    int weight;

    // Default constructor;

    Animal()
    {
        cout << "Inside Default Constructor" << endl;
    }

    // parameterised constructor

    Animal(string name, int age, int weight)
    {
        this->_name = name;
        this->_age = age;
        this->weight = weight;

        cout << "Inside Parameterised Constructor" << endl;
    }

    // for deynamic allocation

    Animal(int name, int age)
    {
        this->_name = name;
        this->_age = age;

        cout << "Dynamic Object creation" << endl;
    }

    // copy costructor

    Animal(Animal &obj)
    {
        this->_name = obj._name;
        this->_age = obj._age;
        this->weight = obj.weight;

        cout << "Inside copy constructor" << endl;
    }

    // getter and setters to access the private member

    void setName(string name)
    {
        this->_name = name;
    }

    string getName()
    {
        return this->_name;
    }

    void setAge(int age)
    {
        this->_age = age;
    }

    int getAge()
    {
        return this->_age;
    }

   virtual void speak()
    {
        cout << "Animal is Speaking" << endl;
    }

    ~Animal()
    {
        cout << "Called the destructor" << endl;
    }
};

class Lion : public Animal
{
public:
    // Lion()
    // {
    //     cout << "Inside the lion" << endl;
    // }

    void speak()
    {
        cout << "Lion is Roaring" << endl;
    }
};

class Tiger : public Animal
{

public:
    void speak()
    {
        cout << "Inside the tiger" << endl;
    }
};

class Liger : public Lion, public Tiger
{
};
int main()
{
    Animal obj; // default constructor
    obj.weight = 48;
    cout << obj.weight << "" << endl;
    obj.setName("Anish");
    cout << obj.getName() << endl;
    obj.setAge(18);
    cout << obj.getAge() << endl;

    Animal dog("Tommy", 10, 30); // parameterised constructor

    Animal cat(dog);

    cout << cat.getName() << endl;
    cout << cat.getAge() << endl;
    cout << cat.weight << endl;

    Animal *dObj = new Animal(3, 4);

    dObj->setName("SanjuBaba");

    cout << dObj->getName() << endl;
    delete dObj;

    // Inheritence
    Lion li;
    li.setName("LionBaba");
    cout << li.getName() << endl;

    li.speak();

    // multiple inheritence.. ambiguity
    Liger lg;
    lg.Tiger::speak();

    // RUN Time Polymorphism

    Animal *ani = new Animal();
    ani->speak(); // Animal is Speaking

   // Upcasting 
    Animal *ani2 = new Lion();
    ani2->speak(); // Animal is Speaking

    delete ani;
    delete ani2;


    return 0;
}