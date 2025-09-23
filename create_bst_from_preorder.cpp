class Solution {
public:
    unordered_map<int,int>mpp;
    int j=0;
    TreeNode *func(vector<int>pre,vector<int>ino,int l,int r)
    {
        if (r<l)return nullptr;
        int rootval=pre[j++];
        int idx=mpp[rootval];
        TreeNode *root=new TreeNode (rootval);
        root->left=func(pre,ino,l,idx-1);
        root->right=func(pre,ino,idx+1,r);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return func(preorder,inorder,0,inorder.size()-1);

    }
};
