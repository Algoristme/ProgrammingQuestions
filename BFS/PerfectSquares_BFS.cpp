// BFS for perfect squares.

class Solution {
public:
    int numSquares(int n) {
        if(n < 0) return -1;
        queue<int> q;
        q.push(n);
        int depth = 0;
        while(!q.empty()){
            ++depth;
            int sz = q.size();                                 
            for(int i = 0; i < sz; ++i ) {             
             int curr = q.front();            
             int sr = sqrt(curr);
             q.pop();   
             for(int n = sr; n >0; --n){
                int delta = curr -(n*n);
                if(delta == 0) {
                  //cout << curr << " " << n << endl;
                  return depth;   
                }
                q.push(delta);
                //cout << "Delta " << delta << endl;
             }
            }
        }
    }
};