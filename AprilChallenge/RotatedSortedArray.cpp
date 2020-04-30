// Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
    
    int helper(vector<int>& arr,int low, int high, int target) {
        if(low > high) return -1;        
        int mid = (low+(high-low)/2);
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[mid] > target) {
            if(mid+1 <= high && arr[mid] > arr[mid+1]) {
                if(target > arr[high]) {
                    return helper(arr,low,mid-1,target);
                }                
                else {
                    return helper(arr,mid+1,high,target);
                }
            }
            else {
                return helper(arr,low,mid-1,target);
            }
        }
        if(arr[mid] < target) {
            if(mid-1 > -1 && arr[mid] < arr[mid-1]) {
                if(target > arr[high]) {
                    return helper(arr,mid+1,high,target);
                }
                else {
                     return helper(arr,low,mid-1,target);
                }
            }
            else {
                return helper(arr,mid+1,high,target);
            }
        }
        return -1;

    }
};