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
    ll k;
    cin >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> vis(n + 1);
    int j = 1, cnt = 0;
    while (!vis[j])
    {
        vis[j] = true;
        j = a[j];
        ++cnt;
    }
    int i = 1, cnt2 = 0;
    while (i != j)
    {
        ++cnt2;
        i = a[i];
    }
    ll cnt1 = cnt - cnt2;
    j = 1;
    if (k <= cnt2)
    {
        while (k--)
        {
            j = a[j];
        }
    }
    else
    {
        k -= cnt2;
        k %= cnt1;
        j = i;
        while (k--)
        {
            j = a[j];
        } 
    }
    cout << j << endl;
    return 0;
}