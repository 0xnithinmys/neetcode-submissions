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
    int maxi = INT_MIN;
    int height(TreeNode* r) {
        if (!r) return 0;
    

    int l = 1 + height(r->left);
    int m = 1 + height(r->right);

    return max(l, m);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int x = height(root->left);
        int y = height(root->right);
        maxi = max(maxi,x+y);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        


        return  maxi;
    }
};
