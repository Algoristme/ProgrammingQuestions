// Binary Tree Pruning
// We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

// Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
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
    TreeNode* pruneTree(TreeNode* root) {        
        pair<bool,TreeNode *> ret = pruneTreeHelper(root);
        return ret.second;
    }
    
    pair<bool,TreeNode *>  pruneTreeHelper(TreeNode *root) {
        if(!root) return pair<int,TreeNode *> (false, nullptr);
                
        pair<bool,TreeNode *> l = pruneTreeHelper(root->left);
        pair<bool,TreeNode *> r = pruneTreeHelper(root->right);
        
        if(!l.first) root->left = nullptr;
        if(!r.first) root->right =nullptr;
        
        bool hasOne = l.first || r.first;
        
        if(root->val == 1) hasOne = true;
        return pair<bool,TreeNode *> (hasOne, root);
        
    }
};