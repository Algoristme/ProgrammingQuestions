// Longest palindromic substring
class Solution {
public:
    int longestPalindromeSubseq_1(string s) {
        int size = s.size();
        if (size <= 1) {
            return size;
        }
        /*dp[i][j] means from index i to index j, the longest palindromic subsequence*/
        vector<vector<int> > dp(size + 1, vector<int> (size + 1, 0));

        /*dp initialization dp[i][i] means contains one character so it equals one*/
        for (int i = 1; i <= size; ++i) {
            dp[i][i] = 1;
        }

       /*j means move the right i means mean to left*/
       // Recurrence relation
       // if(s[i] == s[j]) dp[i,j] = dp[i+1,j-1]+2 ( add 2 to longest palindromic subseq between s[i+1:j-1])

       // else (so, i and j cannot be together, either i matches with j-1 or i+1 matched with j) 
       //   dp[i,j] = max(dp[i+1][j],dp[i][j-1])

       // Recurrence determines the order in which the matrix is filled and the way for loops are structured.

       // since i,j depends on (i+1,j+1) (i+1,j) and (i,j-1)       
       // substring of a length L can be processed only after processing all possible
       // substring of length L-1
       // substring at any index i+1 must be processed before processing substring at index i
       // this is because i depends on i+1

        for (int j = 1; j < size; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                   /*bab i = 0, j = 2  dp[0][2] = dp[1][1] + 2, and like lcs we should compare to 
                   dp[0][1] and d[1][2]  to get the longest*/
                    dp[i][j] = max(dp[i+1][j - 1] + 2, max(dp[i+1][j], dp[i][j-1]));
               }
                else {
                    dp[i][j] = max(dp[i+1][j-1],max(dp[i+1][j], dp[i][j-1]));
                }
            }
        }
        return dp[0][size - 1];
    }
    
    int longestPalindromeSubseq(string s) {
        // LPS[i][j] == if(S[i] == S[j]) LPS[i+1][j-1]+2;
        //              else max(LPS(i,j-1),LPS(i+1,j)
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
        for(int i = 0; i <= s.size(); ++i) {
            dp[i][i] = 1;
        }
        
        for(int d = 1; d < s.size(); ++d) {
            for(int i = 0; i < s.size()-d; ++i) {
                int j = i+d;
                //cout << i << " " << j << " " << s.substr(i,j-i+1) << endl;
                if(s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                //cout << dp[i][j] << endl;
            }
        }
        return dp[0][s.size()-1];
    }
};