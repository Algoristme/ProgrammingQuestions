//Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
//For example, Given s = “eceba” and k = 2,
//
//T is "ece" which its length is 3.

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int res = 0;
		unordered_map<char, int> windowDistinct;
		int start = 0;
		for (int i = 0; i < s.size(); i++) {
			++windowDistinct[s[i]];
			while (windowDistinct.size()>k && start <= i) {
				--windowDistinct[s[start]];
				if (windowDistinct[s[start]] == 0) {
					windowDistinct.erase(s[start]);
				}
				++start;
			}
			res = max(res, i - start + 1);
		}
		//cout << s.substr(start) << endl;
		return res;
	}
};