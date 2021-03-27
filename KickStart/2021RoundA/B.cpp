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
    int kase = 0;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > a(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        vector<vector<int> > left(m, vector<int>(n));
        vector<vector<int> > right(m, vector<int>(n));
        vector<vector<int> > up(m, vector<int>(n));
        vector<vector<int> > down(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!j) left[i][j] = (a[i][j] == 1);
                else
                {
                    if (a[i][j]) left[i][j] = left[i][j - 1] + 1;
                    else left[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; ~j; j--)
            {
                if (j == n - 1) right[i][j] = (a[i][j] == 1);
                else
                {
                    if (a[i][j]) right[i][j] = right[i][j + 1] + 1;
                    else right[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (!i) up[i][j] = (a[i][j] == 1);
                else
                {
                    if (a[i][j]) up[i][j] = up[i - 1][j] + 1;
                    else up[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = m - 1; ~i; i--)
            {
                if (i == m - 1) down[i][j] = (a[i][j] == 1);
                else
                {
                    if (a[i][j]) down[i][j] = down[i + 1][j] + 1;
                    else down[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (left[i][j] >= 2 && down[i][j] >= 2)
                {
                    {
                        int mx = max(left[i][j], down[i][j]);
                        int mi = min(left[i][j], down[i][j]);
                        ans += (min(mi, mx / 2) - 1);
                        ans += (mi / 2 - 1);
                    }
                }
                if (left[i][j] >= 2 && up[i][j] >= 2)
                {
                    {
                        int mx = max(left[i][j], up[i][j]);
                        int mi = min(left[i][j], up[i][j]);
                        ans += (min(mi, mx / 2) - 1);
                        ans += (mi / 2 - 1);
                    }
                }
                if (right[i][j] >= 2 && down[i][j] >= 2)
                {
                    {
                        int mx = max(right[i][j], down[i][j]);
                        int mi = min(right[i][j], down[i][j]);
                        ans += (min(mi, mx / 2) - 1);
                        ans += (mi / 2 - 1);
                    }
                }
                if (right[i][j] >= 2 && up[i][j] >= 2)
                {
                    {
                        int mx = max(right[i][j], up[i][j]);
                        int mi = min(right[i][j], up[i][j]);
                        ans += (min(mi, mx / 2) - 1);
                        ans += (mi / 2 - 1);
                    }
                }
                //cout << i << " " << j << " " << ans << '\n';
            }
        }
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}