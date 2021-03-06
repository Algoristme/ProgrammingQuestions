// DFS for perfect squares.

class Solution {
public:
    int numSquares(int n) {
        int least = INT_MAX;
        dfs(n,0,least);
        return least;
    }
    
    void dfs(int target, int cnt, int &least) {
        if(cnt >= least) {
            return;
        }
        if(target == 0) {
            least = min(cnt,least);
            return;
        }
        if(target < 0) {
            return;
        }
        int start = sqrt(target);
        for(int i = start; i >=1; --i) {
            int sum = target -(i*i);
            dfs(sum,cnt+1,least);
        }
    }
};