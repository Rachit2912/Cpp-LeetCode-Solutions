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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int curr_i = 1;
        int prev_cp = 0, first_cp =0;
        int minDistance = INT_MAX;

        while(next!=nullptr){
            if((curr->val < prev->val && curr->val < next->val) ||(curr->val > prev->val && curr->val > next->val)){

                //if first critical point : 
                if(prev_cp ==0){
                    prev_cp = curr_i;
                    first_cp = curr_i;
                }

                //
                else{
                    minDistance = min(minDistance,curr_i-prev_cp);
                                        prev_cp = curr_i;
                }
            }
            prev = prev->next;
            curr = curr->next;
            next = next->next;
            curr_i++ ;
        }

        if(minDistance != INT_MAX){
            int maxDistance = prev_cp - first_cp;
        ans = {minDistance,maxDistance};
        }

    return ans;
    }
};