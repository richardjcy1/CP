#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<vector<int>> left(n, vector<int>(m));
    vector<vector<int>> right(n, vector<int>(m));
    vector<vector<int>> up(n, vector<int>(m));
    vector<vector<int>> down(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!j) left[i][j] = a[i][j];
            else left[i][j] = left[i][j - 1] + a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; ~j; j--)
        {
            if (j == m - 1) right[i][j] = a[i][j];
            else right[i][j] = right[i][j + 1] + a[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!i) up[i][j] = a[i][j];
            else up[i][j] = up[i - 1][j] + a[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; ~i; i--)
        {
            if (i == n - 1) down[i][j] = a[i][j];
            else down[i][j] = down[i + 1][j] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!a[i][j])
            {
                if (left[i][j]) ++ans;
                if (right[i][j]) ++ans;
                if (up[i][j]) ++ans;
                if (down[i][j]) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}