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
    bool valid(TreeNode* root, long lmin , long lmax) {
        if (!root) return true;

        if(root->val <= lmin ||  root->val >= lmax){
            return false;
        }


        return valid(root->left,lmin, root->val) && valid(root->right, root->val, lmax);
    }
    bool isValidBST(TreeNode* root) { 
        if(!root)return true;
        
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
