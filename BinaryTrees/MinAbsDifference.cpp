// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

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
    int getMinimumDifference(TreeNode* root) {
        TreeNode * prev = nullptr;
        int minDiff = INT_MAX;
        helper(root,prev,minDiff);
        return minDiff == INT_MAX ? 0 : minDiff;
    }
    void helper(TreeNode *root, TreeNode *& prev, int & minDiff) {
        if(!root) return;
        helper(root->left, prev, minDiff);
        if(prev){
            minDiff = min(minDiff, abs(root->val-prev->val));
        }
        prev = root;
        helper(root->right, prev, minDiff);
    }
};