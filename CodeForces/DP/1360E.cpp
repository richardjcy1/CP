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
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '1')
                {
                    bool good = false;
                    if (i == n - 1 || j == n - 1) good = true;
                    else if (i + 1 < n && a[i + 1][j] == '1') good = true;
                    else if (j + 1 < n && a[i][j + 1] == '1') good = true;
                    if (!good) ok = false;
                }
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}