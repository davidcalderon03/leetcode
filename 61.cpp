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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        deque<ListNode*> nodes;
        ListNode* current = head;
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }
        k = k % nodes.size();
        for (int i = 0; i < k; ++i) {
            ListNode* current = nodes.back();
            nodes.pop_back();
            nodes.back()->next = nullptr;
            current->next = nodes.front();
            nodes.push_front(current);
        }
        return nodes.front();
    }
};
