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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* redhead = head;
        ListNode* temp = redhead->next;
            int sum = 0;
        while(temp){
            if(temp->val == 0){
                redhead->val = sum;
                if(!temp->next) break;
                redhead = redhead->next;
                sum = 0;
            }
            sum += temp->val;
            temp=temp->next;
        }
        redhead->next = NULL;
        return head;
        
    }
};