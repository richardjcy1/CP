#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) cin >> a[i][j];
    }
    int mi = INF;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) mi = min(mi, a[i][j]);
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans += (a[i][j] - mi);
        }
    }
    cout << ans << endl;
    return 0;
}