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
        vector<int> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];
        vector<int> degree(n);
        ll ans = accumulate(w.begin(), w.end(), (ll)0);
        priority_queue<tuple<ll, ll>> pq;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            --x; --y;
            degree[x]++;
            degree[y]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] > 1)
            {
                pq.push(make_tuple(w[i], i));
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << ans << " ";
            if (pq.empty()) break;
            auto tmp = pq.top(); pq.pop();
            ans += get<0>(tmp);
            int node = get<1>(tmp);
            // cout << ans << " " << node << endl;
            degree[node]--;
            // cout << "degree " << degree[node] << endl;
            if (degree[node] > 1)
            {
                pq.push(make_tuple(w[node], node));
            }
        }
        cout << endl;
    }
    return 0;
}