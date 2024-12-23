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
  int minimumOperations(TreeNode *root) {
    std::vector<std::vector<int>> tree;
    buildTree(root, 0, tree);
    int operations = 0;
    for (int i = 0; i < tree.size(); ++i) {
      std::cout << "Another level" << std::endl;
      operations += numSwaps(tree[i]);
    }
    return operations;
  }

  void buildTree(TreeNode *current, int level,
                 std::vector<std::vector<int>> &tree) {
    if (current == nullptr) {
      return;
    }
    if (tree.size() < level + 1) {
      tree.push_back({});
    }
    tree[level].push_back(current->val);
    buildTree(current->left, level + 1, tree);
    buildTree(current->right, level + 1, tree);
  }

  int numSwaps(std::vector<int> nums) {
    int swaps = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      if (i != minIndex) {
        swaps++;
      }
      int temp = nums[i];
      nums[i] = nums[minIndex];
      nums[minIndex] = temp;
    }
    std::cout << swaps << std::endl;
    return swaps;
  }
};
