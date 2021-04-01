typedef long long ll;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 3) return {-1, -1, -1};
        vector<ll> left(n), right(n);
        ll sum = accumulate(nums.begin(), nums.begin() + k - 1, (ll)0);
        ll ma = 0;
        int idx = -1;
        vector<ll> tot(n + 1);
        for (int i = 1; i <= n; i++)
        {
            tot[i] = tot[i - 1] + nums[i - 1];
        }
        for (int i = k - 1; i < n; i++)
        {
            sum += nums[i];
            if (sum > ma)
            {
                ma = sum;
                idx = i - k + 1;
            }
            left[i] = idx;
            if (i >= k - 1) sum -= nums[i - k + 1];
        }
        ma = 0;
        idx = -1;
        sum = accumulate(nums.begin() + n - k + 1, nums.end(), (ll)0);
        for (int i = n - k; ~i; i--)
        {
            sum += nums[i];
            if (sum >= ma)
            {
                ma = sum;
                idx = i;
            }
            right[i] = idx;
            if (i <= n - k) sum -= nums[i + k - 1];
        }
        sum = 0;
        vector<int> ans(3);
        for (int i = k; i <= n - k * 2; i++)
        {
            int l = left[i - 1], r = right[i + k];
            ll left_sum = tot[l + k] - tot[l];
            ll right_sum = tot[r + k] - tot[r];
            ll mid_sum = tot[i + k] - tot[i];
            if (left_sum + right_sum + mid_sum > sum)
            {
                sum = left_sum + right_sum + mid_sum;
                ans = vector<int>{l, i, r};
            }
        }
        return ans;
    }
};