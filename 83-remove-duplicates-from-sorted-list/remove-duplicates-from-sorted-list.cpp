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
    ListNode* deleteDuplicates(ListNode* head) {
         // empty list : 
    if(head == NULL || head->next == NULL){
        return head;
    }

    // non empty list:
    ListNode* curr = head;
    while(curr->next != nullptr){
        if(curr->val == curr->next->val){
            ListNode* nextNext = curr->next;
            curr->next = curr->next->next;
            delete nextNext;
        }

        else{
            curr = curr->next;
        }

    }
    return head;
    }
};