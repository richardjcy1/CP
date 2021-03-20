#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n, m, q;
vector<vector<int>> v;
vector<int> ans;
int ma;

void solve(int x, vector<int>& tmp)
{
    if (tmp.size() == n)
    {
        int sum = 0;
        //for (int i: tmp) cout << i << " ";
        //cout << endl;
        for (int i = 1; i <= q; i++)
        {
            if (v[i - 1][1] - 1 >= 0 && v[i - 1][0] - 1 >= 0 && tmp[v[i - 1][1] - 1] - tmp[v[i - 1][0] - 1] == v[i - 1][2]) sum += v[i - 1][3];
        }
        if (sum > ma) 
        {
            ans = tmp;
            ma = sum;
        }
        return;
    }
    for (int i = x; i <= m; i++)
    {
        tmp.push_back(i);
        solve(i, tmp);
        tmp.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    v = vector<vector<int>>(q, vector<int>(4));
    ma = -1;
    ans = {};
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i] = vector<int>{a, b, c, d};
    }
    vector<int> tmp;
    solve(1, tmp);
    cout << ma << endl;
    return 0;
}