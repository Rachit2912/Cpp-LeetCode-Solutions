/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {


     if (head == NULL) {
        return false;
    }

    map<ListNode*, bool> visited;
    ListNode* temp = head;

    while (temp != NULL) {

        if (visited[temp] == true) {
        return 1; // we reached at the visited node 
        }

    visited[temp] = true; // mark the current node as visited
    temp = temp->next;
    }

    return 0; // ll is not circular bcz we got null at the end


    }
};