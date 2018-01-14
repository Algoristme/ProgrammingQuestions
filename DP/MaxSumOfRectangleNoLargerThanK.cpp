// Max Rectangle no less than k ( Kadane's Algo)
// https://leetcode.com/submissions/detail/134652939/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        if(!rows) return 0;
        
        int cols = matrix[0].size();
        if(!cols) return 0;
        
        int res = INT_MIN;
        
        for(int left = 0; left < cols; ++left) {
            vector<int> rowSum(rows,0);
            for ( int right = left; right < cols; ++right) {
                for(int i = 0 ; i < rows; ++i) {
                    rowSum[i]+=matrix[i][right];
                }                        
            // kadanes algo to find max sub array whos sum <= k
            set<int> accruSet = {0};
            int cumSum = 0;
            int maxRect = INT_MIN;
            accruSet.emplace(cumSum);

            for(int i = 0; i < rows; ++i) {
                cumSum+=rowSum[i];
                // why lower bound?
                // if K = 8, curSum = 4 the set will first search if there is (4-8) == -4 if not found it will return the 
                // next number greater than -4 say it were 5, we are still ok as 4-5 = 1 which is still less than K
                // its not worthy to return number > 5 as 4 - 7 while still less than 8 is also than 4 -5 which is what
                // we are interested to find, largest j - i <= k

                //  why cumSum - k ? why not vice versa ? 
                // looking for i such that j-i = k => j-k = i;
                auto it = accruSet.lower_bound(cumSum-k);
                if(it != accruSet.end()) {
                    maxRect = max(maxRect, cumSum - *it);
                }
                accruSet.emplace(cumSum);
                res = max(res,maxRect);
            } // End Kadane's  
            } // End Right iteration
        } // End left iteration
        return res;
    }
};