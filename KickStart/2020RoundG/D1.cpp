#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double solve(vector<int> a)
{
    if (a.size() == 2) return a[0] + a[1];
    ll ans = 0;
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < i; j++) tmp.push_back(a[j]);
        tmp.push_back(a[i] + a[i + 1]);
        for (int j = i + 2; j < n; j++) tmp.push_back(a[j]);
        ans += a[i] + a[i + 1] + (n - 2) * solve(tmp);
    }
    return ans / (n - 1 + 0.0);
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int kase = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
        }
        double ans = solve(a);
        cout << setprecision(20) << "Case #" << ++kase << ": " << ans << endl;
    }

    return 0;
}