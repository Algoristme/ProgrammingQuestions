// Sliding Window Maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0) return nums;
        multiset<int> windowEles;
        vector<int> out;
        for(int i = 0 ; i < nums.size(); ++i) {
            if(i <= k) {
                if(i==k){
                    out.push_back(*windowEles.rbegin());
                }
                else{
                    windowEles.emplace(nums[i]);
                    continue;
                }                
            }
            // remove the last element
            windowEles.erase(windowEles.find(nums[i-k]));
            
            // insert the curr element
            windowEles.emplace(nums[i]);            
            
            // find the max element
            out.push_back(*windowEles.rbegin());
        }
        
        if(k == nums.size()) out.push_back(*windowEles.rbegin());
        return out;
    }
};