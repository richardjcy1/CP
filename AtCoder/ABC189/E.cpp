#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
    if (a[0].size() != b.size())
    {
        cerr << "dimension mismatch" << endl;
    }
    int m = a.size(), n = a[0].size(), k = b[0].size();
    vector<vector<ll>> ans(m, vector<ll>(k));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ll tmp = 0;
            for (int u = 0; u < n; u++)
            {
                tmp += a[i][u] * b[u][j];
            }
            ans[i][j] = tmp;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;;
    cin >> n;
    vector<pair<ll, ll>> p;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    ll m;
    cin >> m;
    vector<pair<ll, ll>> ops;
    for (ll i = 0; i < m; i++)
    {
        ll op;
        cin >> op;
        if (op == 1 || op == 2) ops.push_back(make_pair(op, 0));
        else
        {
            ll v;
            cin >> v;
            ops.push_back(make_pair(op, v));
        }
    }
    ll q;
    cin >> q;
    vector<vector<ll>> a(3, vector<ll>(3));
    a[0][0] = a[1][1] = a[2][2] = 1;
    vector<vector<vector<ll>>> v;
    v.push_back(a);
    for (ll i = 0; i < m; i++)
    {
        if (ops[i].first == 1)
        {
            vector<vector<ll>> t(3, vector<ll>(3));
            t[0][1] = 1;
            t[1][0] = -1;
            t[2][2] = 1;
            v.push_back(mul(t, v.back()));
        }
        else if (ops[i].first == 2)
        {
            vector<vector<ll>> t(3, vector<ll>(3));
            t[0][1] = -1;
            t[1][0] = 1;
            t[2][2] = 1;
            v.push_back(mul(t, v.back()));
        }
        else if (ops[i].first == 3)
        {
            vector<vector<ll>> t(3, vector<ll>(3));
            t[0][0] = -1;
            t[0][2] = 2 * ops[i].second;
            t[1][1] = 1;
            t[2][2] = 1;
            v.push_back(mul(t, v.back()));
        }
        else
        {
            vector<vector<ll>> t(3, vector<ll>(3));
            t[0][0] = 1;
            t[1][1] = -1;
            t[1][2] = 2 * ops[i].second;
            t[2][2] = 1;
            v.push_back(mul(t, v.back()));
        }
    }
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        --b;
        vector<vector<ll>> t(3, vector<ll>(1));
        t[0][0] = p[b].first;
        t[1][0] = p[b].second;
        t[2][0] = 1;
        auto ret = mul(v[a], t);
        cout << ret[0][0] << " " << ret[1][0] << endl;
    }
    return 0;
}