// Word Break Dynamic Programming
// Recurrence:

// match[i] = true if s.substr(0,i) is word that exists in the dictionary.
// Remember: match[i] is TRUE if substring of length i starting from 0 can be matched.
// for all substrings of length len starting at some j, if match[j+len] = true iff match[j] = true.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> match(s.size+1,false);
        unordered_set<string> dict;
        for(auto word : wordDict) {
            dict.emplace(word);
        }
        match[0] = true;
        for(int i = 0 ; i < s.size(); ++i) {
            for(int len = 1; len <= s.size()-i;++len) {
                string str = s.substr(i,len);
                //cout << str << endl;
                if(dict.find(str) != dict.end() && match[i]){
                    cout << i << " " << i+len << endl;
                    match[i+len] = true;
                }
            }
        }
        return match[s.size()];
        
    }
};