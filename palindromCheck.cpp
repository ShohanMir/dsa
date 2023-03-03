#include <bits/stdc++.h>

using namespace std;

int solution(int x) {
    int reverse = 0;
    int temp = x;

    while (temp != 0) {
        reverse = (reverse * 10) + (temp%10);
        temp /= 10;
    }
    return (reverse == x);
};

// driver Code


int main () {
 
    // Some Testcases...
    int num = 12321;
    cout<<solution(num)<<endl; // Yes
 
    return 0;
 
}