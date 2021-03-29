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
    unordered_map<int, int> mp;
    vector<int> ans;
    
    bool solve(TreeNode* node, int start, int end)
    {
        if (start > end || !node || node->val != a[start]) return false;
        if (start == end) return node->val == a[start];
        if (node->left && node->right)
        {
            int lStart = start + 1;
            int rStart = mp[node->right->val];
            int lEnd = rStart - 1;
            int rEnd = end;
            if (solve(node->left, lStart, lEnd) && solve(node->right, rStart, rEnd)) return true;
            int lenLeft = lEnd - lStart + 1;
            int lenRight = rEnd - rStart + 1;
            int newRightStart = start + 1;
            int newLeftStart = mp[node->left->val];
            int newRightEnd = newLeftStart - 1;
            int newLeftEnd = end;
            if (solve(node->right, newRightStart, newRightEnd) && solve(node->left, newLeftStart, newLeftEnd))
            {
                ans.push_back(node->val);
                return true;
            }
            return false;
        }
        else if (node->left)
        {
            if (solve(node->left, start + 1, end)) return true;
        }
        else if (node->right)
        {
            if (solve(node->right, start + 1, end)) return true;
        }
        return false;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        a = v;
        int n = v.size();
        mp = {};
        for (int i = 0; i < n; i++) mp[v[i]] = i;
        ans = {};
        if (solve(root, 0, n - 1)) return ans;
        return {-1};
    }
};