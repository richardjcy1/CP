#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Minimum cost to connect two groups of points: (Bitmask DP) pull dp
dp[i][mask]: connect first i points in group 1 with mask in group2, min cost
point i in group 1: 
#1. 1 to 1 dp[i-1][mask ^ 1 << j] + cost[i - 1][j]
#2. 1 to many dp[i][mask ^ 1 << j] + cost[i - 1][j]
#3. many to 1 dp[i-1][mask] + cost[i - 1][j]

sum all three cases

base: dp[0][0] = 0
return: dp[m][(1<<n)-1]

*/

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int mask = 0; mask < 1 << n; mask++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mask & 1 << j)
                    {
                        dp[i][mask] = min(dp[i][mask], cost[i - 1][j] + dp[i - 1][mask ^ 1 << j]);
                        dp[i][mask] = min(dp[i][mask], cost[i - 1][j] + dp[i][mask ^ 1 << j]);
                        dp[i][mask] = min(dp[i][mask], cost[i - 1][j] + dp[i - 1][mask]);
                    }
                }
            }
        }
        return dp[m][(1 << n) - 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}