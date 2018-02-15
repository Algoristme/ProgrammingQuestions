// Mindistance between two nodes in BT

// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

// Example :

// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.

// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

//           4
//         /   \
//       2      6
//      / \    
//     1   3  

// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.


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
    int minDiffInBST(TreeNode* root) {
        int minV = INT_MAX;
        int prev = 500;
        helper(root,prev,minV);
        return minV;
    }
    
    void helper(TreeNode *root, int& prev, int& minV) {
        if(!root) return;
        helper(root->left,prev,minV);
        minV = min(minV,abs(root->val-prev));
        //cout << root->val << " " << prev << endl;
        prev = root->val;
        helper(root->right,prev,minV);
    }
};