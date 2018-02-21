// // Construct String From Binary Tree

// Input: Binary tree: [1,2,3,4]
//        1
//      /   \
//     2     3
//    /    
//   4     

// Output: "1(2(4))(3)"

// Explanation: Originallay it needs to be "1(2(4)())(3()())",  but you need
// to omit all the unnecessary empty parenthesis pairs.  And it will be
// "1(2(4))(3)".

// Example 2:

// Input: Binary tree: [1,2,3,null,4]
//        1
//      /   \
//     2     3
//      \  
//       4 

// Output: "1(2()(4))(3)"

// Explanation: Almost the same as the first example,  except we can't omit
// the fir

// st parenthesis pair to break the one-to-one mapping relationship between
// the input and the output.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        auto ret = helper(t);
        return ret.substr(1,ret.size()-2);
    }
    string helper(TreeNode *t) {
        if(!t) return "()";        
        string s = to_string(t->val);
        string left = helper(t->left);
        string right = helper(t->right);
        if(left == "()" && right == "()") {
            return "("+s+")";
        }
        if(right == "()") {
            right = "";
        }
        s = "("+s+left+right+")";
        return s;
    }
};