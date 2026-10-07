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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        if(preorder.empty() || inorder.empty())
        return nullptr;
        if(preorder.size()==1)
        return new TreeNode(preorder[0]);
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]]=i;
        }
        return makeTree(preorder,mp,0,0,inorder.size()-1);
    }
    TreeNode* makeTree(vector<int>& preorder, unordered_map<int,int>&mp, int rootIndex, int left, int right)
    {
        TreeNode* root = new TreeNode (preorder[rootIndex]);
        int mid = mp[preorder[rootIndex]]; //find where is the root in inorder
        if(mid>left)
        {
            root->left = makeTree(preorder, mp, rootIndex+1, left, mid-1);
        }
        if(mid<right)
        {
            root->right = makeTree(preorder, mp, rootIndex + mid-left+1, mid+1,right);//rootindex for the right subtree will be found by adding length of left subtree to root which is mid-left+1
        }
        return root;
    }
};
