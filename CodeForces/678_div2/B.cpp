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
        vector<vector<int>> a(n, vector<int>(n));
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i += 2)
            {
                a[i][i] = a[i][i + 1] = a[i + 1][i] = a[i + 1][i + 1] = 1;
            }
        }
        else
        {
            if (n % 3 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = i / 3 * 3; j <= i / 3 * 3 + 2; j++) a[i][j] = 1;
                }
            }
            else if (n % 3 == 1)
            {
                for (int i = 0; i < n - 4; i++)
                {
                    for (int j = i / 3 * 3; j <= i / 3 * 3 + 2; j++) a[i][j] = 1;
                }
                a[n - 4][n - 4] = a[n - 4][n - 3] = a[n - 3][n - 4] = a[n - 3][n - 3] = 1;
                a[n - 2][n - 2] = a[n - 2][n - 1] = a[n - 1][n - 2] = a[n - 1][n - 1] = 1;
            } 
            else
            {
                for (int i = 0; i < n - 2; i++)
                {
                    for (int j = i / 3 * 3; j <= i / 3 * 3 + 2; j++) a[i][j] = 1;
                }
                a[n - 2][n - 2] = a[n - 2][n - 1] = a[n - 1][n - 2] = a[n - 1][n - 1] = 1;
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}