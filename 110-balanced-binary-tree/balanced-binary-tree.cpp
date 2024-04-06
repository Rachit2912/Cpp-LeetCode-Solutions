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

pair<bool,int> isBalancedBT_rcrsn(TreeNode* root){
    // base case :
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    // recursive step : 
    pair<bool,int> left = isBalancedBT_rcrsn(root->left);
    pair<bool,int> right = isBalancedBT_rcrsn(root->right);

    bool l_ans = left.first;
    bool r_ans = right.first;
    bool diff = abs(left.second - right.second) <= 1 ;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second) +1 ;
    if(l_ans && r_ans && diff) {
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}
    bool isBalanced(TreeNode* root) {
        return isBalancedBT_rcrsn(root).first;
    }
};