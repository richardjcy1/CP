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
    ll i;
    for (i = n; ; i++)
    {
        bool ok = true;
        for (ll j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    cout << i << endl;
    return 0;
}