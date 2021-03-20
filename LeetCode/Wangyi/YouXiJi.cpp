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
    vector<vector<int>> a(m, vector<int>(n));
    vector<int> idx(n);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        --x;
        a[idx[x]][x] = 1;
        idx[x]++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int tot = 0;
        for (int j = 0; j < n; j++) tot += a[i][j];
        if (tot == n) ++ans;
        else break;
    }
    cout << ans << endl;
    return 0;
}