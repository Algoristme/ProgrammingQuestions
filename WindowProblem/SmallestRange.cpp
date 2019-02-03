// You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

// Example 1:

// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // process the numbers per list
        multimap<int,int> map;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j) {
                map.emplace(nums[i][j],i);
            }
        }        
        vector<int> arr(nums.size());
        int cntSet = 0;
        
        vector<int> res = {-100000, 100000};
        
        auto start = map.begin();
        auto it = map.begin();
        auto end = map.end();
        
        while( it != map.end()) {
            if(arr[it->second] == 0) {
                ++cntSet;
            }
            ++arr[it->second];
            // Valid window!
            if(cntSet == nums.size()) {                 
                end = next(it,1);
                // shrink window  
                while(start != end && cntSet == nums.size()) {
                    if(arr[start->second] > 0) {
                        --arr[start->second];
                        
                        // Update interval
                        if((it->first - start->first < res[1] - res[0]) ||
                          (it->first - start->first == res[1] - res[0] && 
                           it->first < res[0])) {
                            res[0] = start->first;
                            res[1] = it->first;
                        }
                        
                        // Loop break condition.
                        if(arr[start->second] == 0) {
                            --cntSet;
                        }
                        
                        // Actually shrink by incrementing start.
                        ++start; 
                    }
                }
            }            
            ++it;
        }
        
        return res;
    }
};