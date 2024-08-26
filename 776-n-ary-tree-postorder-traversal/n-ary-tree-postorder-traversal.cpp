/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void post(Node* root, vector<int> &ans){

    // base case : 
    if(!root) return;

    for(auto i : root->children){
        post(i,ans);
    }

    ans.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        post(root,ans);
        return ans;
        
    }
};