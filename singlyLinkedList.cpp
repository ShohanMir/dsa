#include <iostream>
using namespace std;

// node class to represent

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

// Linked list class to implement a linked list

class Linkedlist {
	Node* head; // head of the linked list

	public:
		// default constructor
		Linkedlist() {
			head = NULL; // default head is NULL
		}

		// function to insert a node at the end of the Linkedlist
		void insertAtEnd(int data) {
			Node* newNode = new Node(data); // create a new node
			Node* temp = head; // create a temp node to traverse the list
			if (head == NULL) {
				head = newNode; // if the list is empty, make the new node as head
			} else {
				while (temp->next != NULL) { // traverse the list till the end
					temp = temp->next; // traverse the list
				}
				temp->next = newNode; // assign the new node to the end of the list
			}
		}


		// Function to insert a node at the beginning of the linkedlist
		void insertAtBeginning(int data) {
			Node* newNode = new Node(data); // create a new node
			newNode->next = head; // assign the new node to the next of the head
			head = newNode; // make the new node as head
		}

		// Function to insert a node at a given position in the linkedlist
		void insertNodeAtPosition(int data, int position) { // position starts from 0
			Node* newNode = new Node(data);
			Node* temp = head; // create a temp node to traverse the list
			int count = 0;
			while (count < position - 1) { // traverse the list to the position before the position to be inserted
				temp = temp->next; // traverse the list
				count++; // increment the count
			}
			newNode->next = temp->next; // assign the next of the new node to the next of the node at the position
			temp->next = newNode; // assign the new node to the position
		}

		// Function to delete a node from the linkedlist
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

		// Function to delete a node from the end of the linkedlist
		void deleteNodeFromEnd() {
			Node* temp = head; // create a temp node to traverse the list
			Node* prev = NULL; // create a prev node to store the previous node of the node to be deleted
			while (temp->next != NULL) { // traverse the list till the end
				prev = temp; // assign the previous node to the current node
				temp = temp->next; // assign the current node to the next node
			}
			prev->next = NULL;
			delete temp;
		}

		// Function to delete a node from the beginning of the linkedlist
		void deleteNodeFromBeginning() {
			Node* temp = head;
			head = temp->next;
			delete temp;
		}

		// Function to delete a node from a given position in the linkedlist
		void deleteNodeFromPosition(int position) {
			Node* temp = head; // create a temp node to traverse the list
			Node* prev = NULL;  // create a prev node to store the previous node of the node to be deleted
			int count = 0;
			while (count < position - 1) {
				prev = temp;
				temp = temp->next;
				count++;
			}
			prev->next = temp->next; // assign the next of the node to be deleted to the next of the previous node
			delete temp;
		}

		// Function to print the linkedlist
		void printList() { // print the linkedlist
			Node* temp = head; // create a temp node to traverse the list
			while (temp != NULL) { // traverse the list
				cout << temp->data << " "; // print the data of the node
				temp = temp->next; // assign the next of the current node to the current node
			} 
			cout << endl; // print a new line
		}

		// Function to find the length of the linkedlist

		int findLength() {
			Node* temp = head;
			int count = 0;
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			return count;
		}

		// Function to find the middle of the linkedlist
		int findMiddle() {
			Node* temp = head;
			int count = 0;
			while (temp->next != NULL) {
				temp = temp->next;
				count++;
			}
			return count;
		}

		// Function to find the nth node from the end of the linkedlist
		int findNthFromEnd(int n) {
			Node* temp = head;
			int count = 0;
			while (temp->next != NULL) {
				temp = temp->next;
				count++;
			}
			temp = head;
			while (count > n) {
				temp = temp->next;
				count--;
			}
			return temp->data;
		}

		// Function to find the nth node from the beginning of the linkedlist
		int findNthFromBeginning(int n) {
			Node* temp = head;
			int count = 0;
			while (count < n) {
				temp = temp->next;
				count++;
			}
			return temp->data;
		}

