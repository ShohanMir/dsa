#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int top;
        int array[];
        int cout;
        int size;

    public:
        Stack() {
            top = -1;
            array = new int[size];
            count = 0;
            size = 4;
        }

        void push(int data) {
            if (top == size - 1) {
                cout << "Stack is full" << endl;
                resize();
            } else {
                top++;
                array[top] = data;
            }
        }

        // function to resize the stack
        void resize() {
            int temp[] = NULL;
            if (count == size) {
                temp = new int[size * 2];
                for (int i = 0; i <= size; i++) {
                    temp[i] = array[i];
                }
                delete[] array;
                array = temp;
                size = size * 2;
            }
        }

        void shrinkSize() {
            int temp[] = NULL;

            if (count > 0) {
                temp = new int[count];
                for (int i = 0; i < count; i++) {
                    temp[i] = array[i];
                }
                delete[] array;
                array = temp;
                size = count;
                
            }
        }

        // function to pop the top element from the stack
        int pop() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                int data = array[top];
                top--;
                return data;
            }
        }

        // function to display the stack
        void display() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
            } else {
                for (int i = 0; i <= top; i++) {
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
};

// driver function
int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.display();
    stack.pop();
    stack.display();

    stack.shrinkSize();

    stack.display();
    return 0;
}
