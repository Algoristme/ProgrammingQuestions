//388. Longest Absolute File Path
//Suppose we abstract our file system by a string in the following manner :
//
//The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents :
//
//	dir
//	subdir1
//	subdir2
//	file.ext
//
//	The directory dir contains an empty sub - directory subdir1 and a sub - directory subdir2 containing a file file.ext.
//
//	The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
//
//dir
//subdir1
//file1.ext
//subsubdir1
//subdir2
//subsubdir2
//file2.ext
//
//The directory dir contains two sub - directories subdir1 and subdir2.subdir1 contains a file file1.ext and an empty second - level sub - directory subsubdir1.subdir2 contains a second - level sub - directory subsubdir2 containing a file file2.ext.
//
//We are interested in finding the longest(number of characters) absolute path to a file within our file system.For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
//
//Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system.If there is no file in the system, return 0.

class Solution {
public:
	int lengthLongestPath(string input) {
		// string processing
		int longest = 0;
		int cnt = 0;
		bool isFile = false;
		int depth = 0;
		vector<int> charCnt(256, 0);
		for (int i = 0; i <input.size(); ++i) {
			if (input[i] == '.') {
				isFile = true;
			}
			if (input[i] == '\t') {
				++depth;
				continue;
			}
			if (i == input.size() - 1 || input[i] == '\n') {
				charCnt[depth] = cnt;
				if (depth > 0) {
					charCnt[depth] += charCnt[depth - 1];
				}
				if (i == input.size() - 1) {
					++charCnt[depth];
				}
				cout << depth << " " << charCnt[depth] << endl;
				if (isFile && charCnt[depth] + depth > longest) {
					longest = charCnt[depth] + depth;
				}
				isFile = false;
				cnt = 0;
				depth = 0;
				continue;
			}
			++cnt;
		}
		return longest;
	}
};