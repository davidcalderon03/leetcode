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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr) return head;
        ListNode* leftEdge = head;
        ListNode* leftEnd;
        int i;
        for (i = 1; i < left - 1; ++i) {
            leftEdge = leftEdge->next;
        }
        if (left > 1)
            leftEnd = leftEdge->next;
        else leftEnd = leftEdge;
        if (left == 1) i = 0;
        i += 1;
        ListNode* current;
        if (left > 1) current = leftEdge->next;
        else current = leftEdge;
        ListNode* next = current->next;
        for (;i < right; ++i) {
            ListNode* nextNext = next->next;
            next->next = current;
            current = next;
            next = nextNext;
        }
        if (left != 1) {
            leftEdge->next = current;
        }
        leftEnd->next = next;

        if (left == 1) {
            return current;
        } else {
            return head;
        }
    }
};
