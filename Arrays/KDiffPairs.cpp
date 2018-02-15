// K diff pairs 
// Given an array of integers and an integer k, you need to find
// the number of unique k-diff pairs in the array. Here a k-diff pair is defined
// as an integer pair (i, j), where i and j are both numbers in the array and
// their absolute difference is k.

// Example 1:

// Input: [3, 1, 4, 1, 5], k = 2 Output: 2 Explanation: There are two 2-diff
// pairs in the array, (1, 3) and (3, 5). Although we have two 1s in the input,
// we should only return the number of unique pairs.


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> valCnt;
        int pairs = 0;
        if(k < 0) return pairs;
        for(int i = 0 ; i < nums.size(); ++i) {
            // already counted
            if(valCnt[nums[i]] > 0) {
                if(k==0 && valCnt[nums[i]] == 1) ++pairs;
                ++valCnt[nums[i]];
                continue;
            }
            int key1 = nums[i]+k;
            if(valCnt[key1] > 0) ++pairs;
            
            int key2 = nums[i]-k;
            if(valCnt[key2] > 0) ++pairs;
            
            ++valCnt[nums[i]];
        }
        return pairs;
    }
};