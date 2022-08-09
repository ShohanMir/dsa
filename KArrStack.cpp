#include <iostream>

using namespace std;

class KStack {
    int *arr;
    int *top;
    int *next;

    int n, k;
    int free;

    public:

        // function to check if stack is empty
        // bool isEmpty(int i) {
        //     return top[i] == -1;
        // }

        KStack(int k, int n) {
            this->k = k; // k is the number of stacks
            this->n = n; // n is the size of the array
            arr = new int[n]; // array to store the elements
            top = new int[k]; // array to store the top of the stack
            next = new int[n]; // array to store the next of the stack

            // initialize the top of the stack to -1
            for (int i = 0; i < k; i++) {
                top[i] = -1;
            }

            // initialize the next array
            free = 0;
            for (int i = 0; i < n; i++) {
                next[i] = i+1;
            }

            next[n-1] = -1; // -1 is used to indicate end of free list

        }
        void push(int item, int sn) {
            if (free == -1) {
                cout << "Stack is full" << endl;
                return;
            }
            int i = free;
            free = next[i];

            next[i] = top[sn];
            top[sn] = i;

            arr[i] = item;
        }
        void pop() {
            if (free == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            int i = free;
            free = next[i];
            next[i] = free;
        }
        void peek() {
            if (free == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            int i = free;
            cout << "Top Most elements: " << top[i] << endl;
        }
        void display() {
            if (free == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            int i = free;
            while (i != -1) {
                cout << top[i] << " ";
                i = next[i];
            }
            cout << endl;
        }
};

int main() {
    KStack ks(2,5);
    ks.push(1, 1);
    ks.push(2, 2);
    ks.push(3, 1);
    ks.push(4, 1);
   
    ks.display();
    ks.peek();
    ks.pop();

    return 0;
};