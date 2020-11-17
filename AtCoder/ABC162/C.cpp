#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int l = 1; l <= k; l++)
            {
                ans += __gcd(i, __gcd(j, l));
            }
        }
    }
    cout << ans << endl;
    return 0;
}