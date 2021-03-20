#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    if (n & 1) cout << 0 << endl;
    else
    {
        ll cnt = 0;
        ll x = n;
        while (x)
        {
            ll tmp = x / 5;
            if (tmp & 1)
            {
                cnt += (tmp - 1) / 2;
            }
            else cnt += tmp / 2;
            x /= 5;
        }
        cout << cnt << endl;
    }
    return 0;
}