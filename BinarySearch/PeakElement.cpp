// Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binSearch(0,nums.size()-1,nums);
    }
    
    int binSearch(int low, int high, vector<int> & nums) {
        if(low > high) return -1;
        if(low == high) return high;
        
        int mid = (low+high)/2;
        int midEle = nums[mid];
        
        int prevEle = mid-1 < low  ? INT_MIN : nums[mid-1];
        int nextEle = mid+1 > high ? INT_MIN : nums[mid+1];
        
        if(midEle > prevEle && midEle > nextEle ) return mid;
        
        if(midEle < prevEle) return binSearch(low,mid-1,nums);
        if(midEle < nextEle) return binSearch(mid+1,high,nums);
        
        return -1;
    }
};