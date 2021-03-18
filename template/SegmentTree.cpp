struct SegmentTree
{
    int n;
    vector<int> st;
    
    SegmentTree(vector<int>& nums)
    {
        n = nums.size();
        st = vector<int>(2 * n);
        for (int i = n; i < 2 * n; i++) st[i] = nums[i - n];
        for (int i = n - 1; i > 0; i--) st[i] = st[2 * i] + st[2 * i + 1];
    }
    
    void update(int i, int val)
    {
        int diff = val - st[i + n];
        for (i += n; i > 0; i /= 2) st[i] += diff;
    }
    
    int sumRange(int i, int j)
    {
        int res = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2)
        {
            if (i % 2 == 1) res += st[i++];
            if (j % 2 == 0) res += st[j--];
        }
        return res;
    }
};