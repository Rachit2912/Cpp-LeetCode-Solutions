/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

// saving the inorder : 
void inorderSave(TreeNode* root, vector<int> &v){
    if(!root) return ;
    inorderSave(root->left , v);
    v.push_back(root->val);
    inorderSave(root->right , v);
}

// converting inorder to bst : 
TreeNode* inorderToBST(int s, int e, vector<int> v){
    // base case : 
    if (s > e) {
        return NULL;
    }

    int mid = (s+e)/2 ;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);
    return root;
}

    TreeNode* balanceBST(TreeNode* root) {
         vector<int> v;
    inorderSave(root, v);
    return inorderToBST(0, v.size()-1, v);

    }
};