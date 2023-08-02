#if !defined(BRID_H)
#define BIRD_H
#include<iostream>

class Bird{
    public :

    virtual void eat() = 0;
    // act as a interface
    virtual void fly() = 0;

    // classes that inherits this class has to implement pure virtual functions

};

class sparrow : public Bird
{
    public :
    
    void eat()
    {
        std::cout<<"Sparrow is eating\n";
    }

    void fly()
    {
        std::cout<<"Sparrow is flying\n";

    }
};

class eagle : public Bird
{
    public :
    
    void eat()
    {
        std::cout<<"eagle is eating\n";
    }

    void fly()
    {
        std::cout<<"eagle is flying\n";

    }
};



#endif // 
