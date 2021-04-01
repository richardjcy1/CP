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
typedef long long ll;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    ll ans;
    unordered_map<TreeNode*, vector<ll>> dp;
    
    vector<ll> solve(TreeNode* node)
    {
        if (!node) return {0, INF, -INF, true};
        if (dp.find(node) != dp.end()) return dp[node];
        if (!node->left && !node->right)
        {
            ans = max(ans, (ll)node->val);
            return {node->val, node->val, node->val, true};
        }
        auto l = solve(node->left);
        auto r = solve(node->right);
        if (l[3] && r[3] && (l[2] == -INF || l[2] < node->val) && (r[1] == INF || r[1] > node->val))
        {
            ans = max(ans, l[0] + r[0] + node->val);
            return dp[node] = {l[0] + r[0] + node->val, min(l[1], (ll)node->val), max(r[2], (ll)node->val), true};
        }
        return dp[node] = {0, 0, 0, false};
    }
    
    void dfs(TreeNode* node)
    {
        if (!node) return;
        auto ret = solve(node);
        // if (get<3>(ret)) ans = max(ans, get<0>(ret));
        dfs(node->left);
        dfs(node->right);
    }
    
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;
        dp = {};
        ans = -INF;
        dfs(root);
        return ans < 0 ? 0 : ans;
    }
};