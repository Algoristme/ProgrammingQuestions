// Min size subarray with sum > s
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int wStart = 0; int wEnd = 0;
        int runningSum = 0;
        int minLen = nums.size()+1;
        int runningLen = 0;
        while(wEnd < nums.size()) {
            runningSum+=nums[wEnd];
            ++runningLen;            
            if(runningSum >= s) {
                // shrink window
                while(wStart <= wEnd && runningSum >=s) {
                    //cout << wStart << " " << wEnd << endl;
                    runningSum-=nums[wStart];
                    minLen = min(runningLen,minLen);
                    --runningLen;
                    ++wStart;
                }                
            }
            ++wEnd;
        }
        return minLen == nums.size()+1 ? 0 : minLen;
    }
};