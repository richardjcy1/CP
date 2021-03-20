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
        ll w, h, n;
        cin >> w >> h >> n;
        ll cnt = 1;
        while (w % 2 == 0 || h % 2 == 0)
        {
            if (w % 2 == 0)
            {
                w /= 2;
                cnt *= 2;
            }
            else if (h % 2 == 0)
            {
                h /= 2;
                cnt *= 2;
            }
        }
        if (cnt >= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}