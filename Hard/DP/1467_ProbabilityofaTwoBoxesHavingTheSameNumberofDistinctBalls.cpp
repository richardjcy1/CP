// dfs+memoization
// traverse by each color, distribute balls in one box from 0-b[idx]
// update the color diff and total number of distributed balls
// precompute combinatorial numbers
// Time complexity: O(k*k*n*maxb[i])
// Space complexity: O(k*k*n)
typedef long long ll;
ll dp[10][20][50];

class Solution {
public:
    vector<int> b;
    vector<vector<ll>> C;
    int k;
    ll n;
    
    void comb()
    {
        C[1][0] = C[1][1] = 1;
        for (ll i = 2; i < 50; i++)
        {
            C[i][0] = C[i][i] = 1;
            for (ll j = 1; j < i; j++)
            {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
    }
    
    ll solve(int idx, int diff, int tot)
    {
        if (idx == k) return diff == k && tot == n / 2;
        if (tot > n / 2) return 0;
        if (dp[idx][diff][tot] != -1) return dp[idx][diff][tot];
        ll ans = 0;
        for (int i = 0; i <= b[idx]; i++)
        {
            if (!i)
            {
                ans += solve(idx + 1, diff - 1, tot);
            }
            else if (i == b[idx])
            {
                ans += solve(idx + 1, diff + 1, tot + i);
            }
            else
            {
                ans += solve(idx + 1, diff, tot + i) * C[b[idx]][i];
            }
        }
        return dp[idx][diff][tot] = ans;
    }
    
    double getProbability(vector<int>& b) {
        this->b = b;
        k = b.size();
        memset(dp, -1, sizeof dp);
        C = vector<vector<ll>>(50, vector<ll>(50));
        comb();
        n = accumulate(b.begin(), b.end(), (ll)0);
        return solve(0, k, 0) / (C[n][n / 2] + 0.0);
    }
};