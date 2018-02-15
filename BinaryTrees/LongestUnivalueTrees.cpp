// // Longest Univalue Path Given a binary tree, find the length of the longest
// path where each node in the path has the same value. This path may or may not
// pass through the root.

// Note: The length of path between two nodes is represented by the number of
// edges between them.

// Example 1:

// Input:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5

// Output:

// 2


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
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 1;
        helper(root,maxLen);
        return maxLen-1;
    }
    
    pair<TreeNode *,int> helper(TreeNode *root,int &maxLen) {
        if(!root) return pair<TreeNode *,int>(nullptr,0);
        
        auto left = helper(root->left,maxLen);        
        auto right = helper(root->right,maxLen);
        
        if(left.first && right.first && left.first->val == right.first->val && left.first->val == root->val) {
            //cout << "Came here " << endl;
            maxLen = max(maxLen,left.second+1+right.second);
            //cout << maxLen << endl;
            return {root,max(left.second,right.second)+1};
        }
        
        if(left.first && left.first->val == root->val) {
            left.second;
            maxLen = max(maxLen,max(left.second+1,right.second)); 
            return pair<TreeNode *,int>(root,left.second+1);
        }
        
        if(right.first && right.first->val == root->val) {
            right.second;
            maxLen = max(maxLen,max(right.second+1,left.second));
            return pair<TreeNode *,int>(root,right.second+1);
        }
        maxLen = max(maxLen,max(left.second,right.second));
        maxLen = max(maxLen,1);
        return pair<TreeNode *,int>(root,1);
    }
};