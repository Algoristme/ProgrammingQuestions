//  You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

// Write a function to determine if the starting player can guarantee a win.

// For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

// Follow up:
// Derive your algorithm's runtime complexity. 
//Now let's check the time complexity: Suppose originally the board of size N contains only '+' signs, then roughly we have:
// T(N) = (N-2) * T(N-2) = (N-2) * (N-4) * T(N-4) ... = (N-2) * (N-4) * (N-6) * ... ~ O(N!!)


class Solution {
public:
    bool canWin(string s) {
        if(s.size()<=1){
            return false;
        }
            
        return canWin(s,0);
    }
    
    bool canWin(string s, int start) {
        
        for(int i = start; i <= s.size()-2; ++i) {            
            if(s[i] =='+' && s[i+1] =='+') {
                // make move
                s[i] = '-';
                s[i+1] = '-';
                
                // Other player makes a move
                bool result = canWin(s,0);
                // If result is false; then somewhere either P1 or P2 lost
                // Other player lost, this player won.
                if(result == false) {
                  return true;
                }
            
                // Un make move
                s[i] = '+';
                s[i+1] = '+'; 
            }
        }
        return false;
    }
};