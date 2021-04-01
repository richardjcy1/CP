class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) left[i] = max(left[i], 1 + left[j]);
            }
        }
        for (int i = n - 2; ~i; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j]) right[i] = max(right[i], 1 + right[j]);
            }
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (left[i] > 1 && right[i] > 1)
            {
                ans = max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
};