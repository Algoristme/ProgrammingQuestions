//Network Delay Time

// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w),
// where u is the source node, v is the target node, and w is the time it
// takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all
// nodes to receive the signal? If it is impossible, return -1.

// Note:

//     N will be in the range [1, 100]. K will be in the range [1, N]. The
//     length of times will be in the range [1, 6000]. All edges times[i] =
//     (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> g(N);
        for(int i=0; i < times.size() ; ++i) {
            //cout << i << endl;
            pair<int,int> nbr(times[i][1]-1,times[i][2]);
            int node = times[i][0]-1;
            g[node].emplace_back(nbr);
        }
        //cout << "Came here " << endl;
        vector<int> visited(N,INT_MAX); 
        int time = 0;
        dfs(g,visited,K-1,0);
        for(int i =0; i < N; ++i) {
            //if( i == K-1) continue;
            if(visited[i] == INT_MAX) return -1;
            else
                time = max(time,visited[i]);
        }
        return time;
    }
    
    void dfs(vector<vector<pair<int,int>>> &g, vector<int> &visited, int K, int time) {
        if( time >= visited[K]) {
            return;
        }
        visited[K] = time;
        auto nbrs = g[K];
        for(int i = 0; i < nbrs.size(); ++i) {
            dfs(g,visited,nbrs[i].first,time+nbrs[i].second);
        }
    }

};