#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n <= 2) 
        {
            cout << 1 << endl;
        }
        else
        {
            int ans = (n - 2) % x == 0 ? (n - 2) / x + 1 : (n - 2) / x + 2;
            cout << ans << endl;
        }
    }
    return 0;
}



