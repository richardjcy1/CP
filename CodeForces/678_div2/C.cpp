#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll helper(int x, int y)
{
    ll ans = 1;
    for (int i = x; i >= (x - y + 1); i--)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, pos;
    cin >> n >> x >> pos;
    int small = 0, big = 0;
    int left = 0, right = n;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (pos < mid)
        {
            big++;
            right = mid;
        }
        else if (pos >= mid)
        {
            if (pos > mid) small++;
            left = mid + 1;
        }
    }
    //cout << "big: " << big << " small: " << small << endl;
    ll ans = 0;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    ans = helper(n - x, big) * helper(x - 1, small);
    ans %= mod;
    ans *= fac[n - big - small - 1];
    ans %= mod;
    cout << ans << endl;
    return 0;
}