// Count of range sum

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size()==0) return 0;
        vector<long> sums(nums.size()+1);
        for(int i = 0 ; i < nums.size(); ++i) {
            sums[i+1] = sums[i]+nums[i];
        }
        int cnt = 0;
        helper(sums,0,sums.size(),lower,upper,cnt);
        return cnt;
    }
    
    void helper(vector<long> &sums, int low, int high, int lower, int upper, int &cnt) {
        if(high-low<=1) return;
        int mid = low+(high-low)/2;
        
        helper(sums,low,mid,lower,upper,cnt);
        helper(sums,mid,high,lower,upper,cnt);
                
        int l = low;
        int r1 = mid;
        int r2 = mid;
        while(l < mid) {
            while(l < mid && r1 < high && sums[r1]-sums[l] < lower) {
                ++r1;
            }
            while(l < mid && r2 < high && sums[r2]-sums[l] <= upper) {
                ++r2;
            }
            cnt +=(r2-r1);
            ++l;
        }        
        inplace_merge(sums.begin()+low,sums.begin()+mid,sums.begin()+high);
    }
};