typedef long long ll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

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

class Solution {
public:
    int createSortedArray(vector<int>& a) {
        int n = a.size();
        BIT b(maxn);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            b.add(a[i], 1);
            int mi = b.sum(a[i] - 1);
            int ma = b.sum(maxn) - b.sum(a[i]);
            ans = (ans + min(mi, ma)) % mod;
        }
        return ans;
    }
};