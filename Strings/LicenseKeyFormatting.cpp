// Learnings are you asking yourself why you have a line of code?
// If you have input that you have to ignore?

//482. License Key Formatting
//Now you are given a string S, which represents a software license key which we would like to format.The string S is composed of alphanumerical characters and dashes.The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M + 1 groups).The dashes in the given string are possibly misplaced.
//
//We want each group of characters to be of length K(except for possibly the first group, which could be shorter, but still must contain at least one character).To satisfy this requirement, we will reinsert dashes.Additionally, all the lower case letters in the string must be converted to upper case.
//
//So, you are given a non - empty string S, representing a license key to format, and an integer K.And you need to return the license key formatted according to the description above.
//
//Example 1:
//
//Input: S = "2-4A0r7-4k", K = 4
//
//	Output : "24A0-R74K"
//
//	Explanation : The string S has been split into two parts, each part has 4 characters.



class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int cnt = 0;
		string out = "";
		for (int i = S.size() - 1; i >= 0; --i) {
			// Forgot skipping "-"
			if (S[i] == '-') {
				continue;
			}
			cnt++;
			if (cnt == K + 1) {
				out = "-" + out;
				cnt = 1;
				// This continue was not required.
				//continue;
			}
			if (S[i] >= 'a' && S[i] <= 'z') {
				S[i] = toupper(S[i]);
			}
			string s(1, S[i]);
			out = s + out;
		}
		return out;
	}
};