// Longest increasing subsequence

class Solution {
public:
    
    // Efficient soln
    
    int lengthOfLIS(vector<int>& nums) {
        // LS is vector of longest increasing subseq
        // in sorted order. 
        // For every nums[i], 
        //   if LS[LS.size()-1] < i extend LS
        //   else replace, the smallest number greater than nums[i]
        
        if(nums.size() == 0)  return 0;
        set<int> LS = {nums[0]};
        
        for(int i = 1; i < nums.size(); ++i) {
            auto it = LS.lower_bound(nums[i]);
            if(it != LS.end()) {
                LS.erase(it);
            }
            
            LS.emplace(nums[i]);
        }
        
        return LS.size();
    }
    
    // Bottom up DP Soln.
    int lengthOfLISDP(vector<int>& nums) {
        // Bottom up DP
        // Recurrence relation :
        // LS(i) = len of longest increasing subseq ending @ i
        // LS (i) = 1 + (0,max(LS(j) for all j < i where nums[j] < nums[i]))
        //
        // j = 0,2,3 are less tha i = 5
        // Eg. LS(5) =  1 + max(LS(0),LS(2),LS(3))
        if(nums.size() ==0 ) return 0;
        int maxLen = 1;
        
        vector<int> LS(nums.size(),1);
        LS[0] = 1; // Base case
        // finding all LS[i] for i = 1 to nums.size()-1
        for(int i = 1; i < nums.size(); ++i) {
            for( int j = 0; j <i ; ++j) {
                if(nums[j] < nums[i] && LS[j]+1> LS[i]) {
                    LS[i] =LS[j]+1;
                }
            }
            maxLen = max(maxLen,LS[i]);
        }
        
        return maxLen;
        
    }
};