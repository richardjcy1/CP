#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int b, int m)
{
    int x, y;
    int g = gcdExtended(b, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

void modDivide(int a, int b, int m)
{
    a %= m;
    int inv = modInverse(b, m);
    if (inv == -1) cout << "Division not defined";
    else cout << "Result of division is " << (inv % a) % m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int  a  = 8, b = 3, m = 5; 
    modDivide(a, b, m); 

    return 0;
}