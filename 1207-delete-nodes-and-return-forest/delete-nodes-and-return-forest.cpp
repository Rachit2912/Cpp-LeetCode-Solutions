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

    TreeNode* making_list(TreeNode* node,unordered_set<int> &delset, vector<TreeNode*> &ans){
        if(!node) return nullptr;

        node->left = making_list(node->left,delset,ans);
        node->right = making_list(node->right,delset,ans);

        if(delset.find(node->val) != delset.end()){
            if(node->left) ans.push_back(node->left);
            if(node->right) ans.push_back(node->right);
            delete node;
            return nullptr;
        }
        return node;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // iske baad jin jinko bhi delete krna h un sbki value -1 ho gyi 
        //ab poora graph traverse kregne & jiski value -1 hui h uske 2 cases bnenge :
        // a) ya to vo leaf node h : to usse hmko kuch mtlb nhi 
        // b) koi parent h vo : ese me hmko tuta hue graph ko alg alg krke store krna hoga
        vector<TreeNode*> ans;
        unordered_set<int> delset(to_delete.begin(),to_delete.end());
        root = making_list(root,delset,ans);
        if(root)ans.push_back(root);
        return ans;
    }
};