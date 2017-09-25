//House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        int maxMoney;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
        int pHouse,ppHouse;
        
        if(nums.size()>=2) {
            ppHouse = nums[0];
            pHouse = nums[1];
            
            pHouse = max(ppHouse,pHouse); // Why this?
            maxMoney = pHouse;
        }
        
        for(int i = 2; i < nums.size(); ++i) {
            maxMoney = max(pHouse,ppHouse+nums[i]);

            ppHouse = pHouse;
            pHouse = maxMoney;;
        }
        
        return maxMoney;
    }
};