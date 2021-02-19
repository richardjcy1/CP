#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

string s1, s2;
int n, m;
vector<int> v;

void solve(int idx, int pos)
{
    if (idx == n) 
    {
        v[pos + n]++;
        return;
    }
    if (s2[idx] == '+') solve(idx + 1, pos + 1);
    if (s2[idx] == '-') solve(idx + 1, pos - 1);
    if (s2[idx] == '?')
    {
        solve(idx + 1, pos + 1);
        solve(idx + 1, pos - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s1;
    cin >> s2;
    m = s1.size(), n = s2.size();
    /*dp[i][j]:at ith index in s2, j position, final position
    s[i]=='+' dp[i+1][j+1]
    s[i]=='-' dp[i+1][j-1]
    s[i]=='?' dp[i+1][j+1] dp[i+1][j-1]
    */
    v = vector<int>(2 * n + 5);
    solve(0, 0);
    int cnt = 0;
    int d = 0;
    for (int i = 0; i < m; i++)
    {
        if (s1[i] == '+') ++d;
        else --d;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i];
    }
    double ans = (v[d + n] + 0.0) / cnt;
    cout << setprecision(15) << ans << endl;
    return 0;
}