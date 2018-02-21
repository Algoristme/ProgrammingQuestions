// Duplicate subtrees

// Given a binary tree, return all duplicate subtrees. For each kind of
// duplicate subtrees, you only need to return the root node of any one of
// them.

// Two trees are duplicate if they have the same structure with same node
// values.

// Example 1:

//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4

// The following are two duplicate subtrees:

//       2
//      /
//     4

// and

// 4

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> stringNode;
        vector<TreeNode *> dups;
        helper(root,stringNode);
        for(auto pair : stringNode) {
            if(pair.second.size() > 1) {
                dups.emplace_back(pair.second[0]);
            }
        }
        return dups;
    }
    string helper(TreeNode *root, unordered_map<string,vector<TreeNode*>> &stringNode) {
        if(!root) return "";
        string s = "("+ helper(root->left,stringNode) + to_string(root->val) + helper(root->right,stringNode) + ")";
        stringNode[s].push_back(root);
        return s;
    }
};