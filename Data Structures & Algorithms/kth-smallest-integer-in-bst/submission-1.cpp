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
        int count=0;
        int res=-1;
        dfs(root, count,k,res);
        return res;
    }
    void dfs(TreeNode* root, int& count, int k, int& res)
    {
        if(!root)
        return;
        dfs(root->left, count,k, res);
        count++;

        if(count==k)
        {
            res = root->val;
            return;
        }
        dfs(root->right,count,k,res);
    }
};
