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
    TreeNode* invertTree(TreeNode* root) {
        invertHelper(root);
        return root;
    }

    void invertHelper(TreeNode* node) {
        if (node == nullptr) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invertHelper(node->left);
        invertHelper(node->right);
    }
};
