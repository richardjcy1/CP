class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0;
        vector<int> left(n), right(n);
        left[0] = h[0];
        right[n - 1] = h[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(h[i], left[i - 1]);
        }
        for (int i = n - 2; ~i; i--)
        {
            right[i] = max(h[i], right[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = min(left[i], right[i]);
            ans += (v - h[i]);
        }
        return ans;
    }
};