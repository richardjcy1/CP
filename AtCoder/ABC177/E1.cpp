#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

vector<int> primeFactors(int n)
{
    vector<int> res;
    if (n % 2 == 0)
    {
        res.push_back(2);
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) res.push_back(i);
        while (n % i == 0)
        {
            n /= i;
        }
    }
    if (n > 2)
    {
         res.push_back(n);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto v = primeFactors(a[i]);
        for (int j: v) mp[j]++;
    }
    bool p_ok = true;
    for (auto p: mp)
    {
        if (p.second > 1)
        {
            p_ok = false;
            break;
        }
    }
    if (p_ok) 
    {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int g = a[0];
    for (int i = 1; i < n; i++) g = __gcd(g, a[i]);
    if (g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}
