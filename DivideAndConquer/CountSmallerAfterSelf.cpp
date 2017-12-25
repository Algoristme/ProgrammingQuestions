//  You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

// Example:

// Given nums = [5, 2, 6, 1]

// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

// Return the array [2, 1, 1, 0]. 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> indices(nums.size(),0), res(nums.size(),0);
        
        int mid = nums.size()/2;
        
        iota(indices.begin(),indices.end(),0);
        
        countSmallerHelper(nums,indices,res,0,nums.size()) ;
        return res;
    }
    
    void countSmallerHelper(vector<int> &nums, vector<int> &indices, vector<int> &res, int first, int last) {
        int len = last-first;
        if(len<=1) return;
        int mid = first+len/2;
        
        countSmallerHelper(nums,indices,res,first,mid);
        countSmallerHelper(nums,indices,res,mid,last);
        
        // Merge process
        int p1 = first;
        int p2 = mid;
        vector<int> tmp;
        int semiCnt = 0;
        
        while(p1 < mid || p2 < last) {            
            // left is smaller than right
            if(p2 >=last || (p1 < mid && nums[indices[p1]] <= nums[indices[p2]])) {
                tmp.push_back(indices[p1]);
                res[indices[p1]] += semiCnt;
                ++p1;
            }
            else {
                tmp.push_back(indices[p2]);
                ++semiCnt;
                ++p2;
            }
        }
        move(tmp.begin(),tmp.end(),indices.begin()+first);
    }
};