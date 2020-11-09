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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll tot = 0;
    for (int i = 0; i < n; i++) tot ^= a[i];
    for (int i = 0; i < n; i++)
    {
        cout << (tot ^ a[i]) << " ";
    }
    return 0;
}