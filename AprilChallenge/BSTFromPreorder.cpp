// Construct Binary Search Tree from Preorder Traversal
// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder,0,preorder.size()-1);
    }
    
    TreeNode* constructTree(vector<int> &preOrder, int start, int end) {
        if(start > end) return nullptr;
        
        int i = start+1;
        for(; i <= end ; ++i) {
            if(preOrder[start] < preOrder[i]) {
                break;
            }
        }
        TreeNode * curr = new TreeNode(preOrder[start]);        
        curr->left = constructTree(preOrder, start+1, i-1);
        curr->right = constructTree(preOrder, i, end);
        return curr;
    }
    
    int rightTree(vector<int> &preOrder, int target, int start, int end) {
        for(int i = start; i < end; ++i) {
            if(preOrder[i] > target) {
                return i;
            }
        }
        return end+1;        
    }
};