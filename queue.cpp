#include <bits/stdc++.h>

using namespace std;

//implementing queue

class Queue {
    public:
        int front, rear, size; // front, rear, size are the indices of the queue
        unsigned capacity; // capacity is the maximum size of the queue
        int *array; // array is the array of the queue
};

Queue* createQueue(unsigned capacity) { // O(1)
    Queue* queue = new Queue(); // initialize queue to new queue
    queue->capacity = capacity; // set the capacity of the queue to capacity
    queue->front = queue->size = 0; // set the front and size of the queue to 0

    queue->rear = capacity - 1; // set the rear of the queue to capacity - 1
    queue->array = new int[queue->capacity]; // initialize the array of the queue to new int array of capacity
    return queue; // return the queue
}

int isFull(Queue* queue) { // O(1)
    return (queue->size == queue->capacity); // return true if the size of the queue is equal to the capacity of the queue
}
 
int isEmpty(Queue* queue) { // O(1)
    return (queue->size == 0); // return true if the size of the queue is 0
}

// Dynamicly resize the queue
void resizeQue(Queue* queue) {
    int* temp = new int[queue->capacity * 2]; // initialize temp to new int array of capacity * 2
    for (int i = 0; i < queue->size; i++) { // for each element in the queue
        temp[i] = queue->array[(i + queue->front) % queue->capacity]; // add the element to the temp array
    }
    delete[] queue->array; // delete the array of the queue
    queue->array = temp; // set the array of the queue to temp
    queue->front = 0; // set the front of the queue to 0
    queue->rear = queue->size - 1; // set the rear of the queue to size - 1
    queue->capacity = queue->capacity * 2; // set the capacity of the queue to capacity * 2
}

void enqueue(Queue* queue, int item) { // O(1)
    if (isFull(queue)) {  // if the queue is full
        // cout << "Queue is full" << endl; // print "Queue is full"
        resizeQue(queue);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;  //circular queue 
    queue->array[queue->rear] = item; // add item to the rear
    queue->size = queue->size + 1; // increment size
    cout << item << " Enqueued to queue" << endl; // print the item enqueued
}

// Resize the queue

// void resize(Queue* queue, unsigned capacity) { // O(n)
//     int* temp = new int[capacity]; // initialize temp to new int array of capacity
//     for (int i = 0; i < queue->size; i++) { // for each element in the queue
//         temp[i] = queue->array[(i + queue->front) % queue->capacity]; // add the element to the temp array
//     }
//     delete[] queue->array; // delete the array of the queue
//     queue->array = temp; // set the array of the queue to temp
//     queue->front = 0; // set the front of the queue to 0
//     queue->rear = queue->size - 1; // set the rear of the queue to size - 1
//     queue->capacity = capacity; // set the capacity of the queue to capacity
// }


int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty" << endl; // print "Queue is empty"
        return INT_MIN; // return INT_MIN
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity; // circular queue
    queue->size = queue->size - 1;  // decrement size
    return item; // return the item dequeued
}

int front(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN; // return INT_MIN

    return queue->array[queue->front]; // return the item at the front
}

int rear(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN; // return INT_MIN
    
    return queue->array[queue->rear]; // return the item at the rear
}

void deleteQueue(Queue* queue) { // O(1)
    delete[] queue->array; // delete the array of the queue
    delete queue; // delete the queue
}

// display queue
void display(Queue* queue) { // O(n)
    if (isEmpty(queue)) { // if the queue is empty
        cout << "Queue is empty" << endl; // print "Queue is empty"
        return; // return
    }
    cout << "Queue contains: "; // print "Queue contains: "
    for (int i = queue->front; i <= queue->rear; i++) { // for i from the front to the rear
        cout << queue->array[i] << " "; // print the item at i
    }
    cout << endl; // print new line
}

// Driver code
int main() {
    Queue* queue = createQueue(10); // create a queue of capacity 100

    enqueue(queue, 1); // enqueue 1
    enqueue(queue, 2); // enqueue 2
    enqueue(queue, 3); // enqueue 3
    enqueue(queue, 4); // enqueue 4
    enqueue(queue, 5); // enqueue 5
    enqueue(queue, 6); // enqueue 6
    enqueue(queue, 7); // enqueue 7
    enqueue(queue, 8); // enqueue 8
    enqueue(queue, 9); // enqueue 9
    enqueue(queue, 10); // enqueue 10
    enqueue(queue, 11); // enqueue 11
    enqueue(queue, 12); // enqueue 12
    enqueue(queue, 13); // enqueue 13

    cout << dequeue(queue) << " Dequeued from queue" << endl; // dequeue and print the item dequeued

    cout << "Front item: " << front(queue) << endl; // print the item at the front
    cout << "Rear item: " << rear(queue) << endl; // print the item at the
    display(queue); // display the queue

    return 0;
};