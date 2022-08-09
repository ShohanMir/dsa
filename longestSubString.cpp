#include <iostream>
#include <string>

using namespace std;

// Longest substring

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length(); // length of the string
            int ans = 0; // initialize result
            int i = 0, j = 0; // initialize left and right pointers
            int map[256] = {0}; // map to store the visited characters
            while (i < n && j < n) { // while there are unvisited characters
                if (map[s[j]] == 0) { // if the character is not visited
                    map[s[j]] = 1; // mark it as visited
                    j++; // move the right pointer
                    ans = max(ans, j - i); // update the answer if needed 
                } else { // if the character is already visited
                    map[s[i]] = 0; // unmark it
                    i++; // move the left pointer
                }
            }
            return ans;
        }
};

// driver function

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.lengthOfLongestSubstring(s);
    return 0;
}