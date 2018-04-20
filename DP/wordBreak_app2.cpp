class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        // dp[i] = true, if(s[0,i-1], a string of size i can be broken using word dict)
        // dp[0] = true, (Base condition, a str of len 0 can always be broken);
        dp[0] = true;
        
        unordered_set<string> dict;        
        for(auto word : wordDict) {
            dict.emplace(word);
        }
        
        // Ratinale for for loop:
        // The substring must be considered in such a way that we must have processed substring of 
        // size len-1, starting at 0 before starting to process substring of any length starting at index
        // len, this is because dp[len] depens on dp[len-1].
        // In other words substrings of all lengths len-1 must be process before considering substrings of
        // starting at index len.
        
        for(int i = 0; i <= s.size(); ++i) {
               for(int len = 1; len <= s.size()-i; ++len) {
                // the current substr of size len starting at i is in dict and
                // str(0:i-1) can be broken, this mean str(0,i+len-1) can be broken
                // a string of size len, starting at 0 can be broken into words using
                // dict.
                if(dict.find(s.substr(i,len)) != dict.end() && dp[i] == true) {
                    dp[i+len] = true;
                }
            }
        }
        return dp[s.size()];
    }
    
};