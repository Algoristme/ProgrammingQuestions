// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() ==0) return 0;
        int maxSum = INT_MIN;
        int currSum = 0;
        for(auto &ele : nums) {
            currSum+=ele;
            if(maxSum <= currSum){
                maxSum = currSum;
            }
            if(maxSum <= ele) {
                maxSum = ele;
            }
            if(currSum < 0) {
                currSum = 0;
            }            
        }
        return maxSum;
        
    }
};