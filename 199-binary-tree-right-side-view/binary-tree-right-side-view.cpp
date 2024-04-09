class Solution {
private:
    map<int, int> mp;
    // {yCoordinate, value}
    vector<int> ans;

    void levelOrderTraversal(TreeNode *root) {
        if(root == NULL) return;

        queue<pair<TreeNode*, int>> que; // {node, yCoordinate}
        que.push({root, 0});

        while(!que.empty()) {
            TreeNode *node = que.front().first;
            int y = que.front().second;
            que.pop();

            if(mp.find(y) == mp.end()) {
                mp[y] = node->val;
            }

            if(node->right != NULL) que.push({node->right, y+1});
            if(node->left != NULL) que.push({node->left, y+1});
        }
    }
    
    void populateAns() {
        for(auto pr: mp) {
            ans.push_back(pr.second);
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        levelOrderTraversal(root);
        populateAns();
        return ans;
    }
};