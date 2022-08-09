#include <iostream>
#include <string>

using namespace std;

// A. Way Too Long Words

int main() {
    int n;
cin >> n;

while (n--) {
        string word;
        cin >> word;
        int len = word.length();
        if (len < 10) {
            cout << word << endl;
        } else {
            cout << word[0] << word.length() - 2 << word[word.length()-1] << endl;
            
        }

    }
    return 0;
}
