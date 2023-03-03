#include <bits/stdc++.h>

using namespace std;

// Mathematical Circus

// A new entertainment has appeared in Buryatia — a mathematical circus! The magician shows two numbers to the audience — n and k, where n is even. Next, he takes all the integers from 1 to n, and splits them all into pairs (a,b) (each integer must be in exactly one pair) so that for each pair the integer (a+k)⋅b is divisible by 4 (note that the order of the numbers in the pair matters), or reports that, unfortunately for viewers, such a split is impossible.

// Burenka really likes such performances, so she asked her friend Tonya to be a magician, and also gave him the numbers n and k.

// Tonya is a wolf, and as you know, wolves do not perform in the circus, even in a mathematical one. Therefore, he asks you to help him. Let him know if a suitable splitting into pairs is possible, and if possible, then tell it.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. The following is a description of the input data sets.

// The single line of each test case contains two integers n and k (2≤n≤2⋅105, 0≤k≤109, n is even) — the number of integers and the number being added k.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        if (n == 2&&k==0) cout << "NO" << endl;
        if(n>=2&&k>=1) {
            if(k%2 == 1) {
                cout<<"YES"<<endl;
                for(int i=1;i<=n;i+=2) { // 1 3 5 7 9
                    cout<<i<<" "<<i+1<<endl; // 2 4 6 8 10
                }
            }
            if(k%4==2) {
                cout<<"YES"<<endl;
                for(int i=2;i<=n;i+=4) { // 2 6 10 14 18
                    cout<<i<<" "<<i-1<<endl; // 1 5 9 13 17
                }
                for(int i=3; i<=n; i+=4) { // 3 7 11 15 19
                    cout<<i<<" "<<i+1<<endl; // 4 8 12 16 20
                }
            }
            if(k%4==0)cout<<"NO"<<endl;
        }
    }
    return 0;
}