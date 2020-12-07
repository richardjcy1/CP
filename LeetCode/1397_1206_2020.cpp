#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
const int mod = 1e9 + 7;
ll dp[505][55][2];

class Solution {
public:
    string ss, e;
    vector<int> next;
    
    ll dfs(int pos1, int pos2, bool limit)
    {
        if (pos2 == e.size()) return 0;
        if (pos1 == ss.size()) return 1; 
        if (dp[pos1][pos2][limit ? 1 : 0] > 0) return dp[pos1][pos2][limit ? 1 : 0];
        ll ans = 0;
        int up = limit ? ss[pos1] : 'z';
        for (int i = 'a'; i <= up; i++)
        {
            int idx = pos2 - 1;
            while (idx >= 0 && i != e[idx + 1]) idx = next[idx];
            if (i == e[idx + 1]) ++idx;
            ans += dfs(pos1 + 1, idx + 1, limit && (i == up));
            ans %= mod;
        }
        return dp[pos1][pos2][limit ? 1 : 0] = ans;
    }
    
    ll solve(string s)
    {
        ss = s;
        // m = ss.size();
        memset(dp, 0, sizeof dp);
        return dfs(0, 0, true);
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        e = evil;
        // N = e.size();
        next = vector<int>(e.size());
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < e.size(); i++)
        {
            while (j > -1 && e[i] != e[j + 1]) j = next[j];
            if (e[i] == e[j + 1]) ++j;
            next[i] = j;
        }
        ll ans1 = solve(s1);
        // cout << ans1 << endl;
        // cout << solve(s2) << endl;
        ll ans2 = (solve(s2) - ans1 + mod) % mod;
        // cout << ans2 << endl;
        if (s1.find(evil) == string::npos) ++ans2;
        return (int)(ans2 % mod);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}