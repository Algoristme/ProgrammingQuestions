
Suppose we abstract our file system by a string in the following manner

The string dirntsubdir1ntsubdir2nttfile.ext represents

dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string dirntsubdir1nttfile1.extnttsubsubdir1ntsubdir2nttsubsubdir2ntttfile2.ext represents

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is dirsubdir2subsubdir2file2.ext, and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note

    The name of a file contains at least a . and an extension.
    The name of a directory or sub-directory will not contain a ..

Time complexity required O(n) where n is the size of the input string.

Notice that aaaaaafile1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaasth.png.





class Solution {
public:    
    // 1. How to handle depth, using a stack based approach
    // 2. How to handle '\t' '\n' ? There are single characters.
    // 3. When to update the result and check for maximum? When the isFile boolean is set.
    
    // String parsing code with keeping a count and updating the max count whenever a filename is processed. Remembering to discard the
    // count for the current level when we do an action similar to cd.. or move to the outer level.
    
    int lengthLongestPath(string input) {
        vector<int> depthSize(256,0);
        int level = 0;
        int len = 0;
        int res = 0;
        bool isFile = false;
        for(int i=0; i < input.size(); i++) {
            if(input[i] == '\t'){
                ++level;
                continue;
            }
            if(input[i] == '.') {
                isFile = true;
            }
            if(input[i] == '\n') {
                depthSize[level] = len;                
                isFile = false;
                level = 0;
                len = 0;
                continue;
            }
            ++len;
            if(isFile){
                int sum = 0;
                for(int i =0; i <level ; i++){
                    sum+=depthSize[i];
                }
                res = max(res,sum+len+level);
            }            
            
            
        }
      return res;
    }
};