#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// Given a number n, print all primes smaller than or equal to n
vector<int> SieveOfSundaram(int n)
{
    int nNew = (n - 1) / 2;
    bool marked[nNew + 1];
    memset(marked, false, sizeof marked);
    
    for (int i = 1; i <= nNew; i++)
        for (int j = i; (i + j + 2 * i * j) <= nNew; j++)
            marked[i + j + 2 * i * j] = true;

    vector<int> ans;
    if (n > 2) 
    {
        ans.push_back(2);
        //cout << 2 << " ";
    }
    for (int i = 1; i <= nNew; i++)
    {
        if (!marked[i]) 
        {
            ans.push_back(2 * i + 1);
            //cout << 2 * i + 1 << " ";
        }
    }
    return ans;
}

int main(void) 
{ 
    int n = 20; 
    vector<int> ans = SieveOfSundaram(n); 
    return 0; 
}