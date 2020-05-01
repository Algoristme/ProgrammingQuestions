// DP : LCS
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        
        for(int i = 0; i < text1.size(); ++i) {
            for(int j = 0; j < text2.size(); ++j) {
                dp[i+1][j+1] = text1[i] == text2[j] ? dp[i][j]+1 : max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[text1.size()][text2.size()];
    }    
};