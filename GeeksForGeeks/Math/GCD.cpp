#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 10, b = 15; 
    cout << "GCD(" << a << ", " 
         << b << ") = " << gcd(a, b)  
                        << endl; 
    a = 35, b = 10; 
    cout << "GCD(" << a << ", " 
         << b << ") = " << gcd(a, b)  
                        << endl; 
    a = 31, b = 2; 
    cout << "GCD(" << a << ", " 
         << b << ") = " << gcd(a, b)  
                        << endl; 
    return 0;
}