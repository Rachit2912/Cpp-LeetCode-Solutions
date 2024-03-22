/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if (!head) return nullptr;
        Node* down = flatten(head->child) ;
        Node* remaining_ll_head = flatten(head->next);
        Node* tail = head;
        
        if(down){
        tail->next = down;
        while(tail->next){
            tail->next->prev = tail;
            tail->child = NULL;
            tail = tail->next;
        }}

        tail->next = remaining_ll_head;
        if(remaining_ll_head){
        remaining_ll_head->prev = tail;
        }

        return head;
    }
};