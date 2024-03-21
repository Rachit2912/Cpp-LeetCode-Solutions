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

	// step 2 : add clone nodes in between the originalNodes
	

	Node* originalNode = head;
	Node* cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {
                Node *next = originalNode->next;
                originalNode->next = cloneNode;
                originalNode = next;

                next = cloneNode->next;
                cloneNode->next = originalNode;
                cloneNode = next;
        }



        // step 3 : random pointer copy to cloneNodes
    	temp = head;
        while (temp != NULL){
			if(temp->next != NULL){
				temp->next->random = temp->random ? temp->random->next : temp->random;
			}

			temp = temp->next->next;

		}

        //step 4 : revert the changes done in step 2
		originalNode = head;
		cloneNode = cloneHead;

		while(originalNode != NULL && cloneNode != NULL){
			originalNode->next = cloneNode->next;
			originalNode = originalNode->next;

                        if (originalNode != NULL) {
                                cloneNode->next = originalNode->next;
                        }
                        cloneNode = cloneNode->next;
		}

    
// step 5 : return the cloneHead as your answer
return cloneHead;

    }
};