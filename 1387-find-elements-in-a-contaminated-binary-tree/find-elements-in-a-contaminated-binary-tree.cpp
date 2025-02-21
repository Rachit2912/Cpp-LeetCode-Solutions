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
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root,0);
    }
    
    bool find(int target) {
        return seen.count(target)>0;
    }

private:
    unordered_set<int> seen;
    void dfs(TreeNode* root, int value){
        if(!root)return;
        root->val = value;
        seen.insert(root->val);
        dfs(root->left,value*2+1);
        dfs(root->right,value*2+2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */