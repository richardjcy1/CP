#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                a[i][j] = x;
            }
        }
        ll ans = 0; 
        for (int j = 0; j < n; j++)
        {
            ll tmp = 0;
            for (int i = 0, k = j; i < n && k < n; i++, k++) 
            {
                tmp += a[i][k];
                ans = max(ans, tmp);
            }
        }
        for (int i = 1; i < n; i++)
        {
            ll tmp = 0;
            for (int k = i, j = 0; k < n && j < n; k++, j++)
            {
                tmp += a[k][j];
                ans = max(ans, tmp);
            }
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}