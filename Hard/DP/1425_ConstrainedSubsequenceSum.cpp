class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(dp[0], 0));
        for (int i = 1; i < n; i++)
        {
            auto tmp = pq.top();
            dp[i] = max(nums[i], nums[i] + tmp.first);
            pq.push(make_pair(dp[i], i));
            while (!pq.empty() && i - pq.top().second >= k) pq.pop();
        }
        return *max_element(dp.begin(), dp.end());
    }
};