
// C++ code to find number of unique BSTs
// Dynamic Programming solution
#include <bits/stdc++.h>
using namespace std;

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Example 1:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

    // 1         3     3      2      1
    //  \       /     /      / \      \
    //   3     2     1      1   3      2
    //  /     /       \                 \
    // 2     1         2                 3

// Example 2:

// Input: 1
// Output: 1

    // 1
    //  \
    //   1

// Constraints:

    // 1 <= n <= 19

// find number of unique BST

// solution

int numberOfBST(int n) {
    //DP to store the number of unique BST with key 1
    int dp[n+1];
    fill_n(dp, n+1, 0);

    // Base case
    dp[0] = 1;
    dp[1] = 1;

    // fill the dp table in bottom-up approach

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j<=i; j++) {

            //n-i in right * i-1 in left
            dp[i] = dp[i] + (dp[i-j] * dp[j-1]);
        }
    }
    return dp[n];
}

// driver code

int main() {
    int n = 3;
    cout << "Number of structurally unique BSTs with " << n << " keys are: " << numberOfBST(n) << endl;
    return 0;
}