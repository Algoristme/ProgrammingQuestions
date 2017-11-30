//Longest Increasing Path in a Matrix
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        vector<pair<int,int>> directions {make_pair(1,0),
                                          make_pair(-1,0),
                                          make_pair(0,1),
                                          make_pair(0,-1)};
        
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>>v(m,vector<int>(n,0));
        int maxLen = 0; 
        for(int i = 0 ; i < m; ++i) {
            for(int j = 0; j < n; ++j) {                
                if(v[i][j] == 0) {
                    maxLen = max(maxLen,dfs(matrix,v,i,j,directions,INT_MAX));
                }
                else {
                    maxLen = max(maxLen,v[i][j]);
                }
            }
        }
        return maxLen;
    }
    
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &v, int r, int c, 
                                              vector<pair<int,int>> &directions,
                                              int prev) {
        if(r < 0 || r >=matrix.size() || c < 0 || c >= matrix[0].size()) return 0;
        if(prev <= matrix[r][c]) return 0;
        
        if(v[r][c] > 0) return v[r][c];
        int maxLen = 1;
        for(auto dir : directions) {
            int nR = r+dir.first;
            int nC = c+dir.second;
            v[r][c] = 1;
            maxLen = max(maxLen,1+dfs(matrix,v,nR,nC,directions,matrix[r][c]));
        }
        v[r][c] = maxLen;
        return v[r][c];
    }
};