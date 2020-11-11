#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (a[i] == 0);
    cout << ans << endl;
    return 0;
}