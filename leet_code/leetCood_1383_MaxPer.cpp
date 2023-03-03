#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ios_base::sync_with_stdio(false);
        int MOD = 1e9 + 7;
        vector<pair<int, int>> candidates(n);
        for(int i = 0; i < n; i++) candidates[i] = {efficiency[i], speed[i]};

        sort(candidates.rbegin(), candidates.rend());
        long speedSum = 0, ans = 0;

        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto& [e,s] : candidates) {
            pq.push(s);
            speedSum += s;
            if(pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speedSum * e);
        }
        return ans%MOD;
    }
};

int main() {
    Solution s;
    int n, k, a, b;
    cin>>n;
    vector<int> efficiency, speed;
    for(int i=0;i<n; i++){
        cin>>a;
        cin>>b;
        efficiency.push_back(a);
        speed.push_back(b);
    };
    cin>>k;

    s.maxPerformance(n, speed, efficiency, k);
    
    return 0;
}