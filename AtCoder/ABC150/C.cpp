#include <bits/stdc++.h>
using namespace std;

const int maxn = 8;
int n;
int p[maxn];
int q[maxn];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    int fac[9];
    fac[0] = 1;
    for (int i = 1; i < 9; i++) fac[i] = i * fac[i - 1];
    int a = 0, b = 0, x = fac[n], y = fac[n];
    set<int> st_p{begin(p), end(p)};
    set<int> st_q{begin(q), end(q)};
    for (int i = 0; i < n - 1; i++)
    {
        x /= (n - i);
        auto it = st_p.find(p[i]);
        a += (distance(st_p.begin(), it)) * x;
        st_p.erase(p[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        y /= (n - i);
        auto it = st_q.find(q[i]);
        b += (distance(st_q.begin(), it)) * y;
        st_q.erase(q[i]);
    }
    cout << abs(a - b) << endl;
    return 0;
}