const int maxn = 1e6 + 5;
int son[maxn][2];
int cnt[maxn];
int idx = 0;

class Solution {
public:
    int query(int x, int h)
    {
        int ans = 0, p = 0;
        for (int i = 16; ~i; i--)
        {
            int u = (x >> i) & 1;
            int v = (h >> i) & 1;
            if (u == 0 && v == 1)
            {
                ans += cnt[son[p][0]];
                p = son[p][1];
            }
            if (u == 0 && v == 0)
            {
                p = son[p][0];
            }
            if (u == 1 && v == 0)
            {
                p = son[p][1];
            }
            if (u == 1 && v == 1)
            {
                ans += cnt[son[p][1]];
                p = son[p][0];
            }
            if (!p) return ans;
        }
        return ans;
    }
    
    void insert(int x)
    {
        int p = 0;
        for (int i = 16; ~i; i--)
        {
            int u = (x >> i) & 1;
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
            cnt[p]++;
        }
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;
        int ans = 0;
        for (int i: nums)
        {
            ans = ans + query(i, high + 1) - query(i, low);
            insert(i);
        }
        return ans;
    }
};