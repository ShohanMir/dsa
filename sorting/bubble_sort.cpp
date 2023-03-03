#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Follow the below steps to solve the problem:

// Run a nested for loop to traverse the input array using two variables i and j, such that 0 ≤ i < n-1 and 0 ≤ j < n-i-1
// If arr[j] is greater than arr[j+1] then swap these adjacent elements, else move on
// Print the sorted array
// Below is the implementation of the above approach:
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // swap(arr[j], arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }                 
        }
    }
}

// void bubbleSort(int arr[], int n)
// {
//     int i, j;
//     for (i = 0; i < n - 1; i++)
 
//         // Last i elements are already
//         // in place
//         for (j = 0; j < n - i - 1; j++)
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]);
// }

void printArry(int arr[], int size) {
    int i;
    for(i = 0; i<size; i++)
        cout << arr[i] << ' ';
        
    cout << endl;

}
// Time Complexity: O(N2)
// Auxiliary Space: O(1) 

// Optimized Implementation of Bubble Sort: 

void bubbleSortOptimize(int arr[], int n) {
    int i, j;
    bool swapped;
    for(i = 0; i < n - 1; i++) {
        swapped = false;
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]){
                // swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
    }
}
// Time Complexity: O(N2)
// Auxiliary Space: O(1)

// Recursive Implementation Of Bubble Sort:
void recursiveBubbleSort(int arr[], int n) {
    if (n == 0 || n == 1){
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    recursiveBubbleSort(arr, n-1);
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int N = sizeof(arr)/sizeof(arr[0]);

    // auto start = high_resolution_clock::now();
    // bubbleSort(arr, N);
    // auto stop = high_resolution_clock::now();

    cout << "Sorted arry" << endl;
    printArry(arr, N);

    cout << "optimze bubble sort:" << endl;
    // auto start = high_resolution_clock::now();
    // bubbleSortOptimize(arr, N);
    // auto stop = high_resolution_clock::now();
    // printArry(arr, N);

    cout << "Recursive bubble sort:" << endl;
    auto start = high_resolution_clock::now();
    recursiveBubbleSort(arr, N);
    auto stop = high_resolution_clock::now();
    printArry(arr, N);
 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}