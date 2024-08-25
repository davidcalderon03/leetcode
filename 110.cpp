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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left = checkHeight(root->left, 0);
        int right = checkHeight(root->right, 0);
        std::cout << left << " " << right << std::endl;
        if (abs(left - right) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }

    int checkHeight(TreeNode* root, int height) {
        if (root == nullptr) return height;
        return std::max(
            checkHeight(root->left, height + 1),
            checkHeight(root->right, height + 1)
        );
    }
};
