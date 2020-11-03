#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
public:
/*
Bitmask DP:


*/
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = 0;
                if (i != j)
                {
                    int len = min(A[i].size(), A[j].size());
                    int sz1 = A[i].size(), sz2 = A[j].size();
                    for (int l = 1; l <= len; l++)
                    {
                        if (A[i].substr(sz1 - l) == A[j].substr(0, l))
                        {
                            tmp = l;
                        }
                    }
                    g[i][j] = sz2 - tmp;
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(1 << n, INF));
        vector<vector<int>> p(n, vector<int>(1 << n, INF));
        for (int i = 0; i < n; i++) dp[i][(1 << i)] = A[i].size();
        for (int mask = 1; mask < (1 << n); mask++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        if ((mask & (1 << i)) && (mask & (1 << j)))
                        {
                            int tmp = dp[j][mask - (1 << i)] + g[j][i];
                            if (tmp < dp[i][mask])
                            {
                                dp[i][mask] = tmp;
                                p[i][mask] = j;
                            }
                        }
                    }
                }
                // cout << i << " " << mask << " " << dp[i][mask] << " " << p[i][mask] << endl;
            }
        }
        int ans = INF, idx;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][(1 << n) - 1] < ans)
            {
                ans = dp[i][(1 << n) - 1];
                idx = i;
            }
        }
        // cout << ans << endl;
        string ret{A[idx]};
        int cur = (1 << n) - 1;
        for (int i = 1; i < n; i++)
        {
            int ncur = cur - (1 << idx);
            int nidx = p[idx][cur];
            int m = A[nidx].size();
            // cout << A[nidx] << " " << nidx << " " << g[nidx][idx] << endl;
            ret = A[nidx].substr(0, m - (A[idx].size() - g[nidx][idx])) + ret;
            cur = ncur;
            idx = nidx;
        }
        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}