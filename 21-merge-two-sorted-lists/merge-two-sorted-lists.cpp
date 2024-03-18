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
        ListNode* tail=new ListNode(-1);
        ListNode* head=tail;
        while(list1!=NULL || list2!=NULL){
            if(list1==NULL){
                ListNode* temp=new ListNode(list2->val);
                tail->next=temp;
                tail=temp;
                list2=list2->next;
                continue;
            }
            if(list2==NULL){
                ListNode* temp=new ListNode(list1->val);
                tail->next=temp;
                tail=temp;
                list1=list1->next;
                continue;
            }
            if(list1->val>list2->val){
                ListNode* temp=new ListNode(list2->val);
                tail->next=temp;
                tail=temp;
                list2=list2->next;
            }
            else {
                ListNode* temp=new ListNode(list1->val);
                tail->next=temp;
                tail=temp;
                list1=list1->next;
            }
        }
        return head->next;
    }
};