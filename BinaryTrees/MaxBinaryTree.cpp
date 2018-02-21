// Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;
        int maxI = nums[start];
        int idx = start;
        for(int i = start; i <= end; ++i) {
            if(nums[i] > maxI) {
                maxI = nums[i];
                idx = i;
            }
        }
        TreeNode *nRoot = new TreeNode(maxI);
        nRoot->left = helper(nums,start,idx-1);
        nRoot->right = helper(nums,idx+1,end);
        return nRoot;
    }
    
};