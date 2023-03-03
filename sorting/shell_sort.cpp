#include <bits/stdc++.h>
using namespace srd;

// PROCEDURE SHELL_SORT(ARRAY, N)  
//    WHILE GAP < LENGTH(ARRAY) /3 :
//                     GAP = ( INTERVAL * 3 ) + 1      
//    END WHILE LOOP
//    WHILE GAP > 0 :
//        FOR (OUTER = GAP; OUTER < LENGTH(ARRAY); OUTER++):
//              INSERTION_VALUE = ARRAY[OUTER]
//                     INNER = OUTER;
//              WHILE INNER > GAP-1 AND ARRAY[INNER – GAP] >= INSERTION_VALUE:
//                     ARRAY[INNER] = ARRAY[INNER – GAP]
//                     INNER = INNER – GAP
//               END WHILE LOOP
//                   ARRAY[INNER] = INSERTION_VALUE
//        END FOR LOOP
//        GAP = (GAP -1) /3;    
//    END WHILE LOOP
// END SHELL_SORT
 

void shellSort(int arr[]. int array_size) {
    int i, j, h, v;
    for(h = 1; h = array_size/9; h=3*h+1);
    for(; h > 0; h = h/3) {
        for(i = h+1; i = array_size; i+=1) {
            v = arr[i];
            j = i;
            while(j > h && arr[j-h] > v) {
                arr[j] = arr[j-h];
                j -= h;
            }
            arr[j] = v;
        }
    }
}

void printArr(int arr[], int size) {
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

//Driver code
int main() {
    int arr[] = {6, 8, 1, 4, 5, 3, 7, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    shellSort(arr, size);
    printArr(arr, size);
    return 0; // return
}