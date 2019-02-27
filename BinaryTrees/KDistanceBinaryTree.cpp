// All nodes at a distance of K from a target node in binary tree.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode *, int> lenMap;
        helper(root,target,lenMap);
        
        vector<int> out;
        findKDistance(root,INT_MIN,lenMap,K,out);
        
        return out;
    }
    int helper(TreeNode * root, TreeNode *target, unordered_map<TreeNode *,int> &lenMap) {
        if(!root) return -1;
        if(root == target) {
            lenMap[root] = 0;
            //cout << root->val << " " << lenMap[root] << endl;
            return 0;
        }
        int l = helper(root->left, target,lenMap);
        int r = helper(root->right,target,lenMap);
        if(l == -1 && r == -1) return -1;
        lenMap[root] = l >= 0 ? l+1 : r+1 ;
        //cout << root->val << " " << lenMap[root]  << endl;
        return lenMap[root];
    }
    void findKDistance(TreeNode *root, int len, unordered_map<TreeNode *, int> &lenMap, int K, 
                       vector<int> &out) {
        if(!root) return;                
        if(lenMap.find(root) != lenMap.end()) {
            len = lenMap[root];
        }
        if(len == K) {
            out.push_back(root->val);
        }
        //if(len > K) return;

        findKDistance(root->left,len+1,lenMap,K,out);
        findKDistance(root->right,len+1,lenMap,K,out);
    }
};