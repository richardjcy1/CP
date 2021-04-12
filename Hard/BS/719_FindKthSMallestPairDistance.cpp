typedef long long ll;

class Solution {
public:
    vector<int> a;
    int n;
    int k;
    
    bool check(ll x)
    {
        ll start = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (a[i] - a[start] > x) ++start;
            ans += (i - start);
        }
        return ans >= k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        a = nums;
        n = a.size();
        sort(a.begin(), a.end());
        this->k = k;
        int left = 0, right = 1e6 + 5;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // cout << left << " " << right << " " << mid << " ";
            if (check(mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;    
            }
        }
        return left;
    }
};