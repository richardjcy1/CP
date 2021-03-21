class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n - k + 1);
        for (int i = 0; i < n; i++)
        {
            int idx = i - k + 1;
            while (!dq.empty() && i - dq.front() >= k) dq.pop_front(); // keep window size k - 1
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); // maintain monotonous decreasing queue
            dq.push_back(i);
            if (idx >= 0) ans[idx] = nums[dq.front()]; // check if ok to return result
        }
        return ans;
    }
};