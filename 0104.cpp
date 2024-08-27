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
    int maxDepth(TreeNode* root) {
        return depthHelper(root, 0);
    }

    int depthHelper(TreeNode* node, int depth) {
        if (node == nullptr) return depth;
        return std::max(
            depthHelper(node->left, depth + 1),
            depthHelper(node->right, depth + 1)
        );
    }
};
