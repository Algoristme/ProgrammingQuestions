// Given a binary tree, write a function to get the maximum width of the given
// tree. The width of a tree is the maximum width among all levels. The binary
// tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the
// leftmost and right most non-null nodes in the level, where the null nodes
// between the end-nodes are also counted into the length calculation.

// Example 1:

// Input: 

//            1
//          /   \
//         3     2
//        / \     \  
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

// Example 2:

// Input: 

//           1
//          /  
//         3    
//        / \       
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).

// Example 3:

// Input: 

//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).

// Example 4:

// Input: 

//           1
//          / \
//         3   2
//        /     \  
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).





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
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<int,int>> vec;
        int maxV = 0;
        helper(root,0,1,vec,maxV);
        return maxV;
    }

    void helper(TreeNode *root, int level, int index,vector<pair<int,int>> &vec, int &maxV) {
        if(!root) return;
        if(vec.size() == level) {
            // since you are always going left, this will contain 
            // the left most node index.
            // This is the only way this will work.
            // Preorder traversal, you process the node first
            // As the level increases , u always process the left mode node first.  
            vec.push_back({index,index});
        }            
        else {
            vec[level].second = index;
        }
        maxV = max(maxV,vec[level].second-vec[level].first+1);
        helper(root->left,level+1,2*index,vec,maxV);
        helper(root->right,level+1,2*index+1,vec,maxV);
    }
};