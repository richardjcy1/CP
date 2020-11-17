#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

bool check(ll x, vector<int>& a, int k)
{
    int n = a.size();
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % x == 0) cnt += a[i] / x;
        else cnt += a[i] / x + 1;
    }
    return cnt <= n + k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll left = 1, right = 1e9 + 5;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (check(mid, a, k))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}