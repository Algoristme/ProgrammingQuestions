// Second min value in a BT

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
    int findSecondMinimumValue(TreeNode* root) {
        int min1 = INT_MAX;
        int min2 = INT_MAX-1;
        helper(root,min1,min2);
        return (min2 == INT_MAX-1 || min1 == min2 ) ? -1 :  min2;
    }
    void helper(TreeNode *root, int &min1, int &min2) {
        if(!root) return;
        helper(root->left,min1,min2);
        if(min1 == INT_MAX) {
            min1 = root->val;
            min2 = root->val;
        }
        else if(root->val  < min1) {
            min2 = min1;
            min1 = root->val;            
        }
        else if(root->val > min1 && (root->val < min2 || min1 == min2)) {
            min2 = root->val;
        }
        helper(root->right,min1,min2);
    }
};