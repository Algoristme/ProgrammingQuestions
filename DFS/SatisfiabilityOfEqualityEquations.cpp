// Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

class Solution {
public:
    void dfs(int curr, vector<vector<int>> &g, vector<bool> &v,vector<int> &color, int c) {
        if(v[curr]) return;
        color[curr] = c;
        v[curr] = true;
        for(auto n : g[curr]) {
            dfs(n,g,v,color,c);
        }        
    }
    bool equationsPossible(vector<string>& equations) {
        // build graph
        vector<vector<int>> adjMat;
        adjMat.resize(26);
        for(auto &str : equations) {
            if(str[1] == '=') {
                adjMat[str[0]-'a'].push_back(str[3]-'a');
                adjMat[str[3]-'a'].push_back(str[0]-'a');
            }            
        }
        vector<int> color(26,0);
        vector<bool> v(26,false);
        int c = 0;
        for(int i = 0; i < color.size(); ++i) {
            if(!v[i]) {
                dfs(i,adjMat,v,color,c);
            }
            c++;
        }
        
        for(auto &str : equations) {
            if(str[1] == '!') {
                if(!v[str[0]-'a']) c++;
                if(!v[str[3]-'a']) c++;
                if(color[str[0]-'a'] == color[str[3]-'a']) {
                    return false;
                }
            }
        }
        return true;
    }    
};