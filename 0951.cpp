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
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    map<int, set<int>> tree1;
    map<int, set<int>> tree2;
    set<int> vertices1;
    set<int> vertices2;
    helper(root1, tree1, vertices1);
    helper(root2, tree2, vertices2);
    return tree1 == tree2 && vertices1 == vertices2;
  }
  void helper(TreeNode *root, map<int, set<int>> &edges, set<int> &vertices) {
    if (root == nullptr)
      return;
    vertices.insert(root->val);
    if (root->left != nullptr) {
      edges[root->val].insert(root->left->val);
      helper(root->left, edges, vertices);
    }
    if (root->right != nullptr) {
      edges[root->val].insert(root->right->val);
      helper(root->right, edges, vertices);
    }
  }
};
