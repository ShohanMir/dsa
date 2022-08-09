#include <bits/stdc++.h>
using namespace std;

struct Stack {


    stack<int>s;
    int minEle;

    void getMin() {
		if (s.empty()) {
			cout << "Stack is empty\n";
		} else {
			cout << "Minimum Element in the stack is: " << minEle << endl;
		}
	}

    void peek() {
		if (s.empty()) {
			cout << "Stack is empty";
			return;
		}
		int t = s.top();
		cout << "Top Most elements: ";
		
		(t < minEle) ? cout << minEle: cout << t;
	}

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
            return;
        } else {
            int t = s.top();
            s.pop();

            if (t < minEle) {
                cout << minEle << endl;
                minEle = 2*minEle - t;
            }
            else {
                cout << t << endl;
            }
        }
    }

    void push(int data) {
            if (s.empty()) {
                minEle = data;
                s.push(data);
                cout << "Number inserted: " << data << endl;
                return;
            } else if (data < minEle) {
                s.push(2*minEle - data);
                minEle = data;
            } else {
                s.push(data);
            }
            cout << "Number inserted: " << data << endl;
    }

    void display() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = s.size(); i > 0; i--) {
                cout << s.top() << " "; 
                s.pop();   // pop the element from stack to display it
            }
            cout << endl;
        }
    }
};

// Driver function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Stack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    // s.pop();
    s.getMin();
    // s.pop();
    s.peek();
    cout << endl;
    s.display();
  
    return 0;
}
