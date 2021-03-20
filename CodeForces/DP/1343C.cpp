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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll sum = 0;
        priority_queue<ll> pq;
        pq.push(a[0]);
        for (int i = 1; i < n; i++)
        {
            if ((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0 && a[i - 1] < 0)) pq.push(a[i]);
            else
            {
                sum += pq.top();
                pq = {};
                pq.push(a[i]);
            }
        }
        if (!pq.empty()) sum += pq.top();
        cout << sum << endl;
    }
    return 0;
}