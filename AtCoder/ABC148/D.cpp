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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == j) ++j;
    }
    if (j > 1) cout << n - j + 1 << endl;
    else cout << -1 << endl;
    return 0;
}