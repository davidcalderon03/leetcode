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
    int goodNodes(TreeNode* root) {
        int result = 0;
        helper(root, root->val, result);
        return result;
    }

    void helper(TreeNode* current, int maximum, int& result) {
        if (current == nullptr) return;
        if (current->val >= maximum) result++;
        maximum = max(maximum, current->val);
        helper(current->left, maximum, result);
        helper(current->right, maximum, result);
    }
};
