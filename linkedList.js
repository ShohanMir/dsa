class Node {
  // O(1)
  constructor(value) {
    // O(1)
    this.value = value; // value of the node
    this.next = null;
  }
}

class LinkedList {
  // O(n)
  constructor() {
    this.head = null; // head node
    this.tail = null; // tail is the last node
    this.length = 0;
  }

  insert(value) {
    // O(n)
    this.length++; // O(1)
    let node = new Node(value); // create a new node

    if (this.tail) {
      // if there is a tail
      this.tail.next = node; // Update the tail node to tail node's next node
      this.tail = node; // Update the tail node to new node
      return node; // return the new node
    }

    this.head = this.tail = node; // if there is no head or tail
    return node; // return the new node
  }

  insertHead(value) {
    // O(1)
    this.length++; // O(1)
    let node = new Node(value); // create a new node

    if (this.head) {
      // if there is a head
      node.next = this.head; // Update the head node to head node's next node
      this.head = node; // Update the head node to new node
      return node; // return the new node
    }

    this.head = this.tail = node; // if there is no head or tail
    return node; // return the new node
  }

  removeHead() {
    // O(1)
    if (this.head) {
      // if there is a head
      this.length--; // O(1)
      const removeHead = this.head; // save the head node
      this.head = this.head.next; // Update the head node to head node's next node
      return removeHead; // return the removed head node
    }
    return undefined; // if there is no head
  }

  remove() {
    // O(n)
    if (this.tail) {
      // if there is a tail
      this.length--; // O(1)

      const tailNode = this.tail; // save the tail node

      //search for node the before the tail
      /**Traverse the list and while traversing maintain the previous node address also. By
    the time we reach the end of the list, we will have two pointers, one pointing to the
    tail node and the other pointing to the node before the tail node.**/

      let currentNode = this.head; //pointer to the head node
      while (currentNode.next != tailNode) {
        currentNode = currentNode.next; //currentNode will point to the node before the tail node
      }
      const beforeTail = currentNode; //points to the node before the tail
      this.tail = beforeTail; // Update the tail node to tail node's previous node
      this.tail.next = null; //Update previous node’s next pointer with NULL

      return tailNode; // Return the tail node
    }
    return undefined; // if there is no tail
  }

  print() {
    // O(n)
    let current = this.head; // pointer to the head node
    while (current) {
      // while current is not null
      console.log(current.value); // print the value of the current node
      current = current.next; // move to the next node
    }
  }

  // Bonus functions
  // insert at specific index

  insertIndex(value, index) {
    // O(n)
    if (index >= this.length) {
      // if the index is out of bounds
      throw new Error('Insert index out of bounds'); // throw an error
    }

    if (index === 0) {
      // if the index is 0
      return this.insertHead(value); // insert at the head
    }

    this.length++; // increment the length
    let previousNode = null; // create a new node
    let currentNode = this.head; // create a new node
    for (let i = 0; i < index; i++) {
      // traverse the list
      previousNode = currentNode; // update the previous node
      currentNode = currentNode.next; // update the current node
    }
    const newNode = new Node(value); // create a new node
    newNode.next = currentNode; // update the new node's next node
    previousNode.next = newNode; // update the previous node's next node
    return newNode; // return the new node
  }

  // remove at specific index

  removeIndex(index) {
    // O(n)
    if (index >= this.length) {
      // if the index is out of bounds
      throw new Error('Remove index out of bounds'); // throw an error
    }

    if (index === 0) {
      // if the index is 0
      return this.removeHead(); // remove at the head
    }

    this.length--; // decrement the length
    let previousNode = null; // create a new node
    let currentNode = this.head; // create a new node
    for (let i = 0; i < index; i++) {
      // traverse the list
      previousNode = currentNode; // update the previous node
      currentNode = currentNode.next; // update the current node
    }
    previousNode.next = currentNode.next; // update the previous node's next node
    return currentNode; // return the removed node
  }
}

const linkedList = new LinkedList(2);
linkedList.insert(3);
linkedList.insertHead(10);
linkedList.insertHead(10);
linkedList.insertHead(10);
linkedList.insertHead(9);
linkedList.removeIndex(2);
console.log(linkedList.length); // 3
linkedList.print(); // 10 9 8
//Linked list
