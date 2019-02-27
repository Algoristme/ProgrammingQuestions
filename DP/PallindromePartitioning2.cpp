// Pallindrome partitioning - 2
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> pal(len,vector<bool>(len,false));
        vector<int>cuts(len,INT_MAX);
        
        for(int epos = 0; epos < len; ++epos) {
            cuts[epos] = epos;
            for(int spos = 0; spos <= epos; ++spos) {                
                if(s[epos] == s[spos] && (epos-spos <=2 || pal[spos+1][epos-1])) {
                    pal[spos][epos] = true;
                    if(spos == 0) {
                        cuts[epos] = 0;
                    }
                    else {
                        cuts[epos] = min(cuts[spos-1]+1,cuts[epos]);
                    }
                }
            }
        }
        return cuts[len-1];
    }
};