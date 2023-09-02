#include <bits/stdc++.h>
using namespace std;

template <typename T>
class uniqueptr
{
private:
    T *resource; //? Pointer to the dynamically allocated resource

public:
    // Constructor to initialize the unique_ptr with a resource or nullptr
    uniqueptr(T *a = nullptr) : resource(a)
    {
        cout << "ctor\n";
    }

    //! Deleted copy constructor and copy assignment operator to enforce unique ownership.
    uniqueptr(const uniqueptr<T> &ptr) = delete;
    uniqueptr &operator=(const uniqueptr<T> &ptr) = delete;

    //! Move constructor to transfer ownership from another unique_ptr
    uniqueptr(uniqueptr<T> &&ptr)
    {
        resource = ptr.resource;
        ptr.resource = nullptr;
    }

    //! Move assignment operator to transfer ownership from another unique_ptr
    uniqueptr &operator=(uniqueptr<T> &&ptr)
    {
        if (this != &ptr)
        {
            if (resource)
            {
                delete resource; // *Release the existing resource if it exists
            }
            resource = ptr.resource;
            ptr.resource = nullptr;
        }

        return *this;
    }

    //! Overloaded -> operator to access members of the managed object
    T *operator->()
    {
        return resource;
    }

    //! Overloaded * operator to dereference and access the managed object
    T &operator*()
    {
        return *resource;
    }

    //! Get the raw pointer to the managed resource
    T *get()
    {
        return resource;
    }

    //! Reset the unique_ptr with a new resource or nullptr
    void reset(T *newres = nullptr)
    {
        if (resource)
        {
            delete resource; // Release the existing resource if it exists
        }

        resource = newres;
    }

    // Destructor to automatically release the resource when the unique_ptr goes out of scope
    ~uniqueptr()
    {
        cout << "dtor\n";
        if (resource)
        {
            delete resource;
            resource = nullptr;
        }
    }
};

int main()
{
    // Example usage of the unique_ptr class

    uniqueptr<int> ptr1(new int(69));
    uniqueptr<int> ptr3(new int(79));
    uniqueptr<int> pt4(new int(500));

    //!! Attempting to copy or assign unique_ptrs (will result in compilation errors)
    // uniqueptr<int> ptr2(ptr1);
    // pt4 = ptr3;

    //!! Transferring ownership using move semantics
    // uniqueptr<int> pt3 = std::move(ptr1);
    // pt4 = std::move(ptr1);

    //!! Accessing and manipulating the managed objects
    cout << *(ptr1); // Dereference and print the value

    ptr1.get(); // Get the raw pointer (not commonly used)

    ptr1.reset(new int(30)); // Reset the unique_ptr to manage a new resource

    cout << *(ptr1); // Dereference and print the updated value

    //? unique_ptr ensures exclusive ownership and automatic resource management.
    return 0;
}
