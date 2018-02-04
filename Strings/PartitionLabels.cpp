// Partition Strings
 A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> Len, last(26); // last index of a char
        for (int i = 0; i < s.size(); last[s[i]-'a'] = i++); 

        for (int i = 0, L = 0, R = 0; i < s.size(); i++) 
        {
            R = max(R, last[s[i]-'a']); // track end index of current substring
            if (R == i) Len.push_back(R-L+1), L = R+1; // found a minimum substring
        }
        return Len;        
    }
    
};