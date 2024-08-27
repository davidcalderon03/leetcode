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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        if (length == 1) return nullptr;
        current = head;
        int index = 0;
        while (current != nullptr) {
            if (index == length / 2 - 1) {
                ListNode* next = current->next->next;
                current->next = next;
                break;
            }
            index++;
            current = current->next;
        }
        return head;
    }
};
