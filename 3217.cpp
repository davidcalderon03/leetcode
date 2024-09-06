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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> num_set;
        for (int x : nums) num_set.insert(x);
        while (num_set.contains(head->val)) head = head->next;
        if (head == nullptr) return head;
        ListNode* current = head;
        ListNode* next = head->next;
        while (current != nullptr && current->next != nullptr) {
            next = current->next;
            while (next != nullptr && num_set.contains(next->val)) {
                next = next->next;
            }
            current->next = next;
            current = current->next;
        }


        return head;
    }
};
