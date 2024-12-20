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
         if (!root)return nullptr;  
        
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(q.size()){
            int size = q.size();
            vector<TreeNode*> currLevel;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                currLevel.push_back(node);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            if(l%2){
                int s=0,e=currLevel.size()-1;
                while(s<e){
                    int temp = currLevel[s]->val;
                    currLevel[s]->val = currLevel[e]->val;
                    currLevel[e]->val = temp;
                    s++;e--;
                }
            }
            l++;
        }
        return root;
    }
};