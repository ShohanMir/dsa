#include <bits/stdc++.h>

using namespace std;

// Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) { // O(n^2)
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = s.length(); // length of the string
        int start = 0, end = 0; // initialize result to empty string
        for (int i = 0; i < n; i++) { // for each character
            int len1 = expandAroundCenter(s, i, i); // get the longest palindrome centered at i
            int len2 = expandAroundCenter(s, i, i + 1);   // get the longest palindrome centered at i and i + 1
            int len = max(len1, len2); // get the longest palindrome centered at i and either i or i + 1
            if (len > end - start) { // if the length is greater than the current result
                start = i - (len - 1) / 2; // update the result  after the length is updated
                end = i + len / 2; // update the result  after the center is updated
            }
        }
        return s.substr(start, end - start + 1);
    }
    
    int expandAroundCenter(string s, int left, int right) { // O(n)
        int L = left, R = right; // initialize left and right pointers
        while (L >= 0 && R < s.length() && s[L] == s[R]) { // while left and right pointers are valid
            L--; // move left pointer to the left
            R++; // move right pointer to the right
        }
        return R - L - 1; // return the length of the palindrome
    }
};


// Driver function
int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestPalindrome(s);
    return 0;
}