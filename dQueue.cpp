#include<iostream>

using namespace std;

#define MAX 100

class Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        front = -1;
        rear = 0;
        this->size = size;
    }

    bool isFull() {
        return ((front == 0 && rear == size-1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int value) {
        if(isFull()) {
			cout << "Overflow" << endl;
            return;
		}

        if (front == -1) {
            front = 0;
            rear = 0;
        }

        else if(front == 0) {
            front = size-1;
        }

        else {
            front = front - 1;
        }

        arr[front] = value;
    }

    void insertRear(int value) {
        if(isFull()) {
			cout << "Overflow" << endl;
            return;
		}

        if(front == -1) {
            front = 0;
            rear = 0;
        }

        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear = rear + 1;
        }

        arr[rear] = value;
    }

    void deleteFront() {
        if (isEmpty()) {
			cout << "Queue Underflow\n" << endl;
			return;
		}

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            if (front == size - 1){
                front = 0;
            } else {
                front = front + 1;
            }
        
        }
    }

    void deleteRear() {
        if (isEmpty())
            cout << "Empty" << endl;
        
        if (rear == front) {
            front = -1;
            rear = -1;
        } else {
            if (rear == 0) {
                rear = size - 1;
            } else {
                rear = rear - 1;
            }
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }

        return arr[front];
    }

    getRear() {

        // check whether Deque is empty or not
        if(isEmpty() || rear < 0)
        {
            cout << "Underflow" << endl;
            return -1 ;
        }
        return arr[rear];
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    Deque dq(5);

    cout << "Insert element at rear end d : 5 \n";
    dq.insertRear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);
 
    cout << "get rear element " << " "
         << dq.getRear() << endl;
 
    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "inserting element at front end \n";
    dq.insertFront(15);
 
    cout << "get front element " << " "
         << dq.getFront() << endl;
 
    dq.deleteFront();
 
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;
    return 0;
}
