// Compute from left to right, and right to left
// In each run, if higher than previous one, increment by 1; otherwise put 1
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> left(n), right(n);
        left[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (r[i] > r[i - 1]) left[i] = 1 + left[i - 1];
            else left[i] = 1;
        }
        right[n - 1] = 1;
        for (int i = n - 2; ~i; i--)
        {
            if (r[i] > r[i + 1]) right[i] = 1 + right[i + 1];
            else right[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};