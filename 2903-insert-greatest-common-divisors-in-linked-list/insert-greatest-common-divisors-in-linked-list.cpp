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
 int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
                if (head->next == nullptr) return head;

                ListNode* prev = head;
                ListNode* nextt = head->next;

                while(nextt != NULL){
                    int gcd = GCD(prev->val,nextt->val);
                    ListNode* gN = new ListNode(gcd);
                    prev->next = gN;
                    gN->next = nextt;
                    prev = nextt;
                    nextt = nextt->next;
                }
                return head;
    }
};