// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

// Constraints:

//     1 <= nums.length <= 3 * 10^4
//     0 <= nums[i][j] <= 10^5


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxCanGo = nums[0];        
        for(int i = 1; i < nums.size(); ++i) {
            if(i <= maxCanGo) {
                maxCanGo = max(maxCanGo,i+nums[i]);
            }Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 3 * 10^4
    0 <= nums[i][j] <= 10^5


            if(maxCanGo >= nums.size()-1) return true;
        }
        return maxCanGo >= nums.size()-1;
    }
    
    void helper(int index, vector<int> &nums, bool &r) {
        if(r) return ;
        if(index >= nums.size()-1 || nums[index] >= nums.size()-1) {
            r = true;
            return;
        }
        if(nums[index] == 0) {
            return;
        }
        for(int i = nums[index]; i > 0  ; --i) {
            helper(index+i,nums,r);
            if(r) return;
        }
        
    }
};