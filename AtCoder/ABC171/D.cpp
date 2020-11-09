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
    unordered_map<int, int> mp;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        mp[x]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int b, c;
        cin >> b >> c;
        sum += (c - b) * (ll)mp[b];
        mp[c] += mp[b];
        mp[b] = 0;
        cout << sum << endl;
    }
    return 0;
}