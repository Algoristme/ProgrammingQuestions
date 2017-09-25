// Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

// Example 1:

// Input: 
// s = "abcxyz123"
// dict = ["abc","123"]
// Output:
// "<b>abc</b>xyz<b>123</b>"

// Example 2:

// Input: 
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"


class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.size() == 0) {
            return s;
        }
        for(auto str : dict){
            findSubStr(s,str);
        }
        vector<pair<int,int>> out = mergeIntervals();

        string sbold = "<b>";
        string ebold = "</b>";
        for(int ind = out.size()-1; ind >= 0; --ind) {
            std::cout << out[ind].first << " " << out[ind].second << std::endl;            
            s.insert(out[ind].second+1,ebold);
            s.insert(out[ind].first,sbold);
        }            
        return s;
    }    
private:
    void findSubStr(string const src, string const s ) {
        for(size_t i=0; i < src.size(); ++i) {
            int j = 0;
            int curr= i;
            while(curr<src.size() && j<s.size() && s[j++] == src[curr++]){
              if(j == s.size()){
               //cout << "Matched " << s << curr-j << curr-1 << std::endl;
               subStrIntervals.emplace(curr-j,curr-1);
              }
            }           
        }
    }
    
    vector<pair<int,int>> mergeIntervals(){
        //cout << "intervals size " << subStrIntervals.size() << std::endl;
        vector<pair<int,int>> out;
        
        auto it = subStrIntervals.begin();
        if(it == subStrIntervals.end()) {
            return out;
        }
        auto prev = *it;
        if(next(it,1) == subStrIntervals.end()) {
            out.emplace_back(prev);
        }

        it++;
        while(it != subStrIntervals.end()){
            auto curr = *it;
            if(!overlapping(prev,curr)) {                               
                out.emplace_back(prev);
                prev = curr;
                if(next(it,1) == subStrIntervals.end()) {
                    out.emplace_back(curr);
                }                
            }
            else {
                prev.first = min(prev.first,curr.first);
                prev.second = max(prev.second, curr.second);     
                if(next(it,1) == subStrIntervals.end()) {
                    out.emplace_back(prev);
                }
            }
            it = ++it;
        }
        return out;
    }
    
    bool overlapping(pair<int,int> p1, pair<int,int> p2) {
        if(p2.first-p1.first>1 && p2.first-p1.second>1) {
            return false;
        }
        return true;
    }
    set<pair<int,int>> subStrIntervals; 
    
    
};