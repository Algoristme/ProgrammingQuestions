// Subset-ii

// Given a collection of integers that might contain duplicates, nums, return all possible subsets.

// Note: The solution set must not contain duplicate subsets.

// For example,
// If nums = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {        
        if(nums.size()==0) { 
            subsets.push_back(nums);
            return subsets;
        }
        sort(nums.begin(),nums.end());
        vector<int> subset;
        helper(nums,subset,0);
        return subsets;
    }
    
    void helper(vector<int>& nums, vector<int> ss, int ind) {
        subsets.push_back(ss);
        int pop = INT_MIN;
        for(int i = ind; i < nums.size(); ++i) {
            // if the number that just popped was
            // the same number don't do anything.
            if(nums[i] == pop) continue;
            //choose this num   
            //cout << " pushing " << nums[i] << endl;
            ss.push_back(nums[i]);
            helper(nums,ss,i+1);
            //cout << "popping " << nums[i] << endl;
            pop = nums[i];
            ss.pop_back();
        }
    }
private:
    vector<vector<int>> subsets;
};