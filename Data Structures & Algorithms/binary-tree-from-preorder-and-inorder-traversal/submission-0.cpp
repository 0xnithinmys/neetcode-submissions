class Solution {
public:

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& preorder,
                    int ps, int pe,
                    int is, int ie) {

        if (ps > pe || is > ie) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[ps]);

        int id = is;

        while (inorder[id] != root->val) {
            id++;
        }

        int leftSize = id - is;

        root->left = solve(
            inorder,
            preorder,
            ps + 1,
            ps + leftSize,
            is,
            id - 1
        );

        root->right = solve(
            inorder,
            preorder,
            ps + leftSize + 1,
            pe,
            id + 1,
            ie
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return solve(
            inorder,
            preorder,
            0,
            preorder.size() - 1,
            0,
            inorder.size() - 1
        );
    }
};