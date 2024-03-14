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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // base case : 
        if(head == NULL){
            return NULL;
        }

        // reversing the first 'k' nodes of the ll : 
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* remaining_ll_head = NULL;

        while(count < k && curr != NULL){
            remaining_ll_head = curr->next;
            curr->next = prev;
            prev = curr;
            curr = remaining_ll_head;
            count++;
        } 

        // checking if there are enough nodes for the recursion step :
        int count_remain = 0;
        ListNode* temp = remaining_ll_head;
        while(temp != NULL){
            temp = temp->next;
            count_remain++;
        }

        // doing the recursion step if there are enough nodes :
        if(count_remain >= k){
            head->next = reverseKGroup(remaining_ll_head,k);
        }

        else{
            head->next = remaining_ll_head;
        }

        // returning the head of the k-reversed ll : 
        return prev;

    }
};