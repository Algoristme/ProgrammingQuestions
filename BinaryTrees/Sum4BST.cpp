// Given a Binary Search Tree and a target number, return true if there
// exist two elements in the BST such that their sum is equal to the
// given target.

// Example 1:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True

// Example 2:

// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False


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
    bool findTarget(TreeNode* root, int k) {
        bool res = false;
        helper(root,k,res);
        return res;        
    }
    void helper(TreeNode *root, int k, bool &res) {
        if(!root) return;
        
        if(desiredNum.find(root->val) != desiredNum.end()) {
            res = true;
            return;
        }   
        desiredNum.emplace(k-(root->val));
        
        if(res)
            return;
        
        helper(root->left,k,res);
               
        helper(root->right,k,res);        
    }
    
    unordered_set<int> desiredNum;
};