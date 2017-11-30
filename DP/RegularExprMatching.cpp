// Regular Expression Matching.
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(s.size()+1,vector<bool>(p.size()+1,false));
        match[0][0] = true;
        // a*a*
        for(int i=1; i < match[0].size(); ++i) {
            if(p[i-1] == '*') {
                match[0][i] = match[0][i-2];
            }
        }
        for(int i = 1; i < match.size(); ++i) {
            for(int j = 1; j < match[0].size(); ++j) {
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    //cout << " Matching " << i-1 << " and " << j-1 <<  "  " << match[i-1][j-1] << endl;
                     match[i][j] = match[i-1][j-1];
                }
                if(p[j-1] =='*') {
                    match[i][j] = match[i][j-2];
                    if(p[j-2] =='.' || p[j-2] == s[i-1]){
                        // counting match (ch)* multiple times, so we are still stuck at j
                        match[i][j] = match[i][j] | match[i-1][j] ;                        
                    }                
                }               
            }
        }
        return match[s.size()][p.size()];
    }
};