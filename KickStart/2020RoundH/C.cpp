#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end());
        ll left_x = -1e9 - 5, right_x = 1e9 + 5;
        while (left_x <= right_x)
        {
            ll mid = left_x + (right_x - left_x) / 2;
            if (


    return 0;
}