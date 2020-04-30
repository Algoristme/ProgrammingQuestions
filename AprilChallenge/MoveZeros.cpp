// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Note:

//     You must do this in-place without making a copy of the array.
//     Minimize the total number of operations.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int swapIndex = -1;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] !=0 && swapIndex != -1) {
                nums[swapIndex] = nums[i];
                ++swapIndex;
            }
            else if(nums[i] == 0 && swapIndex == -1) {
                swapIndex = i;
            }
            if(nums[i] == 0) ++cnt;
        }
        if(cnt == nums.size()) return;
        for(int i = nums.size()-cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};