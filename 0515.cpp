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
  vector<int> largestValues(TreeNode *root) {
    std::vector<int> result;
    findLargest(root, 0, result);
    return result;
  }

  void findLargest(TreeNode *node, int level, std::vector<int> &result) {
    if (node == nullptr) {
      return;
    } else if (result.size() == level) {
      result.push_back(node->val);
    } else {
      result[level] = std::max(result[level], node->val);
    }
    findLargest(node->left, level + 1, result);
    findLargest(node->right, level + 1, result);
  }
};
