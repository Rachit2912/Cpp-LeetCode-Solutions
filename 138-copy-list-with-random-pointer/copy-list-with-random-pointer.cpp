#include <unordered_map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
 void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
	// step 1 : create a clone list and copy the content of our ll with next pointers only 
	Node* cloneHead = NULL;
	Node* cloneTail = NULL;
	Node* temp = head;
	while(temp != NULL){
		insertAtTail(cloneHead, cloneTail, temp->val);
		temp = temp->next;
	}

	// step 2 : create a map for store the mappings from original list to clone list
	unordered_map<Node*, Node*> oldToClone;

	Node* originalNode = head;
	Node* cloneNode = cloneHead;
	while(originalNode != NULL && cloneHead != NULL){
		oldToClone[originalNode] = cloneNode;
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;
	}

	originalNode = head;
	cloneNode = cloneHead;

	while(originalNode != NULL){
		cloneNode->random = oldToClone[originalNode->random];
		originalNode = originalNode->next;
		cloneNode = cloneNode->next;
	}

return cloneHead;

    }
};