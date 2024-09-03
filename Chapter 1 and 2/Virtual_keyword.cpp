#include <iostream>
#include <string>
using namespace std;
class Person {
    protected:
        string name;

    public:
        Person() {
            name = "none";
        }
        Person(string name){
            this->name = name;
        }
        virtual void print() {
            cout << name << endl;
        }
};

class Student : public Person {
    protected:
        int student_id;

    public:
        Student(string name, const int student_id) 
        : Person(name){
            this->student_id = student_id;
        }
        virtual void print() {
            cout << name + " " + to_string(student_id) << endl;
        }
    /*
        If this class had allocated memory as part of the
        class implementation itself, we would create a virtual
        destructor that would ensure that we forced the
        computer to use the Student destructor, which would automatically
        call the base/parent destructor as well.
    */
};

int main() {
    Person* person_pointer_array[10];
    /* 
        The code above is an array that has 10 indices, and in each index, there 
        is a pointer that points to a Person object. Normally, the Person class
        print() function would be called for all objects, since C++'s default
        behavior is to go by the declared type. In the code above, we declared the
        pointer to be of type Person. A pointer can point to any child of the class
        it was declared to be (in this case, Person), and dynamic binding with the
        virtual keyword allows the pointer to use functions of an object pointers to
        by a pointer within the array that are not Person objects but rather child
        objects, such as a Student object.

    */
    person_pointer_array[0] = new Person("Bob");
    person_pointer_array[1] = new Student("Anna", 5051);
    person_pointer_array[0]-> print();
    person_pointer_array[1]-> print();

    return 0;
}