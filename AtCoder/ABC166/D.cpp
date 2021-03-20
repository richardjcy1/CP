#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x;
    cin >> x;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            for (ll a = 0; ; a++)
            {
                ll tmp = pow(a, 5) - pow(a - i, 5);
                if (a > i && tmp > x) break;
                if (tmp == x)
                {
                    cout << a << " " << a - i << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}