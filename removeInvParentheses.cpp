#include <bits/stdc++.h>

using namespace std;

// Remove Invalid Parentheses

// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

// Return all the possible results. You may return the answer in any order.

// Input: s = "(a)())()"

// Output: ["(a)()()", "(a)()()"]

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) { // O(n)
        int n = s.length(); // length of the string
        vector<string> res; // initialize result to empty vector
        if (n == 0) { // if the string is empty
            res.push_back(""); // add empty string to the result
            return res; // return the result
        }
        unordered_set<string> visited; // initialize visited to empty set
        queue<string> q; // initialize queue to empty queue
        q.push(s); // add the string to the queue
        visited.insert(s); // add the string to the visited set
        while (!q.empty()) { // while the queue is not empty
            string curr = q.front(); // get the string from the front of the queue
            q.pop(); // remove the string from the queue
            if (isValid(curr)) { // if the string is valid
                res.push_back(curr); // add the string to the result
            }
            for (int i = 0; i < curr.size(); i++) { // for each character in the string
                if (curr[i] == '(' || curr[i] == ')') { // if the character is '(' or ')'
                    string next = curr.substr(0, i) + curr.substr(i + 1); // get the string without the character
                    if (visited.find(next) == visited.end()) { // if the string is not visited
                        q.push(next); // add the string to the queue
                        visited.insert(next); // add the string to the visited set
                    }
                }
            }
        }
        return res; // return the result
    }
    bool isValid(string s) { // O(n)
        int count = 0; 
        for (int i = 0; i < s.length(); i++) { // for each character in the string
            if (s[i] == '(') { // if the character is '('
                count++; // increment the count by 1 
            }
            else if (s[i] == ')') {  // if the character is ')'
                count--;
                if (count < 0) { // if the count is less than 0
                    return false; // return false
                }
            }
        }
        return count == 0;
    }
};

// Driver function
int main() {
    string s;
    cin >> s;
    Solution obj;
    vector<string> res = obj.removeInvalidParentheses(s);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}