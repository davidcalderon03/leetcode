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
  ListNode *deleteDuplicates(ListNode *head) {
    while (head != nullptr && head->next != nullptr &&
           head->val == head->next->val) {
      int val = head->val;
      while (head != nullptr && head->val == val) {
        head = head->next;
      }
    }
    ListNode *current = head;
    if (head == nullptr) {
      return head;
    }
    ListNode *currentNext = current->next;
    while (currentNext != nullptr && currentNext->next != nullptr) {
      while (currentNext != nullptr && currentNext->next != nullptr &&
             currentNext->val == currentNext->next->val) {
        int val = currentNext->val;
        while (currentNext != nullptr && currentNext->val == val) {
          currentNext = currentNext->next;
        }
      }
      current->next = currentNext;
      current = current->next;
      if (currentNext != nullptr) {
        currentNext = currentNext->next;
      }
    }
    return head;
  }
};
