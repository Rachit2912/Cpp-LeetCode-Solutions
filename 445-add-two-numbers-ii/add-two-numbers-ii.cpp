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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* temp = head;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode* a = l1;
        ListNode* b = l2;
        
        while(a != nullptr && b != nullptr) {
            int sum = a->val + b->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            a = a->next;
            b = b->next;
        }
        
        while(a != nullptr) {
            int sum = a->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            a = a->next;
        }
        
        while(b != nullptr) {
            int sum = b->val + carry;
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            b = b->next;
        }
        
        if(carry != 0) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        
        return reverseList(head);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};