const int INF = 0x3f3f3f3f;

class Solution {
public:
    unordered_map<int, int> dp;
    
    int solve(int n)
    {
        if (n == 1) return 1;
        if (n == 0) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        int ans = min(1 + n % 2 + solve(n / 2), 1 + n % 3 + solve(n / 3));
        dp[n] = ans;
        return ans;
    }
    
    int minDays(int n) {
        dp = {};
        return solve(n);
    }
};