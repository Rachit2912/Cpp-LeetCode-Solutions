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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;

        ListNode* curr1=list1,*curr2=list2;
        ListNode* ansHead = new ListNode(-1),*ans = ansHead;


        while(curr1!=NULL && curr2!=NULL){
            if(curr1->val > curr2->val){
                ans->next = new ListNode(curr2->val);
                ans = ans->next;
                curr2=curr2->next;
            }else if(curr1->val < curr2->val){
                ans->next = new ListNode(curr1->val);
                ans = ans->next;
                curr1=curr1->next;
            }else{
                ans->next = new ListNode(curr1->val);
                ans->next->next = new ListNode(curr2->val);
                ans = ans->next->next;
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }

        
        while(curr1){
            ans->next= new ListNode(curr1->val);
            ans=ans->next;
            curr1=curr1->next;
        }

        while(curr2){
            ans->next= new ListNode(curr2->val);
            ans=ans->next;
            curr2=curr2->next;
        }

        return ansHead->next;
    }
};