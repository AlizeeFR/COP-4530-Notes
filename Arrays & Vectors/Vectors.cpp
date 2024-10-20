#include <iostream>
#include <vector>

using namespace std;
/*
    You should know the vector functions, such as 
    push_back, emplace_back, insert,
    begin, back, at, 
    pop_back, erase, clear, empty
    size, capacity, resize, reserve
*/

void first_three_functions(); //push_back, emplace_back, insert
void second_three_functions(); //begin, back, at
void third_four_functions(); //pop_back, erase, clear, empty
void fourth_four_functions(); //size, capacity, resize, reserve

int main() {
    first_three_functions();
    //second_three_functions();
    //third_four_functions();
    fourth_four_functions();
    return 0;
}

void first_three_functions(){
    vector<int> vect_of_ints = {1, 2, 3, 4};
    vect_of_ints.push_back(5);

    /*
        Per StackOverflow, https://stackoverflow.com/questions/10890653/why-would-i-ever-use-push-back-instead-of-emplace-back/36919571#36919571
        "The traditional wisdom is that push_back will 
        construct a temporary object, which will then get moved into v whereas 
        emplace_back will forward the argument along and construct it directly, 
        in place with no copies or moves."

        push_back is generally safer because it uses implicit constructors.

        You provide any arguments required to construct the object you're emplacing 
        or pushing onto it. However, emplace will use the constructor that matches 
        the arguments provided exactly.
    */
   vect_of_ints.emplace_back(6);
   //the insert() function takes two arguments. The location to insert & the element to insert.
   vect_of_ints.insert(vect_of_ints.begin(), 0);

}

void second_three_functions(){

//begin, back, and at functions
    vector<int> vect_of_ints = {1, 2, 3, 4};
    cout << "The element at the beginning of the vector is: " << vect_of_ints.at(0) <<
    "\nThe element at the back (end, largest index) of the vector is: " << vect_of_ints.back() << 
    "\n\nThe function begin() returns a POINTER to an iterator we can use to iterate through the vector.\n"
    "However, you should use the 'auto' type for the loop you use the iterator in.\n"
    "Since you're using a pointer in your loop, to access the vector element pointed at, you must deference it.\n"<< endl;

    for(auto it = vect_of_ints.begin(); it != vect_of_ints.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void third_four_functions(){
    //pop_back, erase, clear

    vector<int> vect_of_ints = {1, 2, 3, 4};
    /* pop_back does NOT return the element at the end of the vector. 
        It simply destroys the last element and reduces the vector's size 
    */
    cout << "Vector size: " << vect_of_ints.size() 
    << "\nNew vector size: " << vect_of_ints.size() << endl;

    /* The function erase() requires an iterator as a parameter.
        The parameter iterator serves as the location of the element to erase.
        The function removes that element and returns a pointer 
        (either an iterator pointer or equivalent to vector.end()) to the
        element that comes after.
    */

    for(auto i = vect_of_ints.begin(); i < vect_of_ints.end(); i++){
        cout << *i << " ";
    }
    cout << endl << "vector after erase(): ";
    auto new_it = vect_of_ints.erase(vect_of_ints.begin()+2);
    for(;new_it<vect_of_ints.end(); new_it++){
        cout << *new_it << " ";
    }
    /* The clear() function will erase all the elements within the vector
        unless these 'elements' are pointers. In that case, you need to
        use the pointers to erase the data at the memory addresses pointed
        at by the pointers and then you can use clear to erase the pointers.
    */
    vect_of_ints.clear();

    cout << "\nSize of the vector after using clear(): " << vect_of_ints.size() << endl <<
    "With the empty() function, you can get a boolean value that states whether the vector is empty" << endl
    << "Is the vector empty? True/False: " << boolalpha << vect_of_ints.empty() << endl << endl;
}

void fourth_four_functions(){
    /*
        The following four functions -- size, capacity, resize,  and reserve --
        are vector functions that 
        1) help you find the number of elements within a vector
        2) help you find the number of elements left in an vector, assuming it is empty, 
            the vector can hold until it needs to be resized.
        3) change the number of elements within/length of the vector
        4) reserve a certain number of element spaces within a vector
    */
    vector<int> vect_of_ints = {1, 2, 3, 4};
    cout
    << "Size of vector, in terms of number of elements: " << vect_of_ints.size() << endl
    << "How many indices/element slots can the vector hold altogether? " << vect_of_ints.capacity() << endl;
    vect_of_ints.resize(10);
    cout
    << "Size of vector, in terms of number of elements: " << vect_of_ints.size() << endl
    << "How many indices/element slots can the vector hold altogether? " << vect_of_ints.capacity() << endl;

    /*
        In C++, the reserve() function for a vector is used to allocate memory for 
        a specified number of elements in advance and increases the capacity, but not the size,
        (the size represents the actual number of elements inside the vector), of the vector.
        
        Reserving memory for future elements helps avoid unnecessary re-allocations as the vector grows in size
    */
    vect_of_ints.resize(4);
    vect_of_ints.reserve(10);

    cout
    << "Size of vector, in terms of number of elements: " << vect_of_ints.size() << endl
    << "How many indices/element slots can the vector hold altogether? " << vect_of_ints.capacity() << endl << endl;
}