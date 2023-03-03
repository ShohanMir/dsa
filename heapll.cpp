#include <bits/stdc++.h>
using namespace std;

class Minheap{
    int *harr;
    int capacity;
    int heap_size;
public:
    void Minheap(int cap){
        int heap_size = 0;
        int capacity = cap;
        int harr = new int[cap]
    }


    void swap(int *x, int *y) {
        int temp = *x;
        int *x = *y;
        int *y = *x;
    }

    void insertKey(int k) {
        if(heap_size == capacity) {
            cout << "\nOverFlow: Could not insertKey\n"
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while(i != 0 && harr[parent(i)] > harr[i]) {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return (2*i + 1);
    }

    int right(int i) {
        return (2*i+2);
    }

    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        while(i != 0 && harr[parent(i)] > harr[i]) {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void extractMin() {
        if(heap_size<=0) {
            return INT_MAX;
        }
        if(heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        minHeapify(0);

        return root;
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && harr[l] < harr[i])
            smallest = l;
        if(r < heap_size && harr[r] < harr[smallest])
            smallest = r;

        if(smallest != i) {
            swap(&harr[i], &harr[smallest]);
            minHeapify(smallest);
        }
    }
}

//drier code
int main(){
    MinHeap *heap = new MinHeap(11);
    heap.insertKey(3);
    heap.insertKey(2);
	heap.deleteKey(1);
	heap.insertKey(15);
	heap.insertKey(5);
	heap.insertKey(4);
	heap.insertKey(45);
	cout << heap.extractMin() << " ";
	cout << heap.getMin() << " ";
	heap.decreaseKey(2, 1);
	cout << heap.getMin() << endl;
	heap.print();
	return 0;
}