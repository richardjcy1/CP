#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    
    while (n)
    {
        if (n & 1) res = (res * a ) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool isPrime(unsigned int n, int k)
{
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    while (k--)
    {
        int a = 2 + rand() % (n - 4);
        if (gcd(n, a) != 1) return false;
        if (power(a, n - 1, n) != 1) return false;
    }
    return true;
}

void SieveOfErathsthenes(int n, bool isPrime[])
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) isPrime[i] = true;
    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * 2; i <= n; i += p)
                isPrime[i] = false;
        }
    }
}

int main() 
{ 
    int k = 3; 
    isPrime(11, k)?  cout << " true\n": cout << " false\n"; 
    isPrime(15, k)?  cout << " true\n": cout << " false\n"; 
    return 0; 
} 