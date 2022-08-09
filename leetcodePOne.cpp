#include <iostream>
#include <string>
#include <vector>


// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

using namespace std;

class NumArray {
public:
    vector<int>v; //vector to store input vector.
    int sum; //sum of all element of vector 
    NumArray(vector<int>& nums) {
        v=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=v[index];     //subtract old element  from sum at index and then update by adding new element val.
        v[index]=val;
        sum+=val;
        
    }
    
    int sumRange(int left, int right) {
        int res=sum; 
        for(int i=0;i<left;i++){    //subtract all element before left and after right
            res-=v[i];
        }
        for(int i=right+1;i<v.size();i++){
            res-=v[i];
        }
        return res;// return res ie. our answer.
    }
};

// class NumArray {
//     int sum;

// public:
//     NumArray(vector<int> nums) {
//         int n = nums.size();
//         sum = new int[n];
//         sum[0] = nums[0];
//         for (int i = 1; i < n; i++) {
//             sum[i] = sum[i - 1] + nums[i];
//         }
//     }
    
//     void update(int i, int val) {
//         sum[i] = sum[i - 1] + val - nums[i];
//     }
    
//     int sumRange(int i, int j) {
//         return sum[j] - (i > 0 ? sum[i - 1] : 0);
//     }
// };