//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

//Your algorithm should run in O(n) complexity. 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // put stuff in set
        unordered_set<int> numSet;
        for ( int i = 0; i < nums.size(); i++) {
            numSet.emplace(nums[i]);
        }
        int longest = 0;
        int currLen = 0;
        for(int i=0; i<nums.size();i++) {            
            int high = nums[i];
            int low = high-1;
            currLen = 0;
            if(numSet.size()==0) {
                break;
            }
            
            for(auto it = numSet.find(high); it !=numSet.end();) {
                ++high;                
                ++currLen;                
                numSet.erase(it);
                it = numSet.find(high);
                //cout << "came here " << high << endl;
            }
            
            for(auto it = numSet.find(low); it!=numSet.end();) {
                --low;                
                ++currLen;
                numSet.erase(it);
                it = numSet.find(low);
                //cout << "came here " << low << endl;
            }
            
            if(currLen > longest) {
                    longest = currLen;
            }
            
        }
        return longest;
    }
};