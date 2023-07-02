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
    void solve(TreeNode* root, vector<int> &pre)
    {
        if (root == NULL) return;
        pre.push_back(root->val);
        solve(root->left, pre);
        solve(root->right, pre);
    }
    void flatten(TreeNode* root) {
        vector<int> pre;
        solve(root, pre);
        int n = pre.size();
        TreeNode* head = new TreeNode();
        TreeNode* curr = head;
        for (int i = 0; i < n; i++)
        {
            TreeNode* temp = new TreeNode(pre[i]);
            curr->right = temp;
            curr = curr->right;
        }
        curr = head->right;
        TreeNode* ans = root;
        while (curr)
        {
            ans->val = curr->val;
            ans->left = NULL;
            ans->right = curr->right;
            curr = curr->right;
            ans = ans->right;
        }
    }
};