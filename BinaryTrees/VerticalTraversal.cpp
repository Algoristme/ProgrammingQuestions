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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> M;
        dfs(root,0,0,M);
        vector<vector<int>> out;
        if(!root) return out;
        for(auto &m : M) {
            vector<int> curr;
            for(auto &y : m.second) {
                for(auto &se : y.second) {
                    curr.push_back(se);
                }
            }
            out.push_back(curr);
        }
        return out;
    }
    void dfs(TreeNode *root, int X, int Y, map<int,map<int,multiset<int>>> &M) {
        if(!root) return;
        M[X][abs(Y)].insert(root->val);
        dfs(root->left,X-1,Y-1,M);
        dfs(root->right,X+1,Y-1,M);
        return;        
    }
};