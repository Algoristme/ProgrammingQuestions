In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:

    The given numbers of 0s and 1s will both not exceed 100
    The size of given string array won't exceed 600.

Example 1:

Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));        
        for(int l = 0; l < strs.size(); ++l) {
            auto res = cal(strs[l]);
            int zeros = res.first;
            int ones = res.second;
            // Rule 1 : Final soln will be in a state wher we would have used. Some nZeros (<=m) and nOnes (<=n)
            // and used max no of strings.
            // State we would be in dp[nZeros][nOnes] = maxStrings
            
            //cout << zeros << " " << ones << endl;
            // Why this should be in decreasing order ??
           
            /* If you increase them, you can use the current string multiple times but the question says we can use each string at most once.                   
            If you decrease them, you ensure that you use the current string at most once.
            Ex. ["1", "1"], m = 0, n = 2
            If you increase i and j, after the first iteration over the first "1" string, dp looks like:
            [
            [0,1,2]
            ]
            But this is wrong, dp[0][2] can't be 2 since we can only use the "1" string once, it should be 1.

            If you decrease i and j instead of increase, dp will look like:
            [
            [0,1,1]
            ]
            which is correct. */
            
            for(int i = m ; i >= zeros ; --i ) {
                for(int j = n; j >= ones; --j) {
                    if(zeros <= i && ones <=j) {
                        // Rule 1:
                        // Why are you populating dp[i][j] ??
                        // recursively define optimal soln in terms of soln to subprobs
                        dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
                        //cout << "came " << i << " " << j << " " << dp[i][j] << endl;
                    }
                    else {
                        dp[i][j] = dp[i][j];
                    }
                }
            }            
        }
        return dp[m][n];
    }
    pair<int,int> cal(string & str) {
        int zeros =0, ones = 0;
        for(auto ch : str) {
            if(ch =='1') ++ones;
            if(ch == '0') ++zeros;            
        }
        return pair<int,int>(zeros,ones);
    }
};