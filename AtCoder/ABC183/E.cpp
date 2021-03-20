#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int h, w;
vector<string> s;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w;
    s = vector<string>(h);
    for (int i = 0; i < h; i++) cin >> s[i];
    vector<vector<ll>> row(h, vector<ll>(w));
    vector<vector<ll>> col(h, vector<ll>(w));
    vector<vector<ll>> diag(h, vector<ll>(w));
    vector<vector<ll>> dp(h, vector<ll>(w));
    dp[h - 1][w - 1] = 1;
    row[h - 1][w - 1] = 1;
    col[h - 1][w - 1] = 1;
    diag[h - 1][w - 1] = 1;
    for (int j = w - 2; ~j; j--)
    {
        if (s[h - 1][j] == '#')
        {
            dp[h - 1][j] = 0;
            continue;
        }
        dp[h - 1][j] = row[h - 1][j + 1];
        row[h - 1][j] = row[h - 1][j + 1] + dp[h - 1][j];
        row[h - 1][j] %= mod;
        diag[h - 1][j] = dp[h - 1][j];
        col[h - 1][j] = dp[h - 1][j];
    }
    for (int i = h - 2; ~i; i--)
    {
        if (s[i][w - 1] == '#')
        {
            dp[i][w - 1] = 0;
            continue;
        }
        dp[i][w - 1] = col[i + 1][w - 1];
        col[i][w - 1] = col[i + 1][w - 1] + dp[i][w - 1];
        col[i][w - 1] %= mod;
        diag[i][w - 1] = dp[i][w - 1];
        row[i][w - 1] = dp[i][w - 1];
    }
    for (int i = h - 2; ~i; i--)
    {
        for (int j = w - 2; ~j; j--)
        {
            if (s[i][j] == '#') continue;
            dp[i][j] = ((row[i][j + 1] + col[i + 1][j]) % mod + diag[i + 1][j + 1]) % mod;
            row[i][j] = (row[i][j + 1] + dp[i][j]) % mod;
            col[i][j] = (col[i + 1][j] + dp[i][j]) % mod;
            diag[i][j] = (diag[i + 1][j + 1] + dp[i][j]) % mod;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}