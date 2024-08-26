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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = maxHeight(root);
        vector<vector<int>>result(height, vector<int>());
        populateData(root, result, height - 1);
        return result;
    }

    int maxHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
    void populateData(TreeNode* root, vector<vector<int>>& result, int height) {
        if (root == nullptr) return;
        result[height].push_back(root->val);
        populateData(root->left, result, height - 1);
        populateData(root->right, result, height - 1);
    }
};
