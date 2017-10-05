// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]

// You should return [1,2,3,6,9,8,7,4,5]. 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector <int> out;
       if(nums.size() == 0)   return out;
       if(nums[0].size() == 0) return out;
        
        int rowStart = 0, rowEnd = nums.size()-1;
        int colStart = 0, colEnd = nums[0].size()-1;
        
        while(rowStart <= rowEnd && colStart <= colEnd) {
            // right 
            int j = colStart;
            while(j <= colEnd ){
                out.push_back(nums[rowStart][j++]);                
            }
            ++rowStart;
            if(rowStart > rowEnd) break;
            // down
            int i = rowStart;
            while(i <= rowEnd) {
                out.push_back(nums[i++][colEnd]);                
            }
            --colEnd;
            if(colStart > colEnd) break;
            // left
            j = colEnd;
            while( j>=colStart) {
                out.push_back(nums[rowEnd][j--]);
            }
            --rowEnd;
            // up
            i = rowEnd;
            while(i>=rowStart) {
                out.push_back(nums[i--][colStart]);
            }
            ++colStart;
        }
        return out;
    }
};