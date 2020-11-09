#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    ll r, d, x;
    cin >> r >> d >> x;
    ll ans = r * x - d;
    for (int i = 0; i < 10; i++)
    {
        cout << ans << endl;
        ans = r * ans - d;
    }
    return 0;
}