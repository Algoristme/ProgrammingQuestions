//  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backTrack(n,n,res,"");
        return res;
    }
    void backTrack(int open, int closed, vector<string> &res, string soFar) {
        if(closed==0) {
            res.emplace_back(soFar);
        }
        
        // Option 1. Open Paren
        // Option 2. Close Paren
        if(open > 0) {            
            backTrack(open-1,closed,res,soFar+"(");            
        }
        if(open < closed) {
            backTrack(open,closed-1,res,soFar+")");
        }
    }
};