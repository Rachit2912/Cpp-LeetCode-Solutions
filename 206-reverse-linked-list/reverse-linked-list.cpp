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
 void recursion_fn(ListNode* &head, ListNode* curr, ListNode* prev){
    // base case :
    if(curr == NULL){
        head = prev;
        return;
    }

    // recursive step :
    ListNode* remaining_ll_head = curr->next;
    recursion_fn(head,remaining_ll_head, curr);
    curr->next = prev;

}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    recursion_fn(head, curr, prev);
    return head;
    }
};

