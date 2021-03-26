class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        q = collections.deque()
        n = len(nums)
        dp = [0] * n
        for i, v in enumerate(nums):
            dp[i] = v
            if len(q) > 0:
                dp[i] = max(dp[i], dp[i] + dp[q[0]])
            while len(q) > 0 and i - q[0] >= k:
                q.popleft()
            while len(q) > 0 and dp[i] >= dp[q[-1]]:
                q.pop()
            if dp[i] > 0:
                q.append(i)
        return max(dp)
            