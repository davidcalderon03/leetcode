/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *issueOne = nullptr;
  TreeNode *issueTwo = nullptr;
  TreeNode *previous = nullptr;
  void recoverTree(TreeNode *root) {
    traverse(root);
    swap(issueOne->val, issueTwo->val);
  }

  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    traverse(root->left);
    if (issueOne == nullptr && previous != nullptr &&
        root->val < previous->val) {
      issueOne = previous;
    }
    if (issueOne != nullptr && root->val < previous->val) {
      issueTwo = root;
    }
    previous = root;
    traverse(root->right);
  }
};
