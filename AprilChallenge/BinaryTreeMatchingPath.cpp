// Given a binary tree where each path going from the root to any leaf form a valid sequence, check if a given string is a valid sequence in such binary tree. 

// We get the given string from the concatenation of an array of integers arr and the concatenation of all values of the nodes along a path results in a sequence in the given binary tree.

 

// Example 1:

// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
// Output: true
// Explanation: 
// The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
// Other valid sequences are: 
// 0 -> 1 -> 1 -> 0 
// 0 -> 0 -> 0

// Example 2:

// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
// Output: false 
// Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not even a sequence.

// Example 3:

// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
// Output: false
// Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a valid sequence.

 

// Constraints:

//     1 <= arr.length <= 5000
//     0 <= arr[i] <= 9
//     Each node's value is between [0 - 9].



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isValid(root,0,arr);
    }
    
    bool isValid(TreeNode *root, int i, vector<int>  &arr) {        
        // Beyond leaf after matching the whole string   
        if(root && !root->left && !root->right && i == arr.size()-1 && root->val == arr[i]) return true;
        
        if(!root) return false;
        
        if(i >= arr.size()) return false;
        
        // This node defaults and does not match
        if(root->val != arr[i]) return false;
        
        // Recursively match left and right.
        // cout << "Came here, matched " << root->val <<std::endl;
        return isValid(root->left, i+1, arr) || isValid(root->right,i+1,arr);
        
    }
};