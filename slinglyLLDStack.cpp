#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;

    // default constructor
    Node () {
        data = 0;
    }

    Node(int data) {
        this->data = data;
    }
};

class Stack {
    Node* top;

    public:
        Stack() {
            top = NULL;
        }

    bool isEmpty() {
        if(top == NULL) {
            return true;
        }
        return false;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->link = top;
        top = temp;
    }

    void pop () {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else {
            Node* temp = top;
            top = top->link;
            delete temp;
        }
    }

    void peek () {
        if (isEmpty())
            cout << "Stack is empty" << endl;
        else
            cout<<"Element at top is : "<< top->data;
    }

    int filled() {
        Node* temp = top;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->link;
        }
        return count;
    }

    void display () {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }
};

int main () {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
	stack.display();
    stack.peek();
    cout << endl;
    cout << "Length of stack is:" << stack.filled() << endl;
    stack.filled();

    return 0;
}
    