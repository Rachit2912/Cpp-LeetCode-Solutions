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

void rightView_rcrsn(TreeNode* root,vector<int> &ans, int level){
    if( root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);

    rightView_rcrsn(root->right,ans,level+1);
    rightView_rcrsn(root->left,ans,level+1);

}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView_rcrsn(root,ans,0);
        return ans;
    }
};