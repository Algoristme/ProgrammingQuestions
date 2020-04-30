//  Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

//     Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//     Any right parenthesis ')' must have a corresponding left parenthesis '('.
//     Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//     '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
//     An empty string is also valid.

// Example 1:

// Input: "()"
// Output: True

// Example 2:

// Input: "(*)"
// Output: True
class Solution {
public:
    bool checkValidString(string s) {
        set<int> starPos;
        stack<pair<char,int>> parenStack;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '*') {
                starPos.emplace(i);
            }
            if(s[i] == '(') {
                parenStack.push({s[i],i});
            }
            if(s[i] == ')') {
                if(!parenStack.empty() && parenStack.top().first == '(') {
                    if(!parenStack.empty()) {
                        parenStack.pop();
                    }                    
                }
                else {
                    parenStack.push({s[i],i});
                }
            }
        }
        while(!parenStack.empty() && !starPos.empty()) {
            auto p = parenStack.top();
            if(p.first == ')') {
                int parenPos = p.second;
                auto it = starPos.lower_bound(parenPos);
                if(it != starPos.begin()) {
                    --it;
                    starPos.erase(it);
                    parenStack.pop();
                }
                else {
                    return false;
                }
            }
            if(p.first == '(') {
                int parenPos = p.second;
                auto it = starPos.lower_bound(parenPos);
                if(it != starPos.end()) {
                    starPos.erase(it);
                    parenStack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return parenStack.empty();
    }
};
Example 3:

Input: "(*))"
Output: True

Note:

    The string size will be in the range [1, 100].


class Solution {
public:
    bool checkValidString(string s) {
        set<int> starPos;
        stack<pair<char,int>> parenStack;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '*') {
                starPos.emplace(i);
            }
            if(s[i] == '(') {
                parenStack.push({s[i],i});
            }
            if(s[i] == ')') {
                if(!parenStack.empty() && parenStack.top().first == '(') {
                    if(!parenStack.empty()) {
                        parenStack.pop();
                    }                    
                }
                else {
                    parenStack.push({s[i],i});
                }
            }
        }
        while(!parenStack.empty() && !starPos.empty()) {
            auto p = parenStack.top();
            if(p.first == ')') {
                int parenPos = p.second;
                auto it = starPos.lower_bound(parenPos);
                if(it != starPos.begin()) {
                    --it;
                    starPos.erase(it);
                    parenStack.pop();
                }
                else {
                    return false;
                }
            }
            if(p.first == '(') {
                int parenPos = p.second;
                auto it = starPos.lower_bound(parenPos);
                if(it != starPos.end()) {
                    starPos.erase(it);
                    parenStack.pop();
                }
                else {
                    return false;
                }
            }
        }
        return parenStack.empty();
    }
};