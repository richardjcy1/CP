class Solution {
public:
    bool winnerSquareGame(int n) {
        if (n == 1) return true;
        vector<bool> dp(n + 1);
        dp[0] = false;
        dp[1] = true;
        for (int i = 2; i <= n; i++)
        {
            bool tmp = false;
            for (int j = 1; j * j <= i; j++)
            {
                tmp = tmp || !dp[i - j * j];
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};