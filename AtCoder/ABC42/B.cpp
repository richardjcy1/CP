#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    string ans;
    for (int i = 0; i < n; i++) ans += v[i];
    cout << ans << endl;
    return 0;
}