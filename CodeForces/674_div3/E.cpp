#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(3);
    vector<int> b(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    ll ma = 0, mi = 0;
    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    for (int i = 0; i < 3; i++) pq.push(make_pair(a[i], i));
    bool ok = false;
    while (1)
    {
        if (ok) break;
        auto p = pq.top(); pq.pop();
        if (p.second == 0)
        {
            if (b[2]) 
            {
                int x = max(0, p.first - b[2]);
                b[2] = max(0, b[2] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else if (b[0])
            {
                int x = max(0, p.first - b[0]);
                b[0] = max(0, b[0] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else
            {
                mi = p.first;
                ok = true;
            }
        }
        else if (p.second == 1)
        {
            if (b[0]) 
            {
                int x = max(0, p.first - b[0]);
                b[0] = max(0, b[0] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else if (b[1])
            {
                int x = max(0, p.first - b[1]);
                b[1] = max(0, b[1] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else
            {
                mi = p.first;
                ok = true;
            } 
        }
        else
        {
            if (b[1]) 
            {
                int x = max(0, p.first - b[1]);
                b[1] = max(0, b[1] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else if (b[2])
            {
                int x = max(0, p.first - b[2]);
                b[2] = max(0, b[2] - p.first);
                pq.push(make_pair(x, p.second));
            }
            else
            {
                mi = p.first;
                ok = true;
            } 
        }
    } 

    cout << mi << " " << ma << endl;

    return 0;
}