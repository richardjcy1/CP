#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;

/*

m rows n cols
mC(m + n)

state:i, j
m - i + n - j moves
(n - j)C(m - i + n - j)
H:(n - j - 1)C(m - i + n - j - 1)
V:(n - j)C(m - i + n - j - 1)


*/

class Solution {
public:
    map<int, map<int, map<int, string>>> dp;
    int m, n;
    vector<vector<ll>> f;
    
    string solve(int i, int j, int k)
    {
        int x = m - i, y = n - j;
        if (x == 0 && y == 0) return "";
        if (x == 0)
        {
            return string(n - j, 'H');
        }
        if (y == 0)
        {
            return string(m - i, 'V');
        }
        if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end() && dp[i][j].find(k) != dp[i][j].end()) return dp[i][j][k];
        string ans;
        ll v = f[x + y - 1][y - 1];
        if (v >= k)
        {
            ans = "H" + solve(i, j + 1, k);
        }
        else
        {
            ans = "V" + solve(i + 1, j, k - v);
        }
        dp[i][j][k] = ans;
        return ans;
    }
    
    string kthSmallestPath(vector<int>& destination, int k) {
        dp = {};
        m = destination[0], n = destination[1];
        f = vector<vector<ll>>(m + n + 1, vector<ll>(m + n + 1));
        f[1][0] = f[1][1] = 1;
        for (int i = 2; i <= m + n; i++)
        {
            f[i][0] = f[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            }
        }
        return solve(0, 0, k);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}