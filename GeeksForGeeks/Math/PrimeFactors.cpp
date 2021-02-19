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
        while (n % 2 == 0)
        {
            cout << 2 << " ";
            res.push_back(2);
            n /= 2;
        }
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 2)
    {
         cout << n << " ";
         res.push_back(n);
    }
    return res;
}

int main()  
{  
    int n = 315;  
    primeFactors(n);  
    return 0;  
}
