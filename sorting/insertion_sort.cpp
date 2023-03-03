#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, j, v;

    for(i = 1; i <= n-1; i++) {
        v = arr[i];
        j = i;
        while(arr[j-1] > v && j>= 1 ) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//driver code

int main() {
    int arr[] = {6, 8, 1, 4, 5, 3, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    cout << "Sorted arry" << endl;
    printArr(arr, n);
    return 0;
}