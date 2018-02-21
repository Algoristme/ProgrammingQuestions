// Is graph bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 0) return false;
        vector<pair<int,bool>> visited(graph.size());
        for(int i = 0; i < graph.size(); ++i) {
            if(!visited[i].first) {
                auto ret = dfs(visited,graph,i,0);
                if(ret == false) {
                    return false;
                }
            }
        }
        return true;
                
    }
    
    bool dfs(vector<pair<int,bool>> &visited, vector<vector<int>> &g, int curr, bool currColor) {
        if(visited[curr].first && visited[curr].second == currColor) {
            return true;
        }
        if(visited[curr].first && visited[curr].second !=currColor) {
            return false;
        }
        visited[curr].first = true;
        visited[curr].second = currColor;
        vector<int> neighbors;
        if(curr < g.size()) {
            neighbors = g[curr];
        }        
        for ( int i = 0 ; i < neighbors.size(); ++i) {
            auto ret = dfs(visited,g,neighbors[i],!currColor);
            if(ret == false) {
                return false;
            }
        }
        return true;
        
    }

};