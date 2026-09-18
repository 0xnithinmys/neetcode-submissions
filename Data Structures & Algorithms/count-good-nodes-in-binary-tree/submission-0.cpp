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
    int dfs(TreeNode* r, int maxi) {
        if (!r) return 0;
        int count = 0;
        if (r->val >= maxi) {
            count = 1;
        }
        maxi = max(maxi, r->val);

        count += dfs(r->left, maxi);
        count += dfs(r->right, maxi);
        return count;
    }
    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};
