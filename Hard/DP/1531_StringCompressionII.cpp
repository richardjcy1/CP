const int INF = 0x3f3f3f3f;
const int maxn = 105;
int dp[maxn][maxn];

class Solution {
public:
    string s;
    int n;
    
    int Len(int n)
    {
        if (n == 1) return 0;
        if (n < 10) return 1;
        if (n < 100) return 2;
        return 3;
    }
    
    int solve(int idx, int tot)
    {
        if (idx == n) return 0;
        if (tot < 0) return INF;
        if (n - idx <= tot) return 0;
        if (dp[idx][tot] != -1) return dp[idx][tot];
        int ans = INF;
        vector<int> cnt(26);
        int ma = 0;
        for (int i = idx; i < n; i++)
        {
            cnt[s[i] - 'a']++;
            int rem = tot - (i - idx + 1) + cnt[s[i] - 'a'];
            if (rem >= 0) ans = min(ans, Len(cnt[s[i] - 'a']) + 1 + solve(i + 1, rem));
        }
        return dp[idx][tot] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        this->s = s;
        n = s.size();
        return solve(0, k);
    }
};