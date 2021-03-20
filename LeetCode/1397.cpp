#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
const int M = 1e9 + 7;
ll dp[505][55][2];

/*
Find all good strings (Digit DP + KMP)

key observation:
string can be treated as integers
within a range
find match in evil string, if mismatch, jump to nearest matched position

dfs(int oidx, int eidx, bool limit): original index, match evil string at eidx, whether at limit

*/

class Solution {
public:
    string es;
    vector<int> next;
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        es = evil;
        next = vector<int>(es.size());
        next[0] = -1;
        int j = -1;
        for (int i = 1; i < es.size(); i++)
        {
            while (j > -1 && es[j + 1] != es[i]) j = next[j];
            if (es[i] == es[j + 1]) j++;
            next[i] = j;
        }
        ll pre = solve(s1), ans = (solve(s2) - pre + M) % M;
        if (s1.find(evil) == string::npos) ans++;
        return (int)(ans % M);
    }
    
    string ds;
    
    ll solve(string digits)
    {
        memset(dp, 0, sizeof dp);
        ds = digits;
        return dfs(0, 0, true);
    }
    
    ll dfs(int idx, int eidx, bool limit)
    {
        if (eidx == es.size()) return 0;
        if (idx == ds.size()) return 1;
        if (dp[idx][eidx][limit ? 1 : 0] > 0) return dp[idx][eidx][limit ? 1 : 0];
        int max = limit ? ds[idx] : 'z';
        ll res = 0;
        for (int i = 'a'; i <= max; i++)
        {
            int tmp = eidx - 1;
            while (tmp >= 0 && es[tmp + 1] != i) tmp = next[tmp];
            if (es[tmp + 1] == i) ++tmp;
            res += dfs(idx + 1, tmp + 1, limit && (i == max));
            res %= M;
        }
        return dp[idx][eidx][limit ? 1 : 0] = res;
    }
    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 8;
    string s1 = "pzdanyao";
    string s2 = "wgpmtywi";
    string evil = "sdka";
    Solution sol;
    cout << sol.findGoodStrings(n, s1, s2, evil) << endl;
    return 0;
}