// Given the root of a binary tree with N nodes, each node in the tree has
// node.val coins, and there are N coins total.

// In one move, we may choose two adjacent nodes and move one coin from one node
// to another.  (The move may be from parent to child, or from child to parent.)

// Return the number of moves required to make every node have exactly one coin.

 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// The idea is that, if the son have more than one coin, give extra coins to parent, or if the son have less than one coin, borrow some coins from parent. The total amount of transferred coins between each parent and son is the answer.
// The key is that we always let sons have only one coin.
// Specifically, for current node, we will firstly let its sons to have only one coin. Then the current node may have more than one coin, or less than one coin (because its sons transfer or borrow money to or from it). Then let current node transfer or borrow some coins to or from its parent.

// Why the total amount of transferred coins is the answer?

// Let's see it from bottom to up. For every subtree, the number of coins must be equal to the number of nodes in the subtree, so for the root of the subtree, it can only and must obtain coins or give extra coins from or to its parent. If we sum up all the transferred coins between each parent and son, it should be the minimum cost of move.
// The dfs function actually does is to make current subtree have correct number of coins, then let the parent of the root to handle lacked coins or extra coins.

// Some one may feel confused that the node can obtain some money from its brothers. It is true, but this process could be divided into two parts: 1. the brother give extra money to the parent. 2. the node borrow money from the parent. So its basically the same thing.
class Solution {
public:
    int distributeCoins(TreeNode* root) {  
        int steps = 0;
        calcAns(root,steps);
        return steps;
    }
    
    int calcAns(TreeNode *root, int &steps) {
        if(!root) return 0;
        
        // Number of coins children have
        int coinsWithChildren = calcAns(root->right,steps) + calcAns(root->left,steps);
        
        // Current Node
        if(root->val == 1) {
            // Retain the value of coinsWithChildren
            coinsWithChildren+=0;
        }
        if(root->val > 1) {
            // Keep one and send it to parents.
            coinsWithChildren+= root->val-1;
        }
        if(root->val < 1) {
            // Borrow one and send it to parents
            coinsWithChildren+=-1;
        }
        steps +=abs(coinsWithChildren);
        return coinsWithChildren;
    }
    
};