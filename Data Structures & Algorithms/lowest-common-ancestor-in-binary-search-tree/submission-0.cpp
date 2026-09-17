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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (root == p || root == q) return root;

        TreeNode* x = lowestCommonAncestor(root->left, p, q);

        TreeNode* y = lowestCommonAncestor(root->right, p, q);
        if (x && y && (x == p || x == q)) return root;

        if(x)return x;
        if(y)return y;

        return nullptr;
    }
};
