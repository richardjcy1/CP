#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT
{
    vector<ll> bit;
    ll n;
    BIT() {init(-1);}
    BIT(ll n_) {init(n_);}
    void init(ll n_)
    {
        n = n_;
        bit.clear();
        bit.resize(n + 1, 0);
    }
    
    ll sum(ll i)
    {
        ll s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(ll i, ll x)
    {
        if (i == 0) return;
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    
    ll sum0(ll i)
    {
        return sum(i + 1);
    }
    
    void add0(ll i, ll x)
    {
        add(i + 1, x);
    }
};

int main() 
{ 
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(freq)/sizeof(freq[0]); 
    BIT bit(n);
    for (int i = 0; i < n; i++)
    {
        bit.add0(i, freq[i]);
    }
    cout << "Sum of elements in arr[0..5] is "
        << bit.sum0(5); 
  
    // Let use test the update operation 
    bit.add0(3, 6);
    cout << "\nSum of elements in arr[0..5] after update is "
        << bit.sum0(5); 
  
    return 0; 
} 