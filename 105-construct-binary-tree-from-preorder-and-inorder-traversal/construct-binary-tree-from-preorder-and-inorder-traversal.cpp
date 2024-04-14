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

void createMap(vector<int> inorder,map<int, int> &nodeToIndex_inorder, int n){
    for (int i=0; i<n; i++) {
        nodeToIndex_inorder[inorder[i]] = i;
    }
}

TreeNode* BT_Pre_In_rcrsn(vector<int> &preorder,vector<int> &inorder, int &pre_index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex_inorder){

    // base case : 
    if(pre_index >= n || inorderStart > inorderEnd) return NULL;

    int element = preorder[pre_index++];
    TreeNode* root = new TreeNode(element);
    int position = nodeToIndex_inorder[element];
    // or can use brute force method to find:
    // for(int i=0; i<n; i++){
    //     if(in[i] == element) {position = i;}
    //     else {position = -1;}
    // }

    // recursive calls for left and right sub parts : 
    root->left = BT_Pre_In_rcrsn(preorder, inorder, pre_index, inorderStart, position-1, n,nodeToIndex_inorder);
    root->right = BT_Pre_In_rcrsn(preorder, inorder, pre_index, position+1, inorderEnd, n,nodeToIndex_inorder);

    return root;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int pre_index = 0;
    map<int, int> nodeToIndex_inorder;
    // creating a map to connect the nodes to their indices in inorder sequence
    createMap(inorder,nodeToIndex_inorder, inorder.size());
    TreeNode* ans = BT_Pre_In_rcrsn(preorder,inorder,pre_index,0, inorder.size()-1, inorder.size(),nodeToIndex_inorder);
    return ans;
    }
};