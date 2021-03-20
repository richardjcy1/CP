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
        vector<tuple<ll, ll, ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            v.push_back(make_tuple(a, b, c, d));
        }
        


    return 0;
}