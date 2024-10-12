#include <iostream>
#include <vector>

//Node class for the linked list
template <typename T>
 class Node {
 public:
     T data;
     Node* next;

     Node(T value) : data(value), next(nullptr) {}
 };

//Stack class using a linked list
 template <typename T>
 class LinkedListStack {
 private:
     Node<T>* top;
     size_t stackSize;

 public:
     LinkedListStack() : top(nullptr), stackSize(0) {} //constructor will initialize the top node & stack size

     void push(T value) {
         Node<T>* newNode = new Node<T>(value);
         newNode->next = top;
         top = newNode;
         stackSize++;
     }

     void pop() {
         if (isEmpty()) {
             std::cout << "Stack is empty. Cannot pop." << std::endl;
             return;
         }

         Node<T>* temp = top;
         top = top->next;
         delete temp; //we use delete keyword here instead of free
         stackSize--;
     }

     T peek() const { //peek lets you find the value of the top element.
         if (isEmpty()) {
             std::cout << "Stack is empty. Cannot peek." << std::endl;
             return T();
         }
         return top->data;
     }

     bool isEmpty() const {
         return top == nullptr;
     }

     size_t size() const {
         return stackSize;
     }

     ~LinkedListStack() { //destructor. pop() uses the delete keyword rather than free()
         while (!isEmpty()) {
             pop();
         }
     }
 };
 class Stack {
 private:
     static const int MAX_SIZE = 100; 
     /*
     Static: The static keyword means that the variable is shared among all instances 
     of the class. In this case, it is a class-level constant, and there will be only one 
     instance of it shared by all instances of the Stack class.

     Const: The const keyword indicates that the variable is constant, meaning its value cannot 
     be modified once it is initialized. In this case, MAX_SIZE is a constant representing the 
     maximum size of the stack, and its value should not be changed during the program's execution.
     */
      // Maximum size of the stack
     int arr[MAX_SIZE];
     int top;

 public:
     Stack() {
         top = -1;
     }

     bool isEmpty() {
         return top == -1;
     }

     bool isFull() {
         return top == MAX_SIZE - 1;
     }

     void push(int value) {
         if (isFull()) {
             std::cout << "Stack overflow. Cannot push.\n";
             return;
         }

         arr[++top] = value;
         std::cout << value << " pushed onto the stack with top index "<< top <<std::endl;
     }

     void pop() {
         if (isEmpty()) {
             std::cout << "Stack is empty. Cannot pop.\n";
             return;
         }

         std::cout << arr[top--] << " popped from the stack.\n";
     }

     int peek() {
         if (isEmpty()) {
             std::cout << "Stack is empty. Cannot peek.\n";
             return -1;   //Assuming -1 as an error value
         }

         return arr[top];
     }
 };

/* Function to reverse elements of a vector using the stack
    It accepts an input vector of type T and creates an empty LinkedListStack
    also of type T. Then, it fills the stack with all of the vector elements.
    Then, it reverses the original input vector by filling the vector using
    the peek() function of the Stack.
*/
template <typename T> 
void reverseVector(std::vector<T>& inputVector) {
     LinkedListStack<T> stack;

    // Push elements onto the stack
     for (size_t i = 0; i < inputVector.size(); ++i) {
         stack.push(inputVector[i]);
     }

    // Pop elements from the stack to reverse the vector
     for (size_t i = 0; i < inputVector.size(); ++i) {
         inputVector[i] = stack.peek();
         stack.pop();
     }
 }

/* Function to check if parentheses in the expression are balanced
    It takes a string as input and creates a linked list to act as a stack.
    Each node represents one character in the string.

    While iterating through the input string, it adds any (, [, or { onto
    the stack and then continues iterating until it finds a right-side matching
    character. It should be symmetrical, so the stack could look like this

    ( [ { (        while checking for )}])

    Letś say it stores the ( first and the string is ([])

    The stack would be filled first as ([ with the top being [.

    When it encounters a ], it will store the top value and compare
    it to ]. If it isn't a match, a false will be returned.
*/
 bool areParenthesesBalanced(const std::string& expression) {
     LinkedListStack<char> charStack;

     for (size_t i = 0; i < expression.size(); ++i) {
         char ch = expression[i];
        
         if (ch == '(' || ch == '[' || ch == '{') {
             charStack.push(ch);
         } else if (ch == ')' || ch == ']' || ch == '}') {
             if (charStack.isEmpty()) {
                 return false;  //Unmatched closing parenthesis
             }

             char topChar = charStack.peek();
             charStack.pop();

             if ((ch == ')' && topChar != '(') ||
                 (ch == ']' && topChar != '[') ||
                 (ch == '}' && topChar != '{')) {
                 return false;  //Mismatched parentheses
             }
         }
     }

     return charStack.isEmpty();
 }


 int main() {
     //Creating a vector of integers
     std::vector<int> myVector = {1, 2, 3, 4, 5};

      //Displaying the original vector
     std::cout << "Original Vector: ";
      for (size_t i = 0; i < myVector.size(); ++i) {
         std::cout << myVector[i] << " ";
     }
     std::cout << std::endl;

      //Reversing the vector using the stack
     reverseVector(myVector);

      //Displaying the reversed vector
     std::cout << "Reversed Vector: ";
      for (size_t i = 0; i < myVector.size(); ++i) {
         std::cout << myVector[i] << " ";
     }
     std::cout << std::endl;


    //Test the expression with balanced parentheses
     std::string balancedExpression = "(a + b) * (c - d)";
     if (areParenthesesBalanced(balancedExpression)) {
         std::cout << "Balanced expression: " << balancedExpression << std::endl;
     } else {
         std::cout << "Unbalanced expression: " << balancedExpression << std::endl;
     }

    //Test the expression with unbalanced parentheses
     std::string unbalancedExpression = "{[x + y) * z}";
     if (areParenthesesBalanced(unbalancedExpression)) {
         std::cout << "Balanced expression: " << unbalancedExpression << std::endl;
     } else {
         std::cout << "Unbalanced expression: " << unbalancedExpression << std::endl;
     }

     return 0;

     Stack myStack;

     myStack.push(10);
     myStack.push(20);
     myStack.push(30);

     std::cout << "Top element: " << myStack.peek() << "\n";

     myStack.pop();
     myStack.pop();
     myStack.pop();

     myStack.push(40);

     std::cout << "Top element: " << myStack.peek() << "\n";

//--------
//stack app-make the string good
 }


/* why size_t?
Consistency: Using size_t is consistent with standard library functions and containers in C++. 
For example, the size() member function of containers in the C++ Standard Library typically returns a size_t.

Correctness: Using an unsigned type like size_t for 
sizes and indices avoids signed/unsigned comparison issues and helps prevent unintended 
behavior in loops and conditions.

*/

