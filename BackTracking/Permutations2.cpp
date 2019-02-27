// 121
//                                                     swap(1,2)      ----> 33
// 1 - true                                            2 - true       ----> 31
// 1 (2,1)                                                  2 (1,1)   ----> 34
//    2 - true         1- true                              1 - true              1, in map and true return 
// 	   12(1)          11(2)                                  21(1)         
// 			 1 - true     2 - true                                   1 - true    
// (1,2,1)              (1,1,2)                                211

//  Duplicates happen when u swap a number with itself. Avoid swapping numbers with themselves using a map

// Explanation
// https://www.youtube.com/watch?v=AsxVqSKPo40
// https://www.youtube.com/watch?v=eUnNw2lR01M


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> l;
        permute(l,nums,0);
        return l;
    }
    
    void permute(vector<vector<int>> &l, vector<int> &A, int start) {
        if(start == A.size()-1) {
            l.push_back(A);
        }
        unordered_map<int,bool> visited;
        for(int i = start; i < A.size(); ++i) {
            if(visited[A[i]]) continue;
            visited[A[i]] = true;
            swap(A[i],A[start]);
            permute(l,A,start+1);
            swap(A[i],A[start]);
        }
     }
};