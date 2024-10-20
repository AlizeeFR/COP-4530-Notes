#include <iostream>
class Base {
public:
    virtual void foo() {}  // Needs at least one virtual method for dynamic_cast
    /* 
        A class with at least one pure virtual method becomes an abstract class 
        and cannot be instantiated directly.
    */
    virtual void sayHello() = 0;  // Pure virtual method. 
    virtual void show() {
        std::cout << "Base class show function\n";
    }

    virtual ~Base() {  // Virtual destructor
        std::cout << "Base class destructor\n";
    }
};

/*
When using dynamic_cast, if the pointer is cast successfully to a derived class, 
calling an overridden method will call the derived class’s version.
*/
class Derived : public Base {
public:
    void foo() override { std::cout << "Derived foo\n"; }
    void show() override {  // Override the virtual method
        std::cout << "Derived class show function\n";
    }
    void sayHello() {
        std::cout << "Hello world" << std::endl;
    }
    
    ~Derived() {
        std::cout << "Derived class destructor\n";
    }

};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Safe downcasting

    if (derivedPtr != nullptr) {
        // Safe to use derivedPtr
        derivedPtr->foo();  // Calls "Derived foo"
    } else {
        // Invalid cast, basePtr was not pointing to a Derived object
    }

/*
    Although basePtr is a pointer to Base, because show() is a virtual method, 
    C++ will determine at runtime that basePtr is pointing to a Derived object, 
    so it will call the Derived class's version of show().
*/
    basePtr->show();  // Calls Derived class show, not Base class show
    delete basePtr;  // Correctly calls Derived destructor first, then Base destructor

return 0;
}
