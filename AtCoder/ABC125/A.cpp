#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, t;
    cin >> a >> b >> t;
    int ans = 0;
    int i = a;
    while (i <= (double)(t + 0.5))
    {
        ans += b;
        i += a;
    }
    cout << ans << endl;
    return 0;
}