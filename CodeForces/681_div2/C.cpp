#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

bool check(ll x, vector<ll>& a, vector<ll>& b)
{
    int n = a.size();
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x) sum += b[i];
    }
    return sum <= x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        ll left = 0, right = 1e9 + 5;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (check(mid, a, b))
            {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        cout << left << endl;
    }

    return 0;
}