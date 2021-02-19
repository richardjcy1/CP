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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        ll x = 0, y = 0;
        bool ok = true;
        while (i <= j)
        {
            if (ok)
            {
                if (a[j] % 2 == 0)
                {
                    x += a[j];
                    j--;
                }
                else j--;
            }
            else
            {
                if (a[j] % 2 == 0) j--;
                else
                {
                    y += a[j];
                    j--;
                }
            }
            ok = !ok;
        }
        if (x > y) cout << "Alice" << endl;
        else if (x == y) cout << "Tie" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}