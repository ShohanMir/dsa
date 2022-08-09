#include <iostream>
using namespace std;

int board[20], count;

int main() {
    int n, i, j;
    void queen(int row, int n);
    cout << "Enter the number of queens: ";
    cin >> n;
    queen(1, n);
    return 0;
}

//fucntion for printing the solution
void print(int n) {
    int i, j;
    cin << "Solution: " << ++count << endl;
    for (i = 1; i<=n; i++) {
        cin << "\t" << i;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                cout << "\t" << "Q ";
            else
                cout << "\t" << "* ";
        }
        cout << endl;
    }
}

//function for check conflicts
// If no conflict for desired position return I otherwise return

int place(int row, int column) {
    int i;
    for (i = 1; i <= row; i++) {
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

//fucntion to check the proper position of queen 
void queen(int row, int n) {
    int column;
    for (column = 1; column<=n; column++) {
        if (place(row, column)) {
            board[row] = column;
            if (row == n) {
                print(n);
            }
            else {
                queen(row + 1, n);
            }
        }
    }
}