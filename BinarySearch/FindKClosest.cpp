//  Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

// Example 1:

// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]

// Example 2:

// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //int index = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int index = lower_bound(arr,0,arr.size()-1,x);
        int left = index-1;
        int right = index;
        while (k--) {
            int leftDiff = abs(arr[left]-x);
            int rightDiff = abs(arr[right]-x);
            if((left >= 0 && leftDiff <= rightDiff) || right >= arr.size()) {
                --left;
            }
            else 
                ++right;
            // else if((right < arr.size() && rightDiff < leftDiff) || left < 0) {
            //     ++right;
            // }
        }
        return vector<int> (arr.begin()+left+1,arr.begin()+right) ;        
    }
    
    int lower_bound(vector<int> arr, int low, int high, int x) {
        if(low > high) {
            return low;
        }
        int mid = (low+high)/2;
        if(arr[mid] == x) return mid;
        if(arr[mid] > x) return lower_bound(arr,low,mid-1,x);
        else
            return lower_bound (arr,mid+1,high,x);
    }
};