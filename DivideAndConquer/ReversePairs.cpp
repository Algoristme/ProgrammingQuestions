// Reverse Pairs
// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

// You need to return the number of important reverse pairs in the given array.

// Example1:

// Input: [1,3,2,3,1]
// Output: 2

class Solution {
public:
   int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
   }
   int mergeSort(int l, int r, vector<int>& nums) {
        if(l>=r) return 0;
        int mid=(r-l)/2+l, count = mergeSort(l,mid,nums) + mergeSort(mid+1,r,nums);
        for(int i=l,j=mid+1;i<=mid;i++) {
            while(j<=r && nums[i]/2.0>nums[j]) j++;
            count+=j-mid-1;
        }
        int i=l,j=mid+1,k=0;
        vector<int> merge(r-l+1);
        while(i<=mid || j<=r)
            if(j>r || (i<=mid && nums[i]<=nums[j])) merge[k++]=nums[i++];
            else merge[k++]=nums[j++];
        copy(merge.begin(),merge.end(),nums.begin()+l);
        return count;
   }
};