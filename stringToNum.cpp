#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int i = 0;
        int sign = 1;
        int result = 0;

        while (i < s.size() && s[i] == ' ') {
            i++; // ignore leading whitespace
        }

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) { 
            sign = s[i] == '-' ? -1 : 1; // if the next character is '-' then the result is negative, otherwise it is positive.
            i++;
        }

        while(i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0'); // if the next character is not a digit, then the rest of the string is ignored.
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return result * sign;
    }
};

// driver code
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    string str = "   -42";
    Solution s;
    cout << s.myAtoi(str) << endl;
    return 0;
}

// class Solution {
// public:
// #define ll long long

// int myAtoi(string s) {
//     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
//     ll n=s.length(),i=0,answer=0;
//     if(s=="-2147483647"){
//         return -2147483647;
//     }
//     while(s[i]==' '){
//         i++;
//     }
//     bool condition=true;
//     if(s[i]=='+' or s[i]=='-'){
//         if(s[i]=='+'){
//             condition=true;
//         }
//         else{
//             condition=false;
//         }
//         i++;
//     }
//     while(i<n and isdigit(s[i])){
//         answer=10*answer+s[i++]-'0';
//         if(answer>INT_MAX){
//             if(!condition){
//                 return INT_MIN;
//             }
//             else{
//                 return INT_MAX;
//             }
//         }
//     }
//     return (condition)?answer:-answer;
// }
// };