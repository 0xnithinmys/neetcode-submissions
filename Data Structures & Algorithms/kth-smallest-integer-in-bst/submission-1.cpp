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
    int cnt = 0;
    int solve(TreeNode* r,int k){
        if(!r)return -1;


        int l = solve(r->left,k);
        if(l!=-1){
            return l;
        }
        cnt++;
        if(cnt == k){
            return r->val;
        }

        return solve(r->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {

        return solve(root,k);
        
    }
};
