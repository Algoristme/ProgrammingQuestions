// Max length of repeated sub array Longest Common Subarray

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        int maxLen = 0;
        for(int i = 0 ; i <= A.size(); ++i) {
            for ( int j = 0; j <= B.size(); ++j) {
                if(i==0 || j == 0) {
                    dp[i][j]  = 0;
                    
                }
                else if(A[i-1] == B[j-1]) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                    maxLen = max(dp[i][j],maxLen);
                }
            }
        }
        return maxLen;
    }
};