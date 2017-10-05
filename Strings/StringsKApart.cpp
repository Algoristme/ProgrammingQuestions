//  Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

// All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

// Example 1:

// s = "aabbcc", k = 3

// Result: "abcabc"

// The same letters are at least distance 3 from each other.

// Example 2:

// s = "aaabc", k = 3 

// Answer: ""

// It is not possible to rearrange the string.

// Example 3:

// s = "aaadbbcc", k = 2

// Answer: "abacabcd"

// Another possible answer is: "abcabcda"

// The same letters are at least distance 2 from each other.

//0. Count how many occurrences of each character: a:4, b:4, c:3, d:2, e:1 
//1. put the most 2 characters (ab) at least k apart first as reference point:
//abXXabXXabXXab (X is empty position)
//2. then fill the gap with all other numbers from most frequency to least frequency like filling out a rotated array:
//   2.1 fill with c first:  abCXabCXabCXab
//   2.2 fill with d then: abcDabcDabcXab
//   2.3 fill with e:    abcdEabcdabcEab    // Here, first E is actually put last, second E is put first, because we are filling gaps in //rotated manner. Note, it doesn't matter if it runs out of empty space, just insert E after abcd anyway, it won't break anything;
//   2.4 fill with f:   abcdeabcdfabceab //A valid solution is generated.

// 3. Finally, how to determine if there is a solution:
//    It's easy: At step 2, if you can't fill all the all empty positions with remaining characters after step 1, there is no solution.

class Solution {
public:
   string rearrangeString(string str, int k) {
        int char_map [26] = {0};
        for (int i = 0 ;  i < str.size(); ++i)
            char_map[str[i] - 'a'] ++;
        multimap<int, char, greater<int>> count_map;
        for (int i = 0; i < 26; ++i)
            count_map.emplace(char_map[i], i + 'a');
        int max_cnt = count_map.begin()->first, pos = 0;
        string str_arr[max_cnt];
        for (auto iter = count_map.begin(); iter != count_map.end(); ++iter)
            for (int i = 0; i < iter->first; ++i, pos = (pos + 1) % max(iter->first, max_cnt - 1))
                str_arr[pos].push_back(iter->second);
        string result;
        for (int i = 0; i < max_cnt - 1; ++i)
            if (str_arr[i].size() < k) return "";
            else result += str_arr[i];
        result += str_arr[max_cnt - 1];
        return result;
    }
};