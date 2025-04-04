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
        unordered_map<int,int> depths;
        int maxDepth = 0;
        
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depthSet(root,0);
        return lca(root,maxDepth);
    }

private:
    void depthSet(TreeNode* root, int depth){
        if(!root)return;
        maxDepth = max(maxDepth,depth);
        depths[root->val]=depth;
        depthSet(root->left,depth+1);
        depthSet(root->right,depth+1);
    }

    TreeNode* lca(TreeNode* root,int maxDepth){

        if(root==NULL || depths[root->val]==maxDepth)return root;

        TreeNode* l = lca(root->left,maxDepth);
        TreeNode* r = lca(root->right,maxDepth);

        if(l==NULL)return r;
        else if(r==NULL)return l;
        else return root;

    }
};