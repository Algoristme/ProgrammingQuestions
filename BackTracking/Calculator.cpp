// Calculator with BT
//https://leetcode.com/submissions/detail/134183814/

class Solution {
public:
    // In general, ask the following questions:
    // What is the sub problem
    // What is the state
    // What is the base case
    // How is the code covering all the sample space
    // For string, are using for loop to iterate or are u incrementing everytime?
    int calculate(string s) {
        int i = 0;
        return calculate(s,i);
    }
    
    private :
    int calculate(string &s, int &i) {
        int res = 0, sign = 1;
        for(;i<s.size();++i) {
            if (isdigit(s[i])) {
                int start = i;
                while (i + 1 < s.length() && isdigit(s[i + 1])) { i++; }
                res += sign * stoi(s.substr(start, i + 1 - start));
            }                        
            else if(s[i] == '(') {
                res += sign *calculate(s,++i);
            }
            else if(s[i] == ')') {
                return res;
            }
            else if(s[i] == '+') {
                sign = 1;
            }
            else if(s[i] == '-') {
                sign = -1;
            }            
        }
        return res;
    }
};