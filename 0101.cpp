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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* first, TreeNode* second) {
        if (first == nullptr && second == nullptr) return true;
        else if (first == nullptr || second == nullptr) return false;
        else if (first->val != second->val) return false;
        std::cout << first->val << " " << second->val << std::endl;
        return isSymmetricHelper(first->left, second->right) && isSymmetricHelper(first->right, second->left);
    }
};
