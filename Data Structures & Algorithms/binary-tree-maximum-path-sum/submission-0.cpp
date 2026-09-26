class Solution {
public:
    int maxi = INT_MIN;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        maxi = max(maxi, root->val + l + r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};