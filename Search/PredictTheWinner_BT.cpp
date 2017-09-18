// Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

// Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score. 

// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return False.

// Input: [1, 5, 233, 7]
// Output: True
// Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canP1Win(nums,0,0,0,nums.size()-1);
    }
    
    bool canP1Win(vector<int> &nums, int s1,  int s2,  int start, int end) {
        if(start > end) {
            return s1 >= s2;
        }
        if(!canP2Win(nums,s1+nums[start],s2,start+1,end) || !canP2Win(nums,s1+nums[end],s2,start,end-1)) {
            return true;
        }
        return false;
    }
    
    bool canP2Win(vector<int> &nums, int s1, int s2, int start, int end){
        if(start > end) {
            return s2>s1;
        }
        if(!canP1Win(nums,s1,s2+nums[start],start+1,end) || !canP1Win(nums,s1,s2+nums[end],start,end-1)){
            return true;
        }
        return false;
        
    }
};