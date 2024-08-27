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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        helper(root, 0, nums.size() - 1, nums);
        return root;
    }

    void helper(TreeNode* node, int low, int high, vector<int>& nums) {
        if (node == nullptr) return;
        int mid = (low + high) / 2;
        node->val = nums[mid];
        if (low < mid) {
            node->left = new TreeNode();
            helper(node->left, low, mid - 1, nums);
        }
        if (mid < high) {
            node->right = new TreeNode();
            helper(node->right, mid + 1, high, nums);
        }
    }





};
