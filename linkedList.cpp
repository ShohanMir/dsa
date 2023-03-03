#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
	Node* head;

	public:
		Linkedlist() {
			head = NULL;
		}


        int findLength() {
			Node* temp = head;
			int count = 0;
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			return count;
		}

        void insertAtBeginning(int data) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }

        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            Node* temp = head;

            if (head == NULL) {
                head = newNode;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void insertAtPosition(int data, int position) {
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

        // void deleteNode(int data) {
        //     Node* temp = head;
        //     Node* prev = NULL;

        //     while(temp != NULL) {
        //         if(temp->data == data) {
        //             if(prev != NULL){
        //                 head = temp->next;
        //             } else {
        //                 prev->next = temp->next;
        //             }
        //             delete temp;
        //             break;
        //         }
        //         prev = temp;
        //         temp = temp->next;
        //     }
        // }

        void deleteNode(int data) {
			Node* temp = head; // create a temp node to traverse the list
			Node* prev = NULL; // create a prev node to store the previous node of the node to be deleted
			while (temp != NULL) { // traverse the list
				if (temp->data == data) { // if the data of the node is equal to the data to be deleted
					if (prev == NULL) { // if the node to be deleted is the head of the list
						head = temp->next; // assign the next of the node to be deleted to the head
					} else { // if the node to be deleted is not the head of the list
						prev->next = temp->next; // assign the next of the node to be deleted to the next of the previous node
					}
					delete temp; // delete the node
					break; // break the loop
				}
				prev = temp; 	// assign the previous node to the current node
				temp = temp->next; // assign the current node to the next node
			}
		}

        void deleteNodeAtBiginning() {
            Node* temp = head;
            head = temp->next;
            delete temp;
        }

        void deleteNodeAtEnd() {
            Node* temp = head;
            Node* prev = NULL;

            while (temp != NULL) {
                prev = NULL;
                temp = temp->next;
            }
            prev->next = NULL;
            delete temp;

        }

        void printList() {
            Node* temp = head;
            cout << "Linked List: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

// driver code
int main() {
	Linkedlist list;
	list.insertAtBeginning(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);

    list.deleteNode(3);
    list.deleteNodeAtBiginning();
    cout << "Lenght of the node: " << list.findLength() << endl;

    list.printList();
    return 0;
}