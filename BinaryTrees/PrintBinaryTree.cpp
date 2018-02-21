/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


    // The row number m should be equal to the height of the given binary tree.
    // The column number n should always be an odd number.
    // The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
    // Each unused space should contain an empty string "".
    // Print the subtrees following the same rules.


// Input:
//       1
//      / \
//     2   5
//    / 
//   3 
//  / 
// 4 
// Output:

// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
//  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
//  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
//  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int maxHt = 0;
        findMaxHt(root,0,maxHt);  
        int rows = maxHt;
        int cols = pow(2,maxHt);
        cols +=(cols-1);
        //cout << rows << " " << cols << endl;
        vector<vector<string>> mat(rows+1,vector<string>(cols,""));
        fillMatrix(root, 0, 0, cols-1, mat);
        return mat;
    }
    void findMaxHt(TreeNode *root, int currHt, int &maxHt){
        if(!root) return;
        findMaxHt(root->left,currHt+1,maxHt);
        maxHt = max(currHt,maxHt);
        findMaxHt(root->right,currHt+1,maxHt);
    }
    void fillMatrix(TreeNode *root, int level, int start, int end, vector<vector<string>> &mat) {
        if(!root) return;
        int mid = start+(end-start)/2;
        //cout << level << " " << mid << " " << root->val << endl;
        mat[level][mid] = to_string(root->val);
        fillMatrix(root->left,level+1,start,mid-1,mat);
        fillMatrix(root->right,level+1,mid+1,end,mat);
    }
};