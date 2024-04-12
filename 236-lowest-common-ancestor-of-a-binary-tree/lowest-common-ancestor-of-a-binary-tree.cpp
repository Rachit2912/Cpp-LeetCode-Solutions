/**
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // base case : 
        if(root == NULL) return NULL;

        if((root == p) || (root == q)) return root;

        TreeNode* leftPart = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightPart = lowestCommonAncestor(root->right,p,q);

        if(leftPart != NULL && rightPart != NULL) return root;
        else if(leftPart != NULL && rightPart == NULL) return leftPart;
        else if(leftPart == NULL && rightPart != NULL) return rightPart;

        return NULL;
    }
};