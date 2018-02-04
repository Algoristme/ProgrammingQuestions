// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

// If possible, output any possible result.  If not possible, return the empty string.

// Example 1:

// Input: S = "aab"
// Output: "aba"

// Example 2:

// Input: S = "aaab"
// Output: ""


class Solution {
public:
    string reorganizeString(string S) {
        string res = "";
        map<char,int> cntMap;
        for(int i = 0; i < S.size(); ++i) {
            cntMap[S[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto p : cntMap) {
            if(p.second > (S.size()+1)/2) return "";
            pq.emplace(p.second,p.first);
        }
        pair<int,char> prev(0,' ');
        while(!pq.empty()) {
            auto curr = pq.top();
            //cout << curr.first << " " << curr.second << endl;
            pq.pop();
            //if(res[res.size()-1] !=curr.second) {
                res += curr.second;                
            //}
            //else {
                //return "";
            //}
            --curr.first;            
            if(prev.first>0) {
                pq.emplace(prev);
            }
            prev = curr;
        }
        
        return res;
    }
};