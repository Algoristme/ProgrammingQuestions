//  Binary Tree Maximum Path Sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limits.h>
#include <algorithm>
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        auto final = maxPathHelper(root);
        return std::max(final.first,final.second);
    }
    std::pair<int,int> maxPathHelper(TreeNode *root) {
        if(root == nullptr) {
            return std::pair<int,int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
        }
        if(root->left == nullptr && root->right==nullptr) {
            return std::pair<int,int>(root->val, root->val);
        }
        auto left = maxPathHelper(root->left);
        auto f1 = left.first;
        auto ls = left.second;
        
        auto right = maxPathHelper(root->right);
        auto f2 = right.first;
        auto rs = right.second;
        
        auto v = root->val;
        
        if(ls < 0 && rs < 0) {
                auto ret1 = std::max({v,ls,rs,f1,f2});
                auto ret2 = v;
                return std::pair<int,int>(ret1,ret2);
        }
        if(ls < 0 && rs >=0) {
            auto ret1 = std::max({rs,f1,f2});
            auto ret2 = v+rs;
            //std::cout << " " << v << " " <<ls << " " <<f1 << " " <<rs << " " <<f2 << std::endl;
            return std::pair<int,int>(ret1,ret2);
        }
        if(ls >=0 && rs < 0) {
            auto ret1 = std::max({ls,f1,f2});
            auto ret2 = v+ls;
            return std::pair<int,int>(ret1,ret2);
        }
        if(ls>=0 && rs >=0) {
            auto ret1 = std::max({rs+v+ls,f1,f2,ls,rs});
            auto ret2 = std::max({rs+v,ls+v});
            //std::cout << " " << v << " " <<ls << " " <<f1 << " " <<rs << " " <<f2 << std::endl;
            return std::pair<int,int>(ret1,ret2);
        }
        //std::cout << " Came here" << std::endl;
        return std::pair<int,int>(0,0);
    }
};