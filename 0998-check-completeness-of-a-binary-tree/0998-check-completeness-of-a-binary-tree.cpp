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
    int countNodes(TreeNode* root)
    {
        if (root == NULL) return 0;
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool solve(TreeNode* root, int i, int count)
    {
        if (root == NULL) return true;
        if (i >= count) return false;
        bool left = solve(root->left, 2*i + 1, count);
        bool right = solve(root->right, 2*i + 2, count);
        return left and right;
    }
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL) return true;
        int count = countNodes(root);
        int i = 0;
        return solve(root, i, count);
    }
};