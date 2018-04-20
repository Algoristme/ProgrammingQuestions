//  Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

// Example:

// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

// Note:

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> out;
        vector<int> tmp;
        int prev = -101;
        genIncSubSeq(nums,0,out,tmp,prev);
        
        vector<vector<int>> res;
        for(auto v : out) {
            res.emplace_back(v);
        }
        return res;
    }
    
    void genIncSubSeq(vector<int> &nums, int ind, set<vector<int>> &out, vector<int> tmp, int prev) {
        
        if(tmp.size() > 1) {
            out.emplace(tmp);
        }
        unordered_set<int> ht;
        // Do not generate duplicates by not adding element which was previously tried at the same ht.
        for(int i = ind; i < nums.size(); ++i) {
            if(nums[i] >= prev && ht.count(nums[i]) ==0) {
                ht.emplace(nums[i]);
                tmp.push_back(nums[i]);
                genIncSubSeq(nums,i+1,out,tmp,nums[i]);
                tmp.pop_back();
            }
        }
    }
};