// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]

// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int product = 1;
         int zeros = 0;
         vector<int> out(nums.size());         
         for( auto num : nums) {             
             if(num == 0) {
                 ++zeros;
                 if(zeros > 1) {
                     return out;
                 }
                 continue;
             }
             product *= num;
         } 
        
        int i = 0;
        for( auto num : nums) {
            if(num ==0) {
                if(zeros == 1) {
                  out[i++]=product;   
                  break;
                }                
            }
            else {
                cout << zeros << endl;
                if(zeros == 0) {
                  cout << "came here " << std::endl;
                  out[i++]= product/num;
                }  
                else{
                    out[i++]=0;
                }                
            }
            
        }
        return out;
    }
};