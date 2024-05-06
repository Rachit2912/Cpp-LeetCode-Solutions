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

 
void inorderSave(TreeNode* root, vector<int> &v){
    if(!root) return ;
    inorderSave(root->left , v);
    v.push_back(root->val);
    inorderSave(root->right , v);
}


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
    inorderSave(root, v);

    int i = 0, j = v.size() - 1;
    while (i < j) {
        int sum = v[i] + v[j];
        if (k == sum) {
            return true;
        }

        else if (sum > k) {
            j-- ; 
        }

        else{
            i++ ; 
        }
    }
    return false;
    }
};