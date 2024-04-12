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
void k_sum_rcrsn(TreeNode* root,int targetSum, int &count, vector<int> paths){
    // base case :
    if(root == NULL) return;

    paths.push_back(root->val);

    // left call:
    k_sum_rcrsn(root->left, targetSum, count, paths);
    // right call :
    k_sum_rcrsn(root->right, targetSum, count, paths);

    // check if targetSum is achieved or not :
    int size = paths.size();
    long long int csum=0;
    for (int i = size-1; i>=0; i--){
        csum+=paths[i];
        if(csum==targetSum) count++;
    }
    
    // remove last element from path as it
    paths.pop_back();
}

    int pathSum(TreeNode* root, int targetSum) {
         vector<int>paths;
    int count = 0;
    k_sum_rcrsn(root,targetSum,count,paths);
    return count;
    }
};