#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = height.size();
        int left = 0, right = n - 1;
        int area, maxArea = 0;
        while (left < right) {
            area = min(height[left], height[right]) * (right - left);
            if(area > maxArea)maxArea = area;
            (height[left] < height[right]) ? left++ : right--;
        }
        return maxArea;
    }
};

// driver Code
int main () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(height)<<endl; // 49
    return 0;
}