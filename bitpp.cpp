#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	
	while (n--) {
		string x;
		cin>>x;
		
		int num =  0;
		
		if (x == "++X"){
			num = num + 1;
			cout << num;
		} else if (x == "--X") {
			num = num - 1;
			cout << num;
		} else {
			cout << 0;
		}
		
		//cout << num;
	}
		
	return 0;
};
