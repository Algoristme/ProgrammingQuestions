// Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        bool found = false;
        helper(root, x, y, found, 0);
        return found;
    }
    int helper(TreeNode *root, int x, int y , bool &found, int depth) {
        if(found || !root) return -1;
        if(root->val == x || root->val == y) {
            return depth;
        }
        
        int l = helper(root->left, x, y, found, depth+1);
        int r = helper(root->right, x, y, found, depth+1);
        
        if(l==r && l != -1 && r != -1 && ((root->left->val != x && root->right->val!=y) && (root->left->val != y && root->right->val!=x))) {
            found = true;
        }
        return l != -1 ? l : r;                
    }
};