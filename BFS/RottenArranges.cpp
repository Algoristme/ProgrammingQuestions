// Rotten oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r_off[] = {1,0,-1,0};
        int c_off[] = {0,1,0,-1};
        int oranges = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0 ; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    //cout << " Found " << endl;
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 1) ++oranges;
            }
        }
        if(!oranges) return 0;
        int minTime = 0;
        while(!q.empty()) {
            int qSize = q.size();
            for(int i = 0; i < qSize;  ++i) {
                auto p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;
                //cout << "Popping " << r << " " << c << " " << qSize << endl;
                for(int x = 0, y = 0 ; x < 4 ; ++x,++y) {
                    int nr = r+r_off[x];
                    int nc = c+c_off[y];
                    if(nr < 0 || nr >= grid.size()) continue;
                    if(nc < 0 || nc >= grid[0].size()) continue;
                    //cout << " Neighs " << nr << " " << nc << endl;
                    if(grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push(make_pair(nr,nc));
                        //cout << " pushed " << nr << " " << nc << endl;
                        --oranges;
                    }
                }
            }
            //cout << " going " << endl;
            if(!q.empty()) ++minTime;
        }
        
        return oranges == 0 ? minTime : -1;
        
    }
};