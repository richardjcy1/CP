#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

bool check(double r, unordered_map<int, vector<int>>& mp, vector<pair<int, int>>& v)
{
    for (auto& p: mp)
    {
        double x0 = p.first;
        int m = p.second.size();
        bool good = false;
        for (int i = 0; i < m - 1; i++)
        {
            bool ok = true;
            double y0 = (p.second[i + 1] + p.second[i]) / 2.0;
            for (auto& point: v)
            {
                int x = point.first, y = point.second;
                if ((x - x0) * (x - x0) + (y - y0) * (y - y0) < r * r) 
                {
                    ok = false;
                }
            }
            good = good || ok;
        }
        if (!good) return false;
    }   
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i].first].push_back(v[i].second);
    }
    for (auto& p: mp)
    {
        p.second.push_back(-100);
        p.second.push_back(100);
        sort(p.second.begin(), p.second.end());
    }
    double left = 0.0, right = 101.0;
    while (right - left >= 1e-5)
    {
        double mid = left + (right - left) / 2;
        cout << left << " " << right << " " << mid << endl;
        if (check(mid, mp, v))
        {
            left = mid;
        }
        else right = mid;
    }
    cout << left << endl;
    return 0;
}