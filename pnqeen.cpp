#include <iostream>
using namespace std;

bool isSafe(int** board, int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    for (i = row, j = col; i>= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) 
            return false;
    

    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j] == 1) 
            return false;

    return true;
}


bool solveNQUtil(int** board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {

            board[i][col] = 1;

            if(solveNQUtil(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}


bool solveNQ() {
    int N;
    cin >> N;

    int** board = new int*[N];
    for (int i = 0; i<N; i++) {
        board[i] = new int[N];
        for (int j = 0; j<N; j++)
            board[i][j] = 0;
    }

    if (solveNQUtil(board, 0, N)) {
        for (int i = 0; i<N; i++) {
            for(int j = 0; j< N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    else {
            cout << "Solution does not exist";
        }

    return 0;

}

int main() {
    solveNQ();
    return 0;
}

