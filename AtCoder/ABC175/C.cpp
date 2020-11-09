#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, k, d;
    cin >> x >> k >> d;
    
    ll a = abs(x);
    if (a / d > k)
    {
        if (x > 0) x -= k * d;
        else x += k * d;
    }
    else
    {
        if (x > 0) x -= a / d * d;
        else x += a / d * d;
        k -= a / d;
        if (x > 0)
        {
            if (k & 1) x -= d;
        }
        else
        {
            if (k & 1) x += d;
        }
    }
    cout << abs(x) << endl;
    return 0;
}