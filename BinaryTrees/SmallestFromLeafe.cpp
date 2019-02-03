// 988. Smallest String Starting From Leaf Given the root of a binary tree, each
// node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0
// represents 'a', a value of 1 represents 'b', and so on.


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
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string l = smallestFromLeaf(root->left);
        
        string r = smallestFromLeaf(root->right);
        
        
        cout << "root val " <<  string(1,root->val+97) << endl ;
        cout << "l " << l << endl;
        cout << "r " << r << endl;
        string ret;
        if(l == "" && r != "") {
            ret = r+string(1,root->val+97);
            return ret;            
        }
        if(l != "" && r == "") {
            return l+string(1,root->val+97);
        }
        if(strcmp(l.c_str(),r.c_str()) >=0) {
            ret = r+string(1,root->val+97);
            //cout << " came wtih " << string(1,root->val+97) << endl;
            //cout << ret << endl;
            return ret;
        }
        if( strcmp(l.c_str(),r.c_str()) <=0)
        {
            ret = l+string(1,root->val+97);
        }
        
        return ret;
        
    }
};