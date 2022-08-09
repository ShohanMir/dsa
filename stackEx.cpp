#include <iostream>
#include <string>

using namespace std;


class Stack {
    private:
        int top; // top is the index of the top element
        int arr[5]; // array to store the stack

    public:
        Stack() { 
            top = -1; // initially top is -1
        }
        void push(int data) { // push a new element to the stack
            if(top == 4) { // if the stack is full
                cout << "Stack is full" << endl; // print stack is full
            } else { // if the stack is not full
                top++; // increment top
                arr[top] = data; // store the data in the top index
            }
        }
        int pop() { // returns the data popped
            if(top == -1) { // if stack is empty
                cout << "Stack is empty" << endl; // print error message
                return -1; // return -1
            } else { // 
                int data = arr[top]; // store the data
                top--;  // decrement the top
                return data; // return the data
            }
        }
        int peek() {   // returns the data at the top of the stack
            if(top == -1) { // if stack is empty
                cout << "Stack is empty" << endl; // print error message
                return -1;
            } else { // returns the data at the top of the stack
                return arr[top]; // return the data
            }
        }
        bool isEmpty() { // returns true if stack is empty
            if(top == -1) {
                return true;
            } else {
                return false;
            }
        }

        // count the number of elements in the stack
        int count() {
            int sum = 0;
            for(int i = 0; i <= top; i++) {
                sum += arr[i]; // add the elements to the sum
            }
            return sum;
        }

        // how many stack are filled with data
        int filled() {
            int sum = 0;
            for(int i = 0; i <= top; i++) {
                if(arr[i] != 0) {
                    sum++;
                }
            }
            return sum;
        }

        // count the elements in stack
        int countElements(int data) {
            int sum = 0;
            for(int i = 0; i <= top; i++) {
                if(arr[i] == data) {
                    sum++;
                }
            }
            return sum;
        }


        // display the stack
        void display() {
            if(top == -1) {
                cout << "Stack is empty" << endl;
            } else {
                for(int i = top; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);

    stack.display();
    cout << "Popped element: " << stack.pop() << endl;
    stack.display();
    cout << "Peeked element: " << stack.peek() << endl;
    stack.display();
    cout << "Is stack empty: " << stack.isEmpty() << endl;
    cout << "Number of elements in stack: " << stack.count() << endl;
    cout << "Number of elements in stack: " << stack.countElements(3) << endl;
    cout << "Number of filled stacks: " << stack.filled() << endl;
    return 0;
}