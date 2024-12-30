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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<deque<int>> traversal;
    helper(root, traversal, 0);
    vector<vector<int>> traversalConversion;
    for (int i = 0; i < traversal.size(); ++i) {
      traversalConversion.push_back({});
      for (int j = 0; j < traversal[i].size(); ++j) {
        traversalConversion[i].push_back(traversal[i][j]);
      }
    }
    return traversalConversion;
  }

  void helper(TreeNode *current, vector<deque<int>> &traversal, int depth) {
    if (current == nullptr) {
      return;
    }
    if (traversal.size() <= depth) {
      traversal.push_back({});
    }
    if (depth % 2 == 0) {
      traversal[depth].push_back(current->val);
    } else {
      traversal[depth].push_front(current->val);
    }
    helper(current->left, traversal, depth + 1);
    helper(current->right, traversal, depth + 1);
  }
};
