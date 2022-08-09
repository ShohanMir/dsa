#include <iostream>
using namespace std;

// create a doubly linked list node
class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        // default constructor
        Node () {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        // parameterised constructor
        Node(int data) {
            this->data = data; // assign data to the node
            this->next = NULL; // default next is NULL
            this->prev = NULL; // default prev is NULL
        }
};

// Linked list class to implement a doubly linked list
class Linkedlist {
    Node* head;

    public:

        Linkedlist() {
            head = NULL; // default head is NULL
        }

        // insert a node at the end of the list
        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            Node* temp = head;
            if(head == NULL) {
                head = newNode;
            } else {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode; // assign new node to the next of the last node
                newNode->prev = temp;   // assign new node to the prev of the last node
            }
        }

        // insert a node at the beginning of the list
        void insertAtBeginning(int data) {
            Node* newNode = new Node(data);
            newNode->next = head; // new node next is the current head  (head is the first node)
            newNode->prev = NULL; // new node prev is NULL

            if(head != NULL) { // if head is not NULL
                head->prev = newNode; // head prev is the new node
            }
            head = newNode;     // head is the new node
        }

        // insert a node at a given position in the list
        void insertNodeAtPosition(int data, int position) {
            Node* newNode = new Node(data);
            Node* temp = head;
            int count = 0;

            while (count < position - 1) {
                temp = temp->next;
                count++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next->prev = newNode;
        }

        // delete a node from the end of the list
        void deleteFromEnd() {
            Node* temp = head;
            Node* prev = NULL;

            while(temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }

        // delete a node from the beginning of the list
        void deleteFromBeginning() {
            Node* temp = head;
            head = temp->next;
            head->prev = NULL;
            delete temp;
        }

        // delete a node
        void deleteNode(int data) {
            Node* temp = head;
            Node* prev = NULL;

            while (temp != NULL) {
                if (temp->data == data) {
                    if (prev == NULL) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next; // prev next is the temp next
                        temp->next->prev = temp->prev; // temp next prev is the prev
                    }
                    delete temp;
                    break;
                }
                prev = temp; // prev is the current temp
                temp = temp->next; // temp is the next of the current temp
            }
        }

        // delete a node from a given position in the list
        void deleteNodeAtPosition(int position) {
            Node* temp = head;
            int count = 0;

            while (count < position - 1) {
                temp = temp->next;
                count++;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
        }

        // sum of the list
        int sumOfList() {
            Node* temp = head;
            int sum = 0;

            while (temp != NULL) {
                sum += temp->data;
                temp = temp->next;
            }
            return sum;
        }

        // find index of a node
        int findIndex(int value) {
            Node* temp = head;
            int count = 0;

            while (temp != NULL) {
                if (temp->data = value) {
                    return count;
                }
                temp = temp->next;
                count++;
            }
            return -1;
        }

        // find the length of the list
        int length() {
            Node* temp = head;
            int count = 0;

            whille(temp != NULL) {
                temp = temp->next;
                count++;
            }
            return count;
        }

        int findNode(int data) {
            Node* temp = head;
            int count = 0;

            while(temp != NULL) {
                if(temp->data == data) {
                    return count;
                }
                temp = temp->next;
                count++;
            }
            return -1;
        }

        // reverse the list
        void reverseList() {
            Node* temp = head;
            Node* prev = NULL;

            while(temp != NULL) {
                Node* next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            head = prev;
        }

        // Reverse the list using recursion
        void reverse() {
            Node* temp = head;
            Node* prev = NULL;
            Node* next = NULL;

            while( temp != NULL ) {
                next = temp->next;
                temp->next = prev;
                prev = temp;
            }

            head = prev;
        }

        // print all the nodes in the list
        void printList() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};


int main() {
    Linkedlist list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    list.insertAtBeginning(4);
    list.insertAtBeginning(5);
    list.insertAtBeginning(6);
    list.insertAtBeginning(7);
    list.insertAtBeginning(8);
    list.insertAtBeginning(9);

    list.printList();
    list.deleteFromBeginning();
    list.printList();
    list.deleteFromEnd();
    list.printList();
    list.deleteNode(4);
    list.printList();
    list.deleteNodeAtPosition(2);
    list.printList();
    list.insertAtEnd(10);
    list.printList();
    list.insertNodeAtPosition(11, 2);
    list.printList();
    return 0;

};
