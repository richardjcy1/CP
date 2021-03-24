#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        if (a > b)
        {
            ll tmp = b - min(b - y, n);
            if (tmp > y) cout << tmp * a << endl;
            else
            {
                a -= min(a - x, n - b + y);
                cout << a * tmp << endl;
            }
        }
        else if (a < b)
        {
            ll tmp = a - min(a - x, n);
            if (tmp > x) cout << tmp * b << endl;
            else
            {
                b -= min(b - y, n - a + x);
                cout << tmp * b << endl;
            }
        }
        else
        {
            if (x > y)
            {
                ll tmp = b - min(b - y, n);
                if (tmp > y) cout << a * tmp << endl;
                else
                {
                    a -= min(a - x, n - b + y);
                    cout << a * tmp << endl;
                }
            }
            else
            {
                ll tmp = a - min(a - x, n);
                if (tmp > x) cout << tmp * b << endl;
                else
                {
                    b -= min(b - y, n - a + x);
                    cout << tmp * b << endl;
                }
            }
        }
    }
    return 0;
}