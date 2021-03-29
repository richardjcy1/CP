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
    vector<int> a;
    int idx = 0;
    int n;
    vector<int> ans;
    
    void dfs(TreeNode* node)
    {
        if (!node) return;
        if (node->val != a[idx])
        {
            ans = {-1};
            return;
        }
        ++idx;
        if (node->left && idx < n && a[idx] != node->left->val)
        {
            ans.push_back(node->val);
            dfs(node->right);
            dfs(node->left);
        }
        else
        {
            dfs(node->left);
            dfs(node->right);
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        a = v;
        n = a.size();
        ans = {};
        dfs(root);
        return !ans.empty() && ans[0] == -1 ? vector<int>{-1} : ans;
    }
};