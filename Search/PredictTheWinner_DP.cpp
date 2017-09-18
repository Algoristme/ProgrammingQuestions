// Predict Winner DP Solution.

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // If there are only two eles, P1 picks max of the two.
        if(nums.size()==2) return true;
        
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        
        int myBest = computeMyScores(nums,dp,0, nums.size()-1);
        
        return (myBest*2 >= accumulate(nums.begin(),nums.end(),0));
        
    }
    
    int computeMyScores(vector<int> &nums, vector<vector<int>> &dp, int i, int j) {
        if(i>j)  return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = nums[i]+min(computeMyScores(nums,dp,i+1,j-1),computeMyScores(nums,dp,i+2,j));
        int right = nums[j] + min(computeMyScores(nums,dp,i,j-2),computeMyScores(nums,dp,i+1,j-1));
        
        dp[i][j] = max(left,right);
        
        return dp[i][j];
    }
};
