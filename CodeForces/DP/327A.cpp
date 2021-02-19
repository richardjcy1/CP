#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    int tot = pre[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int ones = pre[j] - pre[i - 1];
            int zeroes = j - i + 1 - ones;
            ans = max(ans, tot - ones + zeroes);
        }
    }
    cout << ans << endl;
    return 0;
}