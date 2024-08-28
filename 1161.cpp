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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> arr;
        traverseTree(root, 0, arr);
        int max_sum = INT_MIN;
        int max_index = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int row_sum = 0;
            for (int x : arr[i]) {
                row_sum += x;
            }
            if (row_sum > max_sum && arr[i].size() > 0) {
                max_sum = row_sum;
                max_index = i;
                std::cout << max_sum << std::endl;
            }
        }
        return max_index + 1; 
    }

    void traverseTree(TreeNode* current, int depth, vector<vector<int>>& arr) {
        if (current == nullptr) return;
        if (arr.size() >= depth) arr.push_back(std::vector<int>(0));
        arr[depth].push_back(current->val);
        std::cout << "Val: " << current->val << std::endl;
        traverseTree(current->left, depth + 1, arr);
        traverseTree(current->right, depth + 1, arr);
    }
};
