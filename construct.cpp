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
    unordered_map<int,int>mpp;
    int j=0;
    TreeNode *func(vector<int>pre,vector<int>ino,int l,int r)
    {
        if (l>r)return nullptr;
        int rootval=pre[j++];
        int idx=mpp[rootval];;
        TreeNode * root=new TreeNode (rootval);

        root->left=func(pre,ino,l,idx-1);
        root->right=func(pre,ino,idx+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        int idx=preorder.size()-1;
        return func(preorder,inorder,0,inorder.size()-1);
    }
};
