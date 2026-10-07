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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(!front)
            res+="N,";
            else
            {
                res+=to_string(front->val)+",";
                q.push(front->left);//we push null as well to get N
                q.push(front->right);
            }
        }
        return res;               
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss,val,',');//gets first value until "," and saves it to val also removes it from ss
        if(val=="N")
        return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);
        while(getline(ss,val,','))
        {
            TreeNode* node = q.front();
            q.pop();
            if(val!="N") //we add left and right only if it is not null
            {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss,val,',');
            if(val!="N")
            {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
