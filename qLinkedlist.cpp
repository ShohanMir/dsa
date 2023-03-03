#include <bits/stdc++.h>

using namespace std;

struct QNode {
    int data;
    QNode* next;

    QNode(int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode *front, *rear;
    Queue() {
        front = rear = NULL;
    }

    void enQueue(int x) {
        QNode* temp = new QNode(x);

        if(rear == NULL) {
            front = rear = temp;
        }

        rear->next = temp;
        rear = temp;
        cout << x << " Enqueued to Queue" << endl;
    }

    void deQueue() {
        if (front == NULL) {
            return;
        }

        QNode* temp = front;
        front = front->next;

        if(front == NULL) {
            rear = NULL;
        }

        delete (temp);
        cout << temp->data << " Dequeued from Queue" << endl;
    }

    // function to dequeued specific queue
    void deQueueSpe(int x) {
        if (front == NULL) {
            return;
        }
        QNode* temp = front;
        QNode* prev = NULL;
        while (temp != NULL) {
            if (temp->data == x) {
                if (prev == NULL) {
                    front = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete (temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int frontNum() {
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }

    // reverse the queue
    void reverse() {
        if (front == NULL) {
            return;
        }
        QNode* prev = NULL; // previous node
        QNode* curr = front; // current node
        QNode* next = front->next;  // next node
        while (next != NULL) { // while next is not null
            curr->next = prev; // set current next to previous
            prev = curr; // set previous to current
            curr = next; // set current to next
            next = next->next; // set next to next next
        }
        // set current next to previous
        curr->next = prev; // set current next to previous
        front = curr; // set front to current
    }


    void printQueue() {
        QNode* temp = front;
        cout << "Queue contains: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
    q.enQueue(9);
    q.enQueue(10);


    q.deQueue();

    q.printQueue();
    q.reverse();
    q.printQueue();
    q.deQueue();
    q.printQueue();

    cout << "Queue front: " << (q.front)->data << endl;
    cout << "Queue Rear: " << (q.rear)->data << endl;
}