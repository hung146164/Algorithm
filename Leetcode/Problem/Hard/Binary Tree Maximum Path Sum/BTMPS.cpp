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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        sol(ans,root);
        return ans;
    }
    int sol(int&  ans, TreeNode* root)
    {
        if(root==nullptr) return 0;
        int l=sol(ans,root->left);
        int r=sol(ans,root->right);
        int kq=max(max(l,r)+root->val,root->val);
        int kh=l+r+root->val;
        ans=max(ans,root->val);
        ans=max(ans,kh);
        ans=max(ans,kq);
        return kq;
    }
};