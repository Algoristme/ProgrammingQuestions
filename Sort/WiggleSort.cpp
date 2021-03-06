{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22  //Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] // <=\par
 //nums[3]....\par
\par
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].\par
\par
\par
class Solution \{\par
public:\par
    void wiggleSort(vector<int>& nums) \{\par
        // ind == odd, nums[ind] > nums[ind-1] && nums[ind] > nums[ind+1]\par
        // ind == even, nums[ind] < nums[ind-1] && nums[ind] < nums[ind+1]\par
      \par
       for(int i = 1 ; i < nums.size(); ++i) \{                     \par
           // Explanation : Greedy Solution\par
           // say nums[0,i-1] is wiggled\par
           // i is odd \par
           // Case 1: nums[i-1] < nums[i] already wiggled.\par
           // Case 2 : nums[i-1] > nums[i] , swap(i-1,i)\par
           // Since array is already wiggled \par
           // nums[i-2] > nums[i-1] , so nums[i-2] > nums[i-1] (guaranteed!)           \par
           if(i%2 == 1 && nums[i] < nums[i-1]) \{\par
               swap(nums,i);\par
           \}\par
           if(i%2 == 0 && nums[i] > nums[i-1]) \{\par
               swap(nums,i);\par
           \}\par
       \}   \par
    \}\par
    void swap (vector<int> &nums, int i) \{\par
        int tmp = nums[i];\par
        nums[i] = nums[i-1];\par
        nums[i-1] = tmp;\par
    \}\par
\};\par
}
 