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

    vector<int> v;
    void solve(TreeNode* r){
        if(!r)return ;


        v.push_back(r->val);


        solve(r->left);
        solve(r->right);

    }
    int kthSmallest(TreeNode* root, int k) {


        solve(root);
        int x = 0;

        sort(v.begin(),v.end());

        for(int i : v){
            x++;
            if(x == k)return i;
            
        }


        return -1;
        
    }
};
