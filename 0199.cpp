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
  vector<int> rightSideView(TreeNode *root) {
    vector<vector<int>> arr;
    int depth = 0;
    helper(root, depth, arr);
    vector<int> result;
    for (vector<int> row : arr) {
      result.push_back(row[row.size() - 1]);
    }
    return result;
  }

  void helper(TreeNode *node, int depth, vector<vector<int>> &arr) {
    if (node == nullptr)
      return;
    if (arr.size() <= depth)
      arr.push_back(vector<int>(0));
    arr[depth].push_back(node->val);

    helper(node->left, depth + 1, arr);
    helper(node->right, depth + 1, arr);
  }
};
