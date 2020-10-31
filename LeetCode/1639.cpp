#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words.size(), n = target.size(), k = words[0].size();
        vector<vector<int>> cnt(k, vector<int>(26));
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
        dp[0][0] = 1;
        for (int j = 1; j <= k; j++) dp[0][j] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                cnt[j][words[i][j] - 'a']++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += dp[i - 1][j - 1] * cnt[j - 1][target[i - 1] - 'a'];
                dp[i][j] %= mod;
            }
        }
        return dp[n][k];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;
    vector<string> words = {"acca","bbbb","caca"};
    string target = "aba";
    cout << sol.numWays(words, target) << endl;

    return 0;
}