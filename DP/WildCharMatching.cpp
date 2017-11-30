// Wildchar Matching.

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> check(s.size()+1,vector<bool>(p.size()+1,false));
        check[0][0] = true;
        for(int i = 1; i <= p.size(); ++i) {
            if(p[i-1] == '*') {
                check[0][i] = check[0][i-1];
            }
        }
        
        for(int i = 1; i <= s.size(); ++i) {
            for( int j = 1; j <= p.size(); ++j) {
                if(p[j-1] != '*') {
                    if(p[j-1] == s[i-1] || p[j-1] =='?') {
                        check[i][j] = check[i-1][j-1];
                    }                    
                }
                else {
                    // Match something                    
                    // Match nothing
                    check[i][j] = check[i][j-1] | check[i-1][j];
                }
            }            
        }
        
        return check[s.size()][p.size()];
    }
};