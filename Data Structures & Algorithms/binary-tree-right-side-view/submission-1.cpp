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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;

        while (!q.empty()) {
            int x = q.size();

            for (int i = 0; i < x; i++) {
                TreeNode* t = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                if (i == x - 1) v.push_back(t->val);

                q.pop();
            }
        }

        return v;
    }
};
