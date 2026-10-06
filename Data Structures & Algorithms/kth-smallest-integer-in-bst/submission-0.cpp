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
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal of a bst will give a sorted array
        vector<int>t(2);
        t[0]=k;
        dfs(root, t);
        return t[1];
    }
    void dfs(TreeNode* root, vector<int>&t)
    {
        if(!root)
        return;
        dfs(root->left, t);
        if(t[0]==0)
        return;
        t[0]--;
        if(t[0]==0)
        {
            t[1]= root->val;
            return;
        }
        dfs(root->right,t);
    }
};
