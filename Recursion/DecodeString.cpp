//Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
//Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
//Please notice that the 'pos' is passed by reference, use it to record the position of the original string we are looking at.

class Solution {
public:
    string decodeString(string s) {
        int ind = 0;
        return dfs(s,ind);
    }
    string dfs(string s, int &ind) {
        string w = "";
        for(;ind < s.length();++ind) {
            if(s[ind] ==']') {
                return w;
            }
            else if(s[ind] >='0' && s[ind] <='9')  {
                int num = 0;
                while(s[ind] >='0' && s[ind] <='9') {
                    num = num*10+(s[ind]-'0');
                    ++ind;
                }
                // skip '[' which follows digs
                ++ind;
                string curr = dfs(s,ind);
                for(int i = 0 ; i < num; ++i) {
                    w += curr;
                }
            }
            else {
                w +=s[ind];
            }            
        }
        return w;
    }
    
};