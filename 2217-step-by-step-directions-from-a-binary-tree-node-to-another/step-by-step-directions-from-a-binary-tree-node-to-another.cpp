/**
 * Definition for a binary tree TreeNode.
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

TreeNode* lca_BT(TreeNode* root,int n1,int n2){
    // base case :
    if(root == NULL) return NULL;

    // if n1 or n2 found : 
    if(root->val == n1 || root->val == n2){
        return root;
    }

    TreeNode* leftPart = lca_BT(root->left, n1, n2);
    TreeNode* rightPart = lca_BT(root->right, n1, n2);

    if (leftPart != NULL && rightPart != NULL) {
        return root;
    }

    else if (leftPart != NULL && rightPart == NULL) {
        return leftPart;
    }

    else if (leftPart == NULL && rightPart != NULL) {
        return rightPart;
    }

    return NULL; // else when both are NULL 
}

bool findPath(TreeNode* root, int value, string &ans){
    //base cases : 
    if(root == NULL) return false;
    if(root->val == value) return true;

    ans.push_back('L');
    if(findPath(root->left,value,ans)) return true;
    ans.pop_back();

    ans.push_back('R');
    if(findPath(root->right,value,ans)) return true;
    ans.pop_back();


    // ab bhi nhi mil rha mtlb nhi h path :
    return false;
}


    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lca = lca_BT(root,startValue,destValue);

        string ans;
        string pathToStart;
        string pathToDest;
        findPath(lca,startValue,pathToStart);
        findPath(lca,destValue,pathToDest);

        ans.append(pathToStart.length(),'U');
        ans.append(pathToDest);
        return ans;
    }
};