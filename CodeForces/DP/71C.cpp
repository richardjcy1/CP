#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 3; i <= n; i++)
    {
        if (is_prime[i] || i == 4) primes.push_back(i);
    }
    // for (int i: primes) cout << i << " " << endl;
    // cout << endl;
    bool ok = false;
    for (int i: primes)
    {
        if (n % i == 0)
        {
            for (int j = 0; j < n / i; j++)
            {
                bool good = true;
                for (int k = j; k < n; k += n / i)
                {
                    if (!a[k])
                    {
                        good = false;
                        break;
                    }
                }
                if (good)
                {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) break;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}