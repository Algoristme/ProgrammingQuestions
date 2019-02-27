// Squareful arrays
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(),A.end());
        int cnt = 0;
        helper(A,0,cnt);
        return cnt;
    }
    
    void helper(vector<int> A, int start, int &cnt) {
        if(start >= A.size()) {
            // for(auto ele : A) {
            //     cout << ele << " " ;
            // }
            //cout << endl;
            
            ++cnt;
            return;
        }
        for(int i = start; i < A.size(); ++i) {
            if(i != start && A[i] == A[start]) continue;
            if(isSquareful(A,i, start-1)) {
                swap(A[i],A[start]);
                helper(A,start+1,cnt);
                //swap(A[i],A[start]);
            }                        
        }
    }
    
    bool isSquareful(vector<int> &A, int curr, int prev) {
        if(prev < 0) return true;
        int root(round(sqrt(A[curr]+A[prev])));
        return root*root == A[curr]+A[prev];
    }
};