		// Function to find the nth node from the middle of the linkedlist
		int findNthFromMiddle(int n) {
			int count = 0;
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
				count++;
			}
			int mid = count / 2;
			if (n > mid) {
				n = n - mid;
				temp = head;
				while (count > n) {
					temp = temp->next;
					count--;
				}
			} else {
				temp = head;
				while (count > mid) {
					temp = temp->next;
					count--;
				}
				while (count > n) {
					temp = temp->next;
					count--;
				}
			}
			return temp->data;
		}

		// Function to reverse the linkedlist
		void reverseList() {
			Node* temp = head;
			Node* prev = NULL;
			Node* next = NULL;
			while (temp != NULL) { 
				next = temp->next; 
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			head = prev;
		}

		// Function to reverse the linkedlist in groups of given size
		void reverseListInGroups(int size) {
			Node* temp = head;
			Node* prev = NULL;
			Node* next = NULL;
			while (temp != NULL) {
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
				if (temp != NULL && temp->next != NULL && temp->next->next != NULL) {
					temp = temp->next->next;
				}
			}
			head = prev;
		}

		// Function to find the nth node from the end of the linkedlist in groups of given size
		int findNthFromEndInGroups(int n, int size) {
			Node* temp = head;
			int count = 0;
			while (temp->next != NULL) {
				temp = temp->next;
				count++;
				if (count % size == 0) {
					temp = temp->next;
				}
			}
			temp = head;
			while (count > n) {
				temp = temp->next;
				count--;
				if (count % size == 0) {
					temp = temp->next;
				}
			}
			return temp->data;
		}

		// Function to find the nth node from the beginning of the linkedlist in groups of given size

		int findNthFromBeginningInGroups(int n, int size) {
			Node* temp = head;
			int count = 0;
			while (count < n) {
				temp = temp->next;
				count++;
				if (count % size == 0) {
					temp = temp->next;
				}
			}
			return temp->data;
		}

		// Function to find the nth node from the middle of the linkedlist in groups of given size
		int findNthFromMiddleInGroups(int n, int size) {
			int count = 0;
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
				count++;
				if (count % size == 0) {
					temp = temp->next;
				}
			}
			int mid = count / 2;
			if (n > mid) {
				n = n - mid;
				temp = head;
				while (count > n) {
					temp = temp->next;
					count--;
					if (count % size == 0) {
						temp = temp->next;
					}
				}
			} else {
				temp = head;
				while (count > mid) {
					temp = temp->next;
					count--;
					if (count % size == 0) {
						temp = temp->next;
					}
				}
				while (count > n) {
					temp = temp->next;
					count--;
					if (count % size == 0) {
						temp = temp->next;
					}
				}
			}
			return temp->data;
		}

		// Function to sum of the linkedlist

		int sumOfList() { 
			Node* temp = head; // temp is used to traverse the linkedlist
			int sum = 0; // sum is used to store the sum of the linkedlist
			while (temp != NULL) { // O(n)
				sum = sum + temp->data; 
				temp = temp->next;
			}
			return sum;
		}

		// find a value from linked list and return the index of the value
		int findIndex(int value) {
			Node* temp = head;
			int count = 0;
			while (temp != NULL) { 
				if (temp->data == value) {
					return count; // return the index of the value
				}
				temp = temp->next;	
				count++; 
			}
			return -1; // if value is not found in the linkedlist
		}



};

//driver code
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
	list.insertAtBeginning(10);
	list.insertAtBeginning(11);
	list.insertAtBeginning(12);
	list.insertAtBeginning(13);
	list.insertAtBeginning(14);
	list.insertAtBeginning(15);
	list.insertAtBeginning(16);
	list.insertAtBeginning(17);
	list.insertAtBeginning(18);
	list.insertAtBeginning(19);
	list.insertAtBeginning(20);
	list.insertAtBeginning(21);
	list.insertAtBeginning(22);
	list.insertAtBeginning(23);
	list.insertAtBeginning(24);
	list.insertAtBeginning(25);
	list.insertAtBeginning(26);
	list.insertAtBeginning(27);
	list.insertAtBeginning(28);
	list.insertAtBeginning(29);
	list.insertAtBeginning(30);
	list.insertAtBeginning(31);
	list.insertAtBeginning(32);
	list.insertAtBeginning(33);
	list.insertAtBeginning(34);
	list.insertAtBeginning(35);
	list.insertAtBeginning(36);
	list.insertAtBeginning(37);
	list.insertAtBeginning(38);
	list.insertAtBeginning(39);
	list.insertAtBeginning(40);
	list.insertAtBeginning(41);
	list.insertAtBeginning(42);
	list.insertAtBeginning(43);
	list.insertAtBeginning(44);
	list.insertAtBeginning(45);
	list.insertAtBeginning(46);
	list.insertAtBeginning(47);
	list.insertAtBeginning(48);
	list.insertAtBeginning(49);

	list.printList();
	cout << endl;
	list.deleteNode(49);
	list.printList();
	cout << endl;
	list.reverseList();
	list.printList();
	cout << endl;
	list.reverseListInGroups(5);
	list.printList();
	cout << endl;
	cout << list.findNthFromEndInGroups(5, 5) << endl;
	cout << list.findNthFromBeginningInGroups(5, 5) << endl;
	cout << list.findNthFromMiddleInGroups(5, 5) << endl;
	return 0;
}
