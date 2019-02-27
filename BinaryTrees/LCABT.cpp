// Lowest common ancestor in a BT
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) {
            return nullptr;
        }
        return helper(root,p,q);
    }
    TreeNode * helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(!root) {
            return nullptr;
        }
        if(root == p || root == q) {
            return root;
        }
        TreeNode * left = helper(root->left,p, q);
        TreeNode * right = helper(root->right,p,q);
        if(left && right){
            return root;
        }
        
        //  # either one of the chidren returned a node, meaning either p or q found on left or right branch.
        // # Example: assuming 'p' found in left child, right child returned 'None'. This means 'q' is
        // # somewhere below node where 'p' was found we dont need to search all the way, 
        // # because in such scenarios, node where 'p' found is LCA
        return left? left:right;
    }
    
};