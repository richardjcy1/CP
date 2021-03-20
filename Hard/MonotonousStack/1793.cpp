const int INF = 0x3f3f3f3f;

class Solution {
public:
    // Similar problem: 84. Largest Rectangle in Histogram
    // Topic: monotonous stack
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> stk;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = {};
        for (int i = n - 1; ~i; i--)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty())
            {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        int ans = -INF;
        for (int i = 0; i < n; i++)
        {
            if (left[i] < k && right[i] > k)
            {
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return ans;
    }
};