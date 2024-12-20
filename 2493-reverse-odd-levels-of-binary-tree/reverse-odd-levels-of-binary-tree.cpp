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
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }

    void dfs(TreeNode* left, TreeNode* right, int l){
        if(!left || !right)return;

        if(l%2){
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        dfs(left->left,right->right,l+1);
        dfs(left->right,right->left,l+1);
    }
};