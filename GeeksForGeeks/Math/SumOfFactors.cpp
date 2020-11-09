#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int sumOfFactors(int n)
{
    int res = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int curr_sum = 1;
        int curr_term = 1;
        while (n % i == 0)
        {
            n /= i;
            curr_term *= i;
            curr_sum += curr_term;
        }
        res *= curr_sum;
    }
    if (n >= 2)
    {
        res *= (1 + n);
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 30; 
    cout << sumOfFactors(n); 
    return 0;
}