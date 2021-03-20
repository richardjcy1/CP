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
        ll l, r;
        cin >> l >> r;
        if (2 * l > r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
        

    return 0;
}