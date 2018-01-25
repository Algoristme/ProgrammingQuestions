// Expression Add Operator
//  Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

// Examples:

// "123", 6 -> ["1+2+3", "1*2*3"] 
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []


class Solution {
public:
    vector<string> addOperators(string num, int target) {
       vector<string>   out;
       
       helper(out, num, "",0,0,0,target);
       return out;
    }
    
    void helper(vector<string> &out, string num, string expr, long cv, long pv, int pos, int target) {
        if(pos == num.size()) {
            if(target == cv) {
                out.push_back(expr);
            }
        }
        
        for(int i = pos; i < num.size(); ++i) {
            if (num[pos] == '0' && i > pos) break;
            string currNumStr = num.substr(pos,i-pos+1);
            long currNum = stol(currNumStr);
            if(pos == 0) {
               helper(out, num, expr+currNumStr, currNum, currNum, i+1, target);    
            }
            else {
                // vector<string> &out, string num, string expr, long cv, long pv, int pos, int target
                helper(out, num, expr+"+"+currNumStr, cv+currNum, currNum, i+1,target);
                helper(out, num, expr+"-"+currNumStr, cv-currNum, -currNum, i+1,target);
                helper(out, num, expr+"*"+currNumStr, cv-pv+pv*currNum, pv*currNum, i+1,target);

            }
        }
    }
};