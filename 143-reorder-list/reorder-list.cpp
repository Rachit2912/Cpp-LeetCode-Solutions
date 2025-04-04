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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return;

        ListNode* fast=head,*slow=head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow=slow->next;
        }

        ListNode* rev = reverseLL(slow);
        ListNode* curr = head;

        while(rev->next){
            ListNode* tempcurr = curr->next;
            curr->next = rev;

            ListNode* temprev = rev->next;
            rev->next=tempcurr;

            rev = temprev;
            curr = tempcurr;
        }

    }

private:
    ListNode* reverseLL(ListNode* head){

        if(head==NULL || head->next==NULL)return head;

        auto last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }


};