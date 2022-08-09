// Online C++ compiler to run C++ program online
#include <iostream>

class TwoSum {
    public:
    vector<int> twoSum(verctor<int>&nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return vector<int>{map[complement], i};
            }
            else {
                map[nums[i]] = i;
            }
            }

        return vector<int>{-1, -1};
        }
    }
