#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    vector<int> bit;
    int n;
    BIT() {init(-1);}
    BIT(int n_) {init(n_);}
    void init(int n_)
    {
        n = n_;
        bit.clear();
        bit.resize(n + 1, 0);
    }
    
    int sum(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, int x)
    {
        if (i == 0) return;
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    
    int sum0(int i)
    {
        return sum(i + 1);
    }
    
    void add0(int i, int x)
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