// Use mono queue to preserve max sum subsequence within a window of size k
// Time complexity: O(n)
// Space complexity: O(n)
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        int ans = -INF;
        vector<int> sum(n);
        for (int i = 0; i < n; i++)
        {
            sum[i] = nums[i];
            if (!q.empty()) sum[i] += sum[q.front()];
            ans = max(ans, sum[i]);
            while (!q.empty() && i - q.front() >= k) q.pop_front();
            while (!q.empty() && sum[q.back()] <= sum[i]) q.pop_back();
            if (sum[i] > 0) q.push_back(i);
        }
        return ans;
    }
};