// Closest Binary Search Tree Value II
//  Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

// Note:

//     Given target value is a floating point.
//     You may assume k is always valid, that is: k ≤ total nodes.
//     You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)? 

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
       set<pair<unsigned int, int>>  closestPairs;
       findClosest(root,target,k,closestPairs);
    
       vector<int> out;
       for(auto ele : closestPairs) {
           out.emplace_back(ele.second);
       }
       //out.resize(k);
       return out ;
    }
    
    void findClosest(TreeNode* root, double target, int k, set<pair<unsigned int,int>> &closestPair) {
        if(!root) return;
        
        if(closestPair.size() == k ) {
            auto it = --closestPair.end();
            if(abs(target-root->val) < it->first) {
                closestPair.erase(it);
                closestPair.emplace(pair<unsigned int,int>(abs(target-root->val),root->val));
            }                        
            //return;
        }
        else {
            closestPair.emplace(pair<unsigned int,int>(abs(target-root->val),root->val));
        }
          
        findClosest(root->left,target,k,closestPair);
        findClosest(root->right,target,k,closestPair);
    }
};