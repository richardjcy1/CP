#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) cout << "Inverse doesn't exist" << endl;
    else
    {
        int res = (x % m + m) % m;
        cout << "Modular multiplicative inverse is " << res << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a = 3, m = 11;  
    modInverse(a, m);  

    return 0;
}