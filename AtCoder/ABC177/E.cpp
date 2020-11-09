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
            //cout << 2 << " ";
            n /= 2;
        }
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) res.push_back(i);
        while (n % i == 0)
        {
            //cout << i << " ";
            n /= i;
        }
    }
    if (n > 2)
    {
         //cout << n << " ";
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
    vector<bool> vis(1e6 + 5);
    bool pairwise = true;
    for (int i = 0; i < n; i++)
    {
        vector<int> primes = primeFactors(a[i]);
        //cout << a[i] << " ";
        //for (int j: primes) cout << j << " ";
        //cout << endl;
        for (int j: primes)
        {
            if (j != 1 && vis[j]) pairwise = false;
            else vis[j] = true;
        }
    } 
    if (pairwise)
    {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int gcd = a[0];
    for (int i = 1; i < n; i++)
    {
        gcd = __gcd(gcd, a[i]);
    }
    if (gcd == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}