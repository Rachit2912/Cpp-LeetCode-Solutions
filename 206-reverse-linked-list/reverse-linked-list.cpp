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
    ListNode* reverseList(ListNode* head) {
   
    //base case : jb end me last element bacha hoga 
    if (head == NULL || head->next == NULL) {
    return head;
    }

    // recursive step : linked list ko todte todte jao and links reverse krte jao
    ListNode* remaining_ll_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return remaining_ll_head;
    }
};

