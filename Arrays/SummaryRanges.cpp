// Summary Ranges
//  Given a sorted integer array without duplicates, return the summary of its ranges.

// Example 1:

// Input: [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]

// Example 2:

// Input: [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> out;
        for(int i = 0 ; i < nums.size(); ++i) {
            string currInterval = to_string(nums[i]);
            int j = i+1;
            while(j < nums.size() && nums[i]+(j-i) == nums[j]) {
                //cout << nums[i] << " " << nums[j] << endl;
                j++;
            }
            if(j-i > 1) {
                currInterval = to_string(nums[i])+"->"+to_string(nums[j-1]);  
                i = j-1;
            }
            out.push_back(currInterval);
        }
        return out;
    }
};