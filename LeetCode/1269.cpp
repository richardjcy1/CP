#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
const int mod = 1e9 + 7;
ll dp[505][505];

class Solution {
public:
    // unordered_map<ll, unordered_map<ll, ll>> dp;
    int len;
    
    ll solve(int idx, int rem)
    {
        if (rem == 0) 
        {
            if (idx == 0) return 1;
            return 0;
        }
        // if (dp.find(idx) != dp.end() && dp[idx].find(rem) != dp[idx].end()) return dp[idx][rem];
        if (dp[idx][rem] != -1) return dp[idx][rem];
        ll ans = 0;
        if (idx - 1 >= 0)
        {
            ans += solve(idx - 1, rem - 1);
            ans %= mod;
        }
        if (idx + 1 < len)
        {
            ans += solve(idx + 1, rem - 1);
            ans %= mod;
        }
        ans += solve(idx, rem - 1);
        ans %= mod;
        dp[idx][rem] = ans;
        return ans;
    }
    
    
    int numWays(int steps, int arrLen) {
        // dp = {};
        memset(dp, -1, sizeof dp);
        len = arrLen;
        return solve(0, steps);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}