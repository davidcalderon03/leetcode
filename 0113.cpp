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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> current;
        helper(root, targetSum, current, result);
        return result;
    }
    void helper(TreeNode* root, int targetSum, vector<int> current, vector<vector<int>>& result) {
        if (root == nullptr) return;
        current.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                result.push_back(current);
            }
            return;
        }
        helper(root->left, targetSum - root->val, current, result);
        helper(root->right, targetSum - root->val, current, result);
    }
};
