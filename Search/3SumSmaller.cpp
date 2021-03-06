{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22 // Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 // <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.\par
\par
For example, given nums = [-2, 0, 1, 3], and target = 2.\par
\par
Return 2. Because there are two triplets which sums are less than 2:\par
\par
[-2, 0, 1]\par
[-2, 0, 3]\par
\par
Follow up:\par
Could you solve it in O(n2) runtime? \par
\par
// Learnings for counting problems, are you counting stuff again?\par
// How can it be possible?\par
\par
class Solution \{\par
public:\par
    int threeSumSmaller(vector<int>& nums, int target) \{\par
        if(nums.size()==0) \{\par
            return 0;\par
        \}\par
        std::sort(nums.begin(),nums.end());\par
        int cnt = 0;\par
        for(int i = 0 ; i < nums.size(); ++i) \{\par
            int newT = target-nums[i];\par
            // if you start from zero, you will count same triplets for different sums\par
            // Eg triplet [0,1,2]  will be counted for target sum 5 and target sum 4\par
            int low = i+1;            \par
            int high = nums.size()-1;\par
            while(high > low ) \{\par
                if(low == i) \{++low;\}\par
                if(high == i) \{--high;\}\par
                if(nums[low] + nums[high] < newT) \{\par
                    // pick low and you can choose any number from low+1, high\par
                    cnt = cnt + (high-low);\par
                    if(i < high && i > low) \{\par
                        cnt-=1;\par
                    \}\par
                    ++low;   \par
                    continue;\par
                \}\par
                if(nums[low]+nums[high] >= newT) \{\par
                    // try decrementing high\par
                    --high;\par
                    continue;\par
                \}\par
            \}\par
        \}\par
        return cnt;\par
    \}\par
\};\par
}
 