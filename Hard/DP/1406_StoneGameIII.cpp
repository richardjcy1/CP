const int maxn = 50005;
int dp[maxn];

class Solution {
public:
    vector<int> a;
    int n;
    
    int solve(int idx)
    {
        if (idx == n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = a[idx] - solve(idx + 1);
        int tot = a[idx];
        for (int i = idx + 1; i <= idx + 2 && i < n; i++)
        {
            tot += a[i];
            ans = max(ans, tot - solve(i + 1));
        }
        return dp[idx] = ans;
    }
    
    string stoneGameIII(vector<int>& a) {
        this->a = a;
        n = a.size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0);
        if (ans > 0) return "Alice";
        else if (ans < 0) return "Bob";
        return "Tie";
    }
};