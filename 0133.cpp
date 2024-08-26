/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<Node*, Node*> mapping;
        Node* new_start = new Node(node->val);
        mapping[node] = new_start;
        cloneGraphHelper(node, new_start, mapping);
        return new_start;
    }

    void cloneGraphHelper(Node* current, Node* new_current, unordered_map<Node*, Node*>& mapping) {
        for (Node* node : current->neighbors) {
            if (mapping.find(node) == mapping.end()) {
                Node* new_next = new Node(node->val);
                new_current->neighbors.push_back(new_next);
                mapping[node] = new_next;
                cloneGraphHelper(node, new_next, mapping);
            } else {
                new_current->neighbors.push_back(mapping[node]);
            }
        }
    }
};
