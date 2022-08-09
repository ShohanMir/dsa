#include <iostream>
#include <string>
using namespace std;


class Stack {
    private:
        int top;
        int *arr[5];
        int bound;
        int length;

    public:
        Stack() {
            top = -1;
            bound = 4;
            length = 0;
        }

        // increase stack size by given value
        void resize() {
            int value;
            cin >> value;

            int* temp = new int(value);
            for (int i = 0; i <= top; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }

        void push(int data) {
            if (top == bound - 1) {
                cout << "Stack is full" << endl;
                resize();
            } else {
                top++;
                arr[top] = data;
            }
        }

        int pop() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                int data = arr[top];
                top--;
                return data;
            }
        }

        int peek() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return arr[top];
            }
        }

        bool isEmpty() {
            if (top == -1) {
                return true;
            } else {
                return false;
            }
        }

        // increase the stack size
        // void resize() {
        //     int* temp = new int[length + 4];
        //     for (int i = 0; i <= top; i++) {
        //         temp[i] = arr[i];
        //     }
        //     delete[] arr;
        //     arr = temp;
        //     length += bound; // double the size of the stack array
        // }

        // count the number of elements in the stack
        int count() {
            int sum = 0;
            for (int i = 0; i <= top; i++) {
                sum += arr[i];
            }
            return sum;
        }

        // how many stack are filled with data
        int filled() {
            int sum = 0;
            for (int i = 0; i <= top; i++) {
                if (arr[i] != 0) {
                    sum++;
                }
            }
            return sum;
        }

        // count the elements in stack
        int countElements(int data) {
            int sum = 0;
            for (int i = 0; i <= top; i++) {
                if (arr[i] == data) {
                    sum++;
                }
            }
            return sum;
        }

        // display the stack
        void display() {
            if (top == -1) {
                cout << "Stack is empty" << endl;
            } else {
                for (int i = top; i >= 0; i--) {
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


// driver functions
// int main() {
//     Stack stack;
//     int choice;
//     do {
//         cout << "1. Push" << endl;
//         cout << "2. Pop" << endl;
//         cout << "3. Peek" << endl;
//         cout << "4. Display" << endl;
//         cout << "5. Count" << endl;
//         cout << "6. Count Elements" << endl;
//         cout << "7. Count Filled" << endl;
//         cout << "8. Quit" << endl;
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 int data;
//                 cin >> "Enter the data to be pushed" >> data;
//                 stack.push(data);
//                 break;
//             case 2:
//                 stack.pop();
//                 break;
//             case 3:
//                 stack.peek();
//                 break;
//             case 4:
//                 stack.display();
//                 break;
//             case 5:
//                 stack.count();
//                 break;
//             case 6:
//                 int data;
//                 cin >> "Enter the data to be counted" >> data;
//                 stack.countElements(data);
//                 break;
//             case 7:
//                 stack.filled();
//                 break;
//             case 8:
//                 break;
//             default:
//                 cout << "Invalid choice" << endl;
//         }
//     } while (choice != 8);
//     return 0;
// }