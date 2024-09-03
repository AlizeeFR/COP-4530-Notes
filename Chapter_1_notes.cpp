#include <iostream>
#include <string>
using namespace std;
class Vect {

    public:
        Vect();
        Vect(int n);
        ~Vect();
    private:
        int* data; //pointer to an array
        int size;
    
    Vect::~Vect() {
        delete[] data;
    }
};

    Vect::Vect() {
        size = 10;
        data = new int[10];
    }
    Vect::Vect(int n) {
        size = n;
        data = new int[n];
    }

int main() {
    Vect a(100); //create a Vect object named 'a' with an integer array of size 100
    Vect b = a; //attempt to create a Vect object b that copies all the data from a. This is incorrect!
    Vect c; //create a Vect c with default size of 10;
    /* 
        What the above code actually does is create an array to hold 100 int values for Vect a.
        Then, C++ uses the default assignment (=) behavior and performs a shallow copy
        where b.data = a.data. This is because the default = operator simply copies each member of a to b. 
        Consequently, only a pointer to a's array is copied, not the contents of the array itself.
        Vect c is created using the default constructor, which gives its array a size of 10.
        However, the pointer to a's array is copies over, erasing any pointer to the original int[10] array
        and creates a memory leak.

        To create a copy of a's contents, you must create a copy constructor or overload an assignment operator 
        based on how you're trying to copy the contents of the array. For example, the below code would copy 
        the contents of a's array when using a constructor. The code below that would allow you
        to simply declare a Vect and then fill in its details using the assignment operator rather thtan
        a constructor.

        Vect::Vect(const Vect &a) {
            size = a.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = a.data[i]
            }
        }
        Vect a(100);
        Vect c;
        c = a
        Vect& Vect::operator=(const Vect &a) {
            if (this != &a) {
                delete[] data; //This removes the memory allocated by the default constructor
                size = a.size;
                data = new int[size];
                for (int i = 0; i < size; i++) {
                    data[i] = a.data[i]
                }
            }
            return *this;
        }
    */
    return 0;
}