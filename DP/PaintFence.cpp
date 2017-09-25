//  There is a fence with n posts, each post can be painted with one of the k colors.

// You have to paint all the posts such that no more than two adjacent fence posts have the same color.

// Return the total number of ways you can paint the fence.

// Note:
// n and k are non-negative integers. 

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        if(n==1) return k;
        
        int sameColorAsPrev = 0;
        int diffColorThanPrev = 0;
        if(n>=2) {
            sameColorAsPrev = k;
            diffColorThanPrev = k*(k-1);
        } 
        
        for(int i=3; i <=n ; ++i) {
            // for i-th post
            // i-1 post i-2 post                     i post                        i post i-1 post
            // if color(i-2) == color(i-1)           sameColorAsPrev*k-1           Color(i) != Color(i-1)   --1(diffColorsThanP)
            // else                                  diffColorThanPrev             Color(i) == Color(i-1)   --2 (sameColorAsP.)
            //                                       diffColor * k-1               Color(i) != Color(i-1)   --3 (diffColorThanP)
            
            int tmp = diffColorThanPrev;
            diffColorThanPrev = (sameColorAsPrev+diffColorThanPrev) *(k-1);
            sameColorAsPrev = tmp;
         }
        return diffColorThanPrev+sameColorAsPrev;
    }
};