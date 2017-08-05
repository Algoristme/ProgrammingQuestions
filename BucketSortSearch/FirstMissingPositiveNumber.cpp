// 41 Find missing number
//Given an unsorted integer array, find the first missing positive integer.

//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.

//Your algorithm should run in O(n) time and uses constant space. 

// Why is this linear time?
// O(n). There is a nested loop there, but think it this way: 
// in the inner loop, we are doing swap for each A[i] ONLY 
// if A[i-1] != i, otherwise the loop breaks. 
// And for outer loop, we are just iterating through the array. 
// Therefore, we will do swap for each A[i] for at most 1 time. :)
// Complexity = Number of operations we do inside the nested loops.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++) {
            int num = nums[i];
            if(num >= nums.size() || num <0) {
               continue;
            }
            while(num < nums.size() && num >=0 && num != nums[num-1]) {
                swap(nums[i],nums[num-1]);
                num = nums[i];
            }
        }
        for(int i=0; i<nums.size();i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};