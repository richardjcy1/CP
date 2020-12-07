#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;
ll dp[maxn];

/*
Restore the array (DP + memoization)

dp[i]:start from index i to the end, number of ways 
check bit by bit until number > k

rule out leadning zeroes case

T:O(N)
S:O(N)
*/

class Solution {
public:
    string s;
    int n;
    int k;
    
    ll solve(int pos)
    {
        if (pos == n) return 1;
        if (dp[pos] != -1) return dp[pos];
        ll ans = 0;
        for (int i = pos; i < n; i++)
        {
            if (stoll(s.substr(pos, i - pos + 1)) > k) break;
            if (i > pos && s[pos] == '0') break;
            if (stoll(s.substr(pos, i - pos + 1)) >= 1)
            {
                ans += solve(i + 1);
                ans %= mod;
            }
        }
        return dp[pos] = ans;
    }
    
    int numberOfArrays(string s, int k) {
        this->s = s;
        this->k = k;
        n = s.size();
        memset(dp, -1, sizeof dp);
        return solve(0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}