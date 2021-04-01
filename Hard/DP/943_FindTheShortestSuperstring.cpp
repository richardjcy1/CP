const int INF = 0x3f3f3f3f;

class Solution {
public:
    string shortestSuperstring(vector<string>& a) {
        int n = a.size();
        vector<vector<int>> g(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int tmp = 0;
                    for (int k = 1; k <= min(a[i].size(), a[j].size()); k++)
                    {
                        if (a[i].substr(a[i].size() - k) == a[j].substr(0, k)) tmp = k;
                    }
                    g[i][j] = a[j].size() - tmp;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(1 << n, INF));
        vector<vector<int>> prev(n, vector<int>(1 << n, n));
        for (int i = 0; i < n; i++)
        {
            dp[i][1 << i] = a[i].size();
            prev[i][1 << i] = -1;
        }
        for (int mask = 1; mask < 1 << n; mask++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j && (mask & (1 << i)) && (mask & (1 << j)) && dp[j][mask - (1 << i)] != INF)
                    {
                        int tmp = dp[j][mask - (1 << i)] + g[j][i];
                        if (dp[i][mask] > tmp)
                        {
                            dp[i][mask] = tmp;
                            prev[i][mask] = j;
                        }
                    }
                }
            }
        }
        string ans;
        int len = INF, idx;
        for (int i = 0; i < n; i++)
        {
            if (len > dp[i][(1 << n) - 1])
            {
                len = dp[i][(1 << n) - 1];
                idx = i;
            }
        }
        ans = a[idx];
        int mask = (1 << n) - 1;
        while (prev[idx][mask] != -1)
        {
            ans = a[prev[idx][mask]].substr(0, a[prev[idx][mask]].size() - a[idx].size() + g[prev[idx][mask]][idx]) + ans;
            int new_mask = mask - (1 << idx);
            idx = prev[idx][mask];
            mask = new_mask;
        }
        return ans;
    }
};