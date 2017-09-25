// Sort Tx array
//  Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

// The returned array must be in sorted order.

// Expected time complexity: O(n)

// Example:

// nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

// Result: [3, 9, 15, 33]

// nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

// Result: [-23, -5, 1, 7]


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> out;
        if(nums.size()==0) return out;
        if(a==0 && b==0) {
            vector<int> res(nums.size(),c);
            return res;
        }
       
        for( auto num : nums) {
            out.push_back(a*num*num+b*num+c);
            //cout << a*num*num+b*num+c << " ";
        }
        //cout << endl;

        vector<int> merge;        
        if(a<0) {
            int low = 0;
            int high = out.size()-1;
            while( low <= high) {
                if(out[low] <= out[high]) {
                    merge.push_back(out[low++]);
                }
                else {
                    merge.push_back(out[high--]);
                }
            }
            return merge;
        }
        else {
            int low = 0;
            // find the index of lowest point in parabola.
            for(;low < out.size()-1; ++low) {
                if(out[low] < out[low+1]) break;
            }
            int high = low+1;
            while(high-low <= out.size()) {
                // if the left sub array is over copy over the remaining elements 
                // into merged.
                if(high == out.size() || (low >= 0 && out[low] <= out[high])) {
                    merge.push_back(out[low--]);
                }
                // if the left sub array is over, copy over the remaining elements 
                // into merged from right array.
                else {
                    merge.push_back(out[high++]);
                }
            }

        }
        return merge;
    }
    
};