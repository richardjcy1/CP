#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int dp[15][1 << 15][2][2];

/*
Numbers with repeated digits: (digit DP)

more generic digit DP template

dp[pos][state][lead][limit]


*/

class Solution {
public:
    string a;
    int n;
    
    int dfs(int pos, int state, bool lead, bool limit)
    {
        if (pos == n) return 1;
        if (dp[pos][state][lead ? 1 : 0][limit ? 1 : 0] != -1) return dp[pos][state][lead ? 1 : 0][limit ? 1 : 0];
        int up = limit ? a[pos] - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= up; i++)
        {
            if (lead)
            {
                if (!i)
                {
                    ans += dfs(pos + 1, state, lead, false);
                }
                else
                {
                    if (!(state & (1 << i)))
                    {
                        ans += dfs(pos + 1, state | (1 << i), false, limit && i == a[pos] - '0');
                    }
                }
            }
            else
            {
                if (!(state & (1 << i)))
                {
                    ans += dfs(pos + 1, state | (1 << i), false, limit && i == a[pos] - '0');
                }
            }
        }
        return dp[pos][state][lead ? 1 : 0][limit ? 1 : 0] = ans;
    }
    
    int solve(int N)
    {
        a = to_string(N);
        n = a.size();
        return dfs(0, 0, true, true);
    }
    
    int numDupDigitsAtMostN(int N) {
        a = "";
        memset(dp, -1, sizeof dp);
        return N - solve(N) + 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}