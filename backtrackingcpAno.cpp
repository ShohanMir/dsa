#include <iostream>
using namespace std;

// to check if the arr[row][col] == 1  or not

int board[20]
bool isSafe(int x, int y, int n) {
    for (int row=0; row < x - 1; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }

// To check upper left diagonal
    int row = x;
    int col = y;
    while (row>=0 && col>=0) {
        if(arr[row][col] ==1){
            return false;
        }

        row--;
        col--;
    }

// To check upper right digonal
    row = x;
    col = y;
    while (row>=0 && col<n) {
        if(arr[row][col] ==1){
            return false;
        }

        row--;
        col++;
    }
    return true;

}

// Solve nqueens problem using backtracking
bool nQueen(int**arr, int x, int n) {
    if (x >= n) {
        return true;
    }
    // check if queen can be placed in the row and column
    for (int col=0; col<n; col++) {
        if (isSafe(arr, x, col, n)) {
            arr[x][col] = 1;
            
            // move to the another row
            if (nQueen(arr, x + 1, n)) {
                return true;
            }

            arr[x][col] = 0; //backtracking
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

// memory allocation for the 2d array
    int** arr=new int*[n];
    for (int i=0; i<n; i++) {
        arr[i] = new int[n];
        for (int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr, 0, n)) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Solution does not exist" << endl;
    }
    return 0;
}