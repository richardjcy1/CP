//将target里的元素和下标建立映射，问题转化为在arr里找下标的LIS，要添加的个数就是target.size()和LIS.size()之差
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
            if (nums[i] == -1) continue;
            int pos = binarySearch(dp, size, nums[i], nums);
            dp[pos] = nums[i];
            if (pos == size) size++;
        }
        return size;
    }
    
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int m = target.size(), n = arr.size();
        for (int i = 0; i < m; i++)
        {
            mp[target[i]] = i;
        }
        vector<int> nums(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i]) != mp.end()) nums[i] = mp[arr[i]];
        }
        return m - lengthOfLIS(nums);
    }
};