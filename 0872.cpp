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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        constructLeafList(root1, list1);
        constructLeafList(root2, list2);
        return list1 == list2;
    }

    void constructLeafList(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        if (node->left == nullptr &&
            node->right == nullptr) result.push_back(node->val);
        constructLeafList(node->left, result);
        constructLeafList(node->right, result);
    }
};
