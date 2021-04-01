class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '(') continue;
            if (i >= 2 && s[i - 1] == ')' && s[i - 2] == '(') dp[i] = 2 + dp[i - 2];
            else if (i >= 2 && s[i - 1] == ')' && s[i - 2] == ')' && i - dp[i - 1] - 2 >= 0 && s[i - dp[i - 1] - 2] == '(') dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
        }
        return *max_element(dp.begin(), dp.end());
    }
};