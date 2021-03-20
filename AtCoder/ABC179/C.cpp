#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i * j < n; j++)
        {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}