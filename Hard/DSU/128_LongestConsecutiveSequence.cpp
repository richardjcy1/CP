struct DisjointSets
{
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;

    DisjointSets(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int fi(int u)
    {
        if (u != parent[u])
        {
            parent[u] = fi(parent[u]);
        }
        return parent[u];
    }

    bool uni(int x, int y)
    {
        x = fi(x), y =fi(y);
        if (x == y) return false;
        if (size[x] < size[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y)
    {
        x = fi(x);
        y = fi(y);
        return x == y;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        DisjointSets dj(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) == mp.end())
            {
                mp[a[i]] = i;
                if (mp.find(a[i] - 1) != mp.end()) dj.uni(i, mp[a[i] - 1]);
                if (mp.find(a[i] + 1) != mp.end()) dj.uni(i, mp[a[i] + 1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, dj.size[i]);
        return ans;
    }
};