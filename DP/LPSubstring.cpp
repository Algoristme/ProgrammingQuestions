// Longest palindromic substring
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int l = 0, r = 0;
        
        vector<vector<bool>> isPalindrome(len,vector<bool>(len,0));
        
        //b a a a b
        //0 1  2 3 4
        //j = 1 , i  = (0)  ba
        //j = 2 , i = {0,1}  -- (0,2) baa
        //                      (1,2) aa
        //j = 3 , i = {0,1,2} == (0,3) baaa
        //                       (1,3) aaa   dp[1][3] = True 
        //                                                       (2,3) aa     dp[2][3] = True
        //j = 4 , i = {0,1,2,3}  == (0,4) ===> s[0] == s[4], check substr i+1, j-1 dp[1][3] ==True, len = 5
        
        for(int j = 1; j < len; ++j) {
            for (int i = 0; i < j; ++i) {
                bool isInnerPalindrome = isPalindrome[i+1][j-1] || j-i <= 2;
                //cout << s.substr(i,j-i+1) << endl;
                if(isInnerPalindrome && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                    if(r-l < j-i) {
                        l = i;
                        r = j;
                    }
                }                
            }
        }
        return s.substr(l,r-l+1);
    }
};