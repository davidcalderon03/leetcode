#include <deque>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = 0;
        ListNode* currentDestructor = head;
        ListNode* currentConstructor;
        std::deque<ListNode*> remainingNodes;
        bool cancelStack = false;
        while (currentDestructor != nullptr) {
            for (int i = 0; i < k; ++i) {
                if (currentDestructor == nullptr) {
                    cancelStack = true;
                    break;
                }
                remainingNodes.push_back(currentDestructor);
                currentDestructor = currentDestructor->next;
            }
            if (cancelStack) {
                while (remainingNodes.size() > 0) {
                    if (!first) {
                        first = remainingNodes.front();
                        remainingNodes.pop_front();
                        currentConstructor = first;
                    } else {
                        currentConstructor->next = remainingNodes.front();
                        remainingNodes.pop_front();
                        currentConstructor = currentConstructor->next;
                    }
                }
                break;
            }
            for (int i = 0; i < k && remainingNodes.size() > 0; ++i) {
                if (!first) {
                    first = remainingNodes.back();
                    remainingNodes.pop_back();
                    currentConstructor = first;
                } else {
                    currentConstructor->next = remainingNodes.back();
                    remainingNodes.pop_back();
                    currentConstructor = currentConstructor->next;
                }
            }
            if (currentDestructor == nullptr) currentConstructor->next = nullptr;
        }
        return first;
    }
};
