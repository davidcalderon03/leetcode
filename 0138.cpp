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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> pointers; // old pointer to new pointer
        Node* new_head = new Node(head->val);
        Node* current_new = new_head;
        Node* current = head;
        pointers[head] = new_head;
        while (current != NULL) {
            if (current->next != NULL && pointers.find(current->next) == pointers.end()) {
                Node* new_node = new Node(current->next->val);
                current_new->next = new_node;
                pointers[current->next] = new_node;
            } else {
                current_new->next = pointers[current->next];
            }
            if (current->random != NULL && pointers.find(current->random) == pointers.end()) {
                Node* new_node = new Node(current->random->val);
                current_new->random = new_node;
                pointers[current->random] = new_node;
            } else {
                current_new->random = pointers[current->random];   
            }
            current = current->next;
            current_new = current_new->next;
        }
        return new_head;
    }
};
