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
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> a = p;
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (p[i] != a[i]);
    if (cnt == 0 || cnt == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}