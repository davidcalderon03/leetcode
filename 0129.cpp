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
  int sumNumbers(TreeNode *root) {
    int total = 0;
    helper(root, "", total);
    return total;
  }
  void helper(TreeNode *current, string number, int &total) {
    if (current == nullptr) {
      return;
    } else if (current->left == nullptr && current->right == nullptr) {
      total += stoi(number + to_string(current->val));
      return;
    } else {
      helper(current->left, number + to_string(current->val), total);
      helper(current->right, number + to_string(current->val), total);
    }
  }
};
