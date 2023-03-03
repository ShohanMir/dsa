#include <bits/stdc++.h>

using namespace std;

struct DQueNode {
    int value;
    DQueNode* next; // next node in the queue
    DQueNode* prev; // previous node in the queue
};

class DeQue {
private:
    DQueNode* head; // head of the queue
    DQueNode* tail; // tail of the queue

public: 
    DeQue() {
        head = tail = NULL;
    }

    bool isEmpty() {
        if(head == NULL)
            return true;
        return false;
    }

    int size() {
        if (!isEmpty()) {
            DQueNode* temp = head;
            int len = 0;
            while(temp != NULL) {
                len++;
                temp = temp->next;
            }
            return len;

        }
        return 0;
    }

    void insert_first(int element) {
        DQueNode* temp = new DQueNode[sizeof(DQueNode)]; // create a new node
        temp->value = element;

        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        } else {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    void insert_last(int element) {
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        if(head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        } else {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    void remove_first() {
        if (!isEmpty()) {
            DQueNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            if(head == NULL) tail = NULL;
            return;
        }
        cout << "List is empty" << endl;
    }

    void remove_last() {
        if(!isEmpty()) {
            DQueNode* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }
        cout << "List is empty!" << endl;
    }

    void display() {
        if(!isEmpty()) {
            DQueNode* temp = head;
            while(temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is empty!!" << endl;
    }
};

// class to implements stack using Deque

class Stack : public DeQue {
    public:
        void push(int element) {
            insert_last(element);
        }

        void pop() {
            remove_last();
        }
};

// class to implements queue using Deque

class Queue : public DeQue {
    public:
        void enQueue(int element) {
            insert_last(element);
        }

        void deQueue() {
            remove_first();
        }
};

// Drive Code
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.display();

    // object of Queue
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.display();
    q.deQueue();
    q.display();

    cout << "Size of stack is: " << s.size() << endl;
    cout << "Size of Queue is: " << q.size() << endl;

    return 0;
}