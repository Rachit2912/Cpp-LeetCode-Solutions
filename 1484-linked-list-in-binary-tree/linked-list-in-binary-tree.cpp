/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
     if(!root)return false;
     bool r = dfs(root,head);

     r |= isSubPath(head,root->left);
     r |= isSubPath(head,root->right);
     return r;   
    }

    bool dfs(TreeNode* root, ListNode* head){
        if(!head)return true;
        if(!root)return false;

        bool r = false;
        if(root->val == head->val){
            r |= dfs(root->left,head->next);
            r |= dfs(root->right,head->next);
        }
        return r;
    }
};