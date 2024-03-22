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

// for finding middle of ll :
ListNode* middle_ll_2(ListNode* &head){
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    }

    return slow;
}


// merging 2 ll : 
ListNode* merge_2_sorted_ll(ListNode* left, ListNode* right){
    if (left == NULL) {
    return right;
    }

    if (right == NULL) {
    return left;
    }

    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;

    while (left != NULL && right != NULL) {

    if (left->val < right->val) {
    temp->next = left;
    temp = left;
    left = left->next;
    }

    else {
    temp->next = right;
    temp = right;
    right = right->next;
    }
    }

    while (left != NULL) {
    temp->next = left;
    temp = left;
    left = left->next; 
    }

    while (right != NULL) {
    temp->next = right;
    temp = right;
    right = right->next;
    }

    ans = ans->next;
    return ans;

}


    ListNode* sortList(ListNode* head) {


         // base case : 
    if (head == NULL || head->next == NULL) return head;

    // dividing ll into 2 parts and making a partition  around the middle element:
    ListNode* mid = middle_ll_2(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL; // for making a wall or partition to divide the ll into 2 parts 


    // recursive calls to sort both halves :
    left = sortList(left);
    right = sortList(right);

    ListNode* result = merge_2_sorted_ll(left, right);

    // returning the ans.
    return result;
    }
};