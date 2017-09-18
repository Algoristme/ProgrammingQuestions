//  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"

// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 

class Solution {
public:
    string minWindow(string s, string t) {
        // Will be updated to contain the start and size of final min window.
        size_t minStart = 0, minLen = INT_MAX;
        // Valid Window : A window in src which contains all the chars in pattern.
        // Invalid Window : A window in src which does not contain all the chars in pattern.
        // Min Valid Window : Min of all valid windows.
        // These two pointers track the current window in the src.
        // Approach is as follows:
        // 1. Expand the window by moving the end of window to make this valid window.
        // 2. Once, all chars in pattern are found we have a valid window:
        //     a. shrink the valid window and update the min valid window size.
        //     b. if the window becomes invalid search for other valid windows in src.
        
        size_t start = 0,end = 0;
        // Tracks the number of chars we need to find in the current window between src and end.
        size_t remainingNeeded = t.size(); 
        size_t srcLen = s.size();
        
        // This map records a count of chars in pattern. For pattern ABC
        // needed would A-1, B-1, C-2
        // At any point needed map tracks if we need a particular char to make the window valid.
        // if needed[someChar] < 0, we don't need this char in the window.
        // for all chars c in src which are not in pattern, needed[c] < 0
        // if needed[someChar] > 0, we need this char in the window.
        unordered_map<char,int> needed;
        for(auto c : t) needed[c]++;
        
        while(end < srcLen) {
            if(needed[s[end]] >0) {
                --remainingNeeded;
            }
            --needed[s[end]];
            // Doing 1. 
            // Here end points to one more than what is req.            
            ++end;
            
            // We have a valid window. Do shrinking.
            while(remainingNeeded == 0) {            
                if(end-start < minLen) {
                    minStart = start;
                    minLen = end-start;
                }
                ++needed[s[start]];
                if(needed[s[start]] >0) {
                    ++remainingNeeded;
                }
                ++start;
            }
            
        }
        
        if(minLen != INT_MAX) {
            return s.substr(minStart,minLen);
        }
        return "";
        
    }
};