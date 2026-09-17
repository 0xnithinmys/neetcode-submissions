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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> r;
        if(!root)return r;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                TreeNode* t = q.front();

                if (t->left) q.push(t->left);
                if (t->right)q.push(t->right);

                v.push_back(t->val);
                q.pop();
            }
            r.push_back(v);
        }

        return r;
    }
};
