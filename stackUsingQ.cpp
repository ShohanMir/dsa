#include <bits/stdc++.h>

using namespace std;

class Stack { 
    queue<int> q; // queue to implement stack

public:
    void push(int val);
    void pop();
    int top();
    bool isEmpty();
};

void Stack::push(int val) { //O(1)
    int s = q.size();
    q.push(val);

    
    for (int i = 0; i < s; i++) { // move all elements one position forward
        q.push(q.front()); // push front element to the back of the queue
        q.pop(); // pop the front element
    }
    cout << "Pushed " << val << endl;
}

void Stack::pop() { //O(1)
    if (q.empty())
        cout << "Empty Stack" << endl;
    else
        q.pop();
}

int Stack::top() { 
    return (q.empty())? -1 : q.front();
}

bool Stack::isEmpty() { 
    return q.empty();
}

// print the stack
void printStack(Stack s) { //O(n)
    if (s.isEmpty()) {
        cout << "Empty Stack" << endl;
        return;
    }
    cout << "Stack: ";
    while (!s.isEmpty()) {
        cout << s.top() << " "; // print the top element
        s.pop(); // pop the top element
    }
    cout << endl;
}

// Driver code

int main() { 
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element: " << s.top() << endl;

    // s.pop();
    s.push(30);
    s.push(31);
    s.push(32);
    s.pop();
    // cout << "One element popped: " ;
    cout << "Top element: " << s.top() << endl;

    printStack(s);

    return 0;
}