/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root)
    {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        inorder(root->left);
        if (root->right) parent[root->right] = root;
        inorder(root->right);
    }

    vector<int> bfs(TreeNode* root, TreeNode* target, int k, vector<int> &ans)
    {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->val);
        while (!q.empty())
        {
            if (k == 0) break;
            int n = q.size();
            while (n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                // left
                if (curr->left and !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if (curr->right and !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if (parent[curr] and !visited.count(parent[curr]->val))
                {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        vector<int> ans;
        return bfs(root, target, k, ans);
    }
};