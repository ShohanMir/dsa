#include <iostream>

using namespace std;

class KStack {
    int k;
    int *arr;
    int *minEle;
    int top;
    int minTop;
public:
    KStack(int k) { // constructor
        this->k = k; // k is the number of stacks
        arr = new int[k]; // array to store the elements
        minEle = new int[k]; // array to store the minimum elements
        top = -1; // top of the stack is -1
        minTop = -1; // top of the minimum stack is -1
    }
    void getMin() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Minimum Element in the stack is: " << minEle[minTop] << endl;
        }
    }
    void peek() {
        if (top == -1) {
            cout << "Stack is empty";
            return;
        }
        int t = arr[top];
        cout << "Top Most elements: ";
        
        (t < minEle[minTop]) ? cout << minEle[minTop] : cout << t;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        } else {
            int t = arr[top];
            top--;
            
            if (t < minEle[minTop]) {
                cout << minEle[minTop] << endl;
                minEle[minTop] = 2*minEle[minTop] - t;
            }
            else {
                cout << t << endl;
            }
        }
    }
    void push(int data) { // push function
        if (top == k-1) { // if the top is equal to k-1
            cout << "Stack is full" << endl; // print stack is full
            return; // return
        } else if (top == -1) { // if the top is -1
            top++; // increment the top
            arr[top] = data; // assign the data to the top
            minEle[++minTop] = data; // assign the data to the minimum top
            cout << "Number inserted: " << data << endl; // print the data
            return; 
        } else if (data < minEle[minTop]) { // if the data is less than the minimum top
            arr[++top] = 2*minEle[minTop] - data; // assign the data to the top
            minEle[++minTop] = data; // assign the data to the minimum top
        } else {
            arr[++top] = data; 
        }
        cout << "Number inserted: " << data << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    KStack ks(3);
    ks.push(1);
    ks.push(2);
    ks.push(3);
    ks.push(4);
    ks.push(5);
    ks.push(6);
    ks.push(7);
    ks.push(8);
    ks.push(9);

    ks.display();
    ks.getMin();
    ks.peek();
    ks.pop();
    ks.getMin();
    ks.pop();
    ks.getMin();

    return 0;
};