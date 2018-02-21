// House Robber 3

//  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

   //   3
   //  / \
   // 2   3
   //  \   \ 
   //   3   1

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
    
    int rob(TreeNode * root) {
        int maxV = 0;
        helper(root,maxV);
        return maxV;
    }
        // pi, pe  --previous include (pi) previous exclude (pe)
    pair<int,int> helper(TreeNode *root,int &maxV) {
        if(!root) return {0,0};
        auto leftPair = helper(root->left,maxV);
        auto rightPair = helper(root->right,maxV);            
        
        // iL, eL ... iR,eR
        // i = includes this and excludes left and right
        int i = leftPair.second+rightPair.second+root->val; // excludes previous excL+excR+includeThis
        // iL+iR
        int e = leftPair.first+rightPair.first; // includes previous,excludes this
        maxV = max(i,e);
        return {maxV, e};
    }

    int robFlop(TreeNode* root) {
        // idea do a bfs and each level is a index.
        // i is the amount that can be made by robbing this house
        // e is the max amt that can be made by excluding or including this house
        if(!root) return 0;
        queue<TreeNode *> levelSum;
        levelSum.push(root);
        int level = 1;
        int e = 0; // exclude previous level
        int i = 0; // include previous level
        int maxV = 0;
        while(!levelSum.empty()) {
            //cout << levelSum.size() << endl;
            int sum = 0;
            for(int i = 1; i <= level; ++i) {
                auto curr = levelSum.front();
                levelSum.pop();
                int val = 0;
                if(curr) {
                    val = curr->val;
                    //cout << curr->val << endl;
                }
                sum += val;
                //cout << level  << endl;
                if(curr && (curr->left || curr->right)) {
                    levelSum.push(curr->left);
                    levelSum.push(curr->right);
                }                
            }
            int tmp = i; 
            maxV = max(e+sum,i);
            i = maxV;
            e = tmp;
            level = level*2;            
        }
        
        return maxV;
    }
};