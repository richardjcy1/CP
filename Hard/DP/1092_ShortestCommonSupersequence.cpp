class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = m, j = n;
        string lcs;
        while (i && j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcs += str1[i - 1];
                i--; j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
        reverse(lcs.begin(), lcs.end());
        string ans;
        int len = lcs.size();
        i = j = 0;
        int k = 0;
        while (i < m && j < n && k < len)
        {
            while (i < m && str1[i] != lcs[k])
            {
                ans += str1[i];
                i++;
            }
            while (j < n && str2[j] != lcs[k])
            {
                ans += str2[j];
                j++;
            }
            ans += lcs[k];
            i++;
            j++;
            k++;
        }
        while (i < m) ans += str1[i++];
        while (j < n) ans += str2[j++];
        return ans;
    }
};