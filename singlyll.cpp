#include <iostream>
using namespace std;

class Node {
	public:
		int data; // data of the node
		Node* next; // pointer to the next node

		// default constructor
		Node () {
			data = 0;
			next = NULL;
		}

		// parameterised constructor
		Node(int data) {
			this->data = data; // assign data to the node
			this->next = NULL; // default next is NULL
		}
};

class Linkedlist {
    Node* head;

    public:

		Linkedlist() {
			head = NULL; // default head is NULL
		}


        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            Node* temp = head;

            if(head == NULL) {
                head = newNode;
            } else {
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void insertAtBeginning(int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

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

        }


        void deleteNode(int data) {
            Node* temp = head;
            Node* prev = NULL;

            while (temp != NULL) {
                if (temp->data == data) {
                    if (prev == NULL) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }


        void deleteNodeFromEnd() {
            Node* temp = head;
            Node* prev = NULL;

            while(temp->next != NULL) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;
        }

        void deleteNodeFromBeginning() {
            Node* temp = head;
            head = temp->next;
            delete temp;
        }

        void deleteNodeFromPosition(int position) {
            Node* temp = head;
            Node* prev = NULL;
                int count = 0;

            while(count < position - 1) {
                prev = temp;
                temp = temp->next;
                count++;
            }
            prev->next = temp->next;
            delete temp;
        }

        int sumOfLists() {
            Node* temp = head;
            int sum = 0;

            while (temp != NULL) {
                sum += temp->data;
                temp = temp->next;
            }
            return sum;
        }

        int fintIndexOf(int value) {
            Node* temp = head;
            int count = 1;

            while (temp != NULL) {  // while temp is not NULL
                if(temp->data == value) {   // if temp->data is equal to value
                    return count;   // return count
                }
                temp = temp->next; // temp is not NULL, so move to next node
                count++; // increment count
            }
            return -1;
        }

        int findNode(int index) {
            Node* temp = head;
            int count = 0;

            while (temp != NULL) {
                if (count == index) {
                    return temp->data;
                }
                temp = temp->next;
                count++;
            }
        }

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
    list.insertAtEnd(7);
    list.deleteNodeFromBeginning();
    list.printList();
    list.deleteNodeFromEnd();
    list.printList();
    list.deleteNodeFromPosition(3);
    list.printList();
	list.printList();
	cout << endl;
    list.deleteNode(2);
    list.printList();
    cout << endl;
    list.insertNodeAtPosition(8, 3);
    list.printList();
    list.fintIndexOf(8);
    cout << endl;
    cout << list.sumOfLists() << endl;
    cout << list.fintIndexOf(8) << endl;

    return 0;
}
