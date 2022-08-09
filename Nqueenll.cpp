#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<string>v;
    int count = 0;

public:
    bool isSafe(int& row, int& col, int& n) {
        int i, j;

        for (i = row - 1; i >= 0; i--) {
            if (v[i][col] == 'Q')
                return false;
        }

        for (i = row-1, j = col+1; i >= 0 && j <= n; i--, j++) {
            if (v[i][j] == 'Q')
                return false;
        }

        for (i = row -1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if(v[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void solve(int& n, string& s, int l) { // l is the length of the string
        if (l == n) { // if the length of the string is equal to the n
            count++; // increment count
            return; 
        }

        for (int i = 0; i < n; i++) { // for each column
            if(v.empty() || isSafe(l, i, n)) { // if the vector is empty or if the position is safe
                string t = s; // copy the string
                t[i] = 'Q'; // add 'Q' to the string
                v.push_back(t); // add the string to the vector
                solve(n, s, l+1); // solve the problem
                v.pop_back(); // remove the string from the vector
            }
        }
    }

    int totalNQueens(int n) { // O(n^n)
        string s(n, '.');
        solve(n, s, 0);
        return count;
    }
};

int main() {
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
};