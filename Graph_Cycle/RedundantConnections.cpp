//Union find cycle, Redundant Connections

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> repMap;
        vector<int> out(2);
        for(auto e : edges) {
            int p0 = getParent(e[0],repMap);
            int p1 = getParent(e[1],repMap);
            
            if(p0 == p1) {
                out = e;
            }
            else {
                if(p0<p1) {
                    repMap[p1] = p0;
                }
                else {
                    repMap[p0] = p1;
                }
            }
        }
        return out;
    }
    
    int getParent(int node, unordered_map<int,int> &repMap) {
        int parent = node;
        while(repMap.find(parent)!=repMap.end()){
            parent = repMap.find(parent)->second;
        }
        return parent;
    }
};