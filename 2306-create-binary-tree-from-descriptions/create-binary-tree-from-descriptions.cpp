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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodeMap;
        unordered_set<int> children;

        for(auto v: descriptions){
            int parent = v[0];
            int child = v[1];
            bool isLeft = v[2];

            if(nodeMap.find(parent) == nodeMap.end()){
                nodeMap[parent] = new TreeNode(parent);
            }

            if(nodeMap.find(child) == nodeMap.end()){
                nodeMap[child] = new TreeNode(child);
            }

            if(isLeft){
                nodeMap[parent]->left = nodeMap[child];
            }
            else{
                nodeMap[parent]->right = nodeMap[child];
            }
            children.insert(child);
        }

        for(auto nodes: nodeMap){
            if(children.find(nodes.first) == children.end()) return nodes.second;
        }
        return nullptr;

    }
};