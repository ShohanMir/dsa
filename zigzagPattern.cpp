#include <bits/stdc++.h>

using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

class Solution {
    public:
        string convert(string s, int numRows) { //O(n)
        ios_base::sync_with_stdio(false);
            string res = "";
            if (numRows == 1) return s; // if there is only one row, return the string as is
            int n = s.size(); // length of the string
            int i, j;

            for(i = 0; i < numRows; i++) { // for each row
                bool step = true; // true for forward, false for backward

                for (j = i; j < n;) { // j is the index of the current character in the string
                    res += s[j]; // add the current character to the result string
                    if (i == 0 || i == numRows - 1) { // if we are in the first or last row, we only need to add one character
                        j += 2*(numRows - 1); // move to the next character in the string
                        continue;
                    }
                    j += step ? 2*(numRows - i - 1) : 2*i; // move to the next character in the string
                    step = !step; // change the step
                }
            }
            return res;
        }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 3;
    cout << s.convert(str, numRows) << endl;
    return 0;
}