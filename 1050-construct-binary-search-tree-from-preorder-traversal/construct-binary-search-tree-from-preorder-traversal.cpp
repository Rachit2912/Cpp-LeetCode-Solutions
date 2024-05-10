/**
 * Definition for a binary tree TreeNode.
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

TreeNode* ranging(vector<int> &preorder, int mini, int maxi, int &i){
    // preorder completed :
    if (i >= preorder.size()) {
        return NULL;
    }

    // if out of the current selected range :
    if (preorder[i] < mini || preorder[i] > maxi ) {
        return NULL;    
    }

    // making new nodes and put it in place :
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = ranging(preorder, mini, root->val, i);
    root->right = ranging(preorder, root->val, maxi, i);
    return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
         int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return ranging(preorder, mini, maxi, i);
    }
};