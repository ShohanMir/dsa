#include <bits/stdc++.h>
using namespace std;

int main() {
    int up = 0, low = 0, i;
    string s;
    cin>>s;
    for (i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            up++;
        } else {
            low++;
        }
    }
    if (up == low) {
        for (i = 0; i<s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        cout<<s<<endl;
    }

    if (up > low) {
        for (i = 0; i<s.size(); i++) {
            s[i] = toupper(s[i]);
        }
        cout<<s<<endl;
    }
    if (up < low) {
        for (i = 0; i<s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        cout<<s<<endl;
    }
    return 0;
    
}