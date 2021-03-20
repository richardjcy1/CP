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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> r(m);
        vector<double> p(m);
        for (int i = 0; i < m; i++)
        {
            cin >> r[i] >> p[i];
        }
        /*find the first unmatched position from the end i
        if j >= i, ok p
        otherwise (1-p)*following probability
        */
        double ans = 0.0;
        int i = n - 1;
        double coef = 1.0;
        for (; ~i && a[i] == i + 1; i--);
        if (i == -1)
        {
            cout << setprecision(10) << 1.0 << endl;
            continue;
        }
        for (int j = 0; j < m; j++)
        {
            if (r[j] - 1 >= i)
            {
                ans += coef * p[j];
                coef *= (1 - p[j]);
            }
        }
        cout << setprecision(10) << ans << endl;
    }
    return 0;
}