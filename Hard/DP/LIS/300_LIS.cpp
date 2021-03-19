// O(nlogn)利用类似单调栈的方式构造LIS,每次在dp中找对应插入的位置
class Solution {
public:
    int binarySearch(vector<int>& dp, int size, int target, vector<int>& nums)
    {
        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (dp[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int size = 0, n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            int pos = binarySearch(dp, size, nums[i], nums);
            dp[pos] = nums[i];
            if (pos == size) size++;
        }
        return size;
    }
};