const int INF = 0x3f3f3f3f;
const int maxn = 105;
int dp[maxn][maxn];

class Solution {
public:
    string ring, key;
    int m, n;
    
    int solve(int idx1, int idx2)
    {
        if (idx2 == n) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int ans = INF;
        for (int i = 0; i < m; i++)
        {
            int pos = (i + idx1) % m;
            if (ring[pos] == key[idx2])
            {
                ans = min(ans, min(i, m - i) + 1 + solve(pos, idx2 + 1));
            }
        }
        return dp[idx1][idx2] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        this->ring = ring;
        this->key = key;
        m = ring.size();
        n = key.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0);
    }
};