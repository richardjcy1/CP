// Use priority queue to preserve max subsequence within a window of size k
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
        {
            dp[i] = nums[i];
            if (!pq.empty()) dp[i] = max(dp[i], dp[i] + pq.top().first);
            while (!pq.empty() && i - pq.top().second >= k) pq.pop();
            if (dp[i] > 0) pq.push({dp[i], i});
        }
        return *max_element(dp.begin(), dp.end());
    }
};