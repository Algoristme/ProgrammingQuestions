// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        vector<vector<pair<int,int>>> cnt(matrix.size(),vector<pair<int,int>>(matrix[0].size(), {0,0}));
        
        int maxArea = 0;
        
        for(int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][0] == '1') {
                cnt[i][0] = pair<int,int>(1,1);
                maxArea = 1;
            }                        
        }
        
        for(int j = 0; j < matrix[0].size();++j) {
            if(matrix[0][j]=='1') {
                cnt[0][j] = pair<int,int>(1,1);
                maxArea = 1;
            }
        }
                
        
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {        
                if(matrix[i][j]=='1'){
                    int row = min(cnt[i-1][j].first, min(cnt[i-1][j-1].first, cnt[i][j-1].first))+1;
                    int col = min(cnt[i-1][j].second, min(cnt[i-1][j-1].second, cnt[i][j-1].second))+1;

                    cnt[i][j] = {row,col};
                    if(row == col) {
                    maxArea = max(maxArea, row * row);
                    }

                }                
            }
        }
        
        return maxArea;
    }
};