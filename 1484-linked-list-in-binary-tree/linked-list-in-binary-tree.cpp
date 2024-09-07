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
        if(!root) return false;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();

            if(isMatch(top,head)){return true;}

            if(top->left){
                s.push(top->left);
            }

            if(top->right){
                s.push(top->right);
            }
        }
        return false;
    }

    bool isMatch(TreeNode* node,ListNode* head){
        stack<pair<TreeNode*, ListNode*>> s;
        s.push({node,head});

        while(!s.empty()){
            auto [currNode, currHead] = s.top();
            s.pop();

            while(currNode && currHead){
                if(currNode->val != currHead->val){break;}
                currHead = currHead->next;

                if(currHead){
                    if(currNode->left){
                        s.push({currNode->left,currHead});
                    }
                    if(currNode->right){
                        s.push({currNode->right,currHead});
                    }

                    break;
                }
            }
            if(!currHead){
                return true;
            }
        }
        return false;
    }
};