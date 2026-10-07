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
        if(!root)
        return 0;
        int res = INT_MIN;
         maxPathSum(root,res);
        return res;

    }
    int maxPathSum(TreeNode* root, int&res)
    {
        if(!root)
        return 0;
        int leftMax = max(0,maxPathSum(root->left,res));//to not carry -ve sum , compare to 0
        int rightMax = max(0, maxPathSum(root->right,res));
        res = max(res, leftMax + rightMax+root->val); //stores global maxima
        return root->val + max(leftMax, rightMax);//return max straight path value
    }
};
