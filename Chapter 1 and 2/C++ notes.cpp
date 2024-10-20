#include <iostream>
#include <string>

/*
    Even though the member variables are private, 
    returning them by value (without using a reference)
    would involve copying their contents. 
    
    For large objects like strings or complex data structures, 
    this copying can be inefficient and costly
    in terms of both time and memory.


*/
class Person {
private:
    std::string name;  // Private member variable
    int age;           // Private member variable

public:
    // Constructor to initialize the name and age
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Getter for name, returns a reference to a constant
    const std::string& getName() const {
        return name;  // Returning a const reference to avoid copying
        /*
            Without the reference, each call to getName() would create 
            a new copy of the "name" string, which can become inefficient if used frequently.
        */
    }

    // Getter for age, returns a reference to a constant
    const int& getAge() const {
        return age;  // Returning a const reference to avoid copying
    }

    // Example method that does not allow modifying the member variables
    void printInfo() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << std::endl;
    }
};

int main() {
    Person person("John Doe", 30);

    // Accessing the name and age through the getters
    std::cout << "Person's name: " << person.getName() << std::endl;
    std::cout << "Person's age: " << person.getAge() << std::endl;

    // The following lines would cause a compilation error if uncommented,
    // since the returned references are to constant data:
    // person.getName() = "Jane Doe";  // Error: can't modify a const reference
    // person.getAge() = 25;           // Error: can't modify a const reference

    return 0;
}
