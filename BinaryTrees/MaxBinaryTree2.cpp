// Max binary tree 2
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root) {
            return  new TreeNode(val);
        }
        if(root->val < val) {
            TreeNode *nR = new TreeNode(val);
            nR->left = root;
            return nR;
        }
        insert(root,val,root);
        return root;
    }
    // since the value is appended it will always be added to 
    // the right subtree
    // cs 2 : root not changing
    void insert(TreeNode * &root, int val,TreeNode * &p) {
        if(!root) {
            TreeNode *nR = new TreeNode(val);
            p->right = nR;
            return;
        }
        if(root->val < val) {
            TreeNode *nR = new TreeNode(val);
            auto tmp = p->right;
            p->right = nR;
            nR->left =tmp;
            return;
        }
        if(root->val > val) {
           insert(root->right, val, root); 
        }
    }
};