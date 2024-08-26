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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return helper(root, 1);
    }

    int helper(TreeNode* root, int height) {
        if (root == nullptr) return height;
        if (root->left == nullptr && root->right == nullptr) return height;
        if (root->left == nullptr) return helper(root->right, height + 1);
        if (root->right == nullptr) return helper(root->left, height + 1);
        return std::min(
            helper(root->left, height + 1),
            helper(root->right, height + 1)
        );
    }
};
