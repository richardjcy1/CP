#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 105;
int dp[maxn][maxn];
vector<int> a;
int n;
vector<int> sum;

int solve(int idx, int tot)
{
    if (idx == n) return 0;
    if (dp[idx][tot] != -1) return dp[idx][tot];
    int ans = solve(idx + 1, tot);
    if (sum[idx] == 0 && idx + 1 < n && tot >= abs(a[idx + 1] - a[idx]))
    {
        ans = max(ans, 1 + solve(idx + 1, tot - abs(a[idx + 1] - a[idx])));
    }
    return dp[idx][tot] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int b;
    cin >> b;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    /*dp[i][j]: start from ith index with j budget, max cuts
    return dp[0][B]
    base: dp[n][j]=0;
    dp[i][j]=max(dp[i+1][j],1+dp[i+1][j-abs(a[i+1]-a[i])])
    */
    sum = vector<int>(n);
    sum[0] = (a[0] & 1) ? 1 : -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] & 1) sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(0, b);
    cout << ans << endl;
    return 0;
}