void countSort(vector<int>& arr, int n, int exp)
{
    vector<int> output(n);
    int i;
    vector<int> count(10);
    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++) count[i] += count[i - 1];
    for (i = n - 1; ~i; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countSort(arr, arr.size(), exp);
}

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        radixSort(nums);
        int ans = 0;
        for (int i = 1; i < n; i++) ans = max(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};