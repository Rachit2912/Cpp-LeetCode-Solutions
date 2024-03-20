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

 void insertAtTail(struct ListNode* &head, struct ListNode* &tail, int val) {
        
        ListNode* temp = new ListNode(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
}
return prev;
}


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         // reverse ll:
    ListNode* first = reverse(l1);
    ListNode* second = reverse(l2);

    ListNode* ans_head = NULL;
    ListNode* ans_tail = NULL;
    int carry = 0;
    int digit = 0;
    int sum = 0;
    while (first != NULL || second != NULL || carry != 0) {
        
        int val1 = 0;
        if (first != NULL) {
        val1 = first->val;
        }

        int val2 = 0;
        if (second != NULL) {
        val2 = second->val;
        }
        
        sum = carry + val1 + val2 ;
        digit = sum % 10;
        carry = sum / 10;
        insertAtTail(ans_head,ans_tail, digit);

        if (first != NULL) {
        first = first->next;
        }

        if (second != NULL) {
        second = second->next;
        }
    }
    
    ListNode* final_ans = reverse(ans_head);
    
    return final_ans;

    }
